
#ifndef ENTITY_H
#define ENTITY_H

#include <string>

class Entity {
public:
 
    Entity(const std::string& name) : name(name) {}

 
    std::string getName() const {
        return name;
    }

private:
    std::string name;
};

#endif
