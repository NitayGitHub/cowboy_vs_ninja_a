#ifndef TEAM_H
#define TEAM_H
#include <iostream>
#include <sstream>
#include <list>
#include <stdexcept>
#include "Character.hpp"
#include "Ninja.hpp"
#include "Cowboy.hpp"

using namespace std;

namespace ariel
{
    class Team
    {
    private:
    list <Character*> team;
    Character* leader;

    public:
        // Constructors and destructors
        Team(Character* c);
        ~Team();

        // Functions
        void add(Character* c);
        void attack(Team* other);
        void print() const;
        int stillAlive() const;

    };
}
#endif