#include "time.h"
#include <algorithm>
#include <iomanip>
#include <sstream>
#include <ctime>

void Time::init_(int seconds) {
    if (seconds < 0) {
        totalSeconds_ = 0;
    }
    else {
        totalSeconds_ = seconds % (24 * 3600);
    }
}

Time::Time() {
    init_(0);
}

Time::Time(int seconds) {
    init_(seconds);
}

Time::Time(int hours, int minutes, int seconds) {
    hours = std::max(0, hours);
    minutes = std::max(0, std::min(minutes, 59));
    seconds = std::max(0, std::min(seconds, 59));

    init_(hours * 3600 + minutes * 60 + seconds);
}

int Time::getCurrentHour() const {
    return totalSeconds_ / 3600;
}

int Time::getMinutesFromHourStart() const {
    return (totalSeconds_ % 3600) / 60;
}

int Time::getSecondsFromMinuteStart() const {
    return totalSeconds_ % 60;
}

int Time::getFullHours(int seconds) {
    if (seconds < 0) return 0;
    return (seconds % (24 * 3600)) / 3600;
}

int Time::getFullMinutes(int seconds) {
    if (seconds < 0) return 0;
    return ((seconds % (24 * 3600)) % 3600) / 60;
}

int Time::getFullSeconds(int seconds) {
    if (seconds < 0) return 0;
    return ((seconds % (24 * 3600)) % 3600) % 60;
}

Time Time::getCurrentTime() {
    time_t now = time(0);

#ifdef _WIN32
    struct tm localTimeInfo;
    localtime_s(&localTimeInfo, &now);
    return Time(localTimeInfo.tm_hour, localTimeInfo.tm_min, localTimeInfo.tm_sec);
#else
    struct tm* localTimeInfo = localtime(&now);
    return Time(localTimeInfo->tm_hour, localTimeInfo->tm_min, localTimeInfo->tm_sec);
#endif
}

std::string Time::toString() const {
    std::ostringstream oss;
    oss << std::setw(2) << std::setfill('0') << getCurrentHour() << ":"
        << std::setw(2) << std::setfill('0') << getMinutesFromHourStart() << ":"
        << std::setw(2) << std::setfill('0') << getSecondsFromMinuteStart();
    return oss.str();
}

void Time::print() const {
    std::cout << "Время: " << toString() << std::endl;
}

void Time::printBrief() const {
    std::cout << toString();
}
