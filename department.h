#ifndef DEPARTMENT_H
#define DEPARTMENT_H

#include <string>
#include <iostream>
#include <vector>

class Employee; // Предварительное объявление

class Department {
public:
    Department(const std::string& name);

    std::string getName() const;
    void setHead(Employee* head);
    Employee* getHead() const;
    void addEmployee(Employee* employee);
    void print() const;
    void printEmployees() const;

private:
    std::string name_;
    Employee* head_;
    std::vector<Employee*> employees_;
};

#endif
