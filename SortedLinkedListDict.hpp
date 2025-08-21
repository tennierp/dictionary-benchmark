#pragma once
#include "Dictionary.hpp"

class SortedLinkedListDict : public Dictionary {
public:
    void insert(int) override;
    bool lookup(int) const override;
    void remove(int) override;
};