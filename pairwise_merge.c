#include <stdio.h>

void merge(int a[], int n, int b[], int m, int result[])
{
    int i = 0, j = 0, k = 0;

    while (i < n && j < m)
    {
        if (a[i] <= b[j])
            result[k++] = a[i++];
        else
            result[k++] = b[j++];
    }

    while (i < n)
        result[k++] = a[i++];

    while (j < m)
        result[k++] = b[j++];
}

void display(int a[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);

    printf("\n");
}

int main()
{
    int L1[] = {10, 30, 50, 70};
    int L2[] = {20, 40, 60, 80};
    int L3[] = {15, 35, 55, 75};

    int firstMerge[8];
    int finalMerge[12];

    printf("Pairwise Merge\n\n");

    printf("L1: ");
    display(L1, 4);

    printf("L2: ");
    display(L2, 4);

    printf("L3: ");
    display(L3, 4);

    merge(L1, 4, L2, 4, firstMerge);

    printf("\nAfter merging L1 and L2:\n");
    display(firstMerge, 8);

    merge(firstMerge, 8, L3, 4, finalMerge);

    printf("\nFinal merged sequence:\n");
    display(finalMerge, 12);

    return 0;
}
