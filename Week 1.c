1. 
  
  #include <stdio.h>

int main() {
    int num;

    // Input
    printf("Enter a number: ");
    scanf("%d", &num);

    // Check the least significant bit using bitwise AND
    if (num & 1) {
        printf("%d is odd.\n", num);
    } else {
        printf("%d is even.\n", num);
    }

    return 0;
}

2.

  #include <stdio.h>

int countSetBits(int num) {
    int count = 0;

    while (num) {
        count += num & 1;
        num >>= 1;
    }

    return count;
}

int main() {
    int num;

    // Input
    printf("Enter a number: ");
    scanf("%d", &num);

    // Count set bits
    printf("Count of Set bits: %d\n", countSetBits(num));

    return 0;
}

3. 

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

4. Equivalent pointer expression for fetching the value of array element a[i][j][k][2]:

Ans : int value = *(*(*(*(a + i) + j) + k) + 2);
