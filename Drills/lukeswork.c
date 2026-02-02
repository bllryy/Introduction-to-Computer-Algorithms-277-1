// Copyright (c) 2026 Luke Magruder
// drill2.c -- structs and malloc 

#include <err.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//   ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡀⠆⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
//   ⠀⠀⠀⠀⠤⡀⠀⠀⠀⠀⠀⡚⢀⠐⢨⢆⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
//⠀   ⠀⢀⠇⡠⡀⡢⡀⠀⠀⢀⠇⡦⠀⠐⡋⠂⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
//⠀   ⠀⢸⢀⡈⠀⠨⡝⡀⠀⢸⢸⠁⢀⡠⠸⡜⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀
//   ⠀⠀⢸⢸⠇⢀⡄⢘⡙⠀⠸⠈⡆⠁⠸⡄⠁⢆⠀⠀⠀⠀⠀⠀⠀⠀⠀
//   ⠀⠀⢈⡀⠰⢾⠈⣁⠁⢇⣈⠁⡇⠶⢶⠇⢆⣏⠀⠀⠀⠀⠀⠀⠀⠀⠀
//⠀   ⠀⢨⡂⢃⠸⡠⠇⠋⠉⠀⡁⠀⠀⠀⠀⠀⢨⡁⠑⢦⢀⠀⠀⠀⠀⠀
//⠀⠀   ⠀⠨⡬⠋⡄⡀⠀⠀⠈⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⢢⡀⠀⠀⠀
//⠀   ⠀⠀⠋⠀⠀⠘⠀⠀⢀⢀⠠⡴⠒⠓⠊⠁⠒⠂⠠⡀⠀⠀⠹⢄⠀⠀
//   ⠀⠰⡋⠀⠀⠀⢀⠔⠉⠉⠀⠀⠀⠀⠀⠀⠀⢀⡄⠀⠀⠑⡄⠀⠀⢅⠀
//   ⠀⡊⠀⠀⠀⠔⠀⠀⠀⠀⠀⠀⠀⠀⠀⠒⢂⣥⣈⢆⠀⠀⡎⢆⠀⠸⡀
//   ⢀⡇⠀⠀⡆⠀⠀⢁⠂⣀⡈⢃⠀⠀⠀⢰⢸⣦⣿⡌⠀⢀⠗⠋⠀⠀⡇
//   ⠀⢧⠀⠀⠃⠀⠀⠸⠠⣯⣽⡎⡆⣤⢒⡄⠛⣿⣾⠗⢀⢾⠚⢰⠀⡸⠀
//   ⠀⢡⠀⠀⡇⠂⠀⠀⠣⢻⣯⡿⠃⠈⠉⠀⠀⠀⢀⢔⠏⠈⡠⠁⠔⠃⠀
//   ⠀⠘⢢⠀⠈⢦⡩⠖⠤⢄⣀⣀⣀⣀⡠⡤⣐⠚⠉⠭⠊⣠⠴⢍⠀⠀⠀
//   ⠀⠀⠀⠳⢄⡀⠁⠒⠩⢄⡕⣐⡡⠬⠍⠀⠒⣉⠤⠎⠉⠀⠀⠀⠢⣄⠀
//   ⠀⠀⠀⠀⠀⠀⠀⢉⠗⠒⠒⠂⠖⠒⠊⠉⠀⠀⠀⠀⠀⠀⠀⠀⣄⢟⡲
//   ⠀⠀⠀⠀⠀⠀⠀⣠⠀⠀⠀⠀⠀⠀⠖⠀⠀⠀⠐⠗⠆⠀⠀⢠⠛⢬⠜
//   ⠀⠀⠀⠀⠀⠀⠀⣣⣄⡀⠀⠀⠀⠀⠀⢀⠀⠀⠀⠀⠀⠀⠀⠀⢆⠀⠀

// Student struct
typedef struct {
	int studentid;
	int year;
	char name[50];
} student;

// Class struct.  Array of pointers to student structs.
typedef struct {
	int size;
	student **students;
} class;

// Alloc student
student *student_create(char new_name[50], int new_id, int new_year)
{
	student *new = calloc(sizeof(student), 1);

	new->studentid = new_id;
	new->year = new_year;
	strncpy(new->name, new_name, 50);

	return new;
}

// Free student
void student_free(student *s)
{
	free(s);
	return;
}

// Alloc class.  Alloc student for each in size.  Read from "input.txt"
class *class_create(int n)
{
	class *new = calloc(sizeof(class), 1);
	new->size = n;
	new->students = calloc(sizeof(student*), new->size);

	int new_id;
	int new_year;
	char new_name[50];

	FILE *fp = fopen("input.csv", "r");
	if (fp == NULL)
		err(errno,"input.csv");

	for (int i = 0; i < new->size; ++i) {
		fscanf(fp, "%d,%d,%[^\n]%*c\n", 
			&new_id,	
			&new_year,
			new_name);
		new->students[i] = student_create(new_name, new_id, new_year);
	}

	fclose(fp);

	return new;
}

// Free class
void class_free(class *c)
{
	for (int i = 0; i < c->size; ++i)
		student_free(c->students[i]);
	free(c->students);
	free(c);
}

// Print name and class
void class_print(class *c)
{
	printf("Coding Class Roster:\n");
	for (int i = 0; i < c->size; ++i)
		printf("\t%s: Co %d\n", c->students[i]->name, c->students[i]->year);
	return;
}


int main(void)
{
	class *coding = class_create(9);
	class_print(coding);
	class_free(coding);

	return 0;
}
