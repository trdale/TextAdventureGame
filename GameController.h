#ifndef GAMECONTROLLER_H
#define GAMECONTRLLER_H
#include "Room.h"
#include "Item.h"
#include "Maze.h"
#include <algorithm>
#include <iostream>
#include <string>

const int MAX_TIME = 40;
const int MAX_ROOM_SIZE = 16;
const int MAX_ITEM_SIZE = 16;

class game
{
public:
	game();
	void gameTurn();
	int getCurrentTime();
	int getMaxTime();
	room* changeRoom(std::string dir);
	void adjustCurrentTime(int x);
	void setUpItems();
	void createMap();
	void setDefaultRoomDescritpions();
	void setModifiedRoomDescritpions();
	void setCurrentRoomDescriptions();
	void look();
	void move(std::string n);
	void use(std::string n);
	void pickUp(std::string n);
	void checkInventory();
	void setCurrentRoom(room* r);
	void interactWith(item i);
	void insertKey(item i, item j);
	void makeShovel(item i, item j);
	void playGame();
	void createNewGame();

private:
	
	room rooms[MAX_ROOM_SIZE];
	item items[MAX_ITEM_SIZE];
	int currentTime;
	int keysUsed;
	room* currentRoom;
	bool forceExit;
};

#endif