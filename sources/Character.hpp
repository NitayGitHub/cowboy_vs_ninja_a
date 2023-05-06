#ifndef CHARACTER_H
#define CHARACTER_H
#include <iostream>
#include <sstream>
#include <stdexcept>
#include "Point.hpp"
using namespace std;

namespace ariel
{
    enum characterType
    {
        COWBOY = 0,
        NINJA = 1
    };

    class Character
    {
    protected:
        characterType type;
        string name;
        Point location;
        int HP; // Health Points

    public:
        // Constructors
        Character(string name, Point location, int HP, characterType type);

        // Functions
        virtual bool isAlive() const;
        virtual void hit(int damage);
        virtual double distance(const Character* other) const;
        virtual string print() const;

        // Getters and Setters
        string getName() const;
        characterType getType() const;
        Point getLocation() const;
        int getHP() const;
        void setName(string name);
        void setLocation(Point location);
        void setHP(int HP);
    };

}
#endif