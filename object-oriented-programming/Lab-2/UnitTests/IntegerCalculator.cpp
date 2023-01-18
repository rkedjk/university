#include "IntegerCalculator.h"

IntegerCalculator* IntegerCalculator::add(int num) 
{ 
	resetError(); 
	value += num; 
	
	return this; 
}

IntegerCalculator* IntegerCalculator::sub(int num) 
{ 
	resetError(); 
	value -= num; 
	
	return this; 
}

IntegerCalculator* IntegerCalculator::mul(int num) 
{ 
	resetError(); 
	value *= num; 
	
	return this; 
}

IntegerCalculator* IntegerCalculator::div(int num) 
{ 
	resetError();
	
	if(num == 0) // ���� �������� ����� 0, ������������� ���� ������
		hasErrors = true;
	else
		value /= num;	
		
	return this;
}
