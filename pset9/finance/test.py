username1 = {'username': 'john'}
username2 = {'username': 'peter'}
username3 = {'username': 'harry'}
usernames = [username1, username2, username3]
for username in usernames:
    print(username['username'])

CREATE TABLE transactions (id INTEGER PRIMARY KEY, timestamp TEXT, user_id REFERENCES users(id), type TEXT NOT NULL, symbol TEXT NOT NULL,  quantity NUMERIC NOT NULL, price NUMERIC NOT NULL, cost NUMERIC NOT NULL);
sqlite> CREATE TABLE portfolios (id INTEGER PRIMARY KEY, user_id REFERENCES users(id), symbol TEXT NOT NULL, quantity NUMERIC NOT NULL);