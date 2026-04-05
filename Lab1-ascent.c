#include <stdio.h>
#include <math.h>

double sum_ascent(int i, double x, double *current_term)
{
    if (i == 1)
    {
        *current_term = (x - 1.0) / x;
        return *current_term;
    }

    double prev_sum = sum_ascent(i - 1, x, current_term);

    *current_term = (*current_term) * (i - 1.0) * (x - 1.0) / (i * x);

    return prev_sum + (*current_term);
}
int main()
{
    int n;
    double x;

    printf("Enter n (n >= 1): ");
    scanf("%d", &n);

    printf("Enter x (x > 0.5): ");
    scanf("%lf", &x);

    double current_term = 0.0;
    double answer = sum_ascent(n, x, &current_term);

    double value = log(x);

    double error = fabs(answer - value);

    printf("\ndata: n = %d,\n      x = %.8f\n\n", n, x);

    printf("Recursion result: %.8f\n", answer);
    printf("Value of ln(x): %.8f\n", value);
    printf("Error: %.8f\n", error);

    return 0;
}
