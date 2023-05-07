#include "Team.hpp"
#include <iostream>
#include <stdexcept>
#include <cmath>
using namespace std;
namespace ariel
{
    // Constructors
    Team::Team(Character *leader) : leader(leader)
    {
        team.push_back(leader);
    }

    Team2::Team2(Character *leader) : Team(leader) {}

    // Destructors
    Team::~Team()
    {
        for (list<Character *>::iterator it = team.begin(); it != team.end(); it++)
        {
            delete *it;
        }
    }

    SmartTeam::SmartTeam(Character *leader) : Team(leader) {}

    // Functions
    void Team::add(Character *fighter)
    {
        if (team.size() == 10)
        {
            throw string("Team is full");
        }
        if (fighter->getType() == COWBOY)
        {
            team.push_back(fighter);
        }
        else if (fighter->getType() == NINJA)
        {
            team.push_front(fighter);
        }
    }

    void Team2::add(Character *fighter)
    {
        if (team.size() == 10)
        {
            throw string("Team is full");
        }
        team.push_back(fighter);
    }

    bool Team::isLeaderAlive()
    {
        return leader->isAlive();
    }

    void SmartTeam::add(Character *fighter)
    {
        if (team.size() == 10)
        {
            throw string("Team is full");
        }
        if (fighter->getType() == COWBOY)
        {
            team.push_front(fighter);
        }
        else if (fighter->getType() == NINJA)
        {
            team.push_back(fighter);
        }
    }

    bool Team::replaceLeader()
    {
        int minDistance = -1;
        int newLeaderIndex = -1;
        for (list<Character *>::iterator it = team.begin(); it != team.end(); it++)
        {
            if (!((*it)->isAlive()))
            {
                continue;
            }
            if (minDistance == -1)
            {
                minDistance = leader->distance(*it);
                newLeaderIndex = distance(team.begin(), it);
                continue;
            }
            if (leader->distance(*it) < minDistance)
            {
                minDistance = leader->distance(*it);
                newLeaderIndex = distance(team.begin(), it);
            }
        }
        if (newLeaderIndex == -1)
        {
            return false;
        }
        list<Character *>::iterator it = team.begin();
        advance(it, newLeaderIndex);
        leader = *it;
        return true;
    }

    void Team::print()
    {
        for (list<Character *>::iterator it = team.begin(); it != team.end(); it++)
        {
            cout << (*it)->print() << endl;
        }
    }

    int Team::stillAlive()
    {
        int counter = 0;
        for (list<Character *>::iterator it = team.begin(); it != team.end(); it++)
        {
            if ((*it)->isAlive())
            {
                counter++;
            }
        }
        return counter;
    }

    Character *Team::closestToLeader(Team enemy)
    {
        int minDistance = -1;
        Character *closest = nullptr;
        for (list<Character *>::iterator it = enemy.team.begin(); it != enemy.team.end(); it++)
        {
            if (!((*it)->isAlive()))
            {
                continue;
            }
            if (minDistance == -1)
            {
                minDistance = leader->distance(*it);
                closest = *it;
                continue;
            }
            if (leader->distance(*it) < minDistance)
            {
                minDistance = leader->distance(*it);
                closest = *it;
            }
        }
        return closest;
    }

    void Team::attack(Team *other)
    {
        if (!isLeaderAlive())
        {
            if (!replaceLeader())
            {
                cout << "The team has lost" << endl;
                return;
            }
        }
        if (!stillAlive())
        {
            throw string("Can't attack when your team is dead");
        }
        if (!other->stillAlive())
        {
            throw string("Can't attack a dead team");
        }

        Character *closest = closestToLeader(*other);
        for (list<Character *>::iterator it = team.begin(); it != team.end(); it++)
        {
            if (!((*it)->isAlive()))
            {
                continue;
            }
            if (!closest->isAlive() && !other->stillAlive())
            {
                return;
            }
            else if (!closest->isAlive())
            {
                closest = closestToLeader(*other);
            }
            (*it)->attack(closest);
        }
    }

}