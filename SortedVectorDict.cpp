#include "SortedVectorDict.hpp"

void SortedVectorDict::insert(int key) {

    // Initially pushes back the key to the vector
    // Then scans through the array finding the values that are greater than the key, placing the key to its correct position.
    data.push_back(key);
    std::size_t i = data.size() - 1;

    while (i > 0 && data[i - 1] > data[i]) {
        int temp = data[i - 1];

        data[i - 1] = data[i];
        data[i] = temp;

        i -= 1;
    }
}

bool SortedVectorDict::lookup(int key) const {

    // Scans through the array finding the data returning true if found

    for (auto i = 0; i < data.size(); i++) {
        if (data[i] == key) {
            return true;
        }

        // Since the vector is sorted, if it goes beyond the length of the key, it will end short.
        if (data[i] > key) {
            return false;
        }
    }

    return false;
}

void SortedVectorDict::remove(int key) {

    // Linear scan to find the position of the key that's wanted to be removed
    // Removes the key the first time it finds the key values (doesn't delete multiples)

    for (std::size_t i = 0; i < data.size(); ++i) {
        if (data[i] == key) {
            for (std::size_t j = i; j + 1 < data.size(); ++j) {
                data[j] = data[j + 1];
            }
            data.pop_back();
            return;
        }
        if (data[i] > key) {
            return;
        }
    }
}