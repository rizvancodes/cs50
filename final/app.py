import os

from cs50 import SQL
from flask import Flask, flash, jsonify, redirect, render_template, request, session

# Configure application
app = Flask(__name__)

# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True

@app.route("/")
def index():
    """
    initialize drop down menus
    """

    units = {"Applied Science": ["Principles and Applications of Science I", "Practical Scientific Procedures and Techniques"], "Health and Social Care": ["Human Lifespan Development", "Working in Health and Social Care]}

    default_courses = sorted(units.keys())
    default_units = units[default_courses[0]]

    return render_template('index.html',
                       all_courses=default_courses,
                       all_units=default_units)


@app.route('/_update_dropdown')
def update_dropdown():

    # the value of the first dropdown (selected by the user)
    selected_course = request.args.get('selected_course', type=str)

    # get values for the second dropdown
    updated_values = get_dropdown_values()[selected_class]

    # create the value sin the dropdown as a html string
    html_string_selected = ''
    for entry in updated_values:
        html_string_selected += '<option value="{}">{}</option>'.format(entry, entry)

    return jsonify(html_string_selected=html_string_selected)
