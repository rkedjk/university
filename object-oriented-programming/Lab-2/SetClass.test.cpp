#include <iostream>
#include "SetClass.test.hpp"
#include "SetClass.hpp"

using namespace std;
bool SetClass_test::assertBool(bool actual, bool expected)
{
    cout << "Ожидаемый результат: " << expected << endl;
    cout << "Фактический результат: " << actual << endl;
    return actual == expected;
};

bool SetClass_test::assertArray(int actual[50], int expected[50], int actualsize, int expectedsize)
{
    bool check = true;
    int count = expectedsize;
    if (actualsize != expectedsize){
        check = false;
    }
    if (actualsize > expectedsize) {
        count = actualsize;
    }
    cout << "Фактический результат: ";
    for (int i = 0; i < actualsize; ++i)
    {
        cout << ((actual[i])) << " ";
    };
    cout << endl;
    cout << "Ожидаемый результат: ";
    for (int i = 0; i < expectedsize; ++i)
    {
        cout << expected[i] << " ";
    };
    cout << endl;
    for (int i = 0; i < count; ++i)
    {
        if ((actual[i]) != expected[i])
            check = false;
        break;
    };
    return check;
};

bool SetClass_test::isinset_1()
{
    cout << "Тестируем метод IsInSet" << endl;
    cout << "Поиск числа 5 во множестве [1,2,3,4,5]" << endl;

    //arrange
    int Tem[50] = {1, 2, 3, 4, 5};

    //act
    Set Temp(5, Tem);

    //assert
    return assertBool(Temp.isInSet(3), true);
};

bool SetClass_test::isinset_2()
{
    cout << "Тестируем метод IsInSet_2" << endl;
    cout << "Поиск числа 7 во множестве [1,2,3,4,5]" << endl;

    //arrange
    int Tem[50] = {1, 2, 3, 4, 5};

    //act
    Set Temp(5, Tem);

    //assert
    return assertBool(Temp.isInSet(7), false);
};

bool SetClass_test::additem_1()
{
    cout << "Тестируем метод additem" << endl;
    cout << "Добавить число 10 ко множеству [1,2,3,4,5]" << endl;

    //arrange
    int Tem[50] = {1, 2, 3, 4, 5};
    Set Temp(5, Tem);
    int TemExp[50] = {1, 2, 3, 4, 5, 10};

    //act
    Temp.addItem(10);

    //assert
    return assertArray(Temp.getArr(), TemExp,Temp.getSize(),6);
};

bool SetClass_test::deleteitem_1()
{
    cout << "Тестируем метод deleteitem" << endl;
    cout << "Удаление числа 3 из множества [1,2,3,4,5]" << endl;
    
    //arrange
    int Tem[50] = {1, 2, 3, 4, 5};
    Set Temp(5, Tem);
    int TemExp[50] = {1, 2, 4, 5};
    
    //act
    Temp.deleteItem(3);

    //assert
    return assertArray(Temp.getArr(), TemExp,Temp.getSize(),4);
};

bool SetClass_test::setintersection_1()
{
    cout << "Тестируем метод setintersection" << endl;
    cout << "Пересечение множеств [1,2,3] и [3,4,5]" << endl;
    
    //arrange
    int Tem1[50] = {1, 2, 3};
    Set Temp1(3, Tem1);
    int Tem2[50] = {3, 4, 5};
    Set Temp2(3, Tem2);
    int Tem[50];
    Set Temp(0, Tem);
    int TemExp[50] = {3};

    //act
    Temp.setIntersection(Temp1, Temp2);

    //assert
    return assertArray(Temp.getArr(), TemExp,Temp.getSize(),1);
}

bool SetClass_test::setintersection_2()
{
    cout << "Тестируем метод setintersection" << endl;
    cout << "Пересечение множеств [1,2,3] и [4,5]" << endl;
    
    //arrange
    int Tem1[50] = {1, 2, 3};
    Set Temp1(3, Tem1);
    int Tem2[50] = {4, 5};
    Set Temp2(2, Tem2);
    int Tem[50];
    Set Temp(0, Tem);
    int TemExp[50] = {};

    //act
    Temp.setIntersection(Temp1, Temp2);

    //assert
    return assertArray(Temp.getArr(), TemExp,Temp.getSize(),0);
}
bool SetClass_test::setconsolidation_1()
{
    cout << "Тестируем метод setconsolidation" << endl;
    cout << "Сумма множеств [1,2,3] и [4,5]" << endl;
    
    //arrange
    int Tem1[50] = {1, 2, 3};
    Set Temp1(3, Tem1);
    int Tem2[50] = {4, 5};
    Set Temp2(2, Tem2);
    int Tem[50];
    Set Temp(0, Tem);
    int TemEx[50] = {1, 2, 3, 4, 5};

    //act
    Temp.setConsolidation(Temp1, Temp2);

    //assert
    return assertArray(Temp.getArr(), TemEx,Temp.getSize(),5);
}
bool SetClass_test::setconsolidation_2()
{
    cout << "Тестируем метод setconsolidation" << endl;
    cout << "Сумма множеств [1,2,3] и []" << endl;
    
    //arrange
    int Tem1[50] = {1, 2, 3};
    Set Temp1(3, Tem1);
    int Tem2[50] = {};
    Set Temp2(0, Tem2);
    int Tem[50];
    Set Temp(0, Tem);
    int TemEx[50] = {1, 2, 3};

    //act
    Temp.setConsolidation(Temp1, Temp2);

    //assert
    return assertArray(Temp.getArr(), TemEx,Temp.getSize(),3);
}

bool SetClass_test::setsubstraction_1()
{
    cout << "Тестируем метод setsubstraction" << endl;
    cout << "Вычитание множеств [1,2,3] и [3,4,5]" << endl;
    
    //arrange
    int Tem1[50] = {1, 2, 3};
    Set Temp1(3, Tem1);
    int Tem2[50] = {3, 4, 5};
    Set Temp2(3, Tem2);
    int Tem[50];
    Set Temp(0, Tem);
    int TemEx[50] = {1, 2, 4, 5};

    //act
    Temp.setSubstraction(Temp1, Temp2);

    //assert
    return assertArray(Temp.getArr(), TemEx,Temp.getSize(),4);
}
bool SetClass_test::setsubstraction_2()
{
    cout << "Тестируем метод setsubstraction" << endl;
    cout << "Вычитание множеств [1,2,3] и [4,5]" << endl;
    
    //arrange
    int Tem1[50] = {1, 2, 3};
    Set Temp1(3, Tem1);
    int Tem2[50] = {4, 5};
    Set Temp2(2, Tem2);
    int Tem[50];
    Set Temp(0, Tem);
    int TemEx[50] = {1,2,3,4,5};

    //act
    Temp.setSubstraction(Temp1, Temp2);

    //assert    
    return assertArray(Temp.getArr(), TemEx,Temp.getSize(),5);
}

void SetClass_test::updateTestResult(bool passed)
{
    if (passed)
        ++(this->testPassed), cout << "Успех!" << endl << endl;
    else
        cout << "Неудача!" << endl << endl;
}

void SetClass_test::printTestResults()
{
    cout << "[Результаты тестирования Set Class] Тестов пройдено: " << testPassed << " из " << testTotal << endl;
}

void SetClass_test::run()
{
    cout << "Программа юнит-тестирования класса Set" << endl;
    cout << "Программист: Мустафин Радмир" << endl;
    cout << "Студент группы 1413 " << endl;

    cout << "Программа выводит результаты автоматического Unit-тестирования"<< endl<< endl;
    startTest();

    updateTestResult(isinset_1());
    updateTestResult(isinset_2());
    updateTestResult(additem_1());
    updateTestResult(deleteitem_1());
    updateTestResult(setintersection_1());
    updateTestResult(setintersection_2());
    updateTestResult(setconsolidation_1());
    updateTestResult(setconsolidation_2());
    updateTestResult(setsubstraction_1());
    updateTestResult(setsubstraction_2());

    printTestResults();
}
