#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

float compute_addition(float, float);
float compute_subtraction(float, float);
float compute_multiplication(float, float);
float compute_division(float, float);
void read_values_from_keyboard(float *, float *);

int main(void)
{
	float result,x,y;
	char operation;
	
	read_values_from_keyboard(&x,&y);
	
	printf("Please enter the operation type: + - * /\n");
	scanf("\n%c", &operation);
	
	switch(operation)
	{
		case '+':	result=compute_addition(x,y);
					printf("Addition = %.3f",result);
					break;
	
		case '-':	result=compute_subtraction(x,y);
					printf("Subtraction = %.3f",result);
					break;
		
		case '*':	result=compute_multiplication(x,y);
					printf("Multiplication = %.3f",result);
					break;
					
		case '/':	result=compute_division(x,y);
					printf("Quotient = :%.3f",result);
					break;				
	}
	
	return 0;
}


void read_values_from_keyboard(float *a, float *b)
{
	printf("Please enter 2 values:\n");
	scanf("%f%f",a,b);
}

float compute_addition(float x,float y)
{
	return x+y;
}

float compute_subtraction(float x,float y)
{
	return x-y;
}

float compute_multiplication(float x,float y)
{
	return x*y;
}

float compute_division(float x,float y)
{
	return x/y;
}

