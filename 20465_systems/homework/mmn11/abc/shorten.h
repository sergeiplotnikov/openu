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
*/
void ShortenString(char *str);
