#ifndef __DEFINICJE_HPPc__
#define __DEFINICJE_HPPc__

#include <iostream>

using namespace std;

class Ingredient
{
    string name;
    int amount;

public:
    Ingredient(string name, int amount);
    Ingredient() = default;

    string get_name();
    int get_amount();

    void set_name(string new_name);
    void set_amount(int new_amount);

    bool operator==(const Ingredient &ingr) const;
};

#endif