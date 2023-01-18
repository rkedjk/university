#pragma once


/*
	����� IntegerCalculator - ������� ���������� �������������� ������������.
	��������� ����������, ��������, �������� � ������ ����� ����� (� ����������� ���������� ����������). 
*/

class IntegerCalculator
{
	int value = 0; //������� �������� ������������
	bool hasErrors = false; //����, ������������ ���� �� ������ ����� ���������� ��������
public:
	
	IntegerCalculator(int value = 0) // value - ����� ������ ��������� �������� ������������
	{
		this->value = value;
	}
	
	//�������� �������� ������������ (����� ������ ����� ��������� ���� ������ ������������)
	void clear() { resetError(); setValue(0); }

	//���������� ������� �������� ������������
	void setValue(int value) { this->value = value; }
	//�������� ������� �������� ������������
	int getValue() { return value; }
	
	//�������� ���� ������ ��������� ��������
	bool getLastError() { return hasErrors;	}
	//�������� ���� ������
	void resetError() { hasErrors = false;	}
	
	//���������� �������� ��������. ������������ ��� ������ ������������ ���
	//������������� ������� �������
	IntegerCalculator* add(int num);
	
	//���������� �������� ���������
	IntegerCalculator* sub(int num);
	
	//���������� �������� ���������
	IntegerCalculator* mul(int num);
	
	//���������� �������� ������� (����� �������� ���� ������!)
	IntegerCalculator* div(int num);

};
