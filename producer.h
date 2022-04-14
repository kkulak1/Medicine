#ifndef __DEFINICJE_HPPa__
#define __DEFINICJE_HPPa__

#include <iostream>

using namespace std;

class Producer
{
    string name, address;

public:
    Producer(string name = "Jan", string address = "Janow 2A");

    string get_name();
    string get_address();

    void set_name(string new_name);
    void set_address(string new_address);
};

#endif