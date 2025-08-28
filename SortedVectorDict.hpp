#pragma once
#include "Dictionary.hpp"
#include <vector>

class SortedVectorDict : public Dictionary {
public:
    void insert(int) override;
    bool lookup(int) const override;
    void remove(int) override;

private:
    std::vector<int> data;
};