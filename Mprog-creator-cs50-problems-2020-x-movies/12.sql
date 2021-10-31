SELECT movies.title from people JOIN stars ON people.id=stars.person_id JOIN movies on stars.movie_id=movies.id WHERE people.name="Johnny Depp" AND movies.title IN(SELECT movies.title from people JOIN stars ON people.id=stars.person_id JOIN movies ON stars.movie_id = movies.id WHERE people.name="Helena Bonham Carter");

