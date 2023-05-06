#include "Character.hpp"
#include <stdexcept>
#include <cmath>
using namespace std;
namespace ariel
{
    // Constructors

    Character:: Character(string name, Point location, int HP, characterType type) : name(name), location(location), HP(HP), type(type) {}

    // Functions

    bool Character::isAlive() const
    {
        return HP > 0;
    }

    double Character::distance(const Character &other) const
    {
        return location.distance(other.location);
    }

    void Character::hit(int damage)
    {
        if (!isAlive())
        {
            throw string("Character is dead");
        }
        HP -= damage;
    }

    void Character::print() const
    {
        string typeStr = (type == COWBOY ? "C" : "N");
        if(HP < 0){
            cout << "Name:" << "(" << "(" << typeStr << ") " << name << ")" << endl;
            return;
        }
        cout << "Name: " << "(" << typeStr << ") " << name << endl;
        cout << "Health Points: " << HP << endl;
        location.print();   
    }

    // Getters and Setters

    string Character::getName() const
    {
        return name;
    }

    characterType Character::getType() const
    {
        return type;
    }

    Point Character::getLocation() const
    {
        return location;
    }

    int Character::getHP() const
    {
        return HP;
    }

    void Character::setName(string name)
    {
        this->name = name;
    }

    void Character::setLocation(Point location)
    {
        this->location = location;
    }

    void Character::setHP(int HP)
    {
        this->HP = HP;
    }

}