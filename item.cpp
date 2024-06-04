#include "item.h"
#include <QDebug>

Item::Item(const QString& name, const QString& description)
    : description(description) {
    this->name = name;
}

QString Item::getName() const{
    return name;
}

QString Item::getDescription() const{
    return description;
}

Item Item::operator+(const Item& other) const {
    QString combinedDescription = description + " " + other.description;
    return Item("Combined Item", combinedDescription);
}

void Item::interact() {
    qDebug() << "you see a " << name << ": " << description;
}
