#define TRUE 1
#define FALSE 0

unsigned int my_rottate(unsigned int a, int b)
{
	unsigned int result = a;
	unsigned int rottations = b;
	unsigned int mask = 0;
	int i = 0;
	int rottateLeft = b < 0 ? TRUE : FALSE;

	if (rottateLeft)
	{
		rottations *= -1;
	}
	rottations %= (sizeof(a) * 8);

	for(i = rottations; i > 0; --i)
	{
		mask <<= 1;
		mask |= 1;
	}

	if (rottateLeft)
	{
		mask <<= (sizeof(a) * 8 - rottations);
		mask &= result;
		result <<= rottations;
		mask >>= (sizeof(a)	* 8 - rottations);
		result |= mask;
	}
	else
	{
		mask &= result;
		result >>= rottations;
		mask <<= (sizeof(a) * 8 - rottations);
		result |= mask;
	}

	return result;
}
