#ifndef __DEFINICJE_HPP__
#define __DEFINICJE_HPP__

#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

class Open_file
{
    string path;

public:
    Open_file(string path);

    void read_from_txt(string path);
};

#endif
