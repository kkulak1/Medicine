#include <iostream>
#include <fstream>
#include <vector>
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
    vector<Ingredient> ingredients;

    string line;
    int y = 0;

    vector<vector<string>> tab;

    if (myfile.is_open())
    {
        while (getline(myfile, line))
        {

            // for (int i = 0; i < (int)line.length(); i++)
            // {
            //     if (line[i] == ' ')
            //     {
            //         x++;
            //     }
            //     tab[y][x] += line[i];
            // }
            // x = 0;
            // y++;
            vector<string> one_medicine;

            string tmp;

            for (int i = 0; i < (int)line.length(); i++)
            {
                tmp += line[i];

                if (line[i] == ' ')
                {
                    one_medicine.push_back(tmp);
                    tmp = "";
                }
            }

            tab.push_back(one_medicine);
            y++;
        }
        myfile.close();
    }

    cout << tab.size();

    for (int i = 0; i < y; i++)
    {
        Producer producer(tab[i][4], tab[i][5]);
        Date date(stoi(tab[i][7]), stoi(tab[i][8]), stoi(tab[i][9]));
        if (y > 9)
        {
            if ((y - 9) % 2 != 0)
            {
                throw invalid_argument("Wrong ingredients in txt tile!");
            }
            else
            {
                Ingredient ingredient(tab[i][10], stoi(tab[i][11]));
                ingredients.push_back(ingredient);
            }
        }
        Medicine medicine(tab[i][0], stoi(tab[i][1]), tab[i][2], stoi(tab[i][3]), producer, stoi(tab[i][6]), date, ingredients);
        medicines.push_back(medicine);
    }
    cout << medicines.size();
}
