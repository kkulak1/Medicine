#include <iostream>
#include "ingredient.h"

using namespace std;

Ingredient::Ingredient(string n, int a)
{
    name = n;
    set_amount(a);
}

string Ingredient::get_name()
{
    return name;
}

int Ingredient::get_amount()
{
    return amount;
}

void Ingredient::set_name(string new_name)
{
    name = new_name;
}

void Ingredient::set_amount(int new_amount)
{
    if (new_amount <= 0)
    {
        throw invalid_argument("Amount must be positive!");
    }
    else
    {
        amount = new_amount;
    }
}