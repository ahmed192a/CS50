SELECT DISTINCT name FROM
people JOIN stars ON people.id = stars.person_id JOIN
movies ON stars.movie_id = movies.id
Where year = 2004 ORDER BY birth;

