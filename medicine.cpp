#include <iostream>
#include "medicine.h"

using namespace std;

Medicine::Medicine(string n, int c, string asn, int d, Producer p, int nr, Date da, vector<Ingredient> ingr)
{
    name = n;
    set_capacity(c);
    active_substance_name = asn;
    set_dose(d);
    set_nr(nr);
    date = da;
    producer = p;
    ingredients = ingr;
}

string Medicine::get_name()
{
    return name;
}

int Medicine::get_capacity()
{
    return capacity;
}

string Medicine::get_active_substance_name()
{
    return active_substance_name;
}

int Medicine::get_dose()
{
    return dose;
}

int Medicine::get_nr()
{
    return nr;
}

Producer Medicine::get_producer()
{
    return producer;
}

Date Medicine::get_date()
{
    return date;
}

void Medicine::set_name(string new_name)
{
    name = new_name;
}

void Medicine::set_capacity(int new_capacity)
{
    if (new_capacity <= 0)
    {
        throw invalid_argument("Capacity must be a positive number!");
    }
    else
    {
        capacity = new_capacity;
    }
}

void Medicine::set_active_substance_name(string new_active_subs_name)
{
    active_substance_name = new_active_subs_name;
}

void Medicine::set_dose(int new_dose)
{
    if (new_dose <= 0)
    {
        throw invalid_argument("Dose must be a positive number!");
    }
    else
    {
        dose = new_dose;
    }
}

void Medicine::set_nr(int new_nr)
{
    if (new_nr <= 0)
    {
        throw invalid_argument("Number must be positive!");
    }
    else
    {
        nr = new_nr;
    }
}

void Medicine::set_producer(Producer new_producer)
{
    producer = new_producer;
}

void Medicine::set_date(Date new_date)
{
    date = new_date;
}

// bool Medicine::check_ingredient_in(Ingredient ingr)
// {
//     int size = ingredients.size();
//     for (int i = 0; i < size; i++)
//     {
//         if (ingredients[i] == ingr)
//         {
//             return true;
//         }
//     }
//     return false;
// }

// void Medicine::add_ingredient(Ingredient new_ingredient)
// {
//     int check;
//     int size = ingredients.size();
//     for (int i = 0; i < size; i++)
//     {
//         if (ingredients[i] == new_ingredient)
//         {
//             check++;
//         }
//     }
//     if (check == 1)
//     {
//         throw invalid_argument("Ingredient is already there!");
//     }
//     else
//     {
//         ingredients.push_back(new_ingredient);
//     }
// }

// void Medicine::modify_ingredient(Ingredient ingr_to_modify, Ingredient new_ingredient)
// {
//     int pos = -1;
//     int size = ingredients.size();
//     for (int i = 0; i < size; i++)
//     {
//         if (ingredients[i] == ingr_to_modify)
//         {
//             pos = i;
//         }
//     }
//     if (pos >= 0)
//     {
//         ingredients[pos] = new_ingredient;
//     }
//     else
//     {
//         throw invalid_argument("No such ingredient in collection!");
//     }
// }

// void Medicine::delete_ingredient(Ingredient ingr_to_delete)
// {
//     int pos = 0;
//     int size = ingredients.size();
//     for (int i; i < size; i++)
//     {
//         if (ingredients[i] == ingr_to_delete)
//         {
//             ingredients.erase(ingredients.begin() + i);
//             pos++;
//         }
//     }
//     if (pos == 0)
//     {
//         throw invalid_argument("No such ingredient in collection!");
//     }
// }

int Medicine::count_ingredient(int amount)
{
    int number = 0;
    int size = ingredients.size();
    for (int i = 0; i < size; i++)
    {
        if (ingredients[i].get_amount() >= amount)
        {
            number++;
        }
    }
    return number;
}
