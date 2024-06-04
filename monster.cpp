#include "monster.h"
#include <QDebug>

Monster::Monster(const QString& description)
    : description(description) {}

void Monster::interact() {
    qDebug() << "you see a " << description;
}

QString Monster::getDescription() const{
    return description;
}
