#include "Room.h"

room::room()
{

}

room::room(int currentRoomNumber, room* northRoom, room* eastRoom, room* southRoom, room* westRoom)
{
	roomNumber = currentRoomNumber;
	north = northRoom;
	east = eastRoom;
	south = southRoom;
	west = westRoom;
}

void room::setRoomPath(room* r, std::string dir)
{
	if (dir == "north")
	{
		north = r;
	}
	else if (dir == "south")
	{
		south = r;
	}
	else if (dir == "east")
	{
		east = r;
	}
	else
	{
		west = r;
	}
}

room* room::getRoomPath(std::string dir)
{
	if (dir == "north")
	{
		return north;
	}
	else if (dir == "south")
	{
		return south;
	}
	else if (dir == "east")
	{
		return east;
	}
	else if (dir == "west")
	{
		return west;
	}
	else
	{
		return NULL;
	}
}

void room::setDefaultRoomDescription(std::string d)
{
	defaultRoomDescription = d;
}

void room::setModifiedRoomDesciption(std::string d)
{
	modifedRoomDescription = d;
}

void room::setCurrentDescription(std::string d)
{
	currentDescription = d;
}

std::string room::getCurrentDescription()
{
	return currentDescription;
}

std::string room::getDefaultRoomDescritption()
{
	return defaultRoomDescription;
}

std::string room::getModifiedRoomDescription()
{
	return modifedRoomDescription;
}