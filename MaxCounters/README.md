# cod1l1ty Lesson 4: Counting Elements
## Exercise 4: [MaxCounters](https://codility.com/programmers/task/max_counters/)

Write a function:
```
    struct Results solution(int N, int A[], int M);
```
where:
- N is the number of counters from 1 to N.
- A[] is a non-empty zero-indexed array containing integers in the range 1..N+1.
- M is the number of elements in A.

For each integer in A perfrom one of the two possible operations:
- if 1<= A[K] <=N then increase the counter for that value.
- if A[K] = N+1 then make all counters the maximum counter value.

Example:
- Input: N = 5, A = [3, 4, 4, 6, 1, 4, 4], M = 7
- Expected operation:
    * A[0] = 3, counters = (0, 0, 1, 0, 0) // Inc counter 3
    * A[1] = 4, counters = (0, 0, 1, 1, 0) // Inc counter 4
    * A[2] = 4, counters = (0, 0, 1, 2, 0) // Inc counter 4
    * A[3] = 6, counters = (2, 2, 2, 2, 2) // Max all counters to 2
    * A[4] = 1, counters = (3, 2, 2, 2, 2) // Inc counter 1
    * A[5] = 4, counters = (3, 2, 2, 3, 2) // Inc counter 4
    * A[6] = 4, counters = (3, 2, 2, 4, 2) // Inc counter 4
- Expected: Results { C = [3, 2, 2, 4, 2], L = 5 }

Expected worst-case time complexity is O(N+M).

##My solution

The expected worst-case time complexity of O(N+M) indicates that the solution
should use a single iteration across the input array A and the counter array
result.C.

The trick to achieving this is to use a form of [lazy initialisation](https://en.wikipedia.org/wiki/Lazy_initialization).
Only apply the Max Counter when it's greater than the current counter value.
After the input array A has been processed, apply the Max Counter to all
elements that are less than that value.

1. Allocate and initialise the Results struct.
2. Loop through all elements of A
    * If current element == N + 1, set Highest Count so far to Max Count.
    * else:
        1. If counter for current element is < Max Count, set it to Max Count.
        2. Increment this counter.
        3. If this counter is the highest so far, store the Highest Count.
3. Loop through all elements of the counters.
    * If current element < Max Count, set it to Max Count.
4. Return Results struct.

## Test Cases

1. Minimal inputs
    * Inputs: N = 1, A = [ 1 ], M = 1
    * Expected: Results { C = [1], L = 1 }
2. Example
    * Inputs: N = 5, A = [ 3, 4, 4, 6, 1, 4, 4 ], M = 7
    * Expected: Results { C = [ 3, 2, 2, 4, 2 ], L = 5 }
3. Only max counters
    * Inputs: N = 5, A = [ 6, 6, 6, 6, 6, 6, 6 ], M = 7
    * Expected: Results { C = [ 0, 0, 0, 0, 0 ], L = 5 }
4. Two max counters
    * Inputs: N = 5, A = [ 3, 4, 4, 6, 1, 6, 4 ], M = 7
    * Expected: Results { C = [ 3, 3, 3, 4, 3 ], L = 5 }
5. Maximum values
    * Inputs: N = 100000, A = [ rand(1..100001) * M ], M = 100000
    * Expected: Results { C = [? ... ?], L = 100000 }

## Score

This solution scored:
 - 100% for correctness.
 - 100% for required performance, which is O(N+M).
