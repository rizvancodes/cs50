# BTEC Grade Calculator
#### Video Demo:  [Calculator Demo](https://youtu.be/CLbdc2nqJSE)
#### Description: BTEC is a UK pre university qualification which comes in three different streams. You can study a range of different subjects under a BTEC qualification. Each different stream consists of different numbers of units. Each unit is of a different size and awards a different number of points. The aim of this project was to create a grade calculator for students to determine an estimated final grade.

 !(project/assets/Screenshot 2022-10-27 at 15.37.09.png)

## app.py
The backend is implemented in python and Flask using sqlite3 for database implementation.
# get_unitlist
This function calls on the database to retrieve values for the course name and course ID from the COURSES table. These are used to retrieve the units for the course from the UNITS table. The unit titles for each course are stored in a list structure by reading from the database and storing the titles in a list structure. The final step is to create a dictionary where the keys are the course names and the values are the list of unit titles. This is what is returned from the function. 
# calculate_points

# /extcert

# /dip

# /extdip

# /_update_dropdown

# index

# /_calculate_extcert_grade

# /_calculate_dip_grade

# /_calculate_extdip_grade

## courses.db

# COURSES

# UNITS

## requirements.txt

## templates

# layout.html

# index.html

# extcert.html

# dip.html

# extdip.html

## static