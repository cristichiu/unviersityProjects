#include <stdio.h>

int main() {
    // ex 19
    int nums[3];
    printf("Scrie 3 numere diferite separate prin spatiu diferite de 0: ");
    scanf("%d %d %d", &nums[0], &nums[1], &nums[2]);
    if(nums[0] > 9 || nums[0] <= 0 || nums[1] > 9 || nums[1] <= 0 || nums[2] > 9 || nums[2] <= 0) return 0;
    for(int i=0; i<3; i++) {
        for(int j=i+1; j<3; j++) {
            if(nums[i] > nums[j]) {
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
            }
        }
    }
    printf("%d%d%d", nums[2], nums[1], nums[0]);
    return 0;
}