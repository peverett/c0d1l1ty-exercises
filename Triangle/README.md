# cod1l1ty Lesson 6: Sorting
## Exercise 1: [Triangle](https://codility.com/programmers/task/triangle/)

A zero-indexed array A consisting of N integers is given. A truplet (P, Q, R) is
a triangular if:
- 0 <= P < Q < R < N
- A[P] + A[Q] > A[R]
- A[Q] + A[R] > A[P]
- A[R] + A[P] > A[Q]

Write a function that given a zero-indexed array A consisting of N integers,
returns 1 if there exists a triangular triplet for this array and return 0
otherwise.

Example:
- Inputs: A = [10, 2, 5, 1, 8, 20], N = 6
- Expected: Triplet (0, 2, 4) is triangular, should return 1.

Hints:
- Expected worst-case time complexity is O(N*log(N)); So a sort is required in
the solution.

## My solution

I expected a trick math question, but, suprisingly, I worked this one out
myself. Still took a couple of goes to get 100% though.

1. Remove any value from array A that < 1 and recalculate N.
2. If N < 3 return 0, can't be a triangle with less than 3 sides.
3. Sort the array A.
4. Loop for P through array A from 0 to N-3
    * Loop for Q through array A from P to N-2
        1. R = Q+1
        2. if A[P] + A[Q] > A[R] return 1
5. If the loops complete, there is no triangle, return 0

How does this work?
* If we sort the values into progressive sequence, we know that P <= Q <= R,
  therefore, only the 'P + Q > R' test is needed.
* The simplest solution is that whatever value of P, if Q and R are the same,
  then this is an isosceles triangle, so you could first check if `Q == R`, but
  the `P + Q > R` rule still applies so just use that.
* For C, use the `long long` type for the A[P] + A[Q] operation, because at the
  maximum positive range of values in A this addition will cause an overflow
  otherwise.

## Test Cases

1. Default, empty array
    * Inputs: A = [], N = 0
    * Expected: 0
2. Only two elements
    * Inputs: A = [1, 2], N = 2
    * Expected: 0
3. Three elements, is a triangle
    * Inputs: A = [5, 8, 4], N = 3
    * Expected: 1
4. Three elements, not a triangle
    * Inputs: A = [8, 5, 2], N = 0
    * Expected: 0
5. Example
    * Inputs: A = [10, 2, 5, 1, 8, 20], N = 6
    * Expected: 1
6. Three values, all max value of 2147483647
    * Inputs: A = [2147483647, 2147483647, 2147483647], N = 3
    * Expected: 1
7. Extreme ranges, triangle
    * Inputs: A = [2, 2147483646, 2147483647], N = 3
    * Expected: 1
8. Maximum N (N=100000), random values of A
    * Inputs: A = [?, ?, ?, ... ?], N = 100000
    * Expected: ?
9. Maximum N (N=100000), all values of A are negative.
    * Inputs: A = [-1, -1, -1, ... -1], N = 100000
    * Expected: 0

## Score

My solution scored 100% overall:
 - 100% for correctness.
 - 100% for required performance.
