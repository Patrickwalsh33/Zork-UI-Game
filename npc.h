#ifndef NPC_H
#define NPC_H

#include <QString>
#include "gameobject.h"

class NPC : public GameObject {
public:
    virtual ~NPC() = 0; // Pure virtual destructor
    virtual QString getDescription() const override = 0; // Pure virtual function
};

// Define the destructor outside the class definition
inline NPC::~NPC() {}

#endif // NPC_H
