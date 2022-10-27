import os

from cs50 import SQL
from flask import Flask, flash, jsonify, redirect, render_template, request, session

app = Flask(__name__)

app.config["TEMPLATES_AUTO_RELOAD"] = True

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

    points = 0

    for key in selected_units:
        if ((db.execute("SELECT type FROM UNITS WHERE title = ?", key)[0]['type']) == 'External'):
            if ((db.execute("SELECT glh FROM UNITS WHERE title = ?", key)[0]['glh']) == '120'):
                points += e120[selected_units[key]]
            else:
                points += e90[selected_units[key]]
        elif ((db.execute("SELECT type FROM UNITS WHERE title = ?", key)[0]['type']) == 'Internal'):
            if ((db.execute("SELECT glh FROM UNITS WHERE title = ?", key)[0]['glh']) == '120'):
                points += i120[selected_units[key]]
            elif ((db.execute("SELECT glh FROM UNITS WHERE title = ?", key)[0]['glh']) == '90'):
                points += i90[selected_units[key]]
            else:
                points += i60[selected_units[key]]

    return points


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

    selected_course = request.args.get('selected_course', type=str)

    updated_values = unitlist[selected_course]

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

    points = calculate_points(selected_course, selected_units)

    final_grade = 0
    if points >= 90:
        final_grade = 'D*'
    elif 74 <= points < 90:
        final_grade = 'D'
    elif 52 <= points < 74:
        final_grade = 'M'
    elif 36 <= points < 52:
        final_grade = 'P'
    else:
        final_grade = 'U'

    return jsonify(grade_report="Your total points are: {}. Your estimated grade is: {}".format(points, final_grade))

@app.route('/_calculate_dip_grade')
def calculate_dip_grade():
    selected_course = request.args.get('selected_course', type=str)
    selected_units = {request.args.get('unit1', type=str): request.args.get('grade1', type=str),
                      request.args.get('unit2', type=str): request.args.get('grade2', type=str),
                      request.args.get('unit3', type=str): request.args.get('grade3', type=str),
                      request.args.get('unit4', type=str): request.args.get('grade4', type=str),
                      request.args.get('unit5', type=str): request.args.get('grade5', type=str),
                      request.args.get('unit6', type=str): request.args.get('grade6', type=str),
                      request.args.get('unit7', type=str): request.args.get('grade7', type=str),
                      request.args.get('unit8', type=str): request.args.get('grade8', type=str)}

    points = calculate_points(selected_course, selected_units)

    final_grade = 0
    if points >= 180:
        final_grade = 'D*D*'
    elif 162 <= points < 180:
        final_grade = 'D*D'
    elif 144 <= points < 162:
        final_grade = 'DD'
    elif 124 <= points < 144:
        final_grade = 'DM'
    elif 104 <= points < 124:
        final_grade = 'MM'
    elif 88 <= points < 104:
        final_grade = 'MP'
    elif 72 <= points < 88:
        final_grade = 'PP'
    else:
        final_grade = 'U'

    return jsonify(grade_report="Your total points are: {}. Your estimated grade is: {}".format(points, final_grade))

@app.route('/_calculate_extdip_grade')
def calculate_extdip_grade():
    selected_course = request.args.get('selected_course', type=str)
    selected_units = {request.args.get('unit1', type=str): request.args.get('grade1', type=str),
                      request.args.get('unit2', type=str): request.args.get('grade2', type=str),
                      request.args.get('unit3', type=str): request.args.get('grade3', type=str),
                      request.args.get('unit4', type=str): request.args.get('grade4', type=str),
                      request.args.get('unit5', type=str): request.args.get('grade5', type=str),
                      request.args.get('unit6', type=str): request.args.get('grade6', type=str),
                      request.args.get('unit7', type=str): request.args.get('grade7', type=str),
                      request.args.get('unit8', type=str): request.args.get('grade8', type=str),
                      request.args.get('unit9', type=str): request.args.get('grade9', type=str),
                      request.args.get('unit10', type=str): request.args.get('grade10', type=str),
                      request.args.get('unit11', type=str): request.args.get('grade11', type=str),
                      request.args.get('unit12', type=str): request.args.get('grade12', type=str),
                      request.args.get('unit13', type=str): request.args.get('grade13', type=str),}

    points = calculate_points(selected_course, selected_units)

    final_grade = 0
    if points >= 270:
        final_grade = 'D*D*D*'
    elif 252 <= points < 270:
        final_grade = 'D*D*D'
    elif 234 <= points < 252:
        final_grade = 'D*DD'
    elif 216 <= points < 234:
        final_grade = 'DDD'
    elif 196 <= points < 216:
        final_grade = 'DDM'
    elif 176 <= points < 196:
        final_grade = 'DMM'
    elif 156 <= points < 176:
        final_grade = 'MMM'
    elif 140 <= points < 156:
        final_grade = 'MMP'
    elif 124 <= points < 140:
        final_grade = 'MPP'
    elif 108 <= points < 124:
        final_grade = 'PPP'
    else:
        final_grade = 'U'

    #return the points and final grade as a string
    return jsonify(grade_report="Your total points are: {}. Your estimated grade is: {}".format(points, final_grade))