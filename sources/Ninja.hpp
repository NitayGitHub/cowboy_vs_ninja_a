#ifndef NINJA_H
#define NINJA_H
#include <iostream>
#include <sstream>
#include <stdexcept>
#include "Character.hpp"
using namespace std;

namespace ariel
{
    // Ninja class
    class Ninja : public Character
    {
    protected:
        int speed;

    public:
        // Constructors
        Ninja(string name, Point location, int speed, int HP);
        ~Ninja();

        // Functions
        virtual void move(Character* other);
        virtual void slash(Character* other);

        // Extra functions
        void attack(Character* other);
        int getSpeed() const;
        string print() const;
    };

    // Ninja Types
    class YoungNinja : public Ninja
    {
    public:
        YoungNinja(string name, Point location);
    };

    class TrainedNinja : public Ninja
    {
    public:
        TrainedNinja(string name, Point location);
    };

    class OldNinja : public Ninja
    {
    public:
        OldNinja(string name, Point location);
    };
}

#endif