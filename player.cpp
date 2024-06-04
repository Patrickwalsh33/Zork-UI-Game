#include "player.h"
#include "room.h"

Player::Player() : currentRoom(nullptr) {}

void Player::setCurrentRoom(Room* room) {
    currentRoom = room;
}

Room* Player::getCurrentRoom() const{
    return currentRoom;
}
