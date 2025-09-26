/*
Using pointers (and dereferencing), copy a source string (src) to an empty char array (dest).
 Attached is your function header:
Feel free to use strlen() to get the size of your src string.
*/

#include <stdio.h>
#include <string.h>

int main()
{
	char *s = "hello";
	char arr[20];

	strcpy(arr, s);
	
	printf("%s \n", arr);
	return 0;
}
