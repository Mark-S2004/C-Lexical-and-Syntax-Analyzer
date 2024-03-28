#include <stdio.h>

// Define a struct with reserved keyword 'struct'
struct Student
{
    char name[50];
    int age;
    char gender;
};

// Function prototype with reserved keyword 'typedef'
typedef int (*Operation)(int, int);

// Function to add two numbers
int add(int a, int b)
{
    return a + b;
}

int main()
{
    // Define variables with reserved keywords
    int num1 = 10, num2 = 5;
    char ch = 'A';
    float pi = 3.14;

    // Create an array of integers
    int arr[5] = {1, 2, 3, 4, 5};

    // Loop using reserved keyword 'for'
    printf("Array elements: ");
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Conditional statement using reserved keyword 'if'
    if (num1 > num2 && ch == 'A')
    {
        printf("%d is greater than %d and character is 'A'\n", num1, num2);
    }
    else
    {
        printf("%d is less than or equal to %d or character is not 'A'\n", num1, num2);
    }

    // Function call using pointer to function with reserved keyword 'typedef'
    Operation operation = &add;
    printf("Sum of %d and %d is: %d\n", num1, num2, operation(num1, num2));

    // Using reserved keyword 'struct' to define and initialize a structure variable
    struct Student student1 = {"John", 20, 'M'};
    printf("Student: %s, Age: %d, Gender: %c\n", student1.name, student1.age, student1.gender);

    // Logical AND and OR operators
    int x = 10, y = 5;
    if (x > 5 && y < 10)
    {
        printf("Both conditions are true\n");
    }
    if (x > 5 || y > 10)
    {
        printf("At least one condition is true\n");
    }

    // ternary operators
    y += x == 5 ? 5 : 10;

    // Bitwise operators
    int bitwiseResult = x & y;
    printf("Bitwise AND of %d and %d is: %d\n", x, y, bitwiseResult);

    bitwiseResult = x | y;
    printf("Bitwise OR of %d and %d is: %d\n", x, y, bitwiseResult);

    // Special symbols used: () {} ;
    return 0;
}
