#include <iostream>
#include "Set.h"

int main() {
    Set set1, set2;
    int i, n;

    std::cout << "n = "; std::cin >> n;

    i = 0;

    do {
        std::cout << "Enter elements of set 1: ";
        std::cin >> set1;
        i++;
    } while (n > i);

    std::cout << "n = "; std::cin >> n;

    i = 0;

    do {
    std::cout << "Enter elements of set 2: ";
    std::cin >> set2;
    i++;
    } while (n > i);

    std::cout << "Set 1: " << set1 << std::endl;
    std::cout << "Set 2: " << set2 << std::endl;

    std::cout << "Union of set1 and set2: " << (set1.unionSet(set2)) << std::endl;
    std::cout << "Intersection of set1 and set2: " << (set1.intersection(set2)) << std::endl;
    std::cout << "Difference of set1 and set2: " << (set1.difference(set2)) << std::endl;

    char elementToCheck;
    std::cout << "Enter an element to check in set 1: ";
    std::cin >> elementToCheck;
    if (set1.contains(elementToCheck)) {
        std::cout << elementToCheck << " is present in set 1" << std::endl;
    }
    else {
        std::cout << elementToCheck << " is not present in set 1" << std::endl;
    }

    std::cout << "Enter an element to check in set 2: ";
    std::cin >> elementToCheck;
    if (set2.contains(elementToCheck)) {
        std::cout << elementToCheck << " is present in set 2" << std::endl;
    }
    else {
        std::cout << elementToCheck << " is not present in set 2" << std::endl;
    }

    if (set1.isSubsetOf(set2)) {
        std::cout << "Set 1 is a subset of Set 2" << std::endl;
    }
    else {
        std::cout << "Set 1 is not a subset of Set 2" << std::endl;
    }

    return 0;
}
