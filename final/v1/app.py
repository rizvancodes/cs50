import os

from cs50 import SQL
from flask import Flask, flash, jsonify, redirect, render_template, request, session

# Configure application
app = Flask(__name__)

# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///courses.db")

#global variable points per grade for different unit types
e90 = {'D': 24, 'M': 15, 'P': 9, 'N': 6, 'U': 0}
e120 = {'D': 32, 'M': 20, 'P': 12, 'N': 8, 'U': 0}
i60 = {'D': 16, 'M': 10, 'P': 6, 'U': 0}
i90 = {'D': 24, 'M': 15, 'P': 9, 'U': 0}
i120 = {'D': 32, 'M': 20, 'P': 12, 'U': 0}

def get_unitlist():
    courses = db.execute('SELECT * FROM COURSES')
    unitlist = {}

    for course in courses:
        courseid = course['course_id']
        coursename = course['name']

        units = db.execute('SELECT title FROM UNITS WHERE course_id = ?', courseid)
        ulist = []
        for unit in units:
            ulist.append(unit['title'])
        unitlist[coursename] = ulist

    return unitlist

def calculate_points(selected_course, selected_units):


@app.route("/extcert")
def extcert():
    """
    initialize drop down menus
    """
    unitlist = get_unitlist()

    default_courses = sorted(unitlist.keys())
    default_units = unitlist[default_courses[0]]

    return render_template('extcert.html',
                       all_courses=default_courses,
                       all_units=default_units)

@app.route("/dip")
def dip():
    """
    initialize drop down menus
    """
    unitlist = get_unitlist()

    default_courses = sorted(unitlist.keys())
    default_units = unitlist[default_courses[0]]

    return render_template('dip.html',
                       all_courses=default_courses,
                       all_units=default_units)

@app.route("/extdip")
def extdip():
    """
    initialize drop down menus
    """
    unitlist = get_unitlist()

    default_courses = sorted(unitlist.keys())
    default_units = unitlist[default_courses[0]]

    return render_template('extdip.html',
                       all_courses=default_courses,
                       all_units=default_units)


@app.route('/_update_dropdown')
def update_dropdown():

    unitlist = get_unitlist()

    # the value of the first dropdown (selected by the user)
    selected_course = request.args.get('selected_course', type=str)

    # get values for the second dropdown
    updated_values = unitlist[selected_course]

    # create the values in the dropdown as a html string
    html_string_selected = ''
    for entry in updated_values:
        html_string_selected += '<option value="{}">{}</option>'.format(entry, entry)

    return jsonify(html_string_selected=html_string_selected)

@app.route('/')
def index():
    return render_template("index.html")

@app.route('/_calculate_extcert_grade')
def calculate_extcert_grade():
    selected_course = request.args.get('selected_course', type=str)
    selected_units = {request.args.get('unit1', type=str): request.args.get('grade1', type=str),
                      request.args.get('unit2', type=str): request.args.get('grade2', type=str),
                      request.args.get('unit3', type=str): request.args.get('grade3', type=str),
                      request.args.get('unit4', type=str): request.args.get('grade4', type=str)}
    print(selected_units)

    total = 0

    for key in selected_units:
        if ((db.execute("SELECT type FROM UNITS WHERE title = ?", key)[0]['type']) == 'External'):
            if ((db.execute("SELECT glh FROM UNITS WHERE title = ?", key)[0]['glh']) == '120'):
                total += e120[selected_units[key]]
            else:
                total += e90[selected_units[key]]
        elif ((db.execute("SELECT type FROM UNITS WHERE title = ?", key)[0]['type']) == 'Internal'):
            if ((db.execute("SELECT glh FROM UNITS WHERE title = ?", key)[0]['glh']) == '120'):
                total += i120[selected_units[key]]
            elif ((db.execute("SELECT glh FROM UNITS WHERE title = ?", key)[0]['glh']) == '90'):
                total += i90[selected_units[key]]
            else:
                total += i60[selected_units[key]]


    # process the two selected values here and return the response; here we just create a dummy string
    return jsonify(random_text="You selected the car brand: {} and the model: {}. Your total points are: {}".format(selected_course, selected_units, total))

@app.route('/result')
def result():
    return render_template('result.html')