#pragma once

class IntegerCalculator_Test
{
	const int testTotal = 7; // ����� ������
	int testPassed = 0; // ������� ������ ��������
		
	// ��������� �����:	
		
	bool clear_8set_0Result();
	bool add_5add7_12Result();
	bool sub_10sub6_4Result();
	bool mul_5mul8_40Result();
	bool div_10div2_5Result();
	bool div_10div0_Error();
	bool exprCalc_5add7sub2mul9div2_45Result();
	
	
	//�������� ������� ���������� ������
	void startTest() { testPassed = 0; }
	//��������� �������� �����
	bool assertValue(int actual, int expected);
	// ������� �����\������� ����� � �������� testPassed
	void updateTestResult(bool passed);	
	 //������� ���������� ������ � �������
	void printTestResults();
	
public:
	
	//��������� ����-������������ ������ IntegerCalculator
	void run();		
};
