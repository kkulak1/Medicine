#include <iostream>
#include <sstream>
#include "open_file.h"

using namespace std;

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        cerr << "Incorrect number of command line arguments - the minimum is 2, got " << argc << endl;
    }

    string path;

    stringstream stream;

    stream << argv[1];
    stream >> path;
    stream.clear();

    Open_file medicines(string path);
}
