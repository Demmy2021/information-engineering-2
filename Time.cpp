#include <iostream>
#include <Time.hpp>


Time::Time(int total_t){

        hours = total_t/3600;
        total_t = total_t - (hours*3600);
        minutes = total_t/60;
        total_t = total_t-(minutes*60);
        seconds = total_t;

}

std::ostream &operator<<(std::ostream &str, Time &other)
{
    if(other.hours!=0)
        str << other.hours << "h:";
    if(other.minutes!=0)
        str << other.minutes << "m:";
    if(other.seconds!=0)
        str << other.seconds << "s";
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
    return Time( ((seconds+(minutes*60)+(hours*3600))*scalar) );
}

Time::operator int(){
    return int(seconds+(minutes*60)+(hours*3600));
}

