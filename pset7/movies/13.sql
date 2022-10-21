SELECT DISTINCT people.name
FROM people
JOIN stars ON people.id = stars.person_id
WHERE stars.movies_id IN (SELECT movie_id FROM stars WHERE person_id IN(SELECT id FROM people WHERE name = "Kevin Bacon" AND birth = 1958));