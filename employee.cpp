#include "employee.h"
#include "department.h"

Employee::Employee(const std::string& name, Department* department)
    : name_(name), department_(department) {
    if (department_) {
        department_->addEmployee(this);
    }
}

std::string Employee::getName() const {
    return name_;
}

Department* Employee::getDepartment() const {
    return department_;
}

bool Employee::isHead() const {
    return department_ && department_->getHead() == this;
}

void Employee::print() const {
    std::cout << "Сотрудник: " << name_;
    if (department_) {
        std::cout << ", отдел: " << department_->getName();
        if (isHead()) {
            std::cout << " (начальник отдела)";
        }
        else if (department_->getHead()) {
            std::cout << ", начальник: " << department_->getHead()->getName();
        }
        else {
            std::cout << ", начальник не назначен";
        }
    }
    else {
        std::cout << " (не работает в отделе)";
    }
    std::cout << std::endl;
}
