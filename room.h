#ifndef ROOM_H
#define ROOM_H

#include <QString>
#include <QMap>
#include <Qlist>
#include "gameobject.h"

class Room {
public:
    Room(const QString& description);

    QString getDescription() const;
    void setExits(Room* north, Room* east, Room* south, Room* west);
    Room* getExit(const QString& direction) const;

    void addObject(GameObject* object);
    QString listObjects() const;

    friend class Player;

private:
    QString description;
    QMap<QString, Room*> exits;
    QList<GameObject*> objects;
};

#endif
