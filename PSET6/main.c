#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

/*
* Size will be the data input
*/

typedef struct student 
{
	char name[50];
	double GPA;
	int SAT;
} student;

double avgGPA(student *students) 
{
	double totalGPA = 0.0;
	for(int i = 0; i < size; i++) 
	{
		totalGPA += students[i].GPA;
	}

	return totalGPA / size;
}

double avgSAT(student *students) 
{
	int totalSAT = 0;
	for(int i = 0; i < size; i++) 
	{
		totalSAT += students[i].SAT;
	}

	return totalSAT / size;
}

double stdDev(student *students, int size)
{
	double sum = 0.0;
	for (int i = 0; i < size; i++) 
	{
		sum += students[i].gpa;
	}	
	double mean = sum / size;


	double sumSqDiff = 0.0;
	for(int i =0; i < size; i++) 
	{
		sumSqDiff += pow(students[i].GPA - mean,2)
	}

	double variance = sumSqDiff / size;

	return sqrt(variance);
}

void admit(student *students, int size)
{
	for(int i = 0; i < size; i++)
	{
		printf("Name: %s - Status: %s\n", 
			students[i].name, students[i]addmitted ? "Addmittied" : "Rejected");
	}
}


int main() 
{


}
