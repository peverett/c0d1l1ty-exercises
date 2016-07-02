# c0d1l1ty Lesson 3: Time Complexity
## Exercise 2: [TapeEquilibrium](https://codility.com/programmers/task/tape_equilibrium/)

Given a non-empty zero-indexed array A, at any index that splits the array in
two, find the difference between those two parts and return the minimum
difference found.

Example:
* A = [3, 1, 2, 4, 3]
* Differences:
    * p = 1, difference = | 3 - 10 | = 7
    * p = 2, difference = | 4 - 9 | = 5
    * p = 3, difference = | 6 - 7 | = 1
    * p = 4, difference = | 10 - 3| = 7
* The lowest difference is 1.

Hints:
* Worst-case time complexity is O(N) so the calculation must be done in a single loop.
* Worst-case space complexity is O(N) + input storage.

##My solution

1. Calculate the sum of the whole array = right_sum.
2. loop through N elements:
    1. left_sum += current element
    2. right_sum -= current element
    2. difference = absolute(left_sum - right_sum);
    3. If lowest difference, store it.
3. Return the lowest stored difference.

Note, initialise 'lowest_difference' to something very high.

## Test Cases

1. Example provided
    - Inputs: A = [3, 1, 2, 4, 3], N = 5
    - Expected:  1
2. Maximum N, of random elements range -1000..1000.
    - Inputs: A = [?, ?, ?, ... ?], N = 100000
    - Expected:  ?
3. Maximum N, each element is 1000.
    - Inputs: A = [1000, 1000, 1000, ... 1000], N=100000
    - Expected:  0

## Score
This solution scored:
 - 100% for correctness.
 - 100% for required performance, which is O(N).

This solution iterates through the whole array twice. Once to calculate
the sum of the entire array, and then again to find the lowest difference.
I'm not sure if this is really 0(N) performance.
