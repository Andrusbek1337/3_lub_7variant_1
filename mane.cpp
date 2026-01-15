#include "name.h"
#include "employee.h"
#include "department.h"
#include "time.h"
#include <iostream>
#include <string>
#include <limits>

// Проверка на ввод
int inputInt(const std::string& prompt, int minValue = INT_MIN, int maxValue = INT_MAX) {
    int value;
    bool validInput = false;

    while (!validInput) {
        std::cout << prompt;

        // Проверяем, является ли ввод числом
        if (std::cin >> value) {
            // Проверяем диапазон
            if (value >= minValue && value <= maxValue) {
                validInput = true;
            }
            else {
                std::cout << "Ошибка! Введите число от " << minValue << " до " << maxValue << "." << std::endl;
            }
        }
        else {
            // Очищаем поток при вводе букв или других некорректных данных
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Ошибка! Пожалуйста, введите целое число." << std::endl;
        }

        // Очищаем буфер после успешного ввода
        if (validInput) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }

    return value;
}

// Функция для ввода строки
std::string inputString(const std::string& prompt) {
    std::string value;
    std::cout << prompt;
    std::getline(std::cin, value);
    return value;
}

// ЗАДАНИЕ 1
void demonstrateTask1() {
    std::cout << "\n ЗАДАНИЕ 1: КЛАСС ИМЯ " << std::endl;

    Name name1("Клеопатра");
    Name name2("Пушкин", "Александр", "Сергеевич");
    Name name3("Маяковский", "Владимир");

    name1.print();
    name2.print();
    name3.print();
}

// ЗАДАНИЯ 2-3 (с начальником)
void demonstrateTask2And3() {
    std::cout << "\n ЗАДАНИЯ 2 и 3: СОТРУДНИКИ И ОТДЕЛЫ " << std::endl;

    // Создаем отдел IT
    Department itDepartment("IT");

    // Создаем сотрудников
    Employee petrov("Петров", &itDepartment);
    Employee kozlov("Козлов", &itDepartment);
    Employee sidorov("Сидоров", &itDepartment);

    // Делаем Козлова начальником IT отдела
    itDepartment.setHead(&kozlov);

    std::cout << "\nИнформация об отделе:" << std::endl;
    itDepartment.print();

    std::cout << "\nИнформация о сотрудниках:" << std::endl;
    petrov.print();
    kozlov.print();
    sidorov.print();

    std::cout << "\nСписок всех сотрудников отдела:" << std::endl;
    itDepartment.printEmployees();
}

// ЗАДАНИЕ 4
void demonstrateTask4() {
    std::cout << "\n ЗАДАНИЕ 4: СОЗДАНИЕ ВРЕМЕНИ " << std::endl;

    std::cout << "\n1. Из 10000 секунд:" << std::endl;
    Time time1(10000);
    time1.print();

    std::cout << "\n2. Из 2 часов, 3 минут, 5 секунд:" << std::endl;
    Time time2(2, 3, 5);
    time2.print();
}

// ЗАДАНИЕ 5
void demonstrateTask5() {

    // Задача 1: Сколько часов соответствуют времени 34056
    std::cout << "1. Сколько часов соответствуют времени 34056 секунд:" << std::endl;
    Time t1(34056);
    std::cout << "   Время 34056 секунд = " << t1.toString() << std::endl;
    std::cout << "   Текущий час: " << t1.getCurrentHour() << " час" << std::endl;

    std::cout << "\n---" << std::endl;

    // Задача 2: Сколько минут соответствуют времени 4532
    std::cout << "2. Сколько минут соответствуют времени 4532 секунд:" << std::endl;
    Time t2(4532);
    std::cout << "   Время 4532 секунды = " << t2.toString() << std::endl;
    std::cout << "   Минут с начала часа: " << t2.getMinutesFromHourStart() << " минут" << std::endl;

    std::cout << "\n---" << std::endl;

    // Задача 3: Сколько секунд соответствуют времени 123
    std::cout << "3. Сколько секунд соответствуют времени 123 секунды:" << std::endl;
    Time t3(123);
    std::cout << "   Время 123 секунды = " << t3.toString() << std::endl;
    std::cout << "   Секунд с начала минуты: " << t3.getSecondsFromMinuteStart() << " секунд" << std::endl;

    std::cout << "\n---" << std::endl;

    std::cout << "Текущее системное время:" << std::endl;
    Time current = Time::getCurrentTime();
    std::cout << "   Сейчас: " << current.toString() << std::endl;
    std::cout << "   Текущий час: " << current.getCurrentHour() << std::endl;
    std::cout << "   Минут с начала часа: " << current.getMinutesFromHourStart() << std::endl;
    std::cout << "   Секунд с начала минуты: " << current.getSecondsFromMinuteStart() << std::endl;
}

// Интерактивная демонстрация времени
void interactiveTimeDemo() {

    int choice;
    do {
        std::cout << "\nВыберите действие:" << std::endl;
        std::cout << "1. Создать время из секунд" << std::endl;
        std::cout << "2. Создать время из часов, минут, секунд" << std::endl;
        std::cout << "3. Показать текущее время" << std::endl;
        std::cout << "0. Вернуться в главное меню" << std::endl;

        choice = inputInt("Ваш выбор (0-3): ", 0, 3);

        switch (choice) {
        case 1: {
            int seconds = inputInt("Введите количество секунд (0-86400): ", 0, 86400);
            Time userTime(seconds);
            std::cout << "Созданное время: ";
            userTime.print();
            break;
        }
        case 2: {
            int hours = inputInt("Введите часы (0-23): ", 0, 23);
            int minutes = inputInt("Введите минуты (0-59): ", 0, 59);
            int seconds = inputInt("Введите секунды (0-59): ", 0, 59);
            Time userTime(hours, minutes, seconds);
            std::cout << "Созданное время: ";
            userTime.print();
            break;
        }
        case 3: {
            Time current = Time::getCurrentTime();
            std::cout << "Текущее время: ";
            current.print();
            break;
        }
        case 0:
            std::cout << "Возврат в главное меню..." << std::endl;
            break;
        }
    } while (choice != 0);
}

// ГЛАВНАЯ ФУНКЦИЯ
int main() {
    setlocale(LC_ALL, "Russian");

    int choice;
    do {
        std::cout << "1. Задание 1 - Класс Имя" << std::endl;
        std::cout << "2. Задания 2-3 - Сотрудники и отделы" << std::endl;
        std::cout << "3. Задание 4 - Создание времени" << std::endl;
        std::cout << "4. Задание 5 - Сколько сейчас времени?" << std::endl;
        std::cout << "5. Интерактивная демонстрация времени" << std::endl;
        std::cout << "0. Выход из программы" << std::endl;

        choice = inputInt("\nВыберите задание для демонстрации (0-5): ", 0, 5);

        switch (choice) {
        case 1:
            demonstrateTask1();
            break;
        case 2:
            demonstrateTask2And3();
            break;
        case 3:
            demonstrateTask4();
            break;
        case 4:
            demonstrateTask5();
            break;
        case 5:
            interactiveTimeDemo();
            break;
        case 0:
            std::cout << "\nЗавершение программы..." << std::endl;
            break;
        }

        if (choice != 0) {
            std::cout << "\nНажмите Enter для продолжения...";
            std::cin.get();
        }

    } while (choice != 0);

    return 0;
}
