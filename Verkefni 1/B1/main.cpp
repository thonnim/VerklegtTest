#include <iostream>
#include <fstream>
#include "include/superhero.h"

using namespace std;

int main()
{
    char addHero = 'n';

    //Ask the user if he/she wants to add a hero.

    do {
        cout << "Add hero? (Y/N): ";
        cin >> addHero;
    } while (!(toupper(addHero) == 'N' || toupper(addHero) == 'Y'))

    if(toupper(addHero) == 'Y')
    {
        string name = "";
        int age = 0;
        char superpower = 'n';

        //Ask for the hero's name.
        cout << "Name: ";
        cin >> name;

        //Ask for the hero's age.
        cout << "Age: ";
        cin >> age;

        //Ask for the hero's superpower.
        cout << "Please enter a superpower:" << endl;
        cout << "Input f for Flying" << endl;
        cout << "Input g for Giant" << endl;
        cout << "Input h for Hacker" << endl;
        cout << "Input n for None" << endl;
        cout << "If other input, your superhero is a Weakling" << endl;
        cout << "Superpower: ";
        cin >> superpower;

        //Create a new Superhero using the user input.
        Superhero newHero(name, age, superpower);

        //Create the ofstream file
        ofstream fout;
        fout.open("superheroes.txt", ios::app);

        newHero.setVerbose(false);
        fout << newHero;
        newHero.setVerbose(true);

        fout.close();

    }

    ifstream fin;
    fin.open("superheroes.txt");

    if(fin.is_open())
    {
        string name;
        int age;
        char superpower;

        while(!fin.eof())
        {
            fin >> name;
            fin >> age;
            fin >> superpower;

            Superhero tempHero(name, age, superpower);

            cout << tempHero << endl;
        }

        fin.close();
    }
    else
    {
        cout << "ERROR: Could not open file" << endl;
    }


    cin >> addHero;



    return 0;
}
