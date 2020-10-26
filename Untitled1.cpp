#include <stdio.h>
#include <string.h>
#include <time.h>
#define A_SIZE 10

void insertion_sort(int* p, int size);
void swapChar(char* num1, char* num2) {
    char temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}
void insertionSortByName(char name[], int size) {
    int i, j;
    char x;
    for (i = 1; i < size; i++) {
        x = name[i];

        for (j = i - 1; j >= 0 && name[j] > x; j--) {
            name[j + 1] = name[j];
        }
        name[j + 1] = x;
    }
}

int swap(int* xp, int* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
    return temp;
}

void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
}
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1, n2;
    n1 = m - l + 1;
    n2 = r - m;
    int L[15];
    int R[15];

   
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0; 
    j = 0; 
    k = l; 
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
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


void mergeSort(int arr[], int l, int r)
{
    if (l < r) {
        int m = l + (r - l) / 2; 
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


void bubbleSortByName(char name[], int size) {
    int swapped = 0;
    int i = 0;
    int j;
    do {
        swapped = 0;
        for (j = 0; j < size - i - 1; j++) {
            if (name[j] > name[j + 1]) {
                swapChar(&name[j], &name[j + 1]);
                swapped = 1;
            }
        }
        i++;
    } while (swapped);
}


void mergeByName(char num[], const int l, const int m, int r) {
    int i, j, k;

    const int leftSize = m - l + 1;
    const int rightSize = r - m;
  
    int left[(int)leftSize], right[(int)rightSize];

      for (i = 0; i < leftSize; i++) {
        left[i] = num[l + i];
    }
    for (j = 0; j < rightSize; j++) {
        right[j] = num[m + 1 + j];
    }

    j = 0, i = 0, k = l;

    while (leftSize > i && rightSize > j) {
        if (left[i] <= right[j]) {
            num[k] = left[i];
            i++;
        }
        else {
            num[k] = right[j];
            j++;
        }
        k++;
    }

    while (leftSize > i) {
        num[k] = left[i];
        k++;
        i++;
    }
    while (rightSize > j) {
        num[k] = right[j];
        k++;
        j++;
    }
     

  
}

void mergeSortByName(char num[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSortByName(num, l, m);
        mergeSortByName(num, m + 1, r);

        mergeByName(num, l, m, r);
    }
}
void swap(int xp, int yp)
{
    int temp = xp;
    xp = yp;
    yp = temp;
}

void selectionSort(int arr[], int n)
{
    int i, j, min_idx;
    for (i = 0; i < n - 1; i++)
    {
        min_idx = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;
        swap(&arr[min_idx], &arr[i]);
    }
}
void selectionSortByName(char name[], int size) {

    int i, j, min, temp;

    for (i = 0; i < size - 1; i++) {
        min = i;
        for (j = i + 1; j < size; j++) {
            if (name[min] > name[j]) {
                min = j;
            }
        }
        swapChar( & name[i], & name[min]);
    }
}

int main(int argc, char const * argv[])
{
	clock_t start, end;
    double total1,total2,total3,total4,total5,total6,total7,total8,total9,total10;
    int a[A_SIZE] = { 2, 0, 1, 8, 5, 5, 6, 0, 3, 3 };
    printf("Insertion sort for number array: \n");
    start = clock();
    insertion_sort(a, A_SIZE);
     end = clock();
    total1 = (double)(end - start) / CLOCKS_PER_SEC;
    printArray(a, A_SIZE);
    
	char name[] = "zeynep inan";
    int sizeName = (sizeof(name) / sizeof(name[0])) - 1;
        
    start = clock();
    insertionSortByName(name, sizeName);
    end = clock();
    total2 = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time = %f\n", total2);
    printf("\nInsertion sort for name array : \n");

    printf("%s\n", name);
    
    
    int arr[] = { 2, 0, 1, 8, 5, 5, 6,0,3,3 };
    int n1 = sizeof(arr) / sizeof(arr[0]);
        start = clock();

    bubbleSort(arr, n1);
    end = clock();
    total3 = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time = %f\n", total3);
    printf("\nBubble sort for number array: \n");
    printArray(arr, n1);
      

     start = clock();
    bubbleSortByName(name, A_SIZE);
     end = clock();
    total4 = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time = %f\n", total4);
    printf("\nBubble sort for name array : \n");
    printf("%s\n", name);
         


    int arr2[] = { 2, 0, 1, 8, 5, 5,6,0,3,3 };
    int arr2_size = sizeof(arr2) / sizeof(arr2[0]);
      start = clock();

     mergeSort(arr2, 0, arr2_size - 1);
    end = clock();
    total5 = (double)(end - start) / CLOCKS_PER_SEC;
                printf("Time = %f\n", total5);

    printf("\nMerge sort for number array: \n");
          start = clock();

    printArray(arr2, arr2_size);
    end = clock();
    total6 = (double)(end - start) / CLOCKS_PER_SEC;
                printf("Time = %f\n", total6);

          start = clock();

    mergeSortByName(name,0,A_SIZE);
    end = clock();
    total7 = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\nMerge sort for name array : \n");
    printf("%s\n", name);
    

  
    int arr3[] = { 2,0,1,8,5,5,6,0,3,3 };
    int n2 = sizeof(arr3) / sizeof(arr3[0]);
              start = clock();

    selectionSort(arr, n2);
        end = clock();
        total8 = (double)(end - start) / CLOCKS_PER_SEC;
         printf("Time = %f\n", total8);
         
    printf("\nSelection sort by number array: \n");
              start = clock();

    printArray(arr3, n2);
    end = clock();
    total9 = (double)(end - start) / CLOCKS_PER_SEC;

             printf("Time = %f\n", total9);
start = clock();
    selectionSortByName(name, A_SIZE);
     end = clock();
        total10 = (double)(end - start) / CLOCKS_PER_SEC;
    printf("\nSelection sort by name array: \n");
    printf("Time = %f\n", total10);
    printf("%s\n", name);
    
    return 0;
}

void insertion_sort(int* p, int size)
{
    int   i, j, t;

    for (i = 0; ++i < size; ) {
        t = p[i];
        for (j = i; p[j - 1] > t; ) {
            p[j] = p[j - 1];
            if (--j <= 0) break;
        }
        p[j] = t;
    }
}

void print_array(int* p, int size)
{
    int i;

    for (i = 0; i < size; i++)
        printf("%d ", p[i]);
    putchar('\n');
}
