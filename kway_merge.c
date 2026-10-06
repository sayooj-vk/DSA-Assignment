#include <stdio.h>

#define K 3
#define N 4

typedef struct
{
    int value;
    int list;
    int index;
} HeapNode;

HeapNode heap[K];
int heapSize = 0;

void swap(HeapNode *a, HeapNode *b)
{
    HeapNode temp = *a;
    *a = *b;
    *b = temp;
}

void insert(HeapNode node)
{
    int i = heapSize++;
    heap[i] = node;

    while (i > 0)
    {
        int parent = (i - 1) / 2;

        if (heap[parent].value <= heap[i].value)
            break;

        swap(&heap[parent], &heap[i]);
        i = parent;
    }
}

HeapNode deleteMin()
{
    HeapNode min = heap[0];

    heap[0] = heap[--heapSize];

    int i = 0;

    while (1)
    {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int smallest = i;

        if (left < heapSize &&
            heap[left].value < heap[smallest].value)
        {
            smallest = left;
        }

        if (right < heapSize &&
            heap[right].value < heap[smallest].value)
        {
            smallest = right;
        }

        if (smallest == i)
            break;

        swap(&heap[i], &heap[smallest]);
        i = smallest;
    }

    return min;
}

void displayHeap()
{
    printf("Heap: ");

    for (int i = 0; i < heapSize; i++)
    {
        printf("%d ", heap[i].value);
    }

    printf("\n");
}

int main()
{
    int lists[K][N] =
    {
        {10, 30, 50, 70},
        {20, 40, 60, 80},
        {15, 35, 55, 75}
    };

    int position[K] = {0, 0, 0};

    printf("K-way Merge using Min Heap\n\n");

    /* Insert the first element of each list */
    for (int i = 0; i < K; i++)
    {
        HeapNode node = {lists[i][0], i, 0};
        insert(node);
    }

    printf("Initial ");
    displayHeap();

    printf("\nMerged sequence: ");

    while (heapSize > 0)
    {
        HeapNode min = deleteMin();

        printf("%d ", min.value);

        position[min.list]++;

        if (position[min.list] < N)
        {
            HeapNode next =
            {
                lists[min.list][position[min.list]],
                min.list,
                position[min.list]
            };

            insert(next);
        }

        printf("\nAfter processing %d: ", min.value);
        displayHeap();
    }

    printf("\n");

    return 0;
}
