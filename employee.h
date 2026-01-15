#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include <iostream>

class Department; // Предварительное объявление

class Employee {
public:
    Employee(const std::string& name, Department* department = nullptr);

    std::string getName() const;
    Department* getDepartment() const;
    bool isHead() const;
    void print() const;

private:
    std::string name_;
    Department* department_;
};

#endif
