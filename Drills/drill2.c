#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student 
{
    char name[50];
    int studentid;
    int year;
};

struct class 
{
    int size;
    struct student** students;
};

/**
 * @param newname The name of the student.
 * @param newid The student ID.
 * @param newyear The student year.
 * @return A pointer to the newly created student struct.
 */
struct student* createStudent(char newname[50], int newid, int newyear) 
{
    // alloc memory for student struct
    struct student* new_student = (struct student*)malloc(sizeof(struct student));

    strncpy(new_student->name, newname, 50);
    new_student->name[49] = '\0'; // null termination (stole off google)
    new_student->studentid = newid;
    new_student->year = newyear;

    return new_student;
}

/**
 * @param n The number of students in the class.
 * @return A pointer to the newly created class struct.
 */
struct class* createClass(int n) 
{
    struct student** student_array = (struct student**)malloc(n * sizeof(struct student*));

    for (int i = 0; i < n; i++) 
    {
        char name_buffer[50];
        int id_buffer;
        int year_buffer;
;
        printf("Name: ");
        scanf("%s", name_buffer);
        printf("ID: ");
        scanf("%d", &id_buffer);
        printf("Year: ");
        scanf("%d", &year_buffer);

        // assign the result to the student pointer arr
        student_array[i] = createStudent(name_buffer, id_buffer, year_buffer);
    }

    struct class* new_class = (struct class*)malloc(sizeof(struct class));

    // member vars
    new_class->size = n;
    new_class->students = student_array;

    return new_class;
}

int main() 
{
    int num_students = 9;

    struct class* coding = createClass(num_students);

    printf("\nStudent Names in the 'coding' class:\n");
    for (int i = 0; i < coding->size; i++) 
    {
        printf("Student %d: %s\n", i + 1, coding->students[i]->name);
    }

    for (int i = 0; i < coding->size; i++) 
    {
        free(coding->students[i]);
    }
    // free arr *ptrs
    free(coding->students);
    free(coding);           

    return 0;
}
