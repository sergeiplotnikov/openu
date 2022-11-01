#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char **argv)
{
	int i = 0;
	char a[80];
	a[0] = 'A' + 20;
	srand(time(NULL));
	for (i = 1; i< 79; ++i){
		a[i] = a[i - 1] + (rand() % 3) - 1;
	}
	a[79] = '\0';
	printf("%s\n", a);
	return 0;
}

