#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;
int main()
{
    string str;
    cin >> str;
    vector<char> val;
    vector<int> trapId;
    vector<int> animalId;
    int traps = 0;
    int animals = 0;
    map<int, int> id;
    if (str.size() % 2 == 1)
    {
        cout << "Impossible" << endl;
    }
    else
    {
        for (int i = 0; i < str.size(); i++)
        {
            if (islower(str[i]))
            {
                animals++;
                if (trapId.size())
                {
                    if (isupper(val[val.size() - 1]) &&
                        (char)toupper(str[i]) == val[val.size() - 1])
                    {
                        id[trapId[trapId.size() - 1]] = animals;
                        val.pop_back();
                        trapId.pop_back();
                    }
                    else
                    {
                        val.push_back(str[i]);
                        animalId.push_back(animals);
                    }
                }
                else
                {
                    val.push_back(str[i]);
                    animalId.push_back(animals);
                }
            }
            else
            {
                traps++;
                if (animalId.size())
                {
                    if (islower(val[val.size() - 1]) &&
                        (char)tolower(str[i]) == val[val.size() - 1])
                    {
                        id[traps] = animalId[animalId.size() - 1];
                        val.pop_back();
                        animalId.pop_back();
                    }
                    else
                    {
                        val.push_back(str[i]);
                        trapId.push_back(traps);
                    }
                }
                else
                {
                    val.push_back(str[i]);
                    trapId.push_back(traps);
                }
            }
        }
        if (val.size() == 0)
        {
            cout << "Possible" << endl;
            for (int i = 1; i <= id.size(); i++)
            {
                cout << id[i] << " ";
            }
        }
        else
        {
            cout << "Impossible" << endl;
        }
    }
    return 0;
}
