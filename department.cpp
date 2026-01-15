#include "department.h"
#include "employee.h"
#include <algorithm>

Department::Department(const std::string& name)
    : name_(name), head_(nullptr) {
}

std::string Department::getName() const {
    return name_;
}

void Department::setHead(Employee* head) {
    head_ = head;
}

Employee* Department::getHead() const {
    return head_;
}

void Department::addEmployee(Employee* employee) {
    // Проверяем, нет ли уже этого сотрудника в отделе
    if (std::find(employees_.begin(), employees_.end(), employee) == employees_.end()) {
        employees_.push_back(employee);
    }
}

void Department::print() const {
    std::cout << "Отдел: " << name_;
    if (head_) {
        std::cout << ", начальник: " << head_->getName();
    }
    else {
        std::cout << ", начальник не назначен";
    }
    std::cout << std::endl;
}

void Department::printEmployees() const {
    std::cout << "\nСотрудники отдела " << name_ << ":" << std::endl;
    if (employees_.empty()) {
        std::cout << "  В отделе нет сотрудников" << std::endl;
    }
    else {
        for (size_t i = 0; i < employees_.size(); ++i) {
            std::cout << "  " << (i + 1) << ". " << employees_[i]->getName();
            if (employees_[i] == head_) {
                std::cout << " (начальник)";
            }
            std::cout << std::endl;
        }
    }
}
