# Cub3D
School 42 provide us with it's MacOS MiniLibX window management library that allows to open windows and draw in it.
With it we had to make our own graphical engine based on RayCasting technology. Kinda like id Software's 1992 first person Shooter Wolfenstein 3D.
Program takes a level map file as a first argument.
A map consists of special charachters, whitch are interpteted as a level elements when the program launched.
Those are
'1' a wall;
'0' free space (that you can walk through);
'2' sprite;
'W'/'E'/'N' or 'S' as a player starting position and lokking direction (West, East, North or South respectibly)
A big part of a job was to make a perfect map file parser. The rules are:
◦ The map must be closed/surrounded by walls, if not the program must returnan error.
◦ Except for the map content, each type of element can be separated by one ormore empty line(s).
◦ Except for the map content which always has to be the last, each type ofelement can be set in any order in the file.
◦ Except for the map, each type of information from an element can be separatedby one or more space(s).
◦ The map must be parsed as it looks in the file. Spaces are a valid part of themap and are up to you to handle. You must be able to parse any kind of map,as long as it respects the rules of the map
Usage:
This is Makefile project
Clone it, cd into and and enter
"$ make"
then launch by entering
"$ ./cub3D <map>.cub", replacing <map>.cub with a map file (repository includes two: wolf.cub and bobville.cub)
Maps consists of config lines starts with a key upeercase letter and map itself after those.
Configs are:
R resolution
WE western wall texture;
EA eastern wall texture;
NO north wall texture;
SO south wall texture;
S sprite texture;
C ceiling color;
F floor color;
