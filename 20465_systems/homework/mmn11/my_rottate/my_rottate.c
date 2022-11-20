#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "rottate.h"

#define MAX_64BIT_UINT_LENGTH_HEXA 16
#define MAX_64BIT_UINT_LENGTH_DECIMAL 20
#define MAX_64BIT_UINT_LENGTH_OCTAL 22
#define MAX_64BIT_UINT_LENGTH_BINARY 64
#define TRUE 1
#define FALSE 0

/*
 *	ParseStdinArgsAndRun:
 *		Receives the argc and argv params from 'main'.
 *		If two strings were passed on STDIN, the pointers will be passed to
 *		'ProcessInput'. Otherwise NULL pointers will be passed.
 *	arguments:
 *		argc = 'argc' from 'main' - number of arguments passed from STDIN.
 *		argv = 'argv' from **char pointing to STDIN arguments, 'argc' in total.
 *	return:
 *		void
 *	complexity:
 *		complexity of 'ProcessInput'
 */
void ParseStdinArgsAndRun(int argc, char **argv);

/*
 *	ProcessInput:
 *		Receives two pointers to char arrays. If the 1st one is NULL, prompts
 *		the user to enter two string, the 1st representing a non negative number
 *		and the 2nd representing the number and direction of rottations.
 *		Negative for left, positive for right. Both prompts ask to the user
 *		to limit the input to certain ranges.
 *		The function converts the string to numbers, prints the number before
 *		rottation in the binary, octal, decimal and hexadecimal forms.
 *		The number is then rottated and printed again in the 4 bases.
 *	arguments:
 *		numStr = string representing the number to be rottated
 *		rottStr = string representing the number of rottations (+direction).
 *	return:
 *		void
 *	complexity:
 *		time complexity of my_rottate
 *		space complexity of O(1) - allocated buffers are of hardcoded size
 *	assumptions:
 *		the user must provide strings parsable by 'atoi' of <stdlib.h>,
 *		representing numbers in the stated range:
 *			valid uint value for the number
 *			valid int value for rottations
 *		failure to meet these constraints results in undefined behavior
 */
void ProcessInput(char *numStr, char *rottStr);

/*
 *	PromptForNumberString:
 * 		Display a message asking the user to enter a number in a specific range.
 * 		Run 'PromptForInputString' provide it with a buffer and buffer size.
 * 	arguments:
 * 		numBuffer = a buffer to store the users input for the number to be
 * 		'rottated'
 * 		bufferSize = the size of the buffer above
 * 	return:
 * 		void
 * 	complexity:
 * 		time complexity of 'PromptForInputString'
 * 		space complexity of O(1) - buffer provided not allocated
 */
void PromptForNumberString(char *numBuffer, int bufferSize);

/*
 *	PromptForRottationString:
 * 		Display a message asking the user to enter a number in a specific range.
 * 		Run 'PromptForInputString' provide it with a buffer and buffer size.
 * 	arguments:
 * 		numBuffer = a buffer to store the users input for the number of
 * 		rottations (+direction)
 * 		bufferSize = the size of the buffer above
 * 	return:
 * 		void
 * 	complexity:
 * 		time complexity of 'PromptForInputString'
 * 		space complexity of O(1) - buffer provided not allocated
 *
 */
void PromptForRottationString(char *rottBuffer, int bufferSize);

/*
 *	PromptForInputString:
 *		Reads users input from STDIN into the provided buffer. If imput exceeds
 *		buffer size, it will be truncated to fit the buffer. If a newline or EOF
 *		character is encountered, the string will be terminated before the
 *		character (by '\0').
 *	arguments:
 *		buffer - a buffer to hold users input
 *		bufferSize - size of buffer above
 *	return:
 *		void
 *	complexity:
 *		time O(1) reads tp buffer limited by hardcoded size
 *		space O(1) buffer is provided not allocated
 */
void PromptForInputString(char *buffer, int bufferSize);

/*
 *	PrintNumber:
 *		Prints the provided number in binary, ocatl and hexadecimal bases
 *	arguments:
 *		number - the number to be printed in the 3 bases above
 *	return:
 *		void
 *	complexity
 *		time complexity - max time complexity of the 3 helper functions it
 *		calls: PrintBinary, PrintOctal, PrintHexa
 *		space complexity O(1)
 */
void PrintlNumber(unsigned int number);

/*
 *	PrintBinary:
 *		Prints the binary form of a number to STDOUT
 *	arguments:
 *		number - the number to be printed in binary
 *	return:
 *		void
 *	complexity:
 *		time complexity of 'NumberToString'
 *		space complexity of O(1) - buffer size is hardcoded
 */
void PrintBinary(unsigned int number);

/*
 *	PrintOctal:
 *		Prints the octal form of a number to STDOUT
 *	arguments:
 *		number - the number to be printed in octal
 *	return:
 *		void
 *	complexity:
 *		time complexity of 'NumberToString'
 *		space complexity of O(1) - buffer size is hardcoded
 */
void PrintOctal(unsigned int number);

/*
 *	PrintHexa:
 *		Prints the hexadecimal form of a number to STDOUT
 *	arguments:
 *		number - the number to be printed in hexadecimal
 *	return:
 *		void
 *	complexity:
 *		time complexity of 'NumberToString'
 *		space complexity of O(1) - buffer size is hardcoded
 */
void PrintHexa(unsigned int number);

/*
 *	NumberToString:
 * 		Receives a number, a buffer with its size and a radix.
 * 		The form of the number according to the radix(base) is stored in the
 * 		buffer.
 * 	arguments:
 * 		number - number for which a string is created, according to radix
 * 		buffer - used to hold the created string
 * 		bufferSize - the size of the buffer above
 * 		radix - the base for the string-number
 * 	assumptions:
 * 		radix is between 2 and 36.
 */
void NumberToString(unsigned int number, char *buffer, int bufferSize, int radix);

/*
 *	FlipString:
 *		flips the content of a char array, except the terminator:
 *		for example "abcde" becomes "edcba"
 *	arguments:
 *		str - pointer to char array
 *	return:
 *		void
 *	complexity:
 *		time O(n) where n is array length
 *		space O(1)
 */
void FlipString(char *str);

int main(int argc, char **argv)
{
	ParseStdinArgsAndRun(argc, argv);
	return 0;
}

void ParseStdinArgsAndRun(int argc, char **argv)
{
	if (argc < 3)
	{
		ProcessInput(NULL, NULL);
	}
	else{
		ProcessInput(*(argv + 1), *(argv + 2));
	}
}

void ProcessInput(char *numStr, char *rottStr)
{
	/* will hold the number to be rottated */
	unsigned int inputNumber = 0;

	/* will hold the number+direction of rattations */
	int rottations = 0;

	/* will hold the resulting rottated number */
	unsigned int rottatedNumber = 0;

	/* buffer to hold user input for the number, if prompted */
	char numBuffer[MAX_64BIT_UINT_LENGTH_DECIMAL + 1];

	/* buffer to hold user input for rottations, if prompted */
	char rottBuffer[MAX_64BIT_UINT_LENGTH_DECIMAL + 2];

	if (NULL == numStr)
	{
		PromptForNumberString(numBuffer, sizeof(numBuffer));
		numStr = numBuffer;
		PromptForRottationString(rottBuffer, sizeof(rottBuffer));
		rottStr = rottBuffer;
	}

	inputNumber = atoi(numStr);
	rottations = atoi(rottStr);

	printf("The provided number in Decimal:   %32u, rottations: %d", inputNumber, rottations);
	PrintlNumber(inputNumber);

	rottatedNumber = my_rottate(inputNumber, rottations);

	printf("The 'rottated' number in Decimal: %32u", rottatedNumber);
	PrintlNumber(rottatedNumber);
}	

void PromptForNumberString(char *numBuffer, int bufferSize)
{
	printf("Please enter an integer in the range of [0,%u]\n", UINT_MAX);
	PromptForInputString(numBuffer, bufferSize);
}

void PromptForRottationString(char *rottBuffer, int bufferSize)
{
	printf("Please enter a number of rotations in the range of [-%u,%u].\n", INT_MIN, INT_MAX);
	printf("Negative number for left-rottation, positive for right-rottation.\n");
	PromptForInputString(rottBuffer, bufferSize);
}

void PromptForInputString(char *buffer, int bufferSize)
{
	/* pointer used to iterate over the buffer and populate it */
	char *current = buffer;

	/* pointer to last byte of buffer, to prevent overflow */
	char *bufferEnd = buffer + bufferSize - 1;

	/* initiated to FALSE. if assigned TRUE, loop execution stops */
	int stringTerminated = FALSE;

	while ((current != bufferEnd) && (FALSE == stringTerminated))
	{
		*current = getchar();
		if ('\n' == *current)
		{
			*current = '\0';
			stringTerminated = TRUE;
		}
		++current;
	}
	*current = '\0';
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
	/* buffer to hold result of NumberToString */
	char buffer[MAX_64BIT_UINT_LENGTH_BINARY + 1];	

	NumberToString(number, buffer, (sizeof(number) * 8) + 1, 2);
	printf("%64s", buffer);
}

void PrintOctal(unsigned int number)
{
	/* buffer to hold result of NumberToString */
	char buffer[MAX_64BIT_UINT_LENGTH_OCTAL + 1];	

	NumberToString(number, buffer, sizeof(buffer), 8);
	printf("%32s", buffer);
}

void PrintHexa(unsigned int number)
{
	/* buffer to hold result of NumberToString */
	char buffer[MAX_64BIT_UINT_LENGTH_HEXA + 1];	

	NumberToString(number, buffer, sizeof(buffer), 16);
	printf("%16s", buffer);
}

void NumberToString(unsigned int number, char *buffer, int bufferSize, int radix)
{
	/* pointer used to iterate over buffer and populate it */
	char *current = buffer;

	/* pointer to last byte of buffer, used to prevent overflow */
	char *bufferEnd = buffer + bufferSize - 1;

	/* result of modulo operation */
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
	/* pointer that will run backwards from the end of the string */
	char *tail = str;

	/* pointer that will run forwards from teh begining of the string */
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
