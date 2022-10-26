import os

from cs50 import SQL
from flask import Flask, flash, jsonify, redirect, render_template, request, session

# Configure application
app = Flask(__name__)

# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True

@app.route("/extcert")
def extcert():
    """
    initialize drop down menus
    """

    units = {"Applied Science": ["Principles and Applications of Science I", "Practical Scientific Procedures and Techniques"], "Health and Social Care": ["Human Lifespan Development", "Working in Health and Social Care"]}

    default_courses = sorted(units.keys())
    default_units = units[default_courses[0]]

    return render_template('extcert.html',
                       all_courses=default_courses,
                       all_units=default_units)

@app.route("/dip")
def dip():
    """
    initialize drop down menus
    """

    units = {"Applied Science": ["Principles and Applications of Science I", "Practical Scientific Procedures and Techniques"], "Health and Social Care": ["Human Lifespan Development", "Working in Health and Social Care"]}

    default_courses = sorted(units.keys())
    default_units = units[default_courses[0]]

    return render_template('dip.html',
                       all_courses=default_courses,
                       all_units=default_units)

@app.route("/extdip")
def extdip():
    """
    initialize drop down menus
    """

    units = {"Applied Science": ["Principles and Applications of Science I", "Practical Scientific Procedures and Techniques"], "Health and Social Care": ["Human Lifespan Development", "Working in Health and Social Care"]}

    default_courses = sorted(units.keys())
    default_units = units[default_courses[0]]

    return render_template('extdip.html',
                       all_courses=default_courses,
                       all_units=default_units)


@app.route('/_update_dropdown')
def update_dropdown():

    units = {"Applied Science": ["Principles and Applications of Science I", "Practical Scientific Procedures and Techniques"], "Health and Social Care": ["Human Lifespan Development", "Working in Health and Social Care"]}
    # the value of the first dropdown (selected by the user)
    selected_course = request.args.get('selected_course', type=str)

    # get values for the second dropdown
    updated_values = units[selected_course]

    # create the values in the dropdown as a html string
    html_string_selected = ''
    for entry in updated_values:
        html_string_selected += '<option value="{}">{}</option>'.format(entry, entry)

    return jsonify(html_string_selected=html_string_selected)

@app.route('/')
def index():
    return render_template("index.html")

@app.route('/_calculate_extcert_grade')
def process_data():
    selected_course = request.args.get('selected_class', type=str)
    selected_units = {(request.args.get('unit1', type=str): (request.args.get('grade1', type=str),
                      (request.args.get('unit2', type=str): request.args.get('grade2', type=str),
                      request.args.get('unit3', type=str): request.args.get('grade3', type=str
                        
    # process the two selected values here and return the response; here we just create a dummy string

    return jsonify(random_text="You selected the car brand: {} and the model: {}.".format(selected_class, selected_entry))