# Cub3D
42 provide us with it's MacOS MiniLibX window management library that allows to open windows and draw in it.
With it we had to make our own graphical engine based on RayCasting technology. Kinda like id Software's 1992 first person Shooter Wolfenstein 3D.
Usage:
This is Makefile project
Clone it, cd into and and enter
"$ make"
then launch by entering
"$ ./cub3D <map>.cub", replacing <map>.cub with a map file (repository includes two: wolf.cub and bobville.cub)
Maps consists of config lines starts with a key upeercase letter and map itself after those.
Configs are:
R resolution
WE western wall
EA eastern wall
NO north wall
SO south wall
S sprite
C ceiling color
F floor color
