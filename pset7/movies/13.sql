SELECT movie_id FROM stars WHERE person_id IN (SELECT name FROM people WHERE name = "Kevin Bacon" AND birth = 1958);