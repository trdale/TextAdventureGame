#ifndef MAZE_H
#define MAZE_H

#include "Room.h"
#include <string>

//when creating a maze type room, a master room is specified that be default every door will take you back to instead of nothing

class maze : public room
{
public:
	maze(int currentRoomNumber, room* northRoom, room* eastRoom, room* southRoom, room* westRoom);
};

#endif