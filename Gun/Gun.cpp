#include "Gun.h"

Gun::Gun(const std::string& model, int capacity) {
    this->amount = 0;
    this->capacity = capacity;
    this->isReady = false;
    this->model = model;
    this->totalShots = 0;
}

Gun::~Gun() {};

int Gun::getAmount() const {
    return this->amount;
}

int Gun::getCapacity() const {
    return this->capacity;
}

bool Gun::ready() const {
    return this->isReady;
}

const std::string& Gun::getModel() const {
    return this->model;
}

int Gun::getTotalShots() const {
    return this->totalShots;
}


void Gun::prepare() {
    isReady = !isReady;
}

void Gun::reload() {
    amount = capacity;
}

void Gun::shoot() {
    if ( !ready() ) {
        throw NotReady();
    }
    if ( amount == 0 ) {
        throw OutOfRounds ();
    }
    std::cout << this->model << ": Bang!" << std::endl;
    this->amount -= 1;
    this->totalShots +=1;
}


std::ostream& operator<<(std::ostream& out, const Gun& gun) {
    out << "====================" << std::endl;
    out << "Model:  <" << gun.getModel() << ">" << std::endl;
    out << "\tCapacity: " << gun.getCapacity() << std::endl;
    out << "\tAmount: " << gun.getAmount() << "/" << gun.getCapacity() << "\n" <<std::endl;
    out << "Total shots: " << gun.getTotalShots() << std::endl;
    if ( gun.ready() ) {
        out << "Ready to shooting." << std::endl;
    } else {
        out << "Not ready to shooting." << std::endl;
    }
    out << "====================" << std::endl;
    
    return out;
}
