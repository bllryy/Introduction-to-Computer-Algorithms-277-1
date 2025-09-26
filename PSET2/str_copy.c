/*
Using pointers (and dereferencing), copy a source string (src) to an empty char array (dest).
 Attached is your function header:
Feel free to use strlen() to get the size of your src string.
*/

#include <stdio.h>
#include <string.h>

void copy_string(char *dest, char *src);

int main()
{
  char src[100];
  char dest[100];

  printf("Enter a string: ");
  fgets(src, sizeof(src), stdin);

  copy_string(dest, src);
	
	printf("Copied: %s\n", dest);
	return 0;
}

void copy_string(char *dest, char *src) {
while (*src != '\0') {
    *dest = *src;
    dest++;
    src++;
  }
}

