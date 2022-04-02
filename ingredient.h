#ifndef __DEFINICJE_HPP__
#define __DEFINICJE_HPP__

#include <iostream>

using namespace std;

class Ingredient
{
    string name;
    int amount;

public:
    Ingredient(string name, int amount);

    string get_name();
    int get_amount();

    void set_name(string new_name);
    void set_amount(int new_amount);
};

#endif