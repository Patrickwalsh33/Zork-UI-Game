#ifndef PLAYER_H
#define PLAYER_H

#include <QString>
#include "room.h"

class Player {
public:
    Player();

    void setCurrentRoom(Room* room);
    Room* getCurrentRoom() const;


private:
    Room* currentRoom;
};

#endif // PLAYER_H
