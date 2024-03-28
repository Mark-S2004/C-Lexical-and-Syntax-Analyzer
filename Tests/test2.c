#include <stdio.h>

// Function to calculate the factorial of a number
int factorial(int n)
{
    if (n == 0 || n == 1)
        return 1;
    else
        return n * factorial(n - 1);
}

int main()
{
    int i, j;
    int arr[5] = {1, 2, 3, 4, 5};

    // Print array elements
    printf("Array elements: ");
    for (i = 0; i < 5; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Find and print even numbers in the array
    printf("Even numbers in array: ");
    for (i = 0; i < 5; i++)
    {
        if (arr[i] % 2 == 0)
        {
            printf("%d ", arr[i]);
        }
    }
    printf("\n");

    // Calculate and print factorials of numbers from 1 to 5
    printf("Factorials of numbers from 1 to 5: ");
    for (i = 1; i <= 5; i++)
    {
        printf("%d! = %d, ", i, factorial(i));
    }
    printf("\n");

    // Nested loops to print a pattern
    printf("Pattern: \n");
    for (i = 5; i > 0; i--)
    {
        for (j = 0; j <= i; j++)
        {
            printf("* ");
        }
        printf("\n");
    }

    return 0;
}
