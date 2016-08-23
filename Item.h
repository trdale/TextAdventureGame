#ifndef ITEM_H
#define ITEM_H

#include <string>
#include "Room.h"

class item
{
public:
	item();
	item(std::string n, std::string d);
	std::string getName();
	std::string getDescription();
	void setCanCombine(bool b);
	void setInInventory(bool b);
	void setRoomLocation(room* r);
	void setHidden(bool b);
	bool getHidden();
	bool getUsable();
	bool getCanCombine();
	bool getInInventory();
	void setUsable(bool b);
	room* getRoomLocation();
	int getTrapPenalty();
	void setTrapPenalty(int x);

private:
	std::string name;
	std::string description;
	bool canCombine;
	bool inInventory;
	bool hidden;
	room* roomLocation;
	bool usable;
	int trapPenalty;
};


#endif