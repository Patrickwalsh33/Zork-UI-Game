#ifndef GAME_H
#define GAME_H

#include <QString>
#include "room.h"
#include "player.h"
#include "invalid_command_exception.h"
#include "inventory.h"

class Game {
public:
    Game();

    QString processCommand(const QString& command);
    QString getCurrentRoomDescription() const;
    QString getCurrentRoomItems() const;

private:
    void createRooms();
    Player player;
    QMap<QString, Room*> rooms;
    bool isDirectionCommand(const QString& command) const;
    Inventory inventory;

};

#endif 
