#ifndef __DEFINICJE_HPP__
#define __DEFINICJE_HPP__

#include <iostream>

using namespace std;

class Producer
{
    string name, address;

public:
    Producer(string name = "aa", string address = "aaa 2A");

    string get_name();
    string get_address();

    void set_name(string new_name);
    void set_address(string new_address);
};

#endif