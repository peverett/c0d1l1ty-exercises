# c0d1l1ty Lesson 4: Counting Elements
## Exercise 1: [FrogRiverOne](https://codility.com/programmers/task/frog_river_one/)

A frog is crossing a river. It starts at position 0 and must reach position X+1
to get across. To cross it must jump on leaves that fall from a tree at
an interval of one per second.

The zero-indexed array A contains N integers representing the fallen leaves and
their X position, the index is the second that leaf fell.

For example;
    - For inputs: X = 5, A = [1, 3, 1, 4, 2, 3, 5, 4], N = 8
    - The answer is 6 (seconds) as it is when the 6th leaf at position 5
    falls that the frog can cross.

Hints:

Expected worst-case space complexity is O(X), so it's clear that up to X values
of the array A must be counted.

##My solution

The frog's path across the river is another arithmetic sequence.

1. If N < X the frog can never make it across, return -1.
2. Calculate the sum of arithmetic sequence from 1 to X.
3. Initialise a count array of X elements to all 0.
4. loop through up to N elements of array A
    - If the current element is not in the count array
        * subtract current element value from sum
        * if sum is 0 return the index value of the current element.
        * set count[ current element ] to 1
5. Loop ended, Return -1, froggie ain't made it.


## Test Cases

1. X = N = 1 - the frog can cross.
    - Inputs: X = 1, A = [1], N = 1
    - Expected:  1
2. X = 2, N = 1 - (N < X) - the frog cannot cross.
    - Inputs: X = 2, A = [1], N = 1
    - Expected: -1
3. Example given
    - Inputs: X = 5, A = [1, 3, 1, 4, 2, 3, 5, 4], N = 8
    - Expected: 6
4. Missing number in sequence, frog cannot cross.
    - Inputs: X = 5, A = [1, 3, 1, 5, 2, 3, 4, 4], N = 8
    - Expected: -1
5. Max X and N - frog can cross.
    - Inputs: X = 100000, A = [1 .. 100000], N = 100000
    - Expected: 100000
6. Max X and N - frog cannot cross.
    - Inputs: X = 100000, A = [1 .. 99999, 999999], N = 100000
    - Expected: -1

## Score
This solution scored:
 - 100% for correctness.
 - 100% for required performance, which is O(N).
