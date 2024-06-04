#pragma once

#include <QString>

class GameObject {
public:
    virtual ~GameObject() = default; 
    virtual void interact() = 0; 
    virtual QString getDescription() const = 0; 

protected:
    QString name;

};



