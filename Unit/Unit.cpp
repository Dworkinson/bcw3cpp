#include "Unit.h"

void Unit::ensureIsAlive() {
    if ( hitPoints == 0 ) {
        throw UnitIsDead();
    }
}

Unit::Unit(const std::string& name, int hp, int dmg) {
    this->name = name;
    this->hitPointsLimit = hp;
    this->damage = dmg;
    this->hitPoints = hitPointsLimit;
}

Unit::~Unit() {}

int Unit::getDamage() const {
    return this->damage;
}

int Unit::getHitPoints() const {
    return this->hitPoints;
}

int Unit::getHitPointsLimit() const {
    return this->hitPointsLimit;
}

const std::string& Unit::getName() const {
    return this->name;
}


void Unit::addHitPoints(int hp) {
    ensureIsAlive();
    this->hitPoints += hp;
    if ( this->hitPoints > hitPointsLimit ) {
        this->hitPoints = hitPointsLimit;
    }
    std::cout << this->name << ": HP is restored (" << this->hitPoints << "/" << this->hitPointsLimit << ")" << std::endl;
}

void Unit::takeDamage(int dmg) {
    ensureIsAlive();
    if ( dmg >= this->hitPoints ) {
        this->hitPoints = 0;
        std::cout << this->name << " is dead\n" << std::endl;
    } else {
        this->hitPoints -= dmg;
        std::cout << this->name << ": -" << dmg << " HP\n" << std::endl;
    }
}


void Unit::attack(Unit& enemy) {
    std::cout << this->name << " attacked " << enemy.name << std::endl;
    enemy.takeDamage(this->damage);
    if ( enemy.hitPoints > 0 ) {
        this->counterAttack(enemy);
    }
}

void Unit::counterAttack(Unit& enemy) {
    std::cout << enemy.name << " counter attacked" << std::endl;
    this->takeDamage(enemy.damage / 2);
}


std::ostream& operator<<(std::ostream& out, const Unit& unit) {
    out << "Name: " << unit.getName() << std::endl;
    out << "\tHP: " << unit.getHitPoints() << "/" << unit.getHitPointsLimit() << std::endl;
    out << "\tDamage: " << unit.getDamage() << std::endl;
    return out;
}
