#include <iostream>
#include <sstream>
#include "open_file.h"
#include "medicine.h"

using namespace std;

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        cerr << "Incorrect number of command line arguments - the minimum is 2, got " << argc << endl;
    }

    string path;

    vector<Medicine> medicines_obj;

    Objects_from_txt medicines(medicines_obj);

    stringstream stream;

    stream << argv[1];
    stream >> path;
    stream.clear();

    medicines.read_from_txt(path);

    int size = medicines_obj.size();
    cout << size;

    // doesnt work yet

    for (int i = 0; i < size; i++)
    {
        cout << medicines_obj[i].get_name() << endl;
    }

    return 0;
}
