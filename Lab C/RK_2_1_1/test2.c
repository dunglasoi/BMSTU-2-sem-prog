#include <stdio.h>

void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }

        // Hoán đổi phần tử nhỏ nhất với phần tử đầu tiên của dãy chưa sắp xếp
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

int main()
{
    int n;
    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        printf("Nhap phan tu thu %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("Mang truoc khi sap xep: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    selectionSort(arr, n);

    printf("\nMang sau khi sap xep: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}
