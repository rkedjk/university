#include "SetClass.hpp"

class SetClass_test {
    //Общее количество тестов
    const int testTotal = 15;

    //Количество пройденных тестов
    int testPassed = 0;

    //Метод сравнения результата теста с ожидаемым результатом 
    //Предназначен для методов которые выдают булевое значения 
    //\param actual Результат тестируемого метода
    //\param expected Ожидаемый результат метода
    //\return Если тест пройден - True, иначе - False
    bool assertBool(bool actual, bool expected);

    //Метод сравнения результата теста с ожидаемым результатом 
    //Предназначен для методов которые изменяют множества
    //\param actual[50] Результат-массив тестируемого метода
    //\param expected[50] Ожидаемый результат метода
    //\param actualsize Результат-размер тестируемого метода
    //\param expectedsize Ожидаемый-размер результат метода
    //\return Если тест пройден - True, иначе - False
    bool assertArray(int actual[50], int expected[50],int actualsize,int expectedsize);


    bool assertValue(int actual, int expected);

    //Тест 1 метода IsInSet
    bool isinset_1();

    //Тест 2 метода IsInSet
    bool isinset_2();

    //Тест 1 метода Additem
    bool additem_1();

    //Тест 1 метода Deleteitem
    bool deleteitem_1();

    //Тест 1 метода setIntersection
    bool setintersection_1();

    //Тест 2 метода setIntersection
    bool setintersection_2();

    //Тест 1 метода setConsolidation
    bool setconsolidation_1();

    //Тест 2 метода setconsolidation
    bool setconsolidation_2();

    //Тест 1 метода setSubstraction
    bool setsubstraction_1();

    //Тест 2 метода setSubstraction
    bool setsubstraction_2();


    bool addOperationCreate();
	bool addOperationAdd();
	bool addOperationMul();
	bool createdCount();
	bool activeCount();


    //Метод обнуления счётчика пройденных тестов
	void startTest() { testPassed = 0; }

    //Обновление результатов тестировани
	void updateTestResult(bool passed);	
	
    //вывести результаты тестов в консоль
	void printTestResults();

public:
	
	//Запустить юнит-тестирование класса SetClass
	void run();		
};    
