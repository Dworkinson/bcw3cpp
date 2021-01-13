#include "Date.h"


void Date::validate(int day, int month, int year) {
    if ( month < 1 || month > 12 ) {
        throw InvalidDate("Invalid month.");
    }

    if ( day < 1 || day > 31 ) {
        throw InvalidDate("Invalid day.");
    }
    if ( month == 4 || month == 6 || month == 9 || month == 11 ) {
        if ( day > 30 ) {
            throw InvalidDate("Invalid day.");
        }
    }
    if ( month == 2 ) {
        if ( day > 29 ) {
            throw InvalidDate("Invalid day.");
        }
        if ( year % 4 != 0 ) {
            if ( day > 28 ) {
                throw InvalidDate("Invalid day.");
            }
        }
    }
}

Date::Date(int day, int month, int year) {
    this->day = day;
    this->month = month;
    this->year = year;
    validate(day, month, year);
}

Date::~Date() {}

int Date::getDay() const {
    return this->day;
}

int Date::getMonth() const {
    return this->month;
}

int Date::getYear() const {
    return this->year;
}


std::ostream& operator<<(std::ostream& out, const Date& date) {
    if (date.getDay() < 10 ) {
        out << "0";
    }
    out << date.getDay() << ".";
    if (date.getMonth() < 10 ) {
        out << "0";
    }
    out << date.getMonth() << "." << date.getYear() <<std::endl;
    return out;
}
