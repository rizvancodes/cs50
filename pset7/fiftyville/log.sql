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
| 2021 | 7     | 28  | Ruth    | Sometime within ten minutes of the theft, I saw the thief get into a car in the bakery parking lot and drive away. If you have security footage from the bakery parking lot, you might want to look for cars that left the parking lot in that time frame.                                                          |
| 2021 | 7     | 28  | Eugene  | I don't know the thief's name, but it was someone I recognized. Earlier this morning, before I arrived at Emma's bakery, I was walking by the ATM on Leggett Street and saw the thief there withdrawing some money.                                                                                                 |
| 2021 | 7     | 28  | Raymond | As the thief was leaving the bakery, they called someone who talked to them for less than a minute. In the call, I heard the thief say that they were planning to take the earliest flight out of Fiftyville tomorrow. The thief then asked the person on the other end of the phone to purchase the flight ticket. |