#ifndef STUDENT_H
#define STUDENT_H
#include <string>
#include "address.h"
#include "date.h"
class Student {
private:
    std::string firstName, lastName;
    Address address;
    Date birthDate, gradDate;
    int creditHours;
public:
    Student();
    void init(const std::string& csvLine);
    void printStudent() const;
    std::string getLastFirst() const;
};
#endif
