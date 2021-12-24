### Bubble Sort
- It is stable and inplace
- TimeComplexity- O(n^2)
### Selection Sort
- O(n^2) Algorithm
- Does less memory writes compared to Quick sort, Merge Sort, Insertion sort, etc. But cycle sort is optimal interms of memory writes
- Basic Idea of heap sort
- Not Stable 
- Inplace
### Insertion Sort
- O(n^2) worst case
- In-Place and stable
- Used in practise for small arrays(Tim sort and Intro sort)
- O(n) in best case
### Merge sort
- Divide and Conquer(Divide, Conquer and Merge)
- Stable Algorithm
- O(nlogn) time and O(n) space
- Well suited in Linked lists. Works in O(1) auxilary space
- Used in External Sorting
- In general for arrays Quick Sort outperforms it
### Quick Sort
- Divide and Conquer Algorithm
- Worst Case time- O(n^2)
- Despite O(n^2) worst case, it is considered faster because of the following reasons <br>
In-Place, Cache Friendly, Average case is O(nlogn), Tail Recursive.
- Partition is Key function(Naive, Lumito, Hoare)