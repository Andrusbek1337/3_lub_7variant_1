#include "name.h"

Name::Name() : hasLastName_(false), hasFirstName_(false), hasMiddleName_(false) {}

Name::Name(const std::string& last) {
    hasLastName_ = !last.empty();
    hasFirstName_ = false;
    hasMiddleName_ = false;
    if (hasLastName_) lastName_ = last;
}

Name::Name(const std::string& last, const std::string& first) {
    hasLastName_ = !last.empty();
    hasFirstName_ = !first.empty();
    hasMiddleName_ = false;
    if (hasLastName_) lastName_ = last;
    if (hasFirstName_) firstName_ = first;
}

Name::Name(const std::string& last, const std::string& first, const std::string& middle) {
    hasLastName_ = !last.empty();
    hasFirstName_ = !first.empty();
    hasMiddleName_ = !middle.empty();

    if (hasLastName_) lastName_ = last;
    if (hasFirstName_) firstName_ = first;
    if (hasMiddleName_) middleName_ = middle;
}

std::string Name::toString() const {
    std::string result;

    if (hasLastName_) result += lastName_;
    if (hasFirstName_) {
        if (!result.empty()) result += " ";
        result += firstName_;
    }
    if (hasMiddleName_) {
        if (!result.empty()) result += " ";
        result += middleName_;
    }

    return result;
}

void Name::print() const {
    std::cout << "Имя: " << toString() << std::endl;
}
