#define TRUE 1
#define FALSE 0

int CalculateCounter(int counter, char *head);
int HeadIsValid(char *value);
int CharsAscending(char *first, char *second);

void ShortenString(char *str)
{
	char *head = str;
	char *dest = str;
	int consecutiveChars = 0;
	int shortenString = FALSE;

	while ('\0' != *head)
	{
		++head;

		consecutiveChars = CalculateCounter(consecutiveChars, head);

		switch (consecutiveChars)
		{
			case 0:
			case 2:
				if (shortenString)
				{
					*dest = *(head - 1);
				}
				++dest;
				break;
			case 3:
				*dest = '-';
				++dest;
				break;
			default:
				shortenString = TRUE;
				break;
		}
	}
	*dest = '\0';
}

int CalculateCounter(int counter, char *head)
{
	if (HeadIsValid(head) && CharsAscending(head - 1, head))
	{
		if (0 == counter)
		{
			return 2;
		}
		else
		{
			return (counter + 1);
		}
	}
	else
	{
		return 0;
	}
}

int HeadIsValid(char *value)
{
	return
		(('b' <= *value && 'z' >= *value)
		|| ('B' <= *value && 'Z' >= *value));
}

int CharsAscending(char *first, char *second)
{
	return  (*first + 1) == *second;
}
