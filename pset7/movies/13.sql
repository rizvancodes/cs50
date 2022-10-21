SELECT people.name
  FROM people
  JOIN people ON stars.person_id = people.id
  JOIN stars ON stars.movie_id = movies.id
 WHERE people.name IN ("Johnny Depp", "Helena Bonham Carter")
 GROUP BY movies.title
HAVING count(people.name) = 2;