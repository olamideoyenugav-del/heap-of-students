#include "student.h"
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <vector>

Student::Student() : firstName(""), lastName(""), address(), birthDate(), gradDate(), creditHours(0) {}

void Student::init(const std::string& csvLine) {
    std::istringstream stream(csvLine);
    std::vector<std::string> fields;
    std::string field;
    while (std::getline(stream, field, ',')) fields.push_back(field);
    if (fields.size() != 9) throw std::invalid_argument("Student record must have exactly 9 fields");
    std::size_t consumed = 0;
    int credits;
    try {
        credits = std::stoi(fields[8], &consumed);
    } catch (const std::exception&) {
        throw std::invalid_argument("Invalid credit hours");
    }
    if (consumed != fields[8].size() || credits < 0) throw std::invalid_argument("Invalid credit hours");
    Address newAddress;
    newAddress.init(fields[2], fields[3], fields[4], fields[5]);
    Date newBirth, newGrad;
    newBirth.init(fields[6]);
    newGrad.init(fields[7]);
    firstName = fields[0];
    lastName = fields[1];
    address = newAddress;
    birthDate = newBirth;
    gradDate = newGrad;
    creditHours = credits;
}

void Student::printStudent() const {
    std::cout << firstName << ' ' << lastName << '\n';
    address.printAddress();
    std::cout << "DOB: ";
    birthDate.printDate();
    std::cout << "Grad: ";
    gradDate.printDate();
    std::cout << "Credits: " << creditHours << '\n';
    std::cout << "________________________________________" << '\n';
}

std::string Student::getLastFirst() const {
    return lastName + ", " + firstName;
}
