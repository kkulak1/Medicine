#include <iostream>
#include <algorithm>
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

int Medicine::get_nr_ingredients()
{
    return ingredients.size();
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

bool Medicine::operator==(Medicine med)
{
    return (name == med.name) && (capacity == med.capacity) && (active_substance_name == med.active_substance_name) && (dose == med.dose) && (nr == med.nr) && (date.get_day() == med.get_date().get_day()) && (date.get_month() == med.get_date().get_month()) && (date.get_year() == med.get_date().get_year()) && (producer.get_name() == med.get_producer().get_name()) && (producer.get_address() == med.get_producer().get_address());
}

bool Medicine::check_ingredient_in(Ingredient ingr)
{
    int size = ingredients.size();
    for (int i = 0; i < size; i++)
    {
        if (ingredients[i].operator==(ingr))
        {
            return true;
        }
    }
    return false;
}

void Medicine::add_ingredient(Ingredient new_ingredient)
{
    int check;
    int size = ingredients.size();
    for (int i = 0; i < size; i++)
    {
        if (ingredients[i].operator==(new_ingredient))
        {
            check++;
        }
    }
    if (check == 1)
    {
        throw invalid_argument("Ingredient is already there!");
    }
    else
    {
        ingredients.push_back(new_ingredient);
    }
}

void Medicine::modify_ingredient(Ingredient ingr_to_modify, Ingredient new_ingredient)
{
    int pos = -1;
    int size = ingredients.size();
    for (int i = 0; i < size; i++)
    {
        if (ingredients[i].operator==(ingr_to_modify))
        {
            pos = i;
        }
    }
    if (pos >= 0)
    {
        ingredients[pos] = new_ingredient;
    }
    else
    {
        throw invalid_argument("No such ingredient in collection!");
    }
}

void Medicine::delete_ingredient(Ingredient ingr_to_delete)
{
    int pos = 0;
    int size = ingredients.size();
    for (int i = 0; i < size; i++)
    {
        if (ingredients[i].operator==(ingr_to_delete))
        {
            ingredients.erase(ingredients.begin() + i);
            pos = 1;
        }
    }
    if (pos == 0)
    {
        throw invalid_argument("No such ingredient in collection!");
    }
}

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

void Medicine::show_ingredients()
{
    int nr_ingr = ingredients.size();
    cout << "Ingredients(" << nr_ingr << "): " << endl;
    for (int i = 0; i < nr_ingr; i++)
    {
        cout << "    Name: " << ingredients[i].get_name() << endl;
        cout << "    Amount: " << ingredients[i].get_amount() << endl;
    }
    cout << endl;
}

void Medicine::sort_ingr_by_amount()
{
    sort(ingredients.begin(), ingredients.end(), [](Ingredient &lhs, Ingredient &rhs)
         { return lhs.get_amount() < rhs.get_amount(); });
}

void Medicine::sort_ingr_by_name()
{
    sort(ingredients.begin(), ingredients.end(), [](Ingredient &lhs, Ingredient &rhs)
         { return lhs.get_name() < rhs.get_name(); });
}

bool Medicine::operator<=(const Medicine &med) const
{
    return capacity <= med.capacity;
}

bool Medicine::operator>=(const Medicine &med) const
{
    return capacity >= med.capacity;
}

bool Medicine::operator<(const Medicine &med) const
{
    return capacity < med.capacity;
}

bool Medicine::operator>(const Medicine &med) const
{
    return capacity > med.capacity;
}

void Medicine::operatorposti()
{
    capacity++;
}

void Medicine::operatorprei()
{
    ++capacity;
}

void Medicine::operatorpostd()
{
    capacity--;
}

void Medicine::operatorpred()
{
    --capacity;
}