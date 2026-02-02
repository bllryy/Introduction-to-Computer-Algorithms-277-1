#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int foo() {
  int bar;


}

int main()
{
    /*
     * buffer[100] is the "for line in lines"
     */

    char buffer[100];

    FILE *fptr; // create a file pointer

    fptr = fopen("data", "r");

    while(fgets(buffer,100,fptr) != NULL)
    {
        printf("%s", buffer);
    }

    fclose(fptr);


    return 0;

}
