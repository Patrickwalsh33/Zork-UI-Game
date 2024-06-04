#pragma once

#include <QString>

class GameObject {
public:
    virtual ~GameObject() = default; //virtual constructor
    virtual void interact() = 0; //pure virtual function
    virtual QString getDescription() const = 0; //pure virtual function

protected:
    QString name;

};



