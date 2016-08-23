#include "Maze.h"

maze::maze(int currentRoomNumber, room* northRoom, room* eastRoom, room* southRoom, room* westRoom) : room(currentRoomNumber, northRoom, eastRoom, southRoom, westRoom)
{
	defaultRoomDescription = "In this seemingly plain room all the exits look the same, you are not even sure of the one you came in from";
}
