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
    protected:
        list<Character *> team;
        Character *leader;

    public:
        // Constructors and destructors
        Team(Character *leader);
        ~Team();

        // Functions
        virtual void add(Character *fighter);
        void attack(Team *other);
        void print();
        int stillAlive();

        // Extra functions
        bool isLeaderAlive();
        bool replaceLeader();
        Character *closestToLeader(Team enemy);
    };

    class Team2 : public Team
    {
    public:
        Team2(Character *leader);
        void add(Character *fighter);
    };

    class SmartTeam : public Team
    {
    public:
        SmartTeam(Character *leader);
        void add(Character *fighter);
    };
}
#endif