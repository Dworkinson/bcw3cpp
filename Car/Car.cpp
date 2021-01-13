#include "Car.h"

Car::Car(double capacity, double consumption, const Point& location, const std::string& model) {
    this->fuelAmount = 0;
    this->fuelCapacity = capacity;
    this->fuelConsumption = consumption;
    this->location = location;
    this->model = model;
}

Car::~Car() {}

double Car::getFuelAmount() const {
    return this->fuelAmount;
}

double Car::getFuelCapacity() const {
    return this->fuelCapacity;
}

double Car::getFuelConsumption() const {
    return this->fuelConsumption;
}

const Point& Car::getLocation() const {
    return this->location;
}

const std::string& Car::getModel() const {
    return this->model;
}


void Car::drive(const Point& destination) {
    double distance = destination.distance(this->location);
    double fuelNeeded = distance * this->fuelConsumption;

    if ( this->fuelAmount < fuelNeeded ) {
        throw OutOfFuel();
    } else {
        this->fuelAmount -= fuelNeeded;
        this->location = destination;
    }

}

void Car::drive(double x, double y) {
    Point destination(x, y);
    this->drive(destination);
}

void Car::refill(double fuel) {
    double freeCapacity = this->fuelCapacity - this->fuelAmount;

    if ( fuel > freeCapacity ) {
        this->fuelAmount = fuelCapacity;
        throw ToMuchFuel();
    } else {
        this->fuelAmount += fuel;
    }
}


std::ostream& operator<<(std::ostream& out, const Car& car) {
    out << "Model:  <" << car.getModel() << ">" << std::endl;
    out << "\tFuel capacity: " << car.getFuelCapacity() << std::endl;
    out << "\tFuel amount: " << car.getFuelAmount() << std::endl;
    out << "\tFuel consumption: " << car.getFuelConsumption() << std::endl;
    out << "<" << car.getModel() << ">" << " is located in: " << car.getLocation() << std::endl;
    return out;
}
