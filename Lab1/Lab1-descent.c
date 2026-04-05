#include <stdio.h>
#include <math.h>

double sum_descent(int i, unsigned int n, double x, double current_addend, double current_sum)
{
    if (i == n)
    {
        return current_sum;
    } else {

    int next_i = i + 1;
    double next_addend = current_addend * (next_i - 1.0) * (x - 1.0) / (next_i * x);

    double new_sum = current_sum + next_addend;

    return sum_descent(next_i, n, x, next_addend, new_sum);
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

    double answer = sum_descent(1, n, x, first_addend, first_addend);

    double value = log(x);

    double error = fabs(answer - value);

    printf("\ndata: n = %d,\n      x = %.8f\n\n", n, x);

    printf("Recursion result: %.8f\n", answer);
    printf("Value of ln(x): %.8f\n", value);
    printf("Error: %.8f\n", error);

    return 0;
}
