#include <stdio.h>

int Addition(int, int);
int Subtraction(int, int);

int main()
{
    int A, B;

    printf("Enter two numbers: ");
    scanf("%d %d", &A, &B);

    printf("Addition: %d\n", Addition(A, B));
    printf("Subtraction: %d\n", Subtraction(A, B));

    return 0;
}
