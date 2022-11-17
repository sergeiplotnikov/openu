#include <stdio.h>
#include "shorten.h"

#define MAX_LENGTH 80
#define TRUE 1
#define FALSE 0

void processString(char *cmdlineString);
void promptForString(char *buffer, int bufferSize);

int main(int argc, char **argv)
{
	processString(1 < argc ? *(argv + 1) : NULL);
	return 0;
}

void processString(char *cmdlineString)
{
	char *inputString = cmdlineString;
	char buffer[MAX_LENGTH + 1];
	if (NULL == inputString)
	{
		promptForString(buffer, sizeof(buffer));
		inputString = buffer;
	}

	printf("Input  : %s\n", inputString);
	ShortenString(inputString);
	printf("Output : %s\n", inputString);
}

void promptForString(char *buffer, int bufferSize)
{
	char *bufferEnd = buffer + bufferSize - 1;
	int stringTerminated = FALSE;

	printf("Please enter a string of up-to %d characters.\n", MAX_LENGTH);
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
	return;
}

