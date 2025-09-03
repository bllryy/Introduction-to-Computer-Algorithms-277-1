#include <stdio.h>

int main()
{
    int numbers[] = {59, 51, 87, 27, 13, 10, 54, 50, 24, 88, 60, 70, 20, 2, 47, 21, 99, 16, 74, 81, 98, 58, 61, 52, 75, 64, 9, 5, 22, 28, 82, 67, 33, 97, 95, 66, 43, 53, 15, 8, 57, 45, 19, 30, 40, 6, 48, 63, 39, 94, 18, 12, 29, 35, 93, 92, 38, 26, 25, 37, 4, 44, 65, 36, 85,100, 76, 69, 7, 86, 79, 80, 96, 14, 83, 71, 17, 41, 46, 62, 3, 77, 68, 78, 49, 72, 31, 73, 56, 84, 34, 55, 89, 42, 91, 11, 90, 32, 1, 23};

    size_t array_length = sizeof(numbers) / sizeof(numbers[0]);

    printf("The size of the array is: %zu\n", array_length);

    // mean
    int sum = 0;
    for (int i = 0; i < array_length; i++)
    {
        numbers[i] += sum;
    }

    double mean = (double)sum / array_length;
    printf("mean = %d\n", mean);

    // squared deviations
    double devs[100] // deviations: devs
    for (int i = 0; i < array_length; i++)
    {
        double deviation = numbers[i] - mean;
        deviation * deviation = devs[i];
    }

    // add all of the squared deviations
    double sumdevs = 0.0;
    for (int i = 0; i < array_length i++)
    {
        sumdevs += dev[i];
    }


    // calculate the variace
    sumdevs / array_length = double variace

    // print variance
    printf("variance: /////////////////\n", variace)

    return 0;
}
