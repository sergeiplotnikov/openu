/*
 * my_rottate:
 * 	the function receive a non-negative integer and a number
 * 	of rottations. The binary form of the number is 'rottated'
 * 	so that, in case of a rottation to the right, all bits move
 * 	one location to the right with the right-most bit becoming the
 * 	left-most bit. This happens according to the provided number of
 * 	rottaions. If 'rottaions' is negative the number rottates left,
 * 	otherwise it rottates right.
 * arguments:
 * 	a = an unsigned integer to be rottated
 * 	b = a signed integer describing the number of rottations and
 * 	    direction.
 * return:
 * 	the 'rottated' number
 * complexity:
 * 	time O(1), space O(1)
 * assumptions:
 *
 */
unsigned int my_rottate(unsigned int a, int b);
