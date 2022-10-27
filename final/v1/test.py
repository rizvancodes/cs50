import os

from cs50 import SQL
from flask import Flask, flash, jsonify, redirect, render_template, request, session

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///courses.db")

unit_details = db.execute("SELECT * FROM UNITS WHERE course_id = (SELECT course_id FROM COURSES WHERE name = ?)", 'Applied Science')
print(unit_details)