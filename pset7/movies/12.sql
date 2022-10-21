SELECT movies.title
  FROM movies
  JOIN stars ON stars.movie_id = movies.id
  JOIN people ON stars.person_id = people.id
 WHERE people.name IN ("Johnny Depp", "Helena Bonham Carter")
 GROUP BY movies.title
HAVING count(people.name) = 2;

SELECT movies.title
  FROM movies
  JOIN stars ON stars.movie_id = movies.id
  JOIN people ON stars.person_id = people.id
 WHERE people.name IN ("Johnny Depp", "Helena Bonham Carter")
 GROUP BY movies.title
HAVING count(people.name) = 2;