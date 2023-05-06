#include "Ninja.hpp"
#include <stdexcept>
#include <cmath>
using namespace std;
namespace ariel
{
    // Constructors
    Ninja::Ninja(string name, Point location, int speed, int HP) : Character(name, location, HP, NINJA), speed(speed) {}

    YoungNinja::YoungNinja(string name, Point location) : Ninja(name, location, 100, 14) {}

    TrainedNinja::TrainedNinja(string name, Point location) : Ninja(name, location, 120, 12) {}

    OldNinja::OldNinja(string name, Point location) : Ninja(name, location, 150, 8) {}

    // Functions
    void Ninja::move(Character* other)
    {
        if (!isAlive())
        {
            throw string("Character is dead");
        }
        if (!other->isAlive())
        {
            throw string("Target Character is dead");
        }
        location = Point::moveTowards(location, other->getLocation(), speed);
    }

    void Ninja::slash(Character* other)
    {
        if (!isAlive())
        {
            throw string("Character is dead");
        }
        if (!other->isAlive())
        {
            throw string("Target Character is dead");
        }
        if (location.distance(other->getLocation()) > 1)
        {
            cout << "Target is too far away" << endl;
            return;
        }
        other->hit(31);
    }

    int Ninja::getSpeed() const
    {
        return speed;
    }

}