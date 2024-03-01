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
