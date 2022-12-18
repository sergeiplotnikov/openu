#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "my_bytecompare.h"

#define TRUE 1
#define FALSE 0

#define REQUIRED_PARAMS 4
#define EXECUTALBE_NAME 1
#define MIN_INPUT_PARAMS (REQUIRED_PARAMS + EXECUTALBE_NAME)

/*
 *	buffer size for all 4 parameters:
 *		text block = 512
 *		len + 1st + 2nd = 3*3
 *		4 whitespace streaks before each param = 4*10
 *		1 string terminator
 *			==> total: 562 ~ 600
 */
#define INPUT_BUFF_SIZE 600 /* includes terminator */
#define INPUT_BUFF_SIZE_S "599" /* used in scanf, MUST no include terminator */

#define ERR_MSG_BUFF_SIZE 120

/*
 *	ParseStdinArgsAndRun:
 *		Receives the arc and argv params from 'main'.
 *		If the proper amoutn of arguments was passed the program uses them
 *		instead of checking stdin.
 *	arguments:
 *		argc = 'argc' from 'main' - number of arguments passed from executable.
 *		argv = 'argv' from **char pointing to executable arguments,
 *		'argc' in total.
 *	returns:
 *		int - result of 'my_bcmp' if input is valid, 1 otherwise
 */
int ParseStdinArgsAndRun(int argc, char **argv);

int main(int argc, char **argv)
{
	return ParseStdinArgsAndRun(argc, argv);
}

/*
 *	PromptForInput:
 *		Displays instructions for the user on how to provide the input.
 *	arguments:
 *		buffer - a buffer to save the users input
 *	returns:
 *		void
 */
void PromptForInput(char *buffer);

/*
 *	TokenizeInput:
 *		"Breaks up" input by whitespace characters and assigns the provided
 *		pointers to different locations on the input block where the proper
 *		argument string begins. The function sets the pointers so that they
 *		point on the 1st character of the argument and never a whitesapce
 *		character.
 *	arguments:
 *		inputBuffer - pointer to the users input
 *		lenStr - pointer to begining of the 1st param, 'len', in input
 *		frstIdxStr - pointer to begining of the 2nd param, '1st index',
 *			in input
 *		scndIdxStr - pointer to begining of the 3rd param, '2ndt index',
 *			in input
 *		blckStr - pointer to begining of the 4th param, 'text block',
 *			in input
 *	returs:
 *		void
 */
void TokenizeInput(
	const char *inputBuffer,
	char **lenStr,
	char **frstIdxStr,
	char **scndIdxStr,
	char **blckStr
);

/*
 *	ValidateInput:
 *		validates the 4 string provided as input to 'my_bcmp'
 *	arguments:
 *		lenStr - pointer to string containing the 1st param, 'len'
 *		frstIdxStr - pointer to string containing the 2nd param, '1st index'
 *		scndIdxStr - pointer to string containing the 3rd param, '2nd index'
 *		blckStr - pointer to string containing the 4th param, 'text block'
 *	returns:
 *		1 if all input is valid, 0 otherwise
 */
int ValidateInput(
	const char *lenStr,
	const char *frstIdxStr,
	const char *scndIdxStr,
	const char *blckStr
);

/*
 *	PointerFromOffset:
 *		receives a pointer and number of bytes, and returns a void-pointer
 *		to address that is greater by said number of bytes.
 *	arguments:
 *		memBlock - pointer to offset from
 *		offsetInBytes - number of bytes to offset
 *	returns:
 *		void* with address 'offsetInBytes' greater than 'memBlock'
 *	
 */
void* PointerFromOffset(const char *memBlock, int offsetInBytes);

int ParseStdinArgsAndRun(int argc, char **argv)
{
	/* buffer used for the users input */
	char inputBuffer[INPUT_BUFF_SIZE];

	/* pointers to the 4 argument strings, initiated to executable arguments
	   and later used for stdin input if not enough arguments were passed */
	char *lenStr = *(argv + 1);
	char *frstIdxStr = *(argv + 2);
	char *scndIdxStr = *(argv + 3);
	char *blckStr = *(argv + 4);

	/* indicates if the passed argument strings are valid */
	int inputIsValid = TRUE;

	if (MIN_INPUT_PARAMS > argc)
	{
		PromptForInput(inputBuffer);
		TokenizeInput(
			inputBuffer,
			&lenStr,
			&frstIdxStr,
			&scndIdxStr,
			&blckStr
		);
	}

	inputIsValid = ValidateInput(
		lenStr,
		frstIdxStr,
		scndIdxStr,
		blckStr
	);

	if (inputIsValid)
	{
		int result;
		int len = atoi(lenStr);
		int frstIdx = atoi(frstIdxStr);
		int scndIdx = atoi(scndIdxStr);

		printf("\n\nReceived 'len' argument: %d", len);
		printf("\nReceived '1st starting point' argument: %d", frstIdx);
		printf("\nReceived '2nd starting point' argument: %d", scndIdx);
		printf("\nRecieved 'text block' argument: %s", blckStr);

		result =  my_bcmp(
			PointerFromOffset(blckStr, frstIdx),
			PointerFromOffset(blckStr, scndIdx),
			len
		);
		printf("\nCompared blocks are%s identical.\n", 0 == result ? "" : " not");
		return result;
	}
	else
	{
		printf("\nTerminatin execution due to invalid input.\n");
		return 1;
	}
}

void* PointerFromOffset(const char *memBlock, int offsetInBytes)
{
	return (void *)(memBlock + offsetInBytes);
}

void PromptForInput(char *buffer)
{
	printf("Please enter the following 4 parameters, in the order of the list below, separated by either a whitespace, tab or newline.\n");
	printf("Terminate your input pressing CTRL+d twice.\n");
	printf("1) number of consecutive bytes to compare - must be a non-negative number.\n");
	printf("2) zero-based starting position of the 1st compared byte block - must be a non-negative number.\n");
	printf("3) zero-based starting position of the 2nd compared byte block - must be a non-negative number.\n");
	printf("4) A block of text, up to 512 characters, for the 3 parameters above to be applied to.\n");

	scanf("%" INPUT_BUFF_SIZE_S "[^EOF]", buffer);
}

/*
 *	IsWhiteSpace:
 *		check if the charater is a 'space', 'tab' or 'newline' charater
 *	arguments:
 *		c - character to check
 *	returns:
 *		int - 1 if 'whitespace' 0 otherwise
 */
int IsWhiteSpace(char c);

void TokenizeInput(
	const char *inputBuffer,
	char **lenStr,
	char **frstIdxStr,
	char **scndIdxStr,
	char **blckStr
)
{
	/* iterates over the input string */
	char *head = (char *)inputBuffer;

	/* true is head points to a character in a token */
	int inToken = FALSE;

	/* specifies the current of the 4 tokens */
	int currentTokenOrder = 0;

	while ('\0' != *head)
	{
		if (FALSE == inToken && FALSE == IsWhiteSpace(*head))
		{
			++currentTokenOrder;
			inToken = TRUE;
			switch (currentTokenOrder)
			{
				case 1:
					*lenStr = head;
					break;
				case 2:
					*frstIdxStr = head;
					break;
				case 3:
					*scndIdxStr = head;
					break;
				case 4:
					*blckStr = head;
					break;
			}
		}
		else if (TRUE == inToken && TRUE == IsWhiteSpace(*head))
		{
			inToken = FALSE;
		}
		++head;
	}
}

int IsWhiteSpace(char c)
{
	return (' ' == c) || ('\t' == c) || ('\n' == c);
}

/*
 *	IsNonNegativeIntegerString
 *		checks it the provided string represents a non-negative interger.
 *		checking end if string is terminated of a whitespace character is found.
 *	arguments:
 *		str - string argument to check
 *	returns:
 *		1 if string represents a non-negative number, until whitespace,
 *		0 otherwise
 */
int IsNonNegativeIntegerString(const char *str, const char *argName);

int ValidateInput(
	const char *lenStr,
	const char *frstIdxStr,
	const char *scndIdxStr,
	const char *blckStr
)
{
	/* used to hold numeric values of the argument strings */
	int len, frstIdx, scndIdx;

	int blockLen = strlen(blckStr);

	if (
		!IsNonNegativeIntegerString(lenStr, "compare length")
		|| !IsNonNegativeIntegerString(frstIdxStr, "1st byte block starting position")
		|| !IsNonNegativeIntegerString(scndIdxStr, "2nd byte block starting position")
	)
	{
		return FALSE;
	}

	len = atoi(lenStr);
	frstIdx = atoi(frstIdxStr);
	scndIdx = atoi(scndIdxStr);

	if (len > blockLen)
	{
		printf("Comparison length argument is longer then the lenght of the block.\n");
		return FALSE;
	}

	if (frstIdx > blockLen)
	{
		printf("1st byte block starting position is beyond the length of the block.\n");
		return FALSE;
	}

	if (scndIdx > blockLen)
	{
		printf("2nd byte block starting position is beyond the length of the block.\n");
		return FALSE;
	}

	if (frstIdx + len > blockLen)
	{
		printf("1st byte block with comparison-length applied, overflows the block.\n");
		return FALSE;
	}

	if (scndIdx + len > blockLen)
	{
		printf("2nd byte block with comparison-length applied, overflows the block.\n");
		return FALSE;
	}

	return TRUE;
}

int IsNonNegativeIntegerString(const char *str, const char *argName)
{
	/* iterates over the argument string */
	const char *head = str;

	/* TRUE is a character that is not a digin was found */
	int nonDigitFound = FALSE;

	while ('\0' != *head && !IsWhiteSpace(*head) && !nonDigitFound)
	{
		if ('9' < *head || '0' > *head)
		{
			nonDigitFound = TRUE;
		}
		++head;
	}
	if (nonDigitFound)
	{
		printf("%s in not a non-negative integer.\n", argName);
	}

	return TRUE;
}
