#include "Paper.h"

Paper::Paper(int maxSymbols) {
    if ( maxSymbols < 1 ) {
        this->maxSymbols = 4096;
    } else {
        this->maxSymbols = maxSymbols;
    }
    this->symbols = 0;
}

Paper::~Paper() {}


int Paper::getMaxSymbols() const {
    return this->maxSymbols;
}

int Paper::getSymbols() const {
    return this->symbols;
}


void Paper::addContent(const std::string& message) {
    if (this->symbols == this->maxSymbols) {
        throw OutOfSpace(); 
    }
    
    int freeSpace = this->maxSymbols - this->symbols;

    if ( message.size() > freeSpace ) {
        this->content += message.substr(0, freeSpace);
        throw OutOfSpace();
    } else {
        this->content += message;
        this->symbols += message.size();
    }
}

void Paper::show() const {
    std::cout << this->content << std::endl;
}
