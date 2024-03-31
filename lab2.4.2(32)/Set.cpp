#include "Set.h"
#include <sstream>

void Set::add(char c) {
    if (count < size) {
        elements[static_cast<unsigned char>(c)] = true;
        ++count;
    }
    else {
        std::cout << "Error: Set is full" << std::endl;
    }
}

void Set::remove(char c) {
    if (elements[static_cast<unsigned char>(c)]) {
        elements[static_cast<unsigned char>(c)] = false;
        --count;
    }
}

bool& Set::operator[](char c) {
    return elements[static_cast<unsigned char>(c)];
}

std::ostream& operator<<(std::ostream& os, const Set& set) {
    os << "{ ";
    for (int i = 0; i < MAX_SIZE; ++i) {
        if (set.elements[i]) {
            os << static_cast<char>(i) << " ";
        }
    }
    os << "}";
    return os;
}

std::istream& operator>>(std::istream& is, Set& set) {
    char input;
    is >> input;
    set.add(input);
    return is;
}

Set::operator std::string() const {
    std::string result;
    for (int i = 0; i < MAX_SIZE; ++i) {
        if (elements[i]) {
            result += static_cast<char>(i);
        }
    }
    return result;
}

bool Set::contains(char c) const {
    return elements[static_cast<unsigned char>(c)];
}

Set Set::unionSet(const Set& other) const {
    Set resultSet;
    for (int i = 0; i < MAX_SIZE; ++i) {
        resultSet.elements[i] = elements[i] || other.elements[i];
    }
    resultSet.count = std::count(resultSet.elements, resultSet.elements + MAX_SIZE, true);
    return resultSet;
}

Set Set::intersection(const Set& other) const {
    Set resultSet;
    for (int i = 0; i < MAX_SIZE; ++i) {
        resultSet.elements[i] = elements[i] && other.elements[i];
    }
    resultSet.count = std::count(resultSet.elements, resultSet.elements + MAX_SIZE, true);
    return resultSet;
}

Set Set::difference(const Set& other) const {
    Set resultSet;
    for (int i = 0; i < MAX_SIZE; ++i) {
        resultSet.elements[i] = elements[i] && !other.elements[i];
    }
    resultSet.count = std::count(resultSet.elements, resultSet.elements + MAX_SIZE, true);
    return resultSet;
}

bool Set::isSubsetOf(const Set& other) const {
    for (int i = 0; i < MAX_SIZE; ++i) {
        if (elements[i] && !other.elements[i]) {
            return false;
        }
    }
    return true;
}
