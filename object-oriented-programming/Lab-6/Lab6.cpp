#include "University.h"
#include <ctime>
#include <iostream>
#include <cstdlib>
using namespace std;

/****************************************/
/* Laboratory work 6                    */
/* Exceptions, STL templates            */
/*   The main program file              */
/*   Developer Mustafin R.R.            */
/*   Group 1413                         */
/*  Version 16.12.2022                  */
/****************************************/

int main(int argc, char **argv)
{
    srand(time(0));
    cout << "This program is a container class university, in which there are various entities\n"
         << endl;
    int N, sw;
    bool f = true;
    University univer; // Container class
    H_Types tkp;
    cout << "Enter the desired number of future entities. N: ";
    cin >> N;
    cout << endl;
    try
    {
        univer.addRandomHumans(N);
    }                    // Exception handling for adding entities
    catch (Exception &e) // Catch for Humans
    {
        cout << e.getInfo() << endl;
    }
    univer.printAboutHuman(0);
    while (f) // Exit condition
    {         // Interface
        cout << endl
             << "Select an action." << endl;
        cout << "1) Output complete information about each entity." << endl;
        cout << "2) Output brief information about each entity." << endl;
        cout << "3) Find the sum of all the money paid." << endl;
        cout << "4) Average PO for each type of entity." << endl;
        cout << "5) Find the youngest and oldest entity in each view." << endl;
        cout << "6) Create N random entities." << endl;
        cout << "7) Exit." << endl;
        cout << "Your choice... ";
        cin >> sw; // Operation selection
        cout << endl;
        switch (sw)
        {
        case 1:
        {
            univer.printAboutHuman(1);
            break;
        } // Full information
        case 2:
        {
            univer.printAboutHuman(0);
            break;
        }       // Brief information
        case 3: // About salaries
        {
            try
            {
                cout << "Total paid: " << univer.allMoney() << endl;
            } // Processing salary exclusions
            catch (Exception &e)
            {
                cout << e.getInfo() << endl;
            }
            break;
        }
        case 4: // Average by money
        {
            try
            {
                univer.avgMoney();
            }
            catch (Exception &e)
            {
                cout << e.getInfo() << endl;
            }
            break;
        }
        case 5:
        {
            univer.CompAge();
            break;
        }        // age of comp
        case 12: // Change the number of people
        {
            int id;
            cout << "Enter the ID to delete... ID = ";
            cin >> id;
            cout << endl;
            univer.removeHumanID(id);  // Deleting by id
            univer.printAboutHuman(0); // Output of information about the entity
            break;
        }
        case 6: // Enter the desired number of future entities
        {
            cout << "Enter the desired number of future entities. N: ";
            cin >> N;
            cout << endl;
            try
            {
                univer.addRandomHumans(N);
            }
            catch (Exception &e)
            {
                cout << e.getInfo() << endl;
            }
            univer.printAboutHuman(0);
            break;
        }
        case 7:
        {
            cout << "Deleting entities....." << endl;
            f = false;
            univer.removeHumans();
            cout << "The program is finished." << endl;
            break;
        }
        default:
        {
            cout << "ERROR. There is no such menu item." << endl;
            break;
        }
        }
    }
    return 0;
}
