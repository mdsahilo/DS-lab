#include <stdio.h>
This line includes the standard input/output library (stdio.h) which allows us to use printf() (to display output) and scanf() (to take input).

int main() {


The main() function is the starting point of every C program.

The program execution begins from here.

    int num1, num2, sum;


We declare three integer variables:

num1 → to store the first number

num2 → to store the second number

sum → to store the result (addition of num1 and num2)

    printf("Enter first number: ");
    scanf("%d", &num1);


printf() displays a message asking the user to enter the first number.

scanf("%d", &num1); takes integer input from the user and stores it in num1.

%d → format specifier for integers.

&num1 → & means “address of”, so the input value is stored directly in the variable num1.

    printf("Enter second number: ");
    scanf("%d", &num2);


Same as above, but now the user enters the second number, which gets stored in num2.

    sum = num1 + num2;


Here we add the values of num1 and num2 and store the result in sum.

    printf("Sum = %d\n", sum);


This prints the result of addition.

%d is replaced by the value of sum.

\n is for moving to the next line after printing.

    return 0;
}


return 0; tells the system that the program finished successfully.

The closing brace } marks the end of the main() function.
