# Sorting-Algorithm Micro-Benchmark (C++)

A command-line program that times **Quicksort**, **Mergesort**, and **Heapsort** on three input patterns (sorted, random, reverse).  
Written in standard C++17 and measured with `<chrono>`.

---

## Features

* **Quicksort**  
  * Median-of-three pivot selection  
  * Insertion-sort cutoff for sub-arrays ≤ 10 elements
* **Mergesort** (top-down, in-place merge buffer)  
* **Heapsort** (binary max-heap)  
* Microsecond timing for:
  * Already sorted array  
  * Random array (`rand() % 10000`)  
  * Reverse-sorted array  
* Easy switch—comment or uncomment one line to choose the algorithm.

---

## File Overview

| File | Contents |
|------|----------|
| `sort_benchmark.cpp` | All algorithm implementations and `main()` driver. |

---

## Building

```bash
g++ -O3 -std=c++17 sort_benchmark.cpp -o sort_benchmark
Any C++17-compatible compiler works (Clang, MSVC, etc.).
-O3 enables optimizations for more realistic timing.

Running
bash
Copy
./sort_benchmark
Example output (times will vary by hardware):

sql
Copy
Sorted Array time:   110 microseconds
Random Array time:  1380 microseconds
Reversed Array time: 1625 microseconds
Changing the Benchmark
Array length Edit const int size = 5000;.

Input patterns Modify the loops that fill randomArray, sortedArray, and reversedArray.
Note: Replace the reverse loop with

cpp
Copy
for (int i = 0; i < size; ++i)
    reversedArray[i] = size - 1 - i;
to generate a true descending sequence.

Active algorithm In main(), comment out two of the three calls (QuickSort, MergeSort, heapSort) and leave one uncommented.

Possible Extensions
Record results to a CSV for automated plotting.

Add Shellsort, TimSort, or STL std::sort for comparison.

Parallelize with OpenMP and compare single- vs. multi-threaded runs.

Parameterize Quicksort pivot strategy and cutoff size.

License
© 2025 Mohamad Syaj. All Rights Reserved.
This source code is provided for personal or educational study only.
You may not sell, redistribute, or incorporate it into commercial products without the author’s written consent.

Author
Mohamad Syaj
For questions or feedback, please open an issue or contact the author.
