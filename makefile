CXX = g++
CXXFLAGS = -std=c++0x
LDFLAGS = 

OBJS =  

SRCS = Game.cpp Room.cpp Maze.cpp Item.cpp FinalProject.cpp

HEADERS = GameController.h Room.h Maze.h Item.h

final: ${SRCS} ${HEADERS}
	${CXX} ${CXXFLAGS} ${SRCS} -o final










