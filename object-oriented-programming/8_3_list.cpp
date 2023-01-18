#include <iostream> 


//���������� �������� ������
#include <list>

using namespace std;

void printVals(const list<int>& lst)
{
	for(auto& item : lst)
		cout << item << " ";
	cout << endl;
}

int main(int argc, char** argv) 
{
	system("chcp 1251");

	//������������� ������
	list<int> list1;             	 // ������ ������
	list<int> list2(5);          	 // list2 ������� �� 5 �����, ������ ������� ����� �������� �� ���������
	list<int> list3(5, 2);           // list3 ������� �� 5 �����, ������ ����� ����� 2
	list<int> list4{ 1, 2, 4, 5 };   // list4 ������� �� ����� 1, 2, 4, 5
	list<int> list5 = { 1, 2, 3, 5 };// list5 ������� �� ����� 1, 2, 4, 5
	list<int> list6(list5);          // list6 - ����� ������ list5
	list<int> list7 = list6;         // list7 - ����� ������ list6
	
	/*
	� list ��� ������� ������� � �������� �� ������� at()
	����� ���������� ������ � ������� ��� ���������� �������� ����� front() � back().
	��� ������� � ��������� � �������� ����� ���������� ��������
	� ������� ������ � ����������
	*/
	std::list<int> numbers = { 11, 22, 33, 44, 55 };
    int first = numbers.front();  // 11
    int last = numbers.back();  // 55
    //������� ����������
    for (auto iter = numbers.begin(); iter != numbers.end(); iter++)
        cout << (*iter) << " ";
    cout << endl;
    //������� ������
    for (int n : numbers)
        cout << n << " ";
    cout << endl << endl;
    
    /* ������� ������� ��� list ���������� �������:
    size() empty() resize() assign() swap() push_back() pop_back() 
	insert() clear() erase()
    */
    
    /* ����� � list ��������� ������ �� ������ � ������ ���������
    pop_front() - ������� ������ ������� ������
    push_front(val) - �������� val � ������ ������
    */
    printVals(numbers);
    numbers.pop_front();
    printVals(numbers);
    numbers.push_front(999);
    printVals(numbers);
	
	return 0;
}

