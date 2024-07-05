#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
void inputArr1(int *arr1, int N);
void inputMaxValue(int *maxValue);
void randomArr2(int *arr2, int N, int maxValue);
int buildArr3(int *arr1, int *arr2, int *arr3, int N);
void checkArr1(int *arr1, int *arr2, int *arr3, int N);
void printArray(int *arr, int N);

int main() {
    int N = 7, maxValue;
    const N=7;
    int arr1[N], arr2[N], arr3[N];
    srand(time(NULL));
    inputArr1(arr1, N);
    inputMaxValue(&maxValue);
    randomArr2(arr2, N, maxValue);
    printArray(arr1,N);
    printArray(arr2,N);
    checkArr1(arr1, arr2, arr3, N);
    return 0;
}
void inputArr1(int *arr1, int N) {
    for (int i = 0; i < N; i++) {
        printf("Enter arr1[%d]: ", i);
        scanf("%d", &arr1[i]);
    }
}

void inputMaxValue(int *maxValue) {
    printf("Enter maxValue: ");
    scanf("%d", maxValue);
    while (*maxValue <= 0) {
        printf("Invalid input. Re-enter maxValue: ");
        scanf("%d", maxValue);
    }
}

void randomArr2(int *arr2, int N, int maxValue) {
    for (int i = 0; i < N; i++) {
        arr2[i] = rand() % (maxValue+1);
    }
}

int buildArr3(int *arr1, int *arr2, int *arr3, int N) {
    int index = 0, count = 0;
    for (int i = 0; i < N; i++) {
        bool flag = false;
        for (int j = 0; j < N; j++) {
            if (arr1[i] == arr2[j]) {
                flag = true;
                break;
            }
        }
        if (!flag) {
            arr3[index++] = arr1[i];
            count++;
        }
    }
    return count;
}
void checkArr1(int *arr1, int *arr2, int *arr3, int N) {
    int size=buildArr3(arr1, arr2, arr3, N);
    if (size!=0) {
        printArray(arr3, size);
    } else {
        printf("No!!!");
    }
}
void printArray(int *arr, int N) {
    for (int i = 0; i < N; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}