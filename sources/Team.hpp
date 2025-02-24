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
        list<Character *> team;
        Character *leader;

    public:
        // Constructors and destructors
        Team(Character *leader);
        Team(Team &other);
        virtual ~Team();
        Team(Team &&other);

        // operators
        Team &operator=(const Team &other);
        Team &&operator=(const Team &&other);

        // Functions
        virtual void add(Character *fighter);
        void attack(Team *other);
        void print();
        int stillAlive();

        // Extra functions
        bool isLeaderAlive();
        bool replaceLeader();
        Character *closestToLeader(Team *enemy);
        Character* getLeader() const;
        list<Character *> getTeam() const;
    };

    class Team2 : public Team
    {
    public:
        Team2(Character *leader);
        void add (Character *fighter) override;
    };

    class SmartTeam : public Team
    {
    public:
        SmartTeam(Character *leader);
        void add(Character *fighter) override;
    };
}
#endif