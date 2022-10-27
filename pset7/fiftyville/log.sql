-- Keep a log of any SQL queries you execute as you solve the mystery.
-- suspect list
Ruth
Eugene
Raymond
-- check tables structure
.schema
-- search description of crime scene
SELECT description, street FROM crime_scene_reports WHERE year = 2021 AND month = 7 AND day = 28;
-- check interview schema
.schema interviews
-- get transcripts of interviews that mention word bakery
SELECT transcript, year, month, day, name FROM interviews WHERE transcript LIKE '%bakery%';