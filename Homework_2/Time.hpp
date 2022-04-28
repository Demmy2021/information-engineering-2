#pragma once
#include <iostream>

class Time{
public:
    Time(int duration = 0);

    Time operator+(const Time &other) const;
    Time operator-(const Time &other) const;
    Time operator*(const int &scalar) const;
    operator int();
    friend std::ostream &operator<<(std::ostream &str, Time &rhs);
    friend std::istream &operator>>(std::istream &str, Time &rhs);
    //void print() const;
private:
    int hours;
    int minutes;
    int seconds;

};
