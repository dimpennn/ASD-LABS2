#include <stdio.h>
#include <math.h>

double sum_cycle(int n, double x, double current_addend)
{
    double sum = current_addend;

    for (int i = 2; i <= n; i++)
    {
        current_addend = current_addend * (i - 1.0) * (x - 1.0) / (i * x);
        sum += current_addend;
    }

    return sum;
}

int main()
{
    int n;
    double x;

    printf("Enter n (n >= 1): ");
    scanf("%d", &n);

    printf("Enter x (x > 0.5): ");
    scanf("%lf", &x);

    double first_addend = (x - 1.0) / x;

    double answer = sum_cycle(n, x, first_addend);

    double value = log(x);

    double error = fabs(answer - value);

    printf("\ndata: n = %d,\n      x = %.8f\n\n", n, x);

    printf("Recursion result: %.8f\n", answer);
    printf("Value of ln(x): %.8f\n", value);
    printf("Error: %.8f\n", error);

    return 0;
}
