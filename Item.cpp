#include "Item.h"

item::item(std::string n, std::string d)
{
	name = n;
	description = d;
	inInventory = false;
	canCombine = false;
	hidden = true;
	usable = true;
}

item::item()
{

}

std::string item::getDescription()
{
	return description;
}

std::string item::getName()
{
	return name;
}

void item::setCanCombine(bool b)
{
	canCombine = b;
}
void item::setInInventory(bool b)
{
	inInventory = b;
}

void item::setRoomLocation(room* r)
{
	roomLocation = r;
}

void item::setHidden(bool b)
{
	hidden = b;
}

bool item::getHidden()
{
	return hidden;
}

bool item::getUsable()
{
	return usable;
}

void item::setUsable(bool b)
{
	usable = b;
}

bool item::getCanCombine()
{
	return canCombine;
}

bool item::getInInventory()
{
	return inInventory;
}

room* item::getRoomLocation()
{
	return roomLocation;
}

int item::getTrapPenalty()
{
	return trapPenalty;
}

void item::setTrapPenalty(int x)
{
	trapPenalty = x;
}