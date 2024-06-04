#include "game.h"
#include "item.h"
#include "monster.h"
#include "invalid_command_exception.h"

Game::Game() {
    createRooms();
    inventory = Inventory();
}

void Game::createRooms() {
   
    Room* room1 = new Room("You slowly open your eyes. You are in a forest clearing. You have no weapons, food or water. Use the buttons below to navigate and escape the wilderness. To the east lies a sheer mountain face");
    Room* room2 = new Room("You are at the edge of a dark cave. You can hear a loud rustling from further in but you cannot see anything.");
    Room* room3 = new Room("You are in a small hut at the edge of the forest. To the ");

    room1->setExits(nullptr, room2, nullptr, nullptr);
    room2->setExits(room3, nullptr, nullptr, room1);
    room3->setExits(nullptr, nullptr, room2, nullptr);

    
    Item* axe = new Item("Axe", "A sharp-looking axe.");
    Item* wings = new Item("Wings", "A fallen angels wings.");
    Item* key = new Item("Key", "A gigantic golden key.");

   
    Monster* ratman = new Monster("A man sized rat");

    
    room1->addObject(axe);
    room2->addObject(wings);
    room2->addObject(ratman);
    room3->addObject(key);


    rooms["forest"] = room1;
    rooms["cave"] = room2;
    rooms["hut"]= room3;

    player.setCurrentRoom(room1);
}

QString Game::processCommand(const QString& command){
    Room* currentRoom = player.getCurrentRoom();
    Room* nextRoom = currentRoom->getExit(command.toLower());

    if(nextRoom){
        player.setCurrentRoom(nextRoom);
        return "You move " + command + ".\n" + nextRoom->getDescription();
    } else {
        
        if (command == "use") {
            return "You cannot use anything here."; 
        } else if (command == "take") {
            return "There is nothing to take."; 
        } else if (command == "investigate") {
            return "You investigate the room and find:\n" + getCurrentRoomItems(); 
        } else if (isDirectionCommand(command)) {
            return "There is no exit in that direction."; 
        } else {
            throw InvalidCommandException("Invalid command: " + command); 
        }
    }
}

bool Game::isDirectionCommand(const QString& command) const {
    
    return (command == "north" || command == "east" || command == "south" || command == "west");
}

QString Game::getCurrentRoomDescription() const {
    Room* currentRoom = player.getCurrentRoom();
    return currentRoom->getDescription();
}

QString Game::getCurrentRoomItems() const{
    Room* currentRoom = player.getCurrentRoom();
    return currentRoom->listObjects();
}
