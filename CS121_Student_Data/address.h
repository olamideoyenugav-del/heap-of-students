#ifndef ADDRESS_H
#define ADDRESS_H
#include <string>
class Address {
private:
    std::string street, city, state, zip;
public:
    Address();
    void init(const std::string& street, const std::string& city, const std::string& state, const std::string& zip);
    void printAddress() const;
};
#endif
