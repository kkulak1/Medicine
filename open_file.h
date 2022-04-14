#ifndef __DEFINICJE_HPPb__
#define __DEFINICJE_HPPb__

#include <iostream>
#include <fstream>
#include <cstdlib>
#include "medicine.h"

using namespace std;

class Objects_from_txt
{
    vector<Medicine> medicines;

public:
    Objects_from_txt(vector<Medicine> medicines);

    void read_from_txt(string path);
};

#endif
