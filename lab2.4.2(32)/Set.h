#pragma once
#include <iostream>
#include <cstring>
#include <string>

const int MAX_SIZE = 256;

class Set {
private:
    bool elements[MAX_SIZE];
    int size;
    int count; 

public:
    Set() : size(MAX_SIZE), count(0) {
        memset(elements, false, sizeof(elements));
    }

    Set(int maxSize) : size(maxSize), count(0) {
        memset(elements, false, sizeof(elements));
    }

    Set(const Set& other) {
        size = other.size;
        count = other.count;
        memcpy(elements, other.elements, sizeof(elements));
    }

    int getSize() const { return size; }
    int getCount() const { return count; }

    void setSize(int newSize) { size = newSize; }
    void setCount(int newCount) { count = newCount; }

    void add(char c);

    void remove(char c);

    bool& operator[](char c);

    friend std::ostream& operator<<(std::ostream& os, const Set& set);

    friend std::istream& operator>>(std::istream& is, Set& set);

    operator std::string() const;

    bool contains(char c) const;

    Set unionSet(const Set& other) const;

    Set intersection(const Set& other) const;

    Set difference(const Set& other) const;

    bool isSubsetOf(const Set& other) const;

};
