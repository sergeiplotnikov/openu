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
 * assumptions:
 */
int my_bcmp(const void *b1, const void *b2, int len);
