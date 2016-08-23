#include "GameController.h"

game::game() 
{
	createNewGame();
	keysUsed = 0;
	currentTime = 0;
	forceExit = false;
}

void game::gameTurn()
{
	std::string action;
	std::string choice;
	std::cout << "Please Enter what you wish to do" << std::endl;
	std::cout << "1: Look   2: Move   3: Pick Up   4: Use   5: Check Inventory   6: Exit Game" << std::endl;
	std::getline(std::cin, action);
	if (action == "1")
	{
		look();
	}
	else if (action == "2")
	{
		std::cout << "What direction do you wish to move (north, east, south, west)" << std::endl;
		std::getline(std::cin, choice);
		std::transform(choice.begin(), choice.end(), choice.begin(), tolower);
		move(choice);
	}
	else if (action == "3")
	{
		std::cout << "What item do you wish to pick up" << std::endl;
		std::getline(std::cin, choice);
		std::transform(choice.begin(), choice.end(), choice.begin(), tolower);
		pickUp(choice);
	}
	else if (action == "4")
	{
		std::cout << "What do you want to use, please enter name of item" << std::endl;
		std::getline(std::cin, choice);
		std::transform(choice.begin(), choice.end(), choice.begin(), tolower);
		use(choice);
	}
	else if (action == "5")
	{
		checkInventory();
	}
	else if (action == "6")
	{
		std::cout << "Are you sure you wish to exit? yes/no" << std::endl;
		std::getline(std::cin, choice);
		std::transform(choice.begin(), choice.end(), choice.begin(), tolower);
		if (choice == "yes")
		{
			forceExit = true;
			return;
		}
		else
		{
			std::cout << "Game not exiting" << std::endl;
		}
		
	}
	else
	{
		std::cout << "That is not a valid choice" << std::endl;

	}
}



void game::setUpItems()
{
	items[0] = item("metal piece", "A triangular piece of metal, it has a slot on one side, with a hole that runs through the slot perpendicular");
	items[0].setCanCombine(true);
	items[0].setHidden(false);
	items[0].setRoomLocation(&rooms[3]);
	
	items[1] = item("pole", "A wooden pole that was once a shaft for a halbred.  Now its just a plain wooden pull except for the hole running perpendicular at one end where the haldbred blade was secured");
	items[1].setCanCombine(true);
	items[1].setHidden(false);
	items[1].setRoomLocation(&rooms[6]);
	
	items[2] = item("wooden peg", "A small wooden peg, was being used as a chess piece");
	items[2].setCanCombine(true);
	items[2].setHidden(false);
	items[2].setRoomLocation(&rooms[8]);
	
	items[3] = item("ruby key", "An ornate ruby key");
	items[3].setHidden(false);
	items[3].setRoomLocation(&rooms[2]);
	items[3].setTrapPenalty(5);
	
	items[4] = item("green key", "A green key");
	items[4].setHidden(false);
	items[4].setRoomLocation(&rooms[15]);
	items[5].setRoomLocation(&rooms[4]);
	
	items[5] = item("red key", "A red key");
	items[5].setHidden(false);
		
	items[6] = item("blue key", "A blue key");
	items[6].setRoomLocation(&rooms[9]);
	items[5].setHidden(false);
		
	items[7] = item("shovel prototype", "The metal head fits perfectly onto the wooden pole, it looks like a shovel!");
	items[7].setCanCombine(true);
	
	items[8] = item("shovel", "The metal head is secrured to the pole with the wooden peg, you think this would be a functional shovel");
	
	items[9] = item("pole with peg", "The pole now has a wooden peg in the end of it");
	items[9].setCanCombine(true);
	
	items[10] = item("metal piece with peg", "The metal piece has a peg inside the hole, looks like it could either hold something in, or keep something out");
	items[10].setCanCombine(true);
	
	items[11] = item("triangular prism", "On the top face have numbers caved 1, 3, 6, 10, __, 21, 28, 36, 45, 55.  One number appears to be missing.  You find a set of buttons for the numbers 0-9");
	items[11].setRoomLocation(&rooms[9]);
		
	items[12] = item("dirt", "A pile of dirt with an X marked in the top");
	items[12].setRoomLocation(&rooms[4]);
	items[12].setCanCombine(true);
	
	items[13] = item("lever", "A lever that looks like it would still work");
	items[13].setRoomLocation(&rooms[5]);
	items[13].setTrapPenalty(5);
	
	items[14] = item("red button", "A Red button with a sign that reads 'Do Not Press'");
	items[14].setRoomLocation(&rooms[7]);
	items[14].setTrapPenalty(5);
	
	items[15] = item("gate", "Gate with 3 key holes all of a different color: red, blue, green");
	items[15].setRoomLocation(&rooms[1]);
	items[15].setCanCombine(true);
			
}

void game::createMap()
{
	//creates the blank rooms with their directionals N E S W
	rooms[0] = room(0, NULL, NULL, NULL, NULL);
	rooms[1] = room(1, NULL, &rooms[0], &rooms[2], NULL);
	rooms[2] = room(2, &rooms[1], &rooms[3], &rooms[4], NULL);
	rooms[3] = room(3, NULL, NULL, &rooms[5], &rooms[2]);
	rooms[4] = room(4, &rooms[2], &rooms[5], NULL, NULL);
	rooms[5] = room(5, &rooms[3], &rooms[10], &rooms[6], &rooms[4]);
	rooms[6] = room(6, &rooms[5], NULL, &rooms[7], NULL);
	rooms[7] = room(7, &rooms[6], NULL, &rooms[9], &rooms[8]);
	rooms[8] = room(8, NULL, &rooms[7], NULL, NULL);
	rooms[9] = room(9, &rooms[7], NULL, NULL, NULL);
	rooms[10] = room(10, &rooms[11], &rooms[10], &rooms[10], &rooms[5]);
	rooms[11] = maze(11, &rooms[10], &rooms[12], &rooms[10], &rooms[10]);
	rooms[12] = maze(12, &rooms[10], &rooms[10], &rooms[10], &rooms[13]);
	rooms[13] = maze(13, &rooms[10], &rooms[10], &rooms[10], &rooms[14]);
	rooms[14] = maze(14, &rooms[10], &rooms[10], &rooms[15], &rooms[10]);
	rooms[15] = room(15, &rooms[10], &rooms[10], &rooms[10], &rooms[10]);
}

void game::setDefaultRoomDescritpions()
{
	rooms[0].setDefaultRoomDescription("You have found your way out of the labyrinth, freeeeeeeeeeeeedommmmm");
	rooms[1].setDefaultRoomDescription("As you look about the room you see a large locked gate to the East, as well as a passage to the south. Through the gate to the east you see freedom of the outside world. The gate has 3 keyholes, as you are looking at the gate a outer door appears to be slowly shutting, once that door shuts you will be trapped for good!");
	rooms[2].setDefaultRoomDescription("In the center of the room is an ornate pedistal with the letters 'ekat ton od' written on it.  Resting atop the pedistal is a large ruby key.  There are passageways to both the east and the south.");
	rooms[3].setDefaultRoomDescription("This room has rubble strewn about, with a large pile in the NE corner.  Inside the rubble you see a metal piece.  You see a passage to the west and the south");
	rooms[4].setDefaultRoomDescription("In the center of the room there is a section of dirt with a large X etched into the ground. You see a passage to the north and the east");
	rooms[5].setDefaultRoomDescription("You see what was once 3 levers in the room, 2 are broken and only one appears to remain functional. You see a passage in all 4 directions");
	rooms[6].setDefaultRoomDescription("This room contains a 2 rows of statues standing guards on either side of the room. The statues depict warriors holding shields and halbreds.  One statue arm has fallen off and lies on the floor in pieces, the pole of its haldberd broken laying on the floor.  You see a passage to the north and the south");
	rooms[7].setDefaultRoomDescription("The room is bare except for a large red button on the wall with a sign reading 'Do Not Push'. You see a passage to the north, south, and west.");
	rooms[8].setDefaultRoomDescription("The room contains a large chessboard, the pieces look to be in set as if they are in the middle of a game. It looks like the queen for the white side is missing, and has been replaced by a small wooden peg.  The only exit is where you came from, the east");
	rooms[9].setDefaultRoomDescription("The walls and floor of this room are carved with images of triangles.  In the center a triangle prism sticks out of the floor, on closer inspection the top face have numbers caved 1, 3, 6, 10, __, 21, 28, 36, 45, 55.  One number appears to be missing.  You find a set of buttons for the numbers 0-9. The only exit is where you came from the north.");
	rooms[10].setDefaultRoomDescription("An obelisk rises out of the floor with a message carved on its surface 'Never Enter the Warren Without a Strategy'. There is a passage in all directions");
	rooms[15].setDefaultRoomDescription("You find a green key just sitting on the floor in the center of the room. There is a passage in all directions.");
}

void game::setModifiedRoomDescritpions()
{
	rooms[2].setModifiedRoomDesciption("In the center of the room is an ornate pedistal with the letters 'ekat ton od' written on it.  There are passageways to both the east and the south.");
	rooms[3].setModifiedRoomDesciption("This room has rubble strewn about, with a large pile in the NE corner.  You see a passage to the west and the south");
	rooms[4].setModifiedRoomDesciption("In the center of the room there is a hole where you dug out a key from the ground. You see a passage to the north and the east");
	rooms[5].setModifiedRoomDesciption("You see a hole in the middle of the room from when you pulled the lever");
	rooms[6].setModifiedRoomDesciption("This room contains a 2 rows of statues standing guards on either side of the room. The statues depict warriors holding shields and halbreds.  You see a passage to the north and the south");
	rooms[7].setModifiedRoomDesciption("The room has a hole in the middle, from when you decided pressing the button was a good idea. You see a passage to the north, south, and west.");
	rooms[8].setModifiedRoomDesciption("The room contains a large chessboard, the pieces look to be in set as if they are in the middle of a game.  The only exit is where you came from, the east");
	rooms[9].setModifiedRoomDesciption("The walls and floor of this room are carved with images of triangles.  In the center a triangle prism sticks out of the floor with an open empty compartment. The only exit is where you came from the north.");
	rooms[15].setModifiedRoomDesciption("In this seemingly plain room all the exits look the same, you are not even sure of the one you came in from");
}

void game::createNewGame()
{
	createMap();
	setModifiedRoomDescritpions();
	setDefaultRoomDescritpions();
	setCurrentRoomDescriptions();
	setUpItems();	
	currentRoom = &rooms[1];
}

void game::look()
{
	std::cout << currentRoom->getCurrentDescription() << std::endl;
}
void game::move(std::string n)
{
	if (currentRoom->getRoomPath(n) == NULL)
	{
		std::cout << "Not a valid direction, please try again" << std::endl;
	}
	else
	{
		currentRoom = currentRoom->getRoomPath(n);
		std::cout << currentRoom->getCurrentDescription() << std::endl;
		currentTime++;
	}	
}
void game::use(std::string n)
{
	for (int i = 0; i < MAX_ITEM_SIZE; i++)
	{
		if (n == items[i].getName() && items[1].getUsable() == true)
		{
			//is inventory combining with other object 
			if (items[i].getInInventory() == true)
			{
				std::string object;
				std::cout << "What would you like to use that with" << std::endl;
				std::getline(std::cin, object);
				//combining with object 
				for (int j = 0; j < MAX_ITEM_SIZE; j++)
				{
					//inside inventory (shovel)
					if (object == items[j].getName() && items[j].getInInventory() == true)
					{
						makeShovel(items[i], items[j]);
						return;
					}
					//interaction with item in room
					if (items[j].getName() == object && items[j].getRoomLocation() == currentRoom && items[j].getCanCombine() == true && items[j].getInInventory() != true)
					{
						insertKey(items[i], items[j]);
						return;
					}
				}
			}
			//standard use
			if (items[i].getRoomLocation() == currentRoom)
			{
				interactWith(items[i]);
				return;
			}
		}
	}
	std::cout << "You cannot use that" << std::endl;
}
void game::pickUp(std::string n)
{
	for (int i = 0; i < MAX_ITEM_SIZE; i++)
	{
		if (n == items[i].getName() && items[i].getInInventory() == false && items[i].getHidden() == false && items[i].getRoomLocation() == currentRoom)
		{
			items[i].setInInventory(true);
			currentRoom->setCurrentDescription(currentRoom->getModifiedRoomDescription());
			std::cout << "You pick up the " << items[i].getName() << std::endl;
			if (items[i].getName() == "ruby key")
			{
				std::cout << "As you pick up the gear you hear the door in the other room speed up for a few seconds, giving you less time to find a way out" << std::endl;
				adjustCurrentTime(items[i].getTrapPenalty());
			}
			return;
		}
	}
	std::cout << "You cannot pick that up" << std::endl;
}
void game::checkInventory()
{
	std::cout << "Current Inventory: ";
	for (int i = 0; i < MAX_ITEM_SIZE; i++)
	{
		if (items[i].getInInventory() == true)
		{
			std::cout << items[i].getName() << " ";
		}
	}
	std::cout << std::endl;
}

void game::setCurrentRoom(room* r)
{
	currentRoom = r;
}

void game::makeShovel(item i, item j)
{
	if (i.getName() == "metal piece" || j.getName() == "metal piece")
	{
		if (i.getName() == "wooden peg" || j.getName() == "wooden peg")
		{
			items[0].setInInventory(false);
			items[2].setInInventory(false);
			items[10].setInInventory(true);
			std::cout << items[10].getDescription() << std::endl;
		}
		else if (i.getName() == "pole" || j.getName() == "pole")
		{
			items[0].setInInventory(false);
			items[1].setInInventory(false);
			items[7].setInInventory(true);
			std::cout << items[7].getDescription() << std::endl;
		}
		else
		{
			items[0].setInInventory(false);
			items[9].setInInventory(false);
			items[8].setInInventory(true);
			std::cout << items[8].getDescription() << std::endl;
		}
	}

	else if (i.getName() == "pole" || j.getName() == "pole")
	{
		if (i.getName() == "wooden peg" || j.getName() == "wooden peg")
		{
			items[1].setInInventory(false);
			items[2].setInInventory(false);
			items[9].setInInventory(true);
			std::cout << items[9].getDescription() << std::endl;
		}
		else
		{
			items[1].setInInventory(false);
			items[10].setInInventory(false);
			items[8].setInInventory(true);
			std::cout << items[8].getDescription() << std::endl;
		}
	}

	else if (i.getName() == "wooden peg" || j.getName() == "wooden peg")
	{
		items[7].setInInventory(false);
		items[2].setInInventory(false); 
		items[8].setInInventory(true);
		std::cout << items[8].getDescription() << std::endl;
	}

	else
	{
		std::cout << "You cant combine those 2 items" << std::endl;
	}
}

void game::insertKey(item i, item j)
{
	if (j.getName() == "gate")
	{
	
		if (i.getName() == "red key")
		{
			std::cout << "The Red Key";
			items[5].setInInventory(false);
		}
		else if (i.getName() == "blue key")
		{
			std::cout << "The Blue Key";
			items[6].setInInventory(false);
		}
		else if (i.getName() == "green key")
		{
			std::cout << "The Green Key";
			items[4].setInInventory(false);
		}
		std::cout << " fits into the gate" << std::endl;
		keysUsed++;
		if (keysUsed == 3)
		{
			std::cout << "The Gate Opens with a loud creak" << std::endl;
		}
	}
	else if (j.getName() == "dirt")
	{
		if (i.getName() == "shovel prototype")
		{
			std::cout << "The shovel head falls off when you try to dig. You put it back together but it needs something to hold the head on the pole" << std::endl;
		}
		else if (i.getName() == "shovel")
		{
			std::cout << "You use the shovel to dig through the dirt, at the bottom you find a red key, you pick it up and put it in your inventory" << std::endl;
			items[5].setInInventory(true);
			items[8].setInInventory(false);
		}
		else
		{
			std::cout << "You cannot dig with that item" << std::endl;
		}
	}
	else
	{
		std::cout << "You cannot do that" << std::endl;
	}
}

void game::interactWith(item i)
{
	if (i.getName() == "red button")
	{
		items[14].setUsable(false);
		std::cout << "You press the button and a trap door opens underneath you, it will take some of your precious time to climb out of the whole" << std::endl;
		adjustCurrentTime(i.getTrapPenalty());
		currentRoom->setCurrentDescription(currentRoom->getModifiedRoomDescription());
	}
	else if (i.getName() == "lever")
	{
		items[13].setUsable(false);
		std::cout << "As you pull the lever, the room shakes and rumbles, the lever doesnt seem to be working correctly.  Rubble crumbles off the walls and blocks some of the passageways, it takes some of your precious time to clear out the paths again" << std::endl;
		adjustCurrentTime(i.getTrapPenalty());
		currentRoom->setCurrentDescription(currentRoom->getModifiedRoomDescription());
	}
	else if (i.getName() == "triangular prism")
	{
		std::string choice;
		std::cout << "Which button do you press? (0-9)" << std::endl;
		std::getline(std::cin, choice);
		if (choice != "1")
		{
			std::cout << "When you press the button a red light flashes in the middle, it looks like the puzzle has reset" << std::endl;
		}
		else
		{
			std::cout << "As you press 1 a in the blank section on the prism, it seems like it wants you to press another number. Please pick a second number" << std::endl;
			std::getline(std::cin, choice);
			if (choice != "5")
			{
				std::cout << "When you press the button a red light flashes in the middle, it looks like the puzzle has reset" << std::endl;
			}
			else
			{
				items[11].setUsable(false);
				std::cout << "The number 15 flashes green in the middle, then a compartment slides open holding a blue key, you pick it up and put it in your inventory" << std::endl;
				items[6].setInInventory(true);
				currentRoom->setCurrentDescription(currentRoom->getModifiedRoomDescription());
			}
		}
	}
}

void game::adjustCurrentTime(int x)
{
	currentTime += x;
}

void game::playGame()
{
	do
	{
		gameTurn();

		std::cout << "Timer until death " << currentTime << "/" << MAX_TIME << std::endl;

	} while (currentRoom != &rooms[0] && currentTime <= MAX_TIME && forceExit == false);

	if (currentTime >= MAX_TIME)
	{
		std::cout << "You NOOB!!! You ran out of time and died a horribly slow painful death" << std::endl;
	}
	else if (forceExit == true)
	{
		std::cout << "Game ended early due to user choice" << std::endl;
	}
	else
	{
		std::cout << "YOU WIN!" << std::endl;
	}
	
}

void game::setCurrentRoomDescriptions()
{
	for (int i = 0; i < MAX_ROOM_SIZE; i++)
	{
		rooms[i].setCurrentDescription(rooms[i].getDefaultRoomDescritption());
	}
}