#include "List.h"


List::List(int capacity, double multiplier) : capacity(capacity), current(0), multiplier(multiplier) {
        array = (int*)malloc(capacity*sizeof(int));

        if ( array == NULL ) {
            throw OutOfMemoryException();
       }
}

List::~List() {
    free(array);
}

int List::size() const {
    return this->current;
}

int List::max_size() const {
    return this->capacity;
}

void List::erase(int index) {//
    if ( index >= 0 && index < this->current ) {
        this->current -= 1;
        for ( int i = index, j = index + 1; i < this->current; i++, j++ ) {
            this->array[i] = this->array[j];
        }
    } else {
        std::cout << "There is no index: " << index << ". Nothing to erase." << std::endl;
    }
}

void List::insert(int value, int index) {
    if ( index >= 0 && index < this->current ) {
        this->push_back(this->array[this->current-1]);

        for ( int i = this->current - 2, j = i - 1; i > index; i--, j-- ) {
            this->array[i] = this->array[j];
        }
        this->array[index] = value;

    } else {
        this->push_back(value);
        std::cout << "There is no index: " << index << ". Value is added to the end of list." << std::endl;
    }
}

int List::find(int value) const {
    for ( int i = 0; i < this->current; i++ ) {
        if ( this->array[i] == value ) {
            return i;
        } else {
            return -1;
        }
    }
}

void List::push_back(int value) {
    int newCurrent = this->current + 1;

    if ( newCurrent > this->capacity ) {
        int newCapacity = this->capacity * this->multiplier;
        int* newArray = (int*)realloc(this->array, newCapacity*sizeof(int));

        if ( newArray == NULL ) {
            throw OutOfMemoryException();
        }

        this->capacity = newCapacity;
        this->array = newArray;
    }
    this->array[this->current] = value;
    this->current = newCurrent;
}

int List::pop_back() {
    if ( this->current == 0 ) {
        throw ZeroLenException();
    }
    this->current -= 1;
    return this->array[this->current];
}

int compare(const void * x1, const void * x2) {
        return ( *(int*)x1 - *(int*)x2 );
    }

void List::sort() {
    qsort(this->array, this->current, sizeof(int), compare);
}

int List::operator[](int index) const {
    return this->array[index];
}

bool List::operator==(const List& other) const {
    for ( int i = 0; i < this->current; i++ ) {
        if ( this->array[i] != other.array[i] ) {
            return false;
        }
        return true;
    }
}

bool List::operator!=(const List& other) const {
    return !(*this == other);
}


std::ostream& operator<<(std::ostream& out, const List& list) {
    int last = list.size() - 1;

    for ( int i = 0; i < last; i++ ) {
        out << list[i] << ' ';
    }
    out << list[last];
    return out;
}
