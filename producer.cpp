#include <iostream>
#include "producer.h"

using namespace std;

Producer::Producer(string n, string a)
{
    name = n;
    address = a;
}

string Producer::get_name()
{
    return name;
}

string Producer::get_address()
{
    return address;
}

void Producer::set_name(string new_name)
{
    name = new_name;
}

void Producer::set_address(string new_address)
{
    address = new_address;
}