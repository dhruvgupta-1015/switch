#include <stdio.h>
#include <stdbool.h>

void traversal(int arr[], int n)
{
    int i;
    printf("Array is: ");
    for (i = 0; i < n; i++)
    {
        printf(" %d ", arr[i]);
    }
}

void insertion(int arr[], int n)
{
    int val, i, pos;
    printf("Enter the element you want to insert in an array: ");
    scanf("%d", &val);
    printf("Enter the position where you want to insert an element:");
    scanf("%d", &pos);
    for (i = n - 1; i >= pos - 1; i--)
    {
        arr[i + 1] = arr[i];
    }
    n = n + 1;
    arr[pos - 1] = val;
}

void deletion(int arr[], int n)
{
    int i, pos;
    printf("Enter the position you want to delete :");
    scanf("%d", &pos);
    for (i = pos - 1; i < n; i++)
    {
        arr[i] = arr[i + 1];
    }
    n = n - 1;
}

bool search(int arr[], int size, int key)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == key)
        {
            return 1;
        }
    }
    return 0;
}
bool linear_search(int arr[], int n)
{
    printf("Enter the element you want to search : ");
    int key;
    scanf("%d", &key);
    bool found = search(arr, n, key);
    if (found)
    {
        printf("key is present");
    }
    else
    {
        printf("key is not present");
    }
}

void binary_search(int arr[], int n)
{
    int key, i;
    printf("Enter the element you want to search : ");
    scanf("%d", &key);
    int start = 0;
    int end = n - 1;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (arr[mid] == key)
        {
            printf("Key is present ");
            break;
        }
        else if (arr[mid] > key)
        {
            end = mid - 1;
        }
        else
            start = mid + 1;
        if (start > end)
            printf("Key is not present ");
    }
}

void bubble_sort(int arr[], int n) // on every iteration highest element sent at the last index
{
    int i, j, temp;
    for (i = 1; i < n; i++)
    {
        for (j = 0; j < n - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;

        // Move elements of arr[0..i-1], that are greater than key,
        // to one position ahead of their current position
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void printArray(int arr[], int n)
{
    printf("Array after operation is: \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void selection_sort(int arr[], int n)
{
    int i, j, minindex, temp;
    for (i = 0; i < n - 1; i++)
    {
        minindex = i;
        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minindex])
                minindex = j;
        }
        temp = arr[minindex];
        arr[minindex] = arr[i];
        arr[i] = temp;
    }
}

int main()
{
    int val, pos, n, i, ope;
    int arr[10];
    printf("Enter the size of an Array:");
    scanf("%d", &n);
    printf("Enter the elements of an Array:");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter 1 for traversal of Array \n");
    printf("Enter 2 for insertion in Array \n");
    printf("Enter 3 for deletion in Array \n");
    printf("Enter 4 for linear search in Array \n");
    printf("Enter 5 for binary search in Array \n");
    printf("Enter 6 for bubble sort in Array \n");
    printf("Enter 7 for insertion sort in Array \n");
    printf("Enter 8 for selection sort in Array \n");
    printf("Enter the operation you want to perform \n");
    scanf("%d", &ope);
    if (ope >= 9)
    {
        printf("Please Enter The Valid Operation! ");
    }
    switch (ope)
    {
    case 1:
        traversal(arr, n);
        break;
    case 2:
        insertion(arr, n);
        printArray(arr, n);
        break;
    case 3:
        deletion(arr, n);
        printArray(arr, n);
        break;
    case 4:
        linear_search(arr, n);
        break;
    case 5:
        insertionSort(arr, n);
        binary_search(arr, n);
        break;
    case 6:
        bubble_sort(arr, n);
        printArray(arr, n);
        break;
    case 7:
        insertionSort(arr, n);
        printArray(arr, n);
        break;
    case 8:
        selection_sort(arr, n);
        printArray(arr, n);
        break;

    default:
        //   printf("Enter the valid operation ");
        break;
    }

    return 0;
}