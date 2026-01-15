#ifndef NAME_H
#define NAME_H

#include <string>
#include <iostream>

class Name {
public:
    Name();
    Name(const std::string& last);
    Name(const std::string& last, const std::string& first);
    Name(const std::string& last, const std::string& first, const std::string& middle);

    std::string toString() const;
    void print() const;

private:
    std::string lastName_;
    std::string firstName_;
    std::string middleName_;

    bool hasLastName_;
    bool hasFirstName_;
    bool hasMiddleName_;
};
