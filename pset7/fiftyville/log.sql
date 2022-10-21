-- Keep a log of any SQL queries you execute as you solve the mystery.
-- check tables structure
.schema
-- search description of crime scene
SELECT description, street FROM crime_scene_reports WHERE year = 2021 AND month = 7 AND day = 28;
-- check interview schema
.schema interviews