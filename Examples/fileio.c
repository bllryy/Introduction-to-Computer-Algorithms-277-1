#include <locale.h>
#include <stdio.h>
#include <string.h>

/*
  File state machines a way to model procedures that have limited inputs and
outputs

- a name
- a number

our file has a structure

when i read the next line i can add 1 to the state how do we get to state 0?
when we create the struct
we can reset the state back to 0

*/


struct student
{
  char name[50];
  int grade;
}

int main()
{
    /*
     * buffer[100] is the "for line in lines"
     */

    char buffer[100];

    FILE *fptr; // create a file pointer
    fptr = fopen("data", "r");

    int state = 0;
    char tempName[50];
    while (fgets(buffer, 100, fptr) != NULL)
    {
      if (state == 0)
      {
        strncpy(tempName, buffer, 50);
        state = 1;
      }

      else if (state == 1)
      {
        int tempGrade = atoi(buffer);
        struct student newStudent
        strncpy(newStudent.name, tempName, 50);
        newStudent.grade = tempGrade;
        prinft("Student name: %s student grade: %d \n", newStudent.name, newStudent.grade);
        state = 0;
      }
    }

    fclose(fptr);

    return 0;
}
