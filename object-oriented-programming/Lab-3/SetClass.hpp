#pragma once
#include <iostream>
#include <string>
#include "Object.hpp"


//Класс Set 
//Предназначен для работы со множествами
class Set : public Object
{
protected:
    //Массив содержащий элементы множества 
    int Arr[50];

    //Размер множества
    int Size;
    
    //Внутренний метод верификации множества
    //Проверяет множество на повторения
    //Сортирует множество если необходимо 
    //Удаляет последние элементы множества если его размер больше 50
    //Выводит информацию о возможных ошибках
    void verify();
public:
    //\brief Конструктор класса Set
    //\param size Размер множества
    //\param ArrIn Массив со значениями множества
    Set(int, int ArrIn[]);

    //Сеттер размера множества
    //\param size Измененный размер множества
    void setSize(int);

    //Геттер размера множества 
    //\return Размер множества в int
    int getSize();

    //Сеттер массива элементов множества 
    //\param InArr[50] Массив элементов множества
    void setArr(int InArr[50]);
    
    //Геттер массива элементов множества
    //\return Массив элементов множества
    int* getArr();

    //Сеттер конкретного элемента множества
    //\param ord Порядковый номер элемента в массиве
    //\param num Значение элемента в массиве
    void setArrItem(int ord,int num);

    //Геттер конкретного элемента множества
    //\param ord Порядковый номер элемента в массиве
    //\return Значение элемента в массиве
    int getArrItem(int ord);

    //Метод поиска элемента
    //\param target Значение искомого элемента
    //\return Если элемент есть во множестве - True, иначе False
    bool isInSet(int target);

    //Перегрузка оператора +
    //Метод добавления элемента к множеству
    //\param newItem Значение нового элемента множества
    void operator+(int newItem);

    //Метод генерации множества из случайных значений в указанных пределах
    //\param leftEdge Левая граница генерации значений
    //\param rightEdge Правая границ генерации значений
    //\return Новое множество
    Set generateSet(int leftEdge, int rightEdge);



    
    //Метод удаления элемента из множества
    //\param itemOrd Порядковый номер удаляемого элемента
    void operator-(int itemOrd);

    //Метод создания нового множества путем пересечения двух множеств
    //\param First Первое множество
    //\param Second Второе множество
    void setIntersection(Set &First, Set &Second);

    //Метод создания нового множества путем объединения двух множеств
    //\param First Первое множество
    //\param Second Второе множество
    void setConsolidation(Set &First, Set &Second);

    //Метод создания нового множества путем вычисления двух множеств
    //\param First Первое множество
    //\param Second Второе множество
    void setSubstraction(Set &First, Set &Second);
      
    //Метод вывода информации о множестве
    void setDisplay();
};
