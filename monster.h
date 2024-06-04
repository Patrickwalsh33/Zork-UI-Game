#ifndef MONSTER_H
#define MONSTER_H

#include "npc.h"

class Monster : public NPC {

public:
    Monster(const QString& description);
    void interact() override;
    QString getDescription() const override;

private:
    QString description;
};

#endif // MONSTER_H
