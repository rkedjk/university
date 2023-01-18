/*
Лабораторная работа 1. Структуры и модули.
Цель работы: приобрести навык использования модулей в программе
и структур данных в языке С++
Программист: Мустафин Радмир Ренатович
Дата написания: 22.09.2022
*/
#include <iostream>
#include <string>
#include <stdlib.h>
#include "SetsOperator.h" // Подключение собственного модуля

int main()
{
    print("Программа 'Множества'\n");
    print("Разработчик - Мустафин Радмир Ренатович\n");
    print("Описание: Программа работает с множествами чисел.\n");
    print("Для начала работы необходимо создать хотя бы одно множество\n");
    print("Внимание: Максимальное допустимое количество множеств - 10. \n");
    print("Внимание: Максимальное допустимое количество элементов множества - 50. \n\n\n");
    int Option, SetOption, SetOptionT;
    int SetAmount = 0;
    Set SetsArray[10]; // Допустимое количество множеств - 10
    bool IsExit = false;
    while (!IsExit) // Условие выхода из программы
    {
        /*Пользовательское меню*/
        print("Текущее количество множеств - ");
        std::cout << SetAmount << std::endl;
        print("Выберите доступную опцию:\n");
        print("1 - Создать новое множество\n");
        print("2 - Определить принадлежность множеству\n");
        print("3 - Добавить элемент к множеству\n");
        print("4 - Удалить элемент из множества\n");
        print("5 - Создать множество, являющееся пересечением двух переданных множеств.\n");
        print("6 - Создать множество, являющееся объединением двух переданных множеств.\n");
        print("7 - Создать множество, являющееся вычитанием двух переданных множеств.\n");
        print("8 - Вывод множества\n");
        print("0 - Выход из программы\n");
        std::cin >> Option; 
        switch (Option) // Выбор необходимого действия
        {
        case 1: /*Создание нового множества*/
        {
            print("Введите размер множества\n");
            int size = 0;
            std::cin >> size;
            int InputArr[50];
            print("Введите элементы множества через пробел\n");
            for (int i = 0; i < size; i++)
            {
                std::cin >> InputArr[i]; //Ввод элементов в массив 
            }
            SetsArray[SetAmount] = createSet(InputArr, size);
            if (CheckSet(SetsArray[SetAmount]))
            {
                print("Заданное множество - ");
                displayset(SetsArray[SetAmount]);
                SetAmount = SetAmount + 1;
            }
            else
            {
                print("Введенное множество имеет более 50 элементов или повторяющиеся элементы, введите другие значения\n");
            }
            break;
        }
        case 2: /*Определить принадлежность множеству*/
        {
            print("Введите номер множества \n");
            std::cin >> SetOption;
            if ((SetOption > SetAmount) or (SetOption <=0))
            {
                print("Множества с таким номером не существует \n");
                break;
            }
            isInSet(SetsArray[SetOption - 1]);
            break;
        }

        case 3: /*Добавить элемент к множеству*/
        {
            print("Введите номер множества \n");
            std::cin >> SetOption;
            SetsArray[SetOption - 1] = addItem(SetsArray[SetOption - 1]);
            
            displayset(SetsArray[SetOption - 1]);
            break;
        }

        case 4: /*Удалить элемент из множества*/
        {
            print("Введите номер множества \n");
            std::cin >> SetOption;
            displayset(SetsArray[SetOption - 1]);
            SetsArray[SetOption - 1] = deleteItem(SetsArray[SetOption - 1]);
            displayset(SetsArray[SetOption - 1]);
            break;
        }

        case 5: /*Создать множество, являющееся пересечением двух переданных множеств.*/
        {
            print("Введите номер первого множества \n");
            std::cin >> SetOption;
            print("Введите номер второго множества \n");
            std::cin >> SetOptionT;
            SetsArray[SetAmount] = intersection(SetsArray[SetOption - 1], SetsArray[SetOptionT - 1]);
            displayset(SetsArray[SetAmount]);
            SetAmount += 1;
            break;
        }

        case 6: /*Создать множество, являющееся объединением двух переданных множеств.*/
        {
            print("Введите номер первого множества \n");
            std::cin >> SetOption;
            print("Введите номер второго множества \n");
            std::cin >> SetOptionT;
            SetsArray[SetAmount] = consolidation(SetsArray[SetOption - 1], SetsArray[SetOptionT - 1]);
            displayset(SetsArray[SetAmount]);
            SetAmount += 1;
            break;
        }

        case 7: /*Создать множество, являющееся вычитанием двух переданных множеств.*/
        {
            print("Введите номер первого множества \n");
            std::cin >> SetOption;
            print("Введите номер второго множества \n");
            std::cin >> SetOptionT;
            SetsArray[SetAmount] = substraction(SetsArray[SetOption - 1], SetsArray[SetOptionT - 1]);
            displayset(SetsArray[SetAmount]);
            SetAmount += 1;
            break;
        }

        case 8: /*Вывод множества*/
        {
            print("Введите номер множества \n");
            std::cin >> SetOption;
            displayset(SetsArray[SetOption - 1]);
            break;
        }

        case 0: /*Выход из программы*/
            IsExit = true;
            break;

        default: /*Сообщение об ошибке ввода*/
            print("Неверный ввод, попробуйте снова");
            break;
        }
    }
    return 0;
}