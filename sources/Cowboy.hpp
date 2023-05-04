#ifndef COWBOY_H
#define COWBOY_H
#include <iostream>
#include <sstream>
#include <stdexcept>
#include "Character.hpp"
using namespace std;

namespace ariel
{
    class Cowboy : public Character
    {
    private:
        int bullets;

    public:
        // Constructors
        Cowboy(string name, Point location);

        // Functions
        void shoot(Character &other);
        bool hasBullets() const;
        void reload();

        // Getters and Setters
        int getBullets() const;
    };
}

#endif