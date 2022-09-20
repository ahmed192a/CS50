--Kevin Bacon   1958
SELECT DISTINCT name FROM people
JOIN stars ON people.id = stars.person_id
WHERE name != "Kevin Bacon" AND  person_id IN (
SELECT person_id FROM stars
WHERE movie_id IN (
SELECT movie_id FROM stars
WHERE person_id = (
SELECT id FROM people
WHERE name = "Kevin Bacon" AND birth = "1958")));