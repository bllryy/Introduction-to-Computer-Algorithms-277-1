#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

typedef struct student 
{
    char name[50];
    double GPA;
    int SAT;
} student;

double avgGPA(student *students, int size) 
{
    double totalGPA = 0.0;
    for(int i = 0; i < size; i++) 
    {
        totalGPA += students[i].GPA;
    }
    return totalGPA / size;
}

double avgSAT(student *students, int size) 
{
    int totalSAT = 0;
    for(int i = 0; i < size; i++) 
    {
        totalSAT += students[i].SAT;
    }
    return (double)totalSAT / size;
}

double stdDevGPA(student *students, int size)
{
    double sum = 0.0;
    for (int i = 0; i < size; i++) 
    {
        sum += students[i].GPA;
    }    
    double mean = sum / size;
    double sumSqDiff = 0.0;
    for(int i = 0; i < size; i++) 
    {
        sumSqDiff += pow(students[i].GPA - mean, 2);
    }
    double variance = sumSqDiff / size;
    return sqrt(variance);
}

double stdDevSAT(student *students, int size)
{
    double mean = avgSAT(students, size);
    double sumSqDiff = 0.0;
    for(int i = 0; i < size; i++) 
    {
        sumSqDiff += pow(students[i].SAT - mean, 2);
    }
    double variance = sumSqDiff / size;
    return sqrt(variance);
}

void admit(student *students, int size, double meanGPA, double meanSAT, double stdDevSAT)
{
    for(int i = 0; i < size; i++)
    {
        if (students[i].GPA > meanGPA && 
            (students[i].SAT >= (meanSAT + stdDevSAT) || students[i].SAT <= (meanSAT - stdDevSAT)))
        {
            printf("Name: %s - Status: Admitted\n", students[i].name);
        }
        else
        {
            printf("Name: %s - Status: Rejected\n", students[i].name);
        }
    }
}

int main() 
{
    FILE *file = fopen("data.txt", "r");
    int maxStudents = 100;
    student students[maxStudents];
    int size = 0;
    char name[50];
    char line[100];
    
    while (fgets(name, sizeof(name), file)) 
    {
        // https://linux.die.net/man/3/strcspn
        name[strcspn(name, "\n")] = 0;
    
        if (!fgets(line, sizeof(line), file))
            break;
        double GPA = atof(line);
    
        if (!fgets(line, sizeof(line), file))
            break;
        int SAT = atoi(line);
    
        strncpy(students[size].name, name, sizeof(students[size].name) - 1);
        students[size].GPA = GPA;
        students[size].SAT = SAT;
        size++;
    
    }

    fclose(file);
    
    printf("Number of students read: %d\n", size);
    
    double meanGPA = avgGPA(students, size);
    double meanSAT = avgSAT(students, size);
    double stdDevSATValue = stdDevSAT(students, size);
    
    admit(students, size, meanGPA, meanSAT, stdDevSATValue);
    
    return 0;
}