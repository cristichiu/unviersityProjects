#include <stdio.h>
#include <stdlib.h>

int main() {
    // ex 14
    int nums[3];
    printf("Scrie 3 numere diferite separate prin spatiu: ");
    scanf("%d %d %d", &nums[0], &nums[1], &nums[2]);
    for(int i=0; i<3; i++) {
        for(int j=i+1; j<3; j++) {
            if(nums[i] > nums[j]) {
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
            }
        }
    }
    printf("%d", nums[1]);
    return 0;
}