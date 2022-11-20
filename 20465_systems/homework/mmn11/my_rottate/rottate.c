#define TRUE 1
#define FALSE 0

/*
 * my_rottate:
 *     the function receive a non-negative integer and a number
 *     of rottations. The binary form of the number is 'rottated'
 *     so that, in case of a rottation to the right, all bits move
 *     one location to the right with the right-most bit becoming the
 *     left-most bit. This happens according to the provided number of
 *     rottaions. If 'rottaions' is negative the number rottates left,
 *     otherwise it rottates right.
 * arguments:
 *     a = an unsigned integer to be rottated
 *     b = a signed integer describing the number of rottations and
 *         direction.
 * return:
 *     the 'rottated' number
 * complexity:
 *     time O(1), space O(1)
 * assumptions:
 * 
 * DESCRIPTION:
 *     * minimizes the number of rottations to a number that will yield
 *     the same effect
 *     * rottates the number accordint to minimized-rottations and
 *     direction
 */
unsigned int my_rottate(unsigned int a, int b)
{
	/* will hold the resulting 'rottated' number */
	unsigned int result = a;

	/* holds the absolute value of the 'rottation' input */
	unsigned int rottations = b;

	/* mask used to copy the falling-off bits */
	unsigned int mask = 0;

	/* hold TRUE if rottaion is to the left, FALSE if to the right */
	int rottateLeft = b < 0 ? TRUE : FALSE;

	/* holds the number of bits in variable 'a' */
	int numberOfBits = sizeof(a) * 8;

	int i = 0;

	if (rottateLeft)
	{
		rottations *= -1;
	}
	rottations %= numberOfBits;

	for(i = rottations; i > 0; --i)
	{
		mask <<= 1;
		mask |= 1;
	}

	if (rottateLeft)
	{
		mask <<= (numberOfBits - rottations);
		mask &= result;
		result <<= rottations;
		mask >>= (numberOfBits - rottations);
		result |= mask;
	}
	else
	{
		mask &= result;
		result >>= rottations;
		mask <<= (numberOfBits - rottations);
		result |= mask;
	}

	return result;
}
