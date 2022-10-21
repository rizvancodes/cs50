SELECT DISTINCT name
FROM people
WHERE id IN
(SELECT movie_id
   FROM stars
   WHERE person_id IN
   (SELECT id
      FROM people
     WHERE name = "Kevin Bacon" AND birth = 1958));
AND id NOT IN (SELECT id FROM people WHERE name = "Kevin Bacon" AND birth = 1958);