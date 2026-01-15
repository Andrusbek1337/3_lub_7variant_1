#ifndef TIME_H
#define TIME_H

#include <string>
#include <iostream>

class Time {
public:
    Time();
    Time(int seconds);
    Time(int hours, int minutes, int seconds);
    
    int getCurrentHour() const;
    int getMinutesFromHourStart() const;
    int getSecondsFromMinuteStart() const;
    
    static int getFullHours(int seconds);
    static int getFullMinutes(int seconds);
    static int getFullSeconds(int seconds);
    static Time getCurrentTime();
    
    std::string toString() const;
    void print() const;
    void printBrief() const;

private:
    int totalSeconds_;
    void init_(int seconds);
};

#endif
