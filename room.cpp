#include "room.h"

Room::Room(const QString& description) : description(description) {}

QString Room::getDescription() const {
    return description;
}

void Room::setExits(Room* north, Room* east, Room* south, Room* west) {
    if (north) exits["north"] = north;
    if (east) exits["east"] = east;
    if (south) exits["south"] = south;
    if (west) exits["west"] = west;
}

Room* Room::getExit(const QString& direction) const {
    return exits.value(direction, nullptr);
}

void Room::addObject(GameObject* object){
    objects.append(object);
}

QString Room::listObjects() const{
    QString objectDescriptions;
    for(GameObject* object : objects) {
        objectDescriptions += object->getDescription() + "\n";

    }
    return objectDescriptions;
}

