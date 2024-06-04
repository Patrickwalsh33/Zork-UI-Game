#include "inventory.h"

Inventory::Inventory() {}

void Inventory::addItem(const QString& item) {
    items.append(item);
}

void Inventory::removeItem(const QString& item) {
    items.removeOne(item);
}

QStringList Inventory::getItems() const {
    return items;
}
