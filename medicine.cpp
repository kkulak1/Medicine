#include <iostream>
#include "medicine.h"

using namespace std;

Medicine::Medicine(string n, int c, string asn, int d, int nr)
{
    name = n;
    set_capacity(c);
    active_substance_name = asn;
    set_dose(d);
    set_nr(nr);
}