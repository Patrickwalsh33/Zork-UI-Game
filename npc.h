#ifndef NPC_H
#define NPC_H

#include <QString>
#include "gameobject.h"

class NPC : public GameObject {
public:
    virtual ~NPC() = 0; 
    virtual QString getDescription() const override = 0; 
};


inline NPC::~NPC() {}

#endif 
