/* 
 * my_bcmp:
 *	compares bytes 'len' bytes of two memory blocks
 * arguments:
 * 	b1 = pointer to 1st memory block
 * 	b2 = pointer to 2nd memory block
 * return:
 * 	0 if blocks are identical
 * 	1 otherwise
 * complexity:
 * 	time O(n), space O(1)
 * description:
 * 	a loop iterates over the two blocks using two pointers and checks if they
 * 	to identical byte.
 */
int my_bcmp(const void *b1, const void *b2, int len)
{
	int counter = 0;
	const char *ptr1 = b1;
	const char *ptr2 = b2;
	int result = 0;

	while ((counter < len) && (0 == result))
	{
		if (*ptr1 != *ptr2)
		{
			result = 1;
		}
		++ptr1;
		++ptr2;
		++counter;
	}

	return result;
}
