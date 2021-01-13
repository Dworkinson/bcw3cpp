#include "Pen.h"

Pen::Pen(int inkCapacity) {
    this->inkCapacity = inkCapacity;
    this->inkAmount = inkCapacity;
}

Pen::~Pen() {}

int Pen::getInkAmount() const {
    return this->inkAmount;
}

int Pen::getInkCapacity() const {
    return this->inkCapacity;
}

int symbolsQty(const std::string& message) {
    int symbols = message.size();
    int whiteSpaseCounter = 0;
    for (int i = 0; i < message.size(); i++ ) {
        if ( message[i] == ' ' || message[i] == '\n') {
            whiteSpaseCounter += 1;
        }
    }
    symbols -= whiteSpaseCounter;
    return symbols;
}

int cutIndex(const std::string& message, int inkAmount) {
    int index = 0;
    int counter = 0;
    for ( ; counter < inkAmount; index++ ) {
        if ( message[index] != ' ' && message[index] != '\n') {
            counter += 1;
        }
    }
    return index;
}

void Pen::write(Paper& paper, const std::string& message) {
    if ( this->inkAmount == 0 ) {
        throw OutOfInk();
    }

    int symbols = symbolsQty(message);

    if ( inkAmount >= symbols ) {
        paper.addContent(message);
        this->inkAmount -= symbols;
    } else {

        paper.addContent(message.substr(0, cutIndex(message, this->inkAmount)));
        this->inkAmount = 0;
        throw OutOfInk();
    }
}

void Pen::refill() {
    this->inkAmount = this->inkCapacity;
}
