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

  
