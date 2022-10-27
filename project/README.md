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
This route is called when the subject is selected (state change) on the calculator pages. It receives a subject course name from the jquery script on the front end. This is delivered via the GET method. This is retrieved in Flask using request.args.get function as a string type. This is used to determine which list of courses to return to the jquery script. The list of units is parsed and returned using jsonify in JSON format to the jquery script on the front end.
# index
This is the index page which contains links formatted as buttons to each of the different calculator pages
# /_calculate_extcert_grade AND /_calculate_dip_grade AND /_calculate_extdip_grade

This route is called when the submit button is selected (state change) on the calculator pages. It receives subject course name, unit titles and unit grades from the jquery script on the front end. This is delivered via the GET method. This is retrieved in Flask using request.args.get function as a string type.
The unit titles and grades are formatted into a dictionary.
The calculate_points function is called and these two variables are taken as parameters. The function returns a points value. This points value is checked against ertain points thresholds using conditional statmeents. When the points score meets a condition the final_grade variable is updated to the correct grade

## courses.db
SQL database which stores the list of courses and units
# COURSES
CREATE TABLE COURSES (course_id PRIMARY KEY NOT NULL, name TEXT NOT NULL);
# UNITS
CREATE TABLE UNITS (id PRIMARY KEY, unit_id INT NOT NULL, course_id REFERENCES COURSES(course_id), title TEXT NOT NULL, glh TEXT NOT NULL, type TEXT NOT NULL);
## requirements.txt
A list of packages required for the correct functioning of the applciation
## templates
The pages which make up the front end of the application
# layout.html
A standard layout which is extended on other pages using Jinja, includes navbar, footer and stylesheets
# index.html
The homepage where links to the different calculators are included
# extcert.html AND dip.html AND extdip.html
The homepage where links to the different calculators are included. This page consists of different numbers of dropdown selection boxes for the units as each qualification is a different size.

The ext cert contains 4 units
The dip contains 8 units
The extdip contains 13 units

A jquery script at the bottom of the page is used to prepopulate the dropdown when there is a state change. The state change is when the subhect is selected. This triggers the script to send the course via GET to the Flask application. The Flask application then sends back a 

## static

## References
https://flask.palletsprojects.com/en/2.0.x/patterns/jquery/
https://stackoverflow.com/questions/68852940/how-to-create-two-dependent-dynamic-dropdown-lists-using-flask