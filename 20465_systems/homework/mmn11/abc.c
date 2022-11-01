#include <stdio.h>

#define MAX_LENGTH 80

int HeadValueIsValid(char *value);
int FirstPrecedesSecond(char *first, char *second);
int CalculateCounter(int counter, char *head);
void DO(char *string);

int main(int argc, char **argv)
{
	char *inputStr;
	if (1 < argc)
	{
		inputStr = *(argv + 1);
	}
	else
	{
		char str[MAX_LENGTH + 1];
		int i = MAX_LENGTH;

		for (; i > 0; --i)
		{
			str[MAX_LENGTH - i] = getchar();
			if ('\n' == str[MAX_LENGTH - i])
			{
				str[MAX_LENGTH - i] = '\0';
				break;
			}
		}
		str[MAX_LENGTH] = '\0';
		inputStr = str;
	}

	printf("Input  : %s\n", inputStr);
	DO(inputStr);
	printf("Output : %s\n", inputStr);

	return 0;
}

void DO(char *str)
{
	char *head = str;
	char *dest = str;
	int counter = 0;
	int flag = 0;

	while ('\0' != *head)
	{
		++head;

		counter = CalculateCounter(counter, head);

		switch (counter)
		{
			case 0:
			case 1:
				if (flag)
					*dest = *(head - 1);
				++dest;
				break;
			case 2:
				*dest = '-';
				++dest;
				break;
			default:
				flag = 1;
				break;
		}
	}
	*dest = '\0';
}

int CalculateCounter(int counter, char *head)
{
	return HeadValueIsValid(head) && FirstPrecedesSecond(head - 1, head) ? counter + 1 : 0;
}

int HeadValueIsValid(char *value)
{
	return (('b' <= *value && 'z' >= *value) || ('B' <= *value && 'Z' >= *value));
}

int FirstPrecedesSecond(char *first, char *second)
{
	return  (*first + 1) == *second;
}
