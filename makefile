TITLE = mysteryMansion
CPP = Room.cpp
CPP += Connectorroom.cpp
CPP += Inforoom.cpp
CPP += Puzzleroom.cpp
CPP += Passagewayroom.cpp
CPP += Secretroom.cpp
CPP += Hiddenroom.cpp
CPP += Outsideroom.cpp
CPP += Traveler.cpp
CPP += Map.cpp
CPP += Game.cpp
CPP += Utils.cpp
CPP += main.cpp
DELETE = *.gch
DELETE += *.o

all:
	g++ ${CPP} -o ${TITLE}

clean:
	${RM} ${DELETE} ${TITLE}
