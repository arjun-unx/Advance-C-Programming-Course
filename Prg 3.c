#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int num1, num2;

    // Input
    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);

    // Define function pointer and use it to swap
    void (*swapPtr)(int*, int*) = swap;
    swapPtr(&num1, &num2);

    // Output
    printf("Swapped numbers: %d %d\n", num1, num2);

    return 0;
}
