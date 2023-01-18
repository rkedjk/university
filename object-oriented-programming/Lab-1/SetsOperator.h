#include <iostream>
#include <string>

#pragma once

typedef struct 
{
    /*Структура данных множества. Ограничена размером в 50 элементов.*/
    int NumArr[50];
    int size; //Переменная размера множества
} Set;

void swap(int a, int b) //Функция обмена числами. Необходима для сортировки.
{
    int c = a;
    a = b;
    b = c;
}
void bubbleSort(int list[], int listLength) //Сортировка пузырьком.
{
    while (listLength--)
    {
        bool swapped = false;

        for (int i = 0; i < listLength; i++)
        {
            if (list[i] > list[i + 1])
            {
                swap(list[i], list[i + 1]);
                swapped = true;
            }
        }

        if (swapped == false)
            break;
    }
}

void print(std::string string) //Вспомогательная функция вывода в консоль
{
    std::cout << string;
}

bool CheckSet(Set set) //Проверка корректности данных в множестве
{
    bool Check = true;
    if (set.size > 50) //Проверка размера множества
    {
        Check = false;
    }
    for (int i = 0; i < set.size; i++)
    {
        for (int j = 1; j < set.size; j++)
        {
            if (set.NumArr[i] == set.NumArr[j])
            {
                Check = false; //Проверка повторяемости элементов множества
            }
        }
        if (Check = true)
        {
            bubbleSort(set.NumArr, set.size); //Сортировка множества
        }
    }
    return (Check);

}

/*Создание множества и присвоение значений из переданного массива*/
Set createSet(int Array[], int size)
{
    Set set;
    set.size = size; //Передача размера

    for (int i = 0; i < set.size; i++)
    {
        set.NumArr[i] = Array[i];
    }
    return set;
}

/*Проверка существования элемента в множестве*/
void isInSet(Set set)
{
    int ToFind;
    print("Введите число\n");
    std::cin >> ToFind;
    bool IsIn = false;
    for (int i = 0; i < set.size; i++)
    {
        if (set.NumArr[i] == ToFind)
        {
            IsIn = true;
            break;
        }
    }
    /*Функция выводит результат не передавая значения в основной файл программы*/
    if (IsIn)
    {
        print("Число принадлежит заданному множеству\n\n");
    }
    else
    {
        print("Число не принадлежит заданному множеству\n\n");
    }
};

/*Добавление элементов во множество*/
Set addItem(Set set)
{
    set.size += 1; //Корректировка размера
    print("Введите новый элемент\n");
    std::cin >> set.NumArr[set.size - 1]; //Ввод элемента
    return set;
}

/*Удаление элемента из множества*/
Set deleteItem(Set set)
{
    print("Введите номер удаляемого элемента\n");
    int Num;
    std::cin >> Num;//Ввод номера элемента
    for (int i = Num - 1; i < set.size; i++)
    {
        set.NumArr[i] = set.NumArr[i + 1];
    }
    set.size -= 1;//Корректировка размера
    return set;
};

/*Функция пересечения множеств*/
/*Передает новое множество как результат*/
Set intersection(Set setOne, Set setTwo) 
{
    Set set;
    set.size = 0;
    for (int i = 0; i < setOne.size; i++)
    {
        for (int j = 0; j < setTwo.size; j++)
        {
            if (setOne.NumArr[i] == setTwo.NumArr[j])
            {

                set.NumArr[set.size] = setOne.NumArr[i];
                set.size += 1;
            }
        }
    }
    return set;
};

/*Функция объединения множеств*/
/*Передает новое множество как результат*/
Set consolidation(Set setOne, Set setTwo)
{
    Set set;
    set.size = 0;
    for (int i = 0; i < setOne.size; i++)
    {
        set.NumArr[i] = setOne.NumArr[i];
        set.size += 1;
    }
    for (int i = 0; i < setTwo.size; i++)
    {
        bool repeat = false;
        for (int j = 0; j < set.size; j++)
        {
            if (setTwo.NumArr[i] == set.NumArr[j])
            {
                repeat = true;
            }
        }
        if (!repeat)
        {
            set.NumArr[set.size] = setTwo.NumArr[i];
            set.size += 1;
        }
    }
    return set;
};

/*Функция вычитания множеств*/
/*Передает новое множество как результат*/
Set substraction(Set setOne, Set setTwo)
{
    Set set;
    set.size = 0;
    for (int i = 0; i < setOne.size; i++)
    {
        bool repeat = false;
        for (int j = 0; j < setTwo.size; j++)
        {
            if (setOne.NumArr[i] == setTwo.NumArr[j])
            {
                repeat = true;
            }
        }
        if (!repeat)
        {
            set.NumArr[set.size] = setOne.NumArr[i];
            set.size += 1;
        }
    }
    for (int i = 0; i < setTwo.size; i++)
    {
        bool repeat = false;
        for (int j = 0; j < setOne.size; j++)
        {
            if (setTwo.NumArr[i] == setOne.NumArr[j])
            {
                repeat = true;
            }
        }
        if (!repeat)
        {
            set.NumArr[set.size] = setTwo.NumArr[i];
            set.size += 1;
        }
    }

    return set;
};

/*Вывод множества*/
void displayset(Set CurrentSet)
{
    print("(");
    std::cout << CurrentSet.NumArr[0];
    for (int i = 1; i < CurrentSet.size; i++)
    {
        print(",");
        std::cout << CurrentSet.NumArr[i];
    }
    print(") [");
    std::cout << CurrentSet.size;
    print("]\n\n");
}