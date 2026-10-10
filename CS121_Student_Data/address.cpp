#include "address.h"
#include <iostream>
Address::Address() : street(""), city(""), state(""), zip("") {}
void Address::init(const std::string& s, const std::string& c, const std::string& st, const std::string& z) {
    street = s; city = c; state = st; zip = z;
}
void Address::printAddress() const {
    std::cout << street << '\n' << city << ' ' << state << ", " << zip << '\n';
}
