#include "Cowboy.hpp"
#include <stdexcept>
#include <cmath>
using namespace std;
namespace ariel
{
    // Constructors
    Cowboy::Cowboy(string name, Point location) : Character(name, location, 110, COWBOY), bullets(6) {}

    // Functions
    void Cowboy::shoot(Character &other)
    {
        if (hasBullets())
        {
            cout << "No bullets; reload first" << endl;
            return;
        }
        if (!isAlive())
        {
            throw string("Character is dead");
        }
        other.hit(10);
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

    // Getters and Setters
    int Cowboy::getBullets() const
    {
        return bullets;
    }

}