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
