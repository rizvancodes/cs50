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
--| 2021 | 7     | 28  | Ruth    | Sometime within ten minutes of the theft, I saw the thief get into a car in the bakery parking lot and drive away. If you have security footage from the bakery parking lot, you might want to look for cars that left the parking lot in that time frame.                                                          |
--| 2021 | 7     | 28  | Eugene  | I don't know the thief's name, but it was someone I recognized. Earlier this morning, before I arrived at Emma's bakery, I was walking by the ATM on Leggett Street and saw the thief there withdrawing some money.                                                                                                 |
--| 2021 | 7     | 28  | Raymond | As the thief was leaving the bakery, they called someone who talked to them for less than a minute. In the call, I heard the thief say that they were planning to take the earliest flight out of Fiftyville tomorrow. The thief then asked the person on the other end of the phone to purchase the flight ticket. |
SELECT * FROM bakery_security_logs WHERE year = 2021 AND month = 7 AND day = 28;
'
| id  | year | month | day | hour | minute | activity | license_plate |
+-----+------+-------+-----+------+--------+----------+---------------+
| 219 | 2021 | 7     | 28  | 8    | 2      | entrance | 1M92998       |
| 220 | 2021 | 7     | 28  | 8    | 2      | entrance | N507616       |
| 221 | 2021 | 7     | 28  | 8    | 2      | exit     | 1M92998       |
| 222 | 2021 | 7     | 28  | 8    | 2      | exit     | N507616       |
| 223 | 2021 | 7     | 28  | 8    | 7      | entrance | 7Z8B130       |
| 224 | 2021 | 7     | 28  | 8    | 7      | exit     | 7Z8B130       |
| 225 | 2021 | 7     | 28  | 8    | 13     | entrance | 47MEFVA       |
| 226 | 2021 | 7     | 28  | 8    | 13     | exit     | 47MEFVA       |
| 227 | 2021 | 7     | 28  | 8    | 15     | entrance | D965M59       |
| 228 | 2021 | 7     | 28  | 8    | 15     | entrance | HW0488P       |
| 229 | 2021 | 7     | 28  | 8    | 15     | exit     | D965M59       |
| 230 | 2021 | 7     | 28  | 8    | 15     | exit     | HW0488P       |
| 231 | 2021 | 7     | 28  | 8    | 18     | entrance | L93JTIZ       |
| 232 | 2021 | 7     | 28  | 8    | 23     | entrance | 94KL13X       |
| 233 | 2021 | 7     | 28  | 8    | 25     | entrance | L68E5I0       |
| 234 | 2021 | 7     | 28  | 8    | 25     | entrance | HOD8639       |
| 235 | 2021 | 7     | 28  | 8    | 25     | exit     | HOD8639       |
| 236 | 2021 | 7     | 28  | 8    | 34     | exit     | L68E5I0       |
| 237 | 2021 | 7     | 28  | 8    | 34     | entrance | 1106N58       |
| 238 | 2021 | 7     | 28  | 8    | 34     | entrance | W2CT78U       |
| 239 | 2021 | 7     | 28  | 8    | 34     | exit     | W2CT78U       |
| 240 | 2021 | 7     | 28  | 8    | 36     | entrance | 322W7JE       |
| 241 | 2021 | 7     | 28  | 8    | 38     | entrance | 3933NUH       |
| 242 | 2021 | 7     | 28  | 8    | 38     | exit     | 3933NUH       |
| 243 | 2021 | 7     | 28  | 8    | 42     | entrance | 0NTHK55       |
| 244 | 2021 | 7     | 28  | 8    | 44     | entrance | 1FBL6TH       |
| 245 | 2021 | 7     | 28  | 8    | 44     | exit     | 1FBL6TH       |
| 246 | 2021 | 7     | 28  | 8    | 49     | entrance | P14PE2Q       |
| 247 | 2021 | 7     | 28  | 8    | 49     | exit     | P14PE2Q       |
| 248 | 2021 | 7     | 28  | 8    | 50     | entrance | 4V16VO0       |
| 249 | 2021 | 7     | 28  | 8    | 50     | exit     | 4V16VO0       |
| 250 | 2021 | 7     | 28  | 8    | 57     | entrance | 8LLB02B       |
| 251 | 2021 | 7     | 28  | 8    | 57     | exit     | 8LLB02B       |
| 252 | 2021 | 7     | 28  | 8    | 59     | entrance | O784M2U       |
| 253 | 2021 | 7     | 28  | 8    | 59     | exit     | O784M2U       |
| 254 | 2021 | 7     | 28  | 9    | 14     | entrance | 4328GD8       |
| 255 | 2021 | 7     | 28  | 9    | 15     | entrance | 5P2BI95       |
| 256 | 2021 | 7     | 28  | 9    | 20     | entrance | 6P58WS2       |
| 257 | 2021 | 7     | 28  | 9    | 28     | entrance | G412CB7       |
| 258 | 2021 | 7     | 28  | 10   | 8      | entrance | R3G7486       |
| 259 | 2021 | 7     | 28  | 10   | 14     | entrance | 13FNH73       |
| 260 | 2021 | 7     | 28  | 10   | 16     | exit     | 5P2BI95       |
| 261 | 2021 | 7     | 28  | 10   | 18     | exit     | 94KL13X       |
| 262 | 2021 | 7     | 28  | 10   | 18     | exit     | 6P58WS2       |
| 263 | 2021 | 7     | 28  | 10   | 19     | exit     | 4328GD8       |
| 264 | 2021 | 7     | 28  | 10   | 20     | exit     | G412CB7       |
| 265 | 2021 | 7     | 28  | 10   | 21     | exit     | L93JTIZ       |
| 266 | 2021 | 7     | 28  | 10   | 23     | exit     | 322W7JE       |
| 267 | 2021 | 7     | 28  | 10   | 23     | exit     | 0NTHK55       |
| 268 | 2021 | 7     | 28  | 10   | 35     | exit     | 1106N58       |
| 269 | 2021 | 7     | 28  | 10   | 42     | entrance | NRYN856       |
| 270 | 2021 | 7     | 28  | 10   | 44     | entrance | WD5M8I6       |
| 271 | 2021 | 7     | 28  | 10   | 55     | entrance | V47T75I       |
| 272 | 2021 | 7     | 28  | 11   | 6      | entrance | 4963D92       |
| 273 | 2021 | 7     | 28  | 11   | 13     | entrance | C194752       |
| 274 | 2021 | 7     | 28  | 11   | 52     | entrance | 94MV71O       |
| 275 | 2021 | 7     | 28  | 12   | 20     | entrance | FLFN3W0       |
| 276 | 2021 | 7     | 28  | 12   | 49     | entrance | 207W38T       |
| 277 | 2021 | 7     | 28  | 13   | 8      | entrance | RS7I6A0       |
| 278 | 2021 | 7     | 28  | 13   | 30     | entrance | 4468KVT       |
| 279 | 2021 | 7     | 28  | 13   | 42     | entrance | NAW9653       |
| 280 | 2021 | 7     | 28  | 14   | 18     | exit     | NAW9653       |
| 281 | 2021 | 7     | 28  | 15   | 6      | exit     | RS7I6A0       |
| 282 | 2021 | 7     | 28  | 15   | 16     | exit     | 94MV71O       |
| 283 | 2021 | 7     | 28  | 16   | 6      | exit     | WD5M8I6       |
| 284 | 2021 | 7     | 28  | 16   | 38     | exit     | 4468KVT       |
| 285 | 2021 | 7     | 28  | 16   | 42     | exit     | 207W38T       |
| 286 | 2021 | 7     | 28  | 16   | 47     | exit     | C194752       |
| 287 | 2021 | 7     | 28  | 17   | 11     | exit     | NRYN856       |
| 288 | 2021 | 7     | 28  | 17   | 15     | exit     | 13FNH73       |
| 289 | 2021 | 7     | 28  | 17   | 16     | exit     | V47T75I       |
| 290 | 2021 | 7     | 28  | 17   | 18     | exit     | R3G7486       |
| 291 | 2021 | 7     | 28  | 17   | 36     | exit     | FLFN3W0       |
| 292 | 2021 | 7     | 28  | 17   | 47     | exit     | 4963D92       |
+-----+------+-------+-----+------+--------+----------+---------------+
'

SELECT * FROM atm_transactions WHERE year = 2021 AND month = 7 AND day = 28 AND atm_location = 'Humphrey Lane';

SELECT * FROM phone_calls WHERE year = 2021 AND month = 7 AND day = 28 AND duration < 60;
'+-----+----------------+----------------+------+-------+-----+----------+
| id  |     caller     |    receiver    | year | month | day | duration |
+-----+----------------+----------------+------+-------+-----+----------+
| 221 | (130) 555-0289 | (996) 555-8899 | 2021 | 7     | 28  | 51       |
| 224 | (499) 555-9472 | (892) 555-8872 | 2021 | 7     | 28  | 36       |
| 233 | (367) 555-5533 | (375) 555-8161 | 2021 | 7     | 28  | 45       |
| 251 | (499) 555-9472 | (717) 555-1342 | 2021 | 7     | 28  | 50       |
| 254 | (286) 555-6063 | (676) 555-6554 | 2021 | 7     | 28  | 43       |
| 255 | (770) 555-1861 | (725) 555-3243 | 2021 | 7     | 28  | 49       |
| 261 | (031) 555-6622 | (910) 555-3251 | 2021 | 7     | 28  | 38       |
| 279 | (826) 555-1652 | (066) 555-9701 | 2021 | 7     | 28  | 55       |
| 281 | (338) 555-6650 | (704) 555-2131 | 2021 | 7     | 28  | 54       |
+-----+----------------+----------------+------+-------+-----+----------+'
SELECT * FROM flights WHERE year = 2021 AND month = 7 AND day = 29;
'+----+-------------------+------------------------+------+-------+-----+------+--------+
| id | origin_airport_id | destination_airport_id | year | month | day | hour | minute |
+----+-------------------+------------------------+------+-------+-----+------+--------+
| 18 | 8                 | 6                      | 2021 | 7     | 29  | 16   | 0      |
| 23 | 8                 | 11                     | 2021 | 7     | 29  | 12   | 15     |
| 36 | 8                 | 4                      | 2021 | 7     | 29  | 8    | 20     |
| 43 | 8                 | 1                      | 2021 | 7     | 29  | 9    | 30     |
| 53 | 8                 | 9                      | 2021 | 7     | 29  | 15   | 20     |
+----+-------------------+------------------------+------+-------+-----+------+--------+'

SELECT * FROM people WHERE passport_number = (SELECT passport_number FROM passengers WHERE flight_id = 43) AND phone_number = (SELECT caller FROM phone_calls WHERE year = 2021 AND month = 7 AND day = 28);
SELECT * FROM people WHERE phone_number = (SELECT caller FROM phone_calls WHERE year = 2021 AND month = 7 AND day = 28);