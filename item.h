#ifndef ITEM_H
#define ITEM_H

#include <QString>
#include "gameobject.h"
#include "movable.h"

class Item : public GameObject, public Movable{

public:
    Item(const QString& name, const QString& description);

    QString getName() const;
    QString getDescription() const override;
    void interact() override;
    Item operator+(const Item& other) const;

private:
    QString name;
    QString description;

};

#endif // ITEM_H
