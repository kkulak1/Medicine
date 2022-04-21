#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "open_file.h"
#include "medicine.h"
#include "producer.h"
#include "date.h"
#include "ingredient.h"

using namespace std;

Objects_from_txt::Objects_from_txt(vector<Medicine> meds)
{
    medicines = meds;
}

void Objects_from_txt::read_from_txt(string path)
{
    fstream myfile;

    myfile.open(path, ios::in);

    if (myfile.good() == false)
    {
        throw invalid_argument("File doesnt exist!");
        exit(0);
    }

    string line;
    int y = 0;

    vector<vector<string>> tab;

    if (myfile.is_open())
    {
        while (getline(myfile, line))
        {
            vector<string> one_medicine;

            string tmp = "";

            for (int i = 0; i < (int)line.length(); i++)
            {
                if (line[i] == ' ')
                {
                    one_medicine.push_back(tmp);
                    tmp = "";
                }
                else
                {
                    tmp += line[i];
                }
            }
            one_medicine.push_back(tmp);
            tab.push_back(one_medicine);
            y++;
        }
        myfile.close();
    }

    for (int i = 0; i < y; i++)
    {
        vector<Ingredient> ingredients;

        Producer producer(tab[i][4], tab[i][5]);
        Date date(stoi(tab[i][7]), stoi(tab[i][8]), stoi(tab[i][9]));
        int ningr = tab[i].size() - 10;

        if (ningr > 0)
        {
            if ((ningr % 2) == 1)
            {
                throw invalid_argument("Wrong ingredients in txt file!");
            }
            else
            {
                int tmp = ningr / 2;
                for (int j = 0; j < tmp; j++)
                {

                    int ingr_name_pos = 10 + (j * 2);
                    int ingr_amount_pos = 11 + (j * 2);
                    Ingredient ingredient(tab[i][ingr_name_pos], stoi(tab[i][ingr_amount_pos]));
                    ingredients.push_back(ingredient);
                }
            }
        }

        Medicine medicine(tab[i][0], stoi(tab[i][1]), tab[i][2], stoi(tab[i][3]), producer, stoi(tab[i][6]), date, ingredients);
        medicines.push_back(medicine);
    }
}

void Objects_from_txt::show()
{
    int size = medicines.size();

    for (int i = 0; i < size; i++)
    {
        cout << medicines[i].get_name() << endl;
        cout << "Capacity: " << medicines[i].get_capacity() << endl;
        cout << "Active substance name: " << medicines[i].get_active_substance_name() << endl;
        cout << "Dose: " << medicines[i].get_dose() << endl;
        cout << "Number: " << medicines[i].get_nr() << endl;
        cout << "Date: " << medicines[i].get_date().get_day() << "." << medicines[i].get_date().get_month() << "." << medicines[i].get_date().get_year() << endl;
        cout << "Producer: " << medicines[i].get_producer().get_name() << endl;

        medicines[i].show_ingredients();
    }
}

void Objects_from_txt::sort_by_amount()
{
    int size = medicines.size();

    for (int i = 0; i < size; i++)
    {
        medicines[i].sort_ingr_by_amount();
    }
}

void Objects_from_txt::sort_by_name()
{
    int size = medicines.size();

    for (int i = 0; i < size; i++)
    {
        medicines[i].sort_ingr_by_name();
    }
}