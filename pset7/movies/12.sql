SELECT title FROM
movies JOIN stars ON movies.id = stars.movie_id JOIN
people ON stars.person_id = people.id
Where name = "Johnny Depp" AND movies.title IN (
SELECT title FROM
movies JOIN stars ON movies.id = stars.movie_id JOIN
people ON stars.person_id = people.id
Where name = "Helena Bonham Carter");

