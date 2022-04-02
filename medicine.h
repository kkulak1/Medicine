#ifndef __DEFINICJE_HPP__
#define __DEFINICJE_HPP__

#include <iostream>
#include <vector>
#include "producer.h"
#include "date.h"

using namespace std;

class Medicine
{
    string name;
    int capacity;
    string active_substance_name;
    int dose, nr;

    extern vector<Medicine> medicines;

public:
    Medicine(string name, int capacity, string active_substance_name, int dose, int nr);

    string get_name();
    int get_capacity();
    string get_active_substance_name();
    int get_dose();
    int get_nr();

    void set_name(string new_name);
    void set_capacity(int new_capacity);
    void set_active_substance_name(string new_active_substance_name);
    void set_dose(int new_dose);
    void set_nr(int new_nr);
};

#endif
