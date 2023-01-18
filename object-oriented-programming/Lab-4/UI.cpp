#include "UI.hpp"

/**************************************************************/
/* Lab  4.  Polymorphism, abstract classes.                   */
/* Purpose: study polymorphism.                               */
/* Content: Create a hierarchy of classes. Create a composite */
/*   class that stores objects.                               */
/* Student   : Mustafin Radmir                                */
/* Date: 21.11.2022                                           */
/**************************************************************/

/*Main file*/

/// @brief
/// @param min
/// @param max
/// @return
int random(int min, int max) // Generating a random number in the range
{
    if (max < min)
    {
        swap(min, max);
    }
    return min + rand() % (1 + max - min);
}
/// @brief
/// @param m
/// @param size
void shuffleArray(int m[], int size) // Shuffling the array
{
    for (int i = 0; i < size; ++i)
        std::swap(m[i], m[std::rand() % size]);
}
/// @brief
/// @param a
/// @param size
void zeroArr(int a[], unsigned long int size) // Filling the array 0
{
    memset(a, 0, size * sizeof(int));
}

/// @brief
/// @param length
/// @param arr
/// @return
int maxArrayIndex(int length, int *arr) // Index of the maximum element
{
    int max = arr[0];
    int max_i = 0;
    for (int i = 0; i < length; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
            max_i = i;
        }
    }
    return max_i;
}
/// @brief
/// @param length
/// @param arr
/// @return
int minArrayIndex(int length, int *arr) // Index of the minimum element
{
    int min = arr[0];
    int min_i = 0;
    for (int i = 0; i < length; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
            min_i = i;
        }
    }
    return min_i;
}

int run()
{
    srand(unsigned(time(NULL)));
    string names[10] = // Array of names
        {
            "Arseniy",
            "Ksenia",
            "Konstantin",
            "Varvara",
            "Veronika",
            "Daniil",
            "Ivan",
            "Roman",
            "Vasilisa",
            "Alice"};
    string surnames[10] = // Array of surnames
        {
            "Egorov",
            "Yakovleva",
            "Kuzmin",
            "Bogomolova",
            "Firsova",
            "Safronov",
            "Korolev",
            "Kuleshov",
            "Denisova",
            "Novikova"};
    const int N = 10;                   // Number of entities
    int year, tp, sw;                   // Data for work
    int k1 = 0, k2 = 0, k3 = 0, k4 = 0; // Coefficients
    bool f = true;                      // Flag
    University univer;                  // Composite Entity
    int id_type1[N * 2], id_type2[N * 2], id_type3[N * 2], id_type4[N * 2];
    for (int i = 0; i < N; ++i) // Generation of the year of birth
    {
        tp = random(1, 4);
        switch (tp)
        {
        case 1:
        {
            year = random(1999, 2005);
            id_type1[k1++] = i;
            break;
        }
        case 2:
        {
            year = random(1950, 1995);
            id_type2[k2++] = i;
            break;
        }
        case 3:
        {
            year = random(1950, 1990);
            id_type3[k3++] = i;
            break;
        }
        case 4:
        {
            year = random(1980, 1997);
            id_type4[k4++] = i;
            break;
        }
        }
        // Adding Names
        univer.addPersons((names[rand() % 10] + " " + surnames[rand() % 10]).c_str(), year, tp);
    } // Adding subjects
    for (int j = 0; j < k1; ++j)
    {
        int id = id_type1[j];
        int k_subj = random(1, MAX_SUBJECTS);
        for (int k_s = 0; k_s < k_subj; ++k_s)
            univer.getPersons(id)->setValue(random(1, MAX_SUBJECTS), random(random(2, 4), 5));
    }
    for (int j = 0; j < k2; ++j)
    {
        int id = id_type2[j];
        int k_subj = random(1, MAX_SUBJECTS);
        for (int k_s = 0; k_s < k_subj; ++k_s)
            univer.getPersons(id)->setValue(random(1, MAX_SUBJECTS), random(80, 144) / k_subj);
    }
    for (int j = 0; j < k3; ++j)
    {
        int id = id_type3[j];
        int k_subj = random(1, MAX_SUBJECTS);
        for (int k_s = 0; k_s < k_subj; ++k_s)
            univer.getPersons(id)->setValue(random(1, MAX_SUBJECTS), random(80, 144) / k_subj);
        if (k2 > 0)
        {
            int k_zams = random(1, k2);
            shuffleArray(id_type2, k2);
            for (int k_z = 0; k_z < k_zams; ++k_z)
                univer.getPersons(id)->addIntern(univer.getPersons(id_type2[k_z]));
        }
    }
    for (int j = 0; j < k4; ++j)
    {
        int id = id_type4[j];
        int k_subj = random(1, MAX_SUBJECTS);
        for (int k_s = 0; k_s < k_subj; ++k_s)
            univer.getPersons(id)->setValue(random(1, MAX_SUBJECTS), random(80, 144) / k_subj);
        if (k1 > 0)
        {
            int k_studs = random(1, k1);
            shuffleArray(id_type1, k1);
            for (int k_s = 0; k_s < k_studs; ++k_s)
                univer.getPersons(id)->addIntern(univer.getPersons(id_type1[k_s]));
        }
    }
    univer.printAboutPerson(0);
    while (f) // choice
    {
        cout << endl
             << "Select operation" << endl;
        cout << "1) Output complete information about each entity" << endl;
        cout << "2) Output brief information about each entity" << endl;
        cout << "3) Calculate the summary of all the payments" << endl;
        cout << "4) Average PO for each entity" << endl;
        cout << "5) Find the youngest and oldest entity in each view" << endl;
        cout << "6) Create a random entity" << endl;
        cout << "7) Delete the entity" << endl;
        cout << "8) Exit" << endl;
        cin >> sw;
        cout << endl;
        switch (sw)
        {
        case 1:
        {
            univer.printAboutPerson(1);
            break;
        }
        case 2:
        {
            univer.printAboutPerson(0);
            break;
        }
        case 3:
        {
            double sMoney = 0;
            for (int i = 0; i < univer.getFacultyCount(); ++i)
                sMoney += univer.getPersons(i)->getFullPay();
            cout << "Total paid: " << sMoney << endl;
            break;
        }
        case 4:
        {
            zeroArr(id_type1, N * 2);
            zeroArr(id_type2, N * 2);
            zeroArr(id_type3, N * 2);
            zeroArr(id_type4, N * 2);
            k1 = 0, k2 = 0, k3 = 0, k4 = 0;
            double sM1 = 0, sM2 = 0, sM3 = 0, sM4 = 0;
            for (int i = 0; i < univer.getFacultyCount(); ++i)
            {
                tp = univer.getPersons(i)->getTypePerson();
                switch (tp)
                {
                case 1:
                {
                    sM1 += univer.getPersons(i)->getFullPay();
                    id_type1[k1++] = univer.getPersons(i)->getId();
                    break;
                }
                case 2:
                {
                    sM2 += univer.getPersons(i)->getFullPay();
                    id_type2[k2++] = univer.getPersons(i)->getId();
                    break;
                }
                case 3:
                {
                    sM3 += univer.getPersons(i)->getFullPay();
                    id_type3[k3++] = univer.getPersons(i)->getId();
                    break;
                }
                case 4:
                {
                    sM4 += univer.getPersons(i)->getFullPay();
                    id_type4[k4++] = univer.getPersons(i)->getId();
                    break;
                }
                }
            }
            if (k1 > 0)
            {
                cout << "Average PO for students: " << sM1 / k1 << endl;
            }
            else
            {
                cout << "There are no students!" << endl;
            }
            if (k2 > 0)
            {
                cout << "Average PO for teachers: " << sM2 / k2 << endl;
            }
            else
            {
                cout << "No teachers!" << endl;
            }
            if (k3 > 0)
            {
                cout << "Average PO to the manager: " << sM3 / k3 << endl;
            }
            else
            {
                cout << "There are no managers!" << endl;
            }
            if (k4 > 0)
            {
                cout << "Average PO for Researcherers: " << sM4 / k4 << endl;
            }
            else
            {
                cout << "No Researcher staff!" << endl;
            }
            break;
        }
        case 5:
        {
            int year_type1[N * 2], year_type2[N * 2], year_type3[N * 2], year_type4[N * 2];
            zeroArr(id_type1, N * 2);
            zeroArr(id_type2, N * 2);
            zeroArr(id_type3, N * 2);
            zeroArr(id_type4, N * 2);
            k1 = 0, k2 = 0, k3 = 0, k4 = 0;
            for (int i = 0; i < univer.getFacultyCount(); ++i)
            {
                tp = univer.getPersons(i)->getTypePerson();
                switch (tp)
                {
                case 1:
                {
                    year_type1[k1] = univer.getPersons(i)->getAge();
                    id_type1[k1++] = univer.getPersons(i)->getId();
                    break;
                }
                case 2:
                {
                    year_type2[k2] = univer.getPersons(i)->getAge();
                    id_type2[k2++] = univer.getPersons(i)->getId();
                    break;
                }
                case 3:
                {
                    year_type3[k3] = univer.getPersons(i)->getAge();
                    id_type3[k3++] = univer.getPersons(i)->getId();
                    break;
                }
                case 4:
                {
                    year_type4[k4] = univer.getPersons(i)->getAge();
                    id_type4[k4++] = univer.getPersons(i)->getId();
                    break;
                }
                }
            }
            if (k1 > 0)
            {
                cout << endl
                     << "The youngest student:" << endl;
                univer.getPersonID(id_type1[minArrayIndex(k1, year_type1)])->printAbout();
                cout << endl
                     << "The oldest student:" << endl;
                univer.getPersonID(id_type1[maxArrayIndex(k1, year_type1)])->printAbout();
            }
            else
            {
                cout << "No students!" << endl;
            }
            if (k2 > 0)
            {
                cout << endl
                     << "The youngest teacher:" << endl;
                univer.getPersonID(id_type2[minArrayIndex(k2, year_type2)])->printAbout();
                cout << endl
                     << "The most senior teacher:" << endl;
                univer.getPersonID(id_type2[maxArrayIndex(k2, year_type2)])->printAbout();
            }
            else
            {
                cout << "No teachers!" << endl;
            }
            if (k3 > 0)
            {
                cout << endl
                     << "The youngest head:" << endl;
                univer.getPersonID(id_type3[minArrayIndex(k3, year_type3)])->printAbout();
                cout << endl
                     << "The most senior manager:" << endl;
                univer.getPersonID(id_type3[maxArrayIndex(k3, year_type3)])->printAbout();
            }
            else
            {
                cout << "There are no managers!" << endl;
            }
            if (k4 > 0)
            {
                cout << endl
                     << "The youngest Researcherer:" << endl;
                univer.getPersonID(id_type4[minArrayIndex(k4, year_type4)])->printAbout();
                cout << endl
                     << "The most senior Researcherer:" << endl;
                univer.getPersonID(id_type4[maxArrayIndex(k4, year_type4)])->printAbout();
            }
            else
            {
                cout << "No Researcher staff!" << endl;
            }
            break;
        }
        case 7:
        {
            int id;
            cout << "Enter the ID to delete... ID = ";
            cin >> id;
            cout << endl;
            univer.removePersonID(id);
            univer.printAboutPerson(0);
            break;
        }
        case 6:
        {
            k1 = 0;
            k2 = 0;
            k3 = 0;
            k4 = 0;
            zeroArr(id_type1, N * 2);
            zeroArr(id_type2, N * 2);
            zeroArr(id_type3, N * 2);
            zeroArr(id_type4, N * 2);
            for (int i = 0; i < univer.getFacultyCount(); ++i)
            {
                tp = univer.getPersons(i)->getTypePerson();
                switch (tp)
                {
                case 1:
                {
                    id_type1[k1++] = univer.getPersons(i)->getId();
                    break;
                }
                case 2:
                {
                    id_type2[k2++] = univer.getPersons(i)->getId();
                    break;
                }
                case 3:
                {
                    id_type3[k3++] = univer.getPersons(i)->getId();
                    break;
                }
                case 4:
                {
                    id_type4[k4++] = univer.getPersons(i)->getId();
                    break;
                }
                }
            }
            tp = random(1, 4);
            int tmpN = N + 1;
            switch (tp)
            {
            case 1:
            {
                year = random(1999, 2005);
                id_type1[k1++] = tmpN;
                break;
            }
            case 2:
            {
                year = random(1950, 1995);
                id_type2[k2++] = tmpN;
                break;
            }
            case 3:
            {
                year = random(1950, 1990);
                id_type3[k3++] = tmpN;
                break;
            }
            case 4:
            {
                year = random(1980, 1997);
                id_type4[k4++] = tmpN;
                break;
            }
            }
            univer.addPersons((names[rand() % 10] + " " + surnames[rand() % 10]).c_str(), year, tp);
            univer.printAboutPerson(0);
            if (tp == 1)
            {
                int id = id_type1[k1 - 1];
                int k_subj = random(1, MAX_SUBJECTS);
                for (int k_s = 0; k_s < k_subj; ++k_s)
                    univer.getPersonID(id)->setValue(random(1, MAX_SUBJECTS), random(random(2, 4), 5));
            }
            if (tp == 2)
            {
                int id = id_type2[k2 - 1];
                int k_subj = random(1, MAX_SUBJECTS);
                for (int k_s = 0; k_s < k_subj; ++k_s)
                    univer.getPersonID(id)->setValue(random(1, MAX_SUBJECTS), random(80, 144) / k_subj);
            }
            if (tp == 3)
            {
                int id = id_type3[k3 - 1];
                int k_subj = random(1, MAX_SUBJECTS);
                for (int k_s = 0; k_s < k_subj; ++k_s)
                    univer.getPersonID(id)->setValue(random(1, MAX_SUBJECTS), random(80, 144) / k_subj);
                if (k2 > 0)
                {
                    int k_zams = random(1, k2);
                    shuffleArray(id_type2, k2);
                    for (int k_z = 0; k_z < k_zams; ++k_z)
                        univer.getPersonID(id)->addIntern(univer.getPersonID(id_type2[k_z]));
                }
            }
            if (tp == 4)
            {
                int id = id_type4[k4 - 1];
                int k_subj = random(1, MAX_SUBJECTS);
                for (int k_s = 0; k_s < k_subj; ++k_s)
                    univer.getPersonID(id)->setValue(random(1, MAX_SUBJECTS), random(80, 144) / k_subj);
                if (k1 > 0)
                {
                    int k_studs = random(1, k1);
                    shuffleArray(id_type1, k1);
                    for (int k_s = 0; k_s < k_studs; ++k_s)
                        univer.getPersonID(id)->addIntern(univer.getPersonID(id_type1[k_s]));
                }
            }
            break;
        }
        case 8:
        {
            cout << "Deleting entities....." << endl;
            f = false;
            int NM = univer.getFacultyCount();
            for (int i = 0; i < NM; ++i)
                univer.removePersons();
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