# if you have imdbpy installed, then it's fine, but if you don't then copy the below commented line and paste in terminal.
#!pip install imdbpy

import imdb

moviesDB = imdb.IMDb()

moviename = input('Enter movie name: ')
movies = moviesDB.search_movie(moviename)
id = movies[0].getID()
movie = moviesDB.get_movie(id)

title = movie['title']
year = movie['year']
rating = movie['rating']

print('Movie info:')
print(f'{title} - {year}')
print(f'rating: {rating}')



