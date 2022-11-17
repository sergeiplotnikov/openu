#include <stdio.h>
#include <stdlib.h>
#include "rottate.h"

#define MAX_64BIT_UINT_LENGTH_HEXA 16
#define MAX_64BIT_UINT_LENGTH_DECIMAL 20
#define MAX_64BIT_UINT_LENGTH_OCTAL 22
#define MAX_64BIT_UINT_LENGTH_BINARY 64
#define TRUE 1
#define FALSE 0

void processInput(char *numStr, char *rottStr);
int NumberStringIsValid(char *str);
int RottaionStringIsValid(char *str);
void PromptForNumberString(char *numBuffer, int bufferSize);
void PromptForRottationString(char *rottBuffer, int bufferSize);
void PromptForInputString(char *Buffer, int bufferSize);
void PrintlNumber(unsigned int number);
void PrintBinary(unsigned int number);
void PrintOctal(unsigned int number);
void PrintHexa(unsigned int number);
void NumberToString(unsigned int number, char *buffer, int bufferSize, int radix);
void FlipString(char *str);

int main(int argc, char **argv)
{
	if (argc < 3)
	{
		processInput(NULL, NULL);
	}
	else{
		processInput(*(argv + 1), *(argv + 2));
	}
	
	return 0;
}

void processInput(char *numStr, char *rottStr)
{
	unsigned int inputNumber = 0;
	int rottations = 0;
	unsigned int rottatedNumber = 0;
	char numBuffer[MAX_64BIT_UINT_LENGTH_DECIMAL + 1];
	char rottBuffer[MAX_64BIT_UINT_LENGTH_DECIMAL + 2];
	if (NULL == numStr)
	{
		PromptForNumberString(numBuffer, sizeof(numBuffer));
		numStr = numBuffer;
		PromptForRottationString(rottBuffer, sizeof(rottBuffer));
		rottStr = rottBuffer;
	}

	if (FALSE == NumberStringIsValid(numStr))
	{
		printf("Provided number-input is not a valid number. Terminating execution.\n");
		return;
	}
	if (FALSE == RottaionStringIsValid(rottStr))
	{
		printf("Provided rottation-input is not a valid number. Terminating execution.\n");
		return;
	}

	inputNumber = atoi(numStr);
	rottations = atoi(rottStr);

	printf("The provided number in Decimal:   %32u", inputNumber);
	PrintlNumber(inputNumber);

	rottatedNumber = my_rottate(inputNumber, rottations);

	printf("The 'rottated' number in Decimal: %32u", rottatedNumber);
	PrintlNumber(rottatedNumber);
}	

int NumberStringIsValid(char *str)
{
	return TRUE;
}

int RottaionStringIsValid(char *str)
{
	return TRUE;
}

void PromptForNumberString(char *numBuffer, int bufferSize)
{
	unsigned int maxUIntValue = -1;

	printf("Please enter an integer in the range of [0,%u]\n", maxUIntValue);
	PromptForInputString(numBuffer, bufferSize);
}

void PromptForRottationString(char *rottBuffer, int bufferSize)
{
	unsigned int maxUIntValue = -1;

	printf("Please enter a number of rotations in the range of [-%u,%u].\n", maxUIntValue/2 + 1, maxUIntValue/2);
	printf("Negative number for left-rottation, positive for right-rottation.\n");
	PromptForInputString(rottBuffer, bufferSize);
}

void PromptForInputString(char *buffer, int bufferSize)
{
	char *bufferEnd = buffer + bufferSize - 1;
	int stringTerminated = FALSE;

	while ((buffer != bufferEnd) && (FALSE == stringTerminated))
	{
		*buffer = getchar();
		if ('\n' == *buffer)
		{
			*buffer = '\0';
			stringTerminated = TRUE;
		}
		++buffer;
	}
	*buffer = '\0';
}

void PrintlNumber(unsigned int number)
{
	printf("\nIn Binary: ");
	PrintBinary(number);
	printf("\nIn Octal: ");
	PrintOctal(number);
	printf("\nIn Hexadecimal: ");
	PrintHexa(number);
	printf("\n");
}

void PrintBinary(unsigned int number)
{
	char buffer[MAX_64BIT_UINT_LENGTH_BINARY + 1];	
	NumberToString(number, buffer, (sizeof(number) * 8) + 1, 2);
	printf("%64s", buffer);
}

void PrintOctal(unsigned int number)
{
	char buffer[MAX_64BIT_UINT_LENGTH_OCTAL + 1];	
	NumberToString(number, buffer, sizeof(buffer), 8);
	printf("%32s", buffer);
}

void PrintHexa(unsigned int number)
{
	char buffer[MAX_64BIT_UINT_LENGTH_HEXA + 1];	
	NumberToString(number, buffer, sizeof(buffer), 16);
	printf("%16s", buffer);
}

void NumberToString(unsigned int number, char *buffer, int bufferSize, int radix)
{
	char *current = buffer;
	char *bufferEnd = buffer + bufferSize - 1;
	int mod = 0;
	do
	{
		mod = number % radix;
		*current = (mod < 10 ? '0' + mod :  mod - 10 + 'A');
		number /= radix;
		++current;
	} while(number);
	while (current != bufferEnd)
	{
		*current = '0';
		++current;
	}
	*current = '\0';
	FlipString(buffer);
}

void FlipString(char *str)
{
	char *tail = str;
	char *head = str;

	while('\0' != *head)
	{
		++head;
	}
	--head;

	while (head > tail)
	{
		*tail ^= *head;
		*head ^= *tail;
		*tail ^= *head;
		--head;
		++tail;
	}
}
