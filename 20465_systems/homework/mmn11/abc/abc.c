#include <stdio.h>
#include "shorten.h"

#define MAX_LENGTH 80
#define TRUE 1
#define FALSE 0

/*
 *	ParseStdinArgsAndRun:
 *		Receives the argc and argv params from 'main'.
 *		If a string was passed on STDIN, the pointer will be passed to
 *		'ProcessString'. Otherwise NULL will be passed.
 *	arguments:
 *		argc = 'argc' from 'main' - number of arguments passed from STDIN.
 *		argv = 'argv' from **char pointing to STDIN arguments, 'argc' in total.
 */
void ParseStdinArgsAndRun(int argc, char **argv);

/*
 *	ProcessString:
 *		Receives a pointer to char array. If NULL prompts the user to enter a
 *		string. Runs the 'shorten' function on the input string. Prints results
 *		to STDOUT before and after running 'shorten'.
 *	arguments:
 *		cmdlineString = pointer to char array, could be NULL.
 */
void ProcessString(char *cmdlineString);

/*
 *	PromptForString:
 *		Prompts the user to enter a string up to MAX_LENGTH in length.
 *		If users input exceedes the limit above, input is trimmed to fit limit.
 *		If the newline or EOF characters are encountered, the input is
 *		terminaded before that character (by '\0');
 *	arguments:
 *		buffer = pointer to a buffer that will hold the users imput.
 *		bufferSize = the size of the provided buffer.
 */
void PromptForString(char *buffer, int bufferSize);

int main(int argc, char **argv)
{
	ParseStdinArgsAndRun(argc, argv);
	return 0;
}

void ParseStdinArgsAndRun(int argc, char **argv)
{
	ProcessString(1 < argc ? *(argv + 1) : NULL);
}

void ProcessString(char *cmdlineString)
{
	/* will point to the string to be shortened */
	char *inputString = cmdlineString;

	/* buffer to hold the string received from the user if  prompted */
	char buffer[MAX_LENGTH + 1];

	if (NULL == inputString)
	{
		PromptForString(buffer, sizeof(buffer));
		inputString = buffer;
	}

	printf("Input  : %s\n", inputString);
	ShortenString(inputString);
	printf("Output : %s\n", inputString);
}

void PromptForString(char *buffer, int bufferSize)
{
	/* pointer used to iterate over the buffer and populate it */
	char *current = buffer;

	/* pointer to last byte of buffer, used to prevent overflow */
	char *bufferEnd = buffer + bufferSize - 1;

	/* initiated to FALSE. if assigned TRUE, loop execution stops */
	int stringTerminated = FALSE;

	printf("Please enter a string of up-to %d characters.\n", MAX_LENGTH);
	while ((current != bufferEnd) && (FALSE == stringTerminated))
	{
		*current = getchar();
		if ('\n' == *current || EOF == *current)
		{
			*current = '\0';
			stringTerminated = TRUE;
		}
		++current;
	}
	*current = '\0';
	return;
}
