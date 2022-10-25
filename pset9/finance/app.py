import os

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from tempfile import mkdtemp
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, login_required, lookup, usd

# Configure application
app = Flask(__name__)

# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True

# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")

# Make sure API key is set
if not os.environ.get("API_KEY"):
    raise RuntimeError("API_KEY not set")


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/")
@login_required
def index():
    """Show portfolio of stocks"""
    stocks = db.execute("SELECT * FROM portfolios")
    cash = db.execute("SELECT cash FROM users WHERE id = ?", session["user_id"])[0]["cash"]
    holdings = cash
    for stock in stocks:
        stock["value"] = stock["quantity"] * lookup(stock["symbol"])["price"]
        holdings += stock["value"]
    return render_template("index.html", stocks=stocks, cash=cash, holdings=holdings)


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""
    if request.method == "POST":
        symbol = request.form.get("symbol")
        shares = request.form.get("shares")
        if not request.form.get("symbol"):
            return apology("must provide stock", 422)
        elif int(shares) <= 0:
            return apology("You must enter a valid number of shares", 422)
        else:
            quote = lookup(symbol)
            if quote == None:
                return apology("This stock does not exist", 400)
            else:
                id = session["user_id"]
                cash = db.execute("SELECT cash FROM users WHERE id = ?", id)
                cost = float(shares) * float(quote["price"])
                if cost > float(cash[0]["cash"]):
                    return apology("You do not have sufficient funds", 400)
                db.execute("INSERT INTO transactions (user_id, type, symbol, quantity, price, cost, timestamp) VALUES (?, ?, ?, ?, ?, ?, datetime('now'))", id, 'BUY', symbol, shares, quote["price"], cost)
                remcash = float(cash[0]["cash"]) - cost
                db.execute("UPDATE users SET cash = ? WHERE id = ?", remcash, id)
                currentHoldings = db.execute("SELECT * FROM portfolios WHERE user_id = ?", id)
                for stock in currentHoldings:
                    if symbol == stock["symbol"]:
                        old = db.execute("SELECT quantity FROM portfolios WHERE user_id = ? AND symbol = ?", id, symbol)
                        new = int(shares) + int(old[0]["quantity"])
                        db.execute("UPDATE portfolios SET quantity = ? WHERE id = ? AND symbol = ?", new, id, symbol)
                    else:
                        db.execute("INSERT INTO portfolios (user_id, symbol, quantity) VALUES(?, ?, ?)", id, symbol, shares)
        return redirect("/")
    else:
        return render_template("buy.html")


@app.route("/history")
@login_required
def history():
    """Show history of transactions"""
    transactions = db.execute("SELECT * FROM transactions WHERE user_id = ?", session["user_id"])
    return render_template("history.html", transactions=transactions)


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Query database for username
        rows = db.execute("SELECT * FROM users WHERE username = ?", request.form.get("username"))

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(rows[0]["hash"], request.form.get("password")):
            return apology("invalid username and/or password", 403)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    """Get stock quote."""
    if request.method == "POST":
        symbol = request.form.get("symbol")
        if not request.form.get("symbol"):
            return apology("You must provide a symbol", 400)
        quote = lookup(symbol)
        if quote == None:
            return apology("This stock does not exist", 400)
        else:
            return render_template("quoted.html", quote=quote)
    else:
        return render_template("quote.html")


@app.route("/register", methods=["GET", "POST"])
def register():

    if request.method == "POST":

        usernames = db.execute("SELECT username FROM users")

        if not request.form.get("username"):
            return apology("must provide username", 422)
        elif not request.form.get("password"):
            return apology("must provide password", 422)
        elif not request.form.get("confirmation"):
            return apology("must confirm password", 422)
        elif not request.form.get("password") == request.form.get("confirmation"):
            return apology("must provide username", 422)
        else:
            for username in usernames:
                if username['username'] == request.form.get("username"):
                    return apology("username already exists", 422)
            username = request.form.get("username")
            hash = generate_password_hash(request.form.get("password"))
            db.execute("INSERT INTO users (username, hash) VALUES(?, ?)", username, hash)
            return redirect("/")
        """Register user"""
    else:
        return render_template("/register.html")


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""
    portfolio = db.execute("SELECT * FROM portfolios WHERE user_id = ?", session["user_id"])
    if request.method == "POST":
        symbol = request.form.get("symbol")
        shares = request.form.get("shares")
        if not request.form.get("symbol"):
            return apology("must provide stock", 422)
        elif float(shares) <= 0 or not float(shares).is_integer():
            return apology("You must enter a valid number of shares", 422)
        else:
            for stock in portfolio:
                if symbol == stock["symbol"]:
                    if int(shares) > (db.execute("SELECT quantity FROM portfolios WHERE symbol = ?", symbol))[0]["quantity"]:
                        return apology("You must enter a valid number of shares", 422)

            quote = lookup(symbol)
            id = session["user_id"]
            cash = db.execute("SELECT cash FROM users WHERE id = ?", id)
            cost = float(shares) * float(quote["price"])
            db.execute("INSERT INTO transactions (user_id, type, symbol, quantity, price, cost, timestamp) VALUES (?, ?, ?, ?, ?, ?, datetime('now'))", id, 'SELL', symbol, shares, quote["price"], cost)
            remcash = float(cash[0]["cash"]) + cost
            db.execute("UPDATE users SET cash = ? WHERE id = ?", 10000, id)
            for stock in portfolio:
                if symbol == stock["symbol"]:
                    old = db.execute("SELECT quantity FROM portfolios WHERE user_id = ? AND symbol = ?", id, symbol)
                    new = int(old[0]["quantity"]) - int(shares)
                    db.execute("UPDATE portfolios SET quantity = ? WHERE id = ? AND symbol = ?", new, id, symbol)
                    if new == 0:
                        db.execute("DELETE FROM portfolios WHERE symbol = ?", symbol)
            return redirect("/")

    return render_template("sell.html", portfolio=portfolio)
