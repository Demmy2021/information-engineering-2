#include <iostream>
#include <Time.hpp>


Time::Time(int duration){

        hours = duration/3600;
        duration = duration - (hours*3600);
        minutes = duration/60;
        duration = duration-(minutes*60);
        seconds = duration;
}

std::ostream &operator<<(std::ostream &str, Time &other)
{
    if(other.hours!=0)   str << other.hours << "h:";
    if(other.minutes!=0) str << other.minutes << "m:";
    if(other.seconds!=0) str << other.seconds << "s";
    return str;
}

std::istream &operator>>(std::istream &str, Time &other)
{
    std:: cout << "Enter number of hours:";
    str >> other.hours;
    std:: cout << "Enter number of minutes:";
    str >> other.minutes;
    std:: cout << "Enter number of seconds:";
    str >> other.seconds;

    return str;
}

Time Time::operator+(const Time &rhs) const {
 return Time(((hours+rhs.hours)*3600)+((minutes+rhs.minutes)*60) + seconds+rhs.seconds);
}

Time Time::operator-(const Time &rhs) const {
 return Time(((hours-rhs.hours)*3600)+((minutes-rhs.minutes)*60) + seconds-rhs.seconds);
}

Time Time::operator*(const int &scalar) const {
    return Time((((hours*3600))*scalar+(minutes*60)+seconds) );
}

Time::operator int(){
    return int((hours*3600)+(minutes*60)+seconds);
}

