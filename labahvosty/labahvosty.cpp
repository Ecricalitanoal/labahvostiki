#include <iostream>
#include <ctime>
#include "Header.h"
int main()
{
    srand(time(0));
    setlocale(0, "");
    int n;
    std::cout << "Введите число студентов: ";
    std::cin >> n;
    std::cout << "\nСписок конца 1-ого года\n";
    student* students = new student[n];
    filling(students, n);
    filling_exams(students, n);
    sort(students, n);
    give_status(students, n);
    print(students, n);
    std::cout << "\nСписок конца 2-ого года\n";
    next_main(students, n);
    std::cout << "\nСписок конца 3-ого года\n";
    next_main(students, n);
}
