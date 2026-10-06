# DSA Assignment – Question 9

## Topic
K-Way Merge using Min Heap and Pairwise Merge

## Problem

A financial system receives three already sorted transaction lists:

- L1 = 10, 30, 50, 70
- L2 = 20, 40, 60, 80
- L3 = 15, 35, 55, 75

The task is to merge the three sorted lists into one sorted list using:

1. K-way merge using a Min Heap
2. Pairwise merging

Both approaches are compared based on operations, comparisons, time complexity, heap size, and space requirements.

## Input

L1 = 10 30 50 70  
L2 = 20 40 60 80  
L3 = 15 35 55 75

## Output

Final merged sequence:

10 15 20 30 35 40 50 55 60 70 75 80

## K-Way Merge using Min Heap

The first element of each sorted list is inserted into a Min Heap.
The minimum element is repeatedly removed and the next element from
the same list is inserted into the heap.

Time Complexity: O(N log k)

Space Complexity: O(k)

Maximum Heap Size: 3

## Pairwise Merge

First, L1 and L2 are merged.

Result:

10 20 30 40 50 60 70 80

Then this result is merged with L3.

Final Result:

10 15 20 30 35 40 50 55 60 70 75 80

Time Complexity: O(Nk) in general

Space Complexity: O(N)

## Comparison

| Parameter | K-Way Min Heap | Pairwise Merge |
|---|---|---|
| Data Structure | Min Heap | Arrays |
| Heap Size | Maximum k | Not applicable |
| Time | O(N log k) | O(Nk) in general |
| Space | O(k) | O(N) |
| Intermediate Array | Not required | Required |
| More Files | More efficient | Less efficient |

## Conclusion

Both methods successfully merge the sorted transaction lists.

K-way merge using a Min Heap is more suitable when the number of
sorted files increases because it provides better time and space
efficiency.
