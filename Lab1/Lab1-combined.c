#include <stdio.h>
#include <math.h>

double sum_combined(int i, unsigned int n, double x, double current_addend)
{
    if (i == n)
    {
        return current_addend;
    } else {

    int next_i = i + 1;
    double next_addend = current_addend * (next_i - 1.0) * (x - 1.0) / (next_i * x);

    double remaining_sum = sum_combined(next_i, n, x, next_addend);

    return current_addend + remaining_sum;
    }
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

    double answer = sum_combined(1, n, x, first_addend);

    double value = log(x);

    double error = fabs(answer - value);

    printf("\ndata: n = %d,\n      x = %.8f\n\n", n, x);

    printf("Recursion result: %.8f\n", answer);
    printf("Value of ln(x): %.8f\n", value);
    printf("Error: %.8f\n", error);

    return 0;
}
