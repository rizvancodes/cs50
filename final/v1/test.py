import os

from cs50 import SQL
from flask import Flask, flash, jsonify, redirect, render_template, request, session

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///courses.db")

unit_details = db.execute("SELECT type FROM UNITS WHERE title = ?", 'Principles and Applications of Applied Science I')
print(unit_details)