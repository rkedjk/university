
#include <iostream>
#include <string>
#include "SetClass.hpp"
using namespace std;

Set::Set(int size, int ArrIn[50])
{
    addOp("Created");
    setSize(size);
    for (int i = 0; i < this->Size; i++)
    {
        setArrItem(i, ArrIn[i]);
    };
};

void Set::verify()
{
    if ((this->Size) > 50)
    {
        cout << "Внимание: Размер множества превышает допустимое значение, лишние элементы не будут обрабатываться" << endl;
    }

    bool isSorted = true;
    for (int i = 1; i < this->Size; i++)
    {
        if ((this->Arr[i]) < (this->Arr[i - 1]))
        {
            isSorted = false;
            cout << "Значения множества буду отсортированы" << endl;
            break;
        }

        if (!isSorted)
        {
            int j = 0;
            int tmp = 0;
            for (int i = 0; i < this->Size; i++)
            {
                j = i;
                for (int k = i; k < this->Size; k++)
                {
                    if (this->Arr[j] > this->Arr[k])
                    {
                        j = k;
                    }
                }
                tmp = this->Arr[i];
                this->Arr[i] = this->Arr[j];
                this->Arr[j] = tmp;
            }
        }

        for (int i = 1; i<this->Size; i++){
            if (this->Arr[i]=this->Arr[i-1]){
                this-i;
            }
        }
    }
}
void Set::setSize(int size)
{
    this->Size = size;
};
int Set::getSize()
{
    return this->Size;
};
// Сеттер всего массива множества
void Set::setArr(int InArr[50])
{
    for (int i = 0; i < 50; i++)
    {
        Arr[i] = InArr[i];
    };
};

int *Set::getArr()
{
    return this->Arr;
};

void Set::setArrItem(int ord, int num)
{
    this->Arr[ord] = num;
};
int Set::getArrItem(int ord)
{
    return this->Arr[ord];
};

bool Set::isInSet(int target)
{
    bool IsIn = false;
    for (int i = 0; i < this->Size; i++)
    {
        if (this->Arr[i] == target)
        {
            IsIn = true;
            break;
        }
    }
    return IsIn;
};
void Set::operator+(int newItem)
{
    addOp("Added item");
    this->Size += 1;
    this->Arr[this->Size - 1] = newItem;
};

void Set::operator-(int itemOrd)
{
    addOp("Deleted Item");
    for (int i = itemOrd - 1; i < this->Size; i++)
    {
        this->Arr[i] = this->Arr[i + 1];
    }
    this->Size -= 1;
};
void Set::setIntersection(Set &First, Set &Second)
{
    addOp("Created Set By Intersection");
    for (int i = 0; i < First.getSize(); i++)
    {
        for (int j = 0; j < Second.getSize(); j++)
        {
            if (First.getArrItem(i) == Second.getArrItem(j))
            {
                this->Arr[this->Size] = First.getArrItem(i);
                this->Size += 1;
            }
        }
    }
};
void Set::setConsolidation(Set &First, Set &Second)
{
    addOp("Created Set By Consolidation");
    this->Size = 0;
    for (int i = 0; i < First.getSize(); i++)
    {
        this->Arr[i] = First.getArrItem(i);
        this->Size += 1;
    }
    for (int i = 0; i < Second.getSize(); i++)
    {
        bool repeat = false;
        for (int j = 0; j < this->Size; j++)
        {
            if (Second.getArrItem(i) == this->Arr[j])
            {
                repeat = true;
            }
        }
        if (!repeat)
        {
            this->Arr[this->Size] = Second.getArrItem(i);
            this->Size += 1;
        }
    }
};

void Set::setSubstraction(Set &First, Set &Second)
{
    addOp("Created Set By Substraction");
    this->Size = 0;
    for (int i = 0; i < First.getSize(); ++i)
    {
        bool repeat = false;
        for (int j = 0; j < Second.getSize(); ++j)
        {
            if (First.getArrItem(i) == Second.getArrItem(j))
            {
                repeat = true;
            }
        }
        if (!repeat)
        {
            this->setArrItem(this->getSize(), First.getArrItem(i));
            this->setSize(this->getSize() + 1);
        }
    }
    for (int i = 0; i < Second.getSize(); ++i)
    {
        bool repeat = false;
        for (int j = 0; j < First.getSize(); ++j)
        {
            if (Second.getArrItem(i) == First.getArrItem(j))
            {
                repeat = true;
            }
        }
        if (!repeat)
        {
            this->setArrItem(this->getSize(), Second.getArrItem(i));
            this->setSize(this->getSize() + 1);
        }
    }
};
void Set::setDisplay()
{
    addOp("Set Displayed");
    std::cout << "(";
    std::cout << this->getArrItem(0);
    for (int i = 1; i < this->getSize(); i++)
    {
        std::cout << ",";
        std::cout << this->getArrItem(i);
    }
    std::cout << ") [";
    std::cout << this->getSize();
    std::cout << "]\n\n";
};

Set Set::generateSet(int low, int high){
    
	int Tem[50];
	//Счётчики циклов
	srand(time(NULL));
	for (int i = 0;i < 11; i++){
			Tem[i] = int(rand() % int(high*100))/100 + low;
	}

    Set Temp(10,Tem);
	Temp.addOp("Created Set By Random Generation");
	return Temp;

}
