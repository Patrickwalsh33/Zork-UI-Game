// entity.h
#ifndef ENTITY_H
#define ENTITY_H

#include <string>

class Entity {
public:
    // Constructor
    Entity(const std::string& name) : name(name) {}

    // Get entity name
    std::string getName() const {
        return name;
    }

private:
    std::string name;
};

#endif // ENTITY_H
