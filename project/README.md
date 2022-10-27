# BTEC Grade Calculator
#### Video Demo:  [Calculator Demo](https://youtu.be/CLbdc2nqJSE)
#### Description: BTEC is a UK pre university qualification which comes in three different streams. You can study a range of different subjects under a BTEC qualification. Each different stream consists of different numbers of units. Each unit is of a different size and awards a different number of points. The aim of this project was to create a grade calculator for students to determine an estimated final grade.

 !(project/assets/Screenshot 2022-10-27 at 15.37.09.png)

## app.py
The backend is implemented in python and Flask using sqlite3 for database implementation.

# unit points global variables
This is a group of dictionaries of grade keys and point values for different type and size of units.
# get_unitlist
This function calls on the database to retrieve values for the course name and course ID from the COURSES table. These are used to retrieve the units for the course from the UNITS table. The unit titles for each course are stored in a list structure by reading from the database and storing the titles in a list structure. The final step is to create a dictionary where the keys are the course names and the values are the list of unit titles. This 'unitlist' dictionary is from the function and will be later used to populate dependent selection dropdowns
# calculate_points
This function takes a course name and dictionary of unit title keys and grade values as a parameter. This is then used to determine the size of the unit by querying the database. I have used a number of conditionals to determine the type of unit and which points table to use from the unit points global variables. This is done by using the course name and unit title parameter and querying the database to check if they meet different conditions. Once we have found the correct conditions the grade value parameter is used to determine the number of points achieved for a unit of that type and size.
# /extcert
This route initialises the Extended Certificate calculator page and calls the get_unitlist function taking the keys from the dictionary returned from that function and using it to populate the course subject dropdown boxes.
# /dip
This route initialises the Diploma calculator page and calls the get_unitlist function taking the keys from the dictionary returned from that function and using it to populate the course subject dropdown boxes.
# /extdip
This route initialises the Extended Diploma calculator page and calls the get_unitlist function taking the keys from the dictionary returned from that function and using it to populate the course subject dropdown boxes.
# /_update_dropdown
This route is called when the subject is selected on the calculator page.
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