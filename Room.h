#ifndef ROOM_H
#define ROOM_H

#include <string>

class room
{
public:
	room();
	room(int currentRoomNumber, room* northRoom = NULL, room* eastRoom = NULL, room* southRoom = NULL, room* westRoom = NULL);
	room* getRoomPath(std::string dir);
	void setRoomPath(room* r, std::string dir);
	void setDefaultRoomDescription(std::string d);
	void setModifiedRoomDesciption(std::string d);
	void setCurrentDescription(std::string d);
	std::string getCurrentDescription();
	std::string getModifiedRoomDescription();
	std::string getDefaultRoomDescritption();
		
protected:
	
	int roomNumber;
	std::string currentDescription;
	std::string defaultRoomDescription;
	std::string modifedRoomDescription;
	room *west;
	room *east;
	room *north;
	room *south;
};

#endif