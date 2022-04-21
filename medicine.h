#ifndef __DEFINICJE_HPP__
#define __DEFINICJE_HPP__

#include <iostream>
#include <vector>
#include "producer.h"
#include "date.h"
#include "ingredient.h"

using namespace std;

class Medicine
{
    string name;
    int capacity;
    string active_substance_name;
    int dose, nr;
    Date date;
    Producer producer;

    vector<Ingredient> ingredients;

public:
    Medicine(string name, int capacity, string active_substance_name, int dose, Producer producer, int nr, Date date, vector<Ingredient> ingredients);

    string get_name();
    int get_capacity();
    string get_active_substance_name();
    int get_dose();
    int get_nr();
    Producer get_producer();
    Date get_date();
    int get_nr_ingredients();

    void set_name(string new_name);
    void set_capacity(int new_capacity);
    void set_active_substance_name(string new_active_substance_name);
    void set_dose(int new_dose);
    void set_nr(int new_nr);
    void set_producer(Producer new_producer);
    void set_date(Date new_date);

    bool check_ingredient_in(Ingredient ingr);
    void add_ingredient(Ingredient new_ingredient);
    void modify_ingredient(Ingredient ingr_to_modify, Ingredient new_ingr);
    void delete_ingredient(Ingredient ingredient_to_delete);
    int count_ingredient(int amount);
    void sort_by_name();
    void sort_by_amount();

    void show_ingredients();

    bool operator==(Medicine med);
    bool operator<=(const Medicine &med) const;
    bool operator>=(const Medicine &med) const;
    bool operator<(const Medicine &med) const;
    bool operator>(const Medicine &med) const;
    void operatorposti();
    void operatorprei();
    void operatorpostd();
    void operatorpred();

    void sort_ingr_by_amount();
    void sort_ingr_by_name();
};

#endif
