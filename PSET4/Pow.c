#include <stdio.h>

double power(double x, int n) 
{
    if (n == 0)
        return 1;

    // exponent is negative
    if (n < 0)
        return 1 / power(x, -n);

    // exponent is even
    if (n % 2 == 0) 
    {
        double half = power(x, n / 2);
        return half * half;
    }

    // exponent is odd
    else
        return x * power(x, n - 1);
}

int main() 
{
    double x;
    int n;

    printf("Enter base (x): ");
    scanf("%lf", &x);

    printf("Enter exponent (n): ");
    scanf("%d", &n);

    double result = power(x, n);

    printf("%.2lf raised to the power %d is %.2lf\n", x, n, result);

    return 0;
}


/*
*
*The program stores bases and exponents in arrays.
*For each pair it calls the power()
*Results are stored in another array 
*
*
* https://stackoverflow.com/questions/25860850/what-is-the-difference-between-f-and-lf-in-c
*
*
*Problem 0 – Pow.c
An illustrative example of when recursion is useful is computing the power of a number. For example, We first notice that if is a power of 2, then can be computed 
by squaring. For example, is the square of , so can be computed using only two multiplications instead of three. As it happens, this technique can be used 
even when  is not a power of 2. 
    • If  is even, we use the formula .
    • If  is odd, then . 
Write a recursive function that computes . (The recursion ends when , in which case the function returns 1.) To test your function, write a 
program 
that asks the user to enter values for and , calls power to 
compute , and then displays the value returned by the function.
*
*/
