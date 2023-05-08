#include "Ninja.hpp"
#include <stdexcept>
#include <cmath>
using namespace std;
namespace ariel
{
    // Constructors
    Ninja::Ninja(string name, Point location, int speed, int HP) : Character(name, location, HP, NINJA), speed(speed) {}

    Ninja::~Ninja() {}

    YoungNinja::YoungNinja(string name, Point location) : Ninja(name, location, 14, 100) {}

    TrainedNinja::TrainedNinja(string name, Point location) : Ninja(name, location, 12, 120) {}

    OldNinja::OldNinja(string name, Point location) : Ninja(name, location, 8, 150) {}

    // Functions
    void Ninja::move(Character* other)
    {
        if (!isAlive())
        {
            throw runtime_error("Can't move when you're dead");
        }
        location = Point::moveTowards(location, other->getLocation(), speed);
    }

    void Ninja::slash(Character* other)
    {
        if (!isAlive())
        {
            throw runtime_error("Can't attack when you're dead");
        }
        if (!other->isAlive())
        {
            throw runtime_error("Target Character is dead");
        }
        if (location.distance(other->getLocation()) > 1)
        {
            cout << "Target " << other->getName() << " is too far away from " << name << endl;
            return;
        }
        other->hit(31);
    }

    int Ninja::getSpeed() const
    {
        return speed;
    }

    string Ninja::print() const
    {
        if (HP <= 0)
        {
            return "Name: ((N)" + name + ")";
        }
        return "Name: (N) " + name + "\nHealth Points: " + to_string(HP) + "\nLocation: " + location.toString();
    }

    void Ninja::attack(Character* other){
        if (!isAlive())
        {
            cout << "Can't attack when you're dead" << endl;
            return;
        }
        if (!other->isAlive())
        {
            cout << "Target Character is dead" << endl;
            return;
        }
        if (location.distance(other->getLocation()) > 1)
        {
            move(other);
            return;
        }
        slash(other);
    }

}