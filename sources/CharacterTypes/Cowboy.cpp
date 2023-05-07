#include "Cowboy.hpp"
#include <stdexcept>
#include <cmath>
using namespace std;
namespace ariel
{
    // Constructors
    Cowboy::Cowboy(string name, Point location) : Character(name, location, 110, COWBOY), bullets(6) {}

    Cowboy::~Cowboy() {}

    // Functions
    void Cowboy::shoot(Character *other)
    {
        if (hasBullets())
        {
            cout << "No bullets; reload first" << endl;
            return;
        }
        if (!isAlive())
        {
            throw string("Can't attack when you're dead");
        }
        other->hit(10);
        this->bullets--;
    }

    bool Cowboy::hasBullets() const
    {
        return bullets > 0;
    }

    void Cowboy::reload()
    {
        if (!isAlive())
        {
            throw string("Character is dead");
        }
        this->bullets = 6;
    }

    string Cowboy::print() const
    {
        if (HP <= 0)
        {
            return "Name: ((C)" + name + ")";
        }
        return "Name: (C) " + name + "\nHealth Points: " + to_string(HP) + "\nLocation: " + location.toString();
    }

    // Getters and Setters
    int Cowboy::getBullets() const
    {
        return bullets;
    }

    void Cowboy::attack(Character *other)
    {
        if (!isAlive())
        {
            cout << "Can't attack when you're dead" << endl;
            return;
        }
        if(!other->isAlive()){
            return;
        }
        if (hasBullets()){
            reload();
        }
        shoot(other);
    }
}