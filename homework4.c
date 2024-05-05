#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selectionSort(int arr[], int n);
void insertionSort(int arr[], int n);
void mergeSort(int arr[], int left, int right);
void merge(int arr[], int left, int middle, int right);
void printArray(int arr[], int n);

int main() {
    printf("Islem seciniz\n");
    printf("1 - insertionSort\n");
    printf("2 - selectionSort\n");
    printf("3 - mergeSort\n");
    printf("4 - sayilari sirali yazdir\n");
    printf("5 - cikis\n");

    int numbers[1000];
    FILE *file = fopen("numbers.txt", "r");
    if (file == NULL) {
        printf("Dosya okuma hatasi\n");
        return 1;
    }

    int n = 0;
    int num;
    while (fscanf(file, "%d", &num) != EOF && n < 1000) {
        numbers[n++] = num;
    }
    fclose(file);

    char islem;
    printf("Islem seciniz: ");
    scanf(" %c", &islem);

    switch (islem) {
        case '1': {
            clock_t start = clock();
            insertionSort(numbers, n);
            clock_t end = clock();
            double totalTime = ((double) (end - start)*1000) / CLOCKS_PER_SEC;
            printf("insertionSort %.10f milisaniyede siraladi.\n", totalTime);
            break;
        }
        case '2': {
            clock_t start = clock();
            selectionSort(numbers, n);
            clock_t end = clock();
            double totalTime = ((double) (end - start)*1000) / CLOCKS_PER_SEC;
            printf("selectionSort %.10f milisaniyede siraladi.\n", totalTime);
            break; 
        }
        case '3': {
            clock_t start = clock();
            mergeSort(numbers, 0, n - 1);
            clock_t end = clock();
            double totalTime = ((double) (end - start)*1000) / CLOCKS_PER_SEC;
            printf("mergeSort %.12f milisaniyede siraladi.\n", totalTime);
            break;
        }
        case '4':
            printf("Siralanmis Sayilar:\n");
            printArray(numbers, n);
            break;
        case '5':
            printf("Cikis\n");
            break;
        default:
            printf("Yanlis deger girdiniz\n");
    }

    return 0;
}

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        int temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int middle = (left + right) / 2;
        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);
        merge(arr, left, middle, right);
    }
}

void merge(int arr[], int left, int middle, int right) {
    int n1 = middle - left + 1;
    int n2 = right - middle;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[middle + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d\n", arr[i]);
    }
}
