#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void init(int *arr, int size)
{
        srand(time(NULL));
        while(size >= 0)
                arr[size--] = rand() % 100;
}

void print(int *arr, int size)
{
        int i;
        for(i = 0; i < size; i++)
                printf("%d\t", arr[i]);
        putchar('\n');
}

void bubble(int *arr, int size)
{
        int i, j;
        for(i = 0; i < size; i++)
        {
                for(j = 0; j < size - i - 1; j++)
                {
                        if(arr[j] > arr[j + 1])
                        {
                                arr[j] = arr[j] + arr[j + 1];
                                arr[j + 1] = arr[j] - arr[j + 1];
                                arr[j] = arr[j] - arr[j + 1];
                        }
                }
        }
}

void insert(int *arr, int size)
{
        int i, j;
        int tmp;
        for(i = 1; i < size; i++)
        {
                tmp = arr[i];
                for(j = i; j > 0 && tmp < arr[j - 1]; j--)
                {
                        arr[j] = arr[j - 1];
                }
                arr[j] = tmp;
        }
}

void choose(int *a, int size)
{
        int i, j, k, t;
        for(i = 0; i < size - 1; i++)
        {
                k = i;
                for(j = i + 1; j < size; j++)
                {
                        if(a[k] > a[j])
                                k = j;
                        if(i != k)
                        {
                                t = a[i];
                                a[i] = a[k];
                                a[k] = t;
                        }
                }
        }
}

int main(int argc, const char *argv[])
{
        int arr[10];
        init(arr, sizeof(arr)/sizeof(int));
        print(arr, sizeof(arr)/sizeof(int));
        choose(arr, sizeof(arr)/sizeof(int));
        print(arr, sizeof(arr)/sizeof(int));
        return 0;
}

