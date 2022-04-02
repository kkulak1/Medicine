#include <iostream>
#include <fstream>
#include <vector>
#include "open_file.h"
#include "medicine.h"

using namespace std;

Open_file::Open_file(string p)
{
    path = p;
}

void read_from_txt(string path)
{
    ifstream myfile;

    myfile.open(path, ios::in);

    if (myfile.good() == false)
    {
        throw invalid_argument("File doesnt exist!");
        exit(0);
    }

    vector<Medicine> medicines;

    string line;
    int n_line;

    while (getline(myfile, line))
    {

        n_line++;
    }

    myfile.close();
}
