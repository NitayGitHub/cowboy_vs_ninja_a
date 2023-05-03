#ifndef CHARACTER_H
#define CHARACTER_H
#include <iostream>
#include <sstream>
#include <stdexcept>
#include "Point.hpp"
using namespace std;

namespace ariel
{
    class Character
    {
    private:
        string name;
        Point location;
        int HP; // Health Points
    
    public:
        Character(string name, Point location, int HP);
        bool isAlive() const;

        // Getters and Setters
        string getName() const;
        Point getLocation() const;
        int getHP() const;
        void setName(string name);
        void setLocation(Point location);
        void setHP(int HP);
    };

}
#endif