#define TRUE 1
#define FALSE 0

/*
 *	CalculateCounter:
 *		calculates a new value based on current coutner value and the value
 *		of the 'head' pointer, using helper functions.
 *	arguments:
 *		counter = current value of counter
 *		head = pointing to current position of 'head'
 *	return:
 *		new value for counter
 *	complexity:
 *		time O(1), space O(1) (based on helper functions)
 */
int CalculateCounter(int counter, char *head);

/*
 *	HeadIsValid:
 *		check if the value of 'head' is 'valid'.
 *		according to the logic of 'ShortenString', head will iterate over the
 *		string and look check for consecutive characters in *head and *(head-1).
 *		Thus a valid head value can never be 'a' or 'A' because then *(head-1)
 *		holds a non ABC character that is smaller in value by 1.
 *		Valid values are in range [b,z] and [B,Z].
 *	arguments:
 *		head = the 'head' pointer of 'ShortenString'
 *	return:
 *		1 (TRUE) if valid, 0 (FALSE) otherwise.
 *	complexity:
 *		time O(1), space O(1)
 */
int HeadIsValid(char *head);

/*
 *	CharsAscending:
 *		checks if the two pointers point to values different by 1 with the first
 *		being the smaller.
 *	arguments:
 *		first = pointer to a character
 *		second = pointer to a character
 *	return:
 *		1 (TRUE) if charcters meet the requirements above, 0 (FALSE) otherwise.
 *	complexity:
 *		time O(1), space O(1)
 */
int CharsAscending(char *first, char *second);

/* 
 *	ShortenString:
 *		the function receives a char-array and changes it in-place so
 *		that all consecutive sequences of 3 or more ABC characters, of
 *		matching case, are replaced by the 1st character of the sequesce
 *		a dash and then the last character of the sequence.
 *		For example, the string 'dabcefLMNOpQrstuv567zyx'
 *		will change to          'da-cefL-OpQr-v567zyx'
 *	arguments:
 *		str = pointer to char array to be used as input.
 *	return:
 *		void
 *	complexity:
 *		time O(n), space O(1)
 *	assumptions:
 *		1) when receiving input from STDIN, it is assumed that the array
 *		will be terminated by '\0'.
 *
 *	DESCRIPTION:
 *		* in a loop, the 'head' pointer will iterate over the array.
 *		* the 'dest' pointer will lag behind 'head' and serve as the destination
 *		for copying characters from 'head' in case the resulting string
 *		will be shortened - a sequencee of 4< char found.
 *		* on each iteration of the loop the actions are dicatated by the value
 *		of 'consecutiveChars' which is the counter for the number of consecutive
 *		characters found in the current sequence.
 */
void ShortenString(char *str)
{
	/* used to iterate over the array and update counter */
	char *head = str;

	/* used as destination for copying 'head' */
	char *dest = str;

	/* number of consecutive chars in current sequence */
	int consecutiveChars = 0;

	/* indicates if values from 'head' should be copied to 'dest' */
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

int HeadIsValid(char *head)
{
	return
		(('b' <= *head && 'z' >= *head)
		|| ('B' <= *head && 'Z' >= *head));
}

int CharsAscending(char *first, char *second)
{
	return  (*first + 1) == *second;
}
