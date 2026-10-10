#include "date.h"
#include <iostream>
#include <sstream>
#include <stdexcept>
Date::Date() : month(1), day(1), year(1900) {}
void Date::init(const std::string& dateText) {
    std::istringstream input(dateText);
    int m, d, y;
    char slash1, slash2;
    if (!(input >> m >> slash1 >> d >> slash2 >> y) || slash1 != '/' || slash2 != '/' || (input >> std::ws && !input.eof())) {
        throw std::invalid_argument("Date must be mm/dd/yyyy");
    }
    if (m < 1 || m > 12 || y < 1) throw std::invalid_argument("Invalid month or year");
    const int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    bool leap = (y % 4 == 0 && (y % 100 != 0 || y % 400 == 0));
    int maxDay = days[m - 1] + (m == 2 && leap ? 1 : 0);
    if (d < 1 || d > maxDay) throw std::invalid_argument("Invalid day");
    month = m; day = d; year = y;
}
void Date::printDate() const {
    const char* names[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    std::cout << names[month - 1] << ' ' << day << ", " << year << '\n';
}
