# c0d1l1ty Lesson 6: Sorting
## Exercise 2: [Distinct](https://codility.com/programmers/task/distinct/)

Given a zero-indexed array A consisting of N integers, return the number of
distinct values in array A.

Example:
- Inputs: A = [2, 1, 1, 2, 3, 1], N = 6
- Expected: 3, because there are three distinct values; 1, 2 and 3.

Complexity:
* Expected worst-case time-complexity is O(N*log(N)).
* Expected worst-case space-complexity is O(N), beyond input storage and
arguements.

## My solution

Compared to other c0d1l1ty exercises this was by far the easiest yet. Maybe
there is a simpler answer, but this worked and scored 100%.

1. If N == 0 return 0
2. Sort the input array.
3. Loop through the sorted array and count the unique values.
4. Return unique value count.

## Test Cases

1. Default, empty array
    * Inputs: A = [], N = 0
    * Expected: 0
2. Only one element
    * Inputs: A = [1], N = 1
    * Expected: 1
3. Example.
    * Inputs: A = [2, 1, 1, 2, 3, 1], N = 6
    * Expected: 3
4. Sequentual sequence, 6 numbers
    * Inputs: A = [1, 2, 3, 4, 5, 6], N = 6
    * Expected: 6
5. N = 100000, random values in A between -1000000000 and 1000000000.
    * Inputs: A = [?, ?, ?, ... ?], N = 10000
    * Expected: ?
6. N = 100000, all values of A are maximum negative -1000000000.
    * Expected: 1

## Score

My solution scored 100% overall:
 - 100% for correctness.
 - 100% for required performance.
