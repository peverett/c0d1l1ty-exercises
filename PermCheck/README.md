# c0d1l1ty Lesson 4: Counting Elements
## Exercise 2: [PermCheck](https://codility.com/programmers/task/perm_check/)

A permutation is a sequence of 1..N where each value is only present once but
the values can be in any order.

The task is to check the values in a zero-index array A of size N to see if it
is a permutation (contains all values 1..N) and return 1, or not and return 0.

For example, this array is a permutation:
- Inputs: A = [4, 1, 3, 2], N = 4
- Result: 1

This array is not a permutation, because the value 2 is missing:
- Inputs: A = [4, 1, 3], N = 3
- Result: 0

##My solution

At first, I thought this was similar to the [FrogRiverOne](https://codility.com/programmers/task/frog_river_one/)
problem and implemented a similar solution, which did work and probably would
have scored well (but see Note below).

Not mentioned in the task description but not explicitly discounted:
- array A can contain duplicate values.
Explcitly stated:
- a value can > N
However, if either case occurs, the permutation cannot be valid. This provides
a simpler solution where calculating the arithmetic sequence of 1..N is not
needed.

1. Allocate and intialise to all 0 a count array of size N+1;
2. Loop through all elements of A.
    * If current element value > N OR has already been counted, return 0
    * Else record the current element value as counted
3. Return 1, permutation is complete.

## Test Cases

1. N = 1, valid permutation
    - Inputs: A = [1], N = 1
    - Expected:  1
2. N = 1, not a permutation
    - Inputs: A = [2], N = 1
    - Expected: 0
3. Example valid permutation
    - Inputs: A = [4, 1, 3, 2], N = 4
    - Expected: 1
4. Example invalid permutation
    - Inputs: A = [4, 1, 3], N = 3
    - Expected: 0
5. Repeated value, invalid permutation
    - Inputs: A = [4, 1, 3, 3], N = 4
    - Expected: 0
6. Max N (N == 100,000), valid permutation
    - Inputs: A = [1 .. 100000], N=100000
    - Expected: 1
7. Max N, Max A value, invalid permutation
    - Inputs: A = [1 .. 99999, 1000000000], N = 100000
    - Expected: 0


## Score
This solution scored:
 - 100% for correctness.
 - 100% for required performance, which is O(N).

*Note*

There are antisum test cases for this on Codility e.g. the sum of all values in
A is correct for the arithmetic sequence 1..N but the array is not a permutation
(e.g. duplicate values). This solution passes those tests but my initial
implementation would have failed, I think.
