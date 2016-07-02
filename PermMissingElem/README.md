# c0d1l1ty Lesson 3: Time Complexity
## Exercise 3: [PermMissingElement](https://codility.com/programmers/task/perm_missing_elem/)

Zero-indexed array A contains integers in the range 1..(N+1). This means that:
- The array contains all the numbers of an arithmetic sequence.
- Except one of the numbers in that sequence is missing.

The task is to determine the missing2dd sequence number.

Example:
- For the array A = [ 2, 3, 1, 5 ] and N = 5
- The missing number is 4 in the sequence of 1, 2, 3, (4), 5.

##My solution

You have to know the trick of how to calculate the [sum of an arithmetic
sequence](http://hotmath.com/hotmath_help/topics/sum-of-the-first-n-terms-of-an-arithmetic-sequence.html).

1. Calculate the sum of the arithmetic sequence N+1.
2. loop through N elements of A and subtract them from the sum
3. Return what is left, which should be the missing number in the sequence.

Since the N is in the range 1..100,000 calculate the sum use the `long long`
type. Convert back to `int` to return because by then the value should be less
or equal to the maximum N+1.

## Test Cases

1. Empty array
    - Inputs: A = [], N = 0
    - Expected: 1
2. N = 1
    - Inputs: A = [1], N = 1
    - Expected: 2
3. Example provided
    - Inputs: A = [2, 3, 1, 5], N = 4
    - Expected:  4
4. Missing is first in sequence (e.g. 1).
    - Inputs: A = [2, 3, 4, 5, 6], N = 5
    - Expected: 1
5. Missing is last in sequence
    - Inputs: A = [1, 2, 3, 4, 5], N = 5
    - Expected: 6
6. Maximum sequence 1 .. 100,001, N = 100,000, missing is 87654.
    - Inputs: A = [1, 2, 3, 4, 5, ... 100001], N = 100000
    - Expected: 87654

## Score
This solution scored:
 - 100% for correctness.
 - 100% for required performance, which is O(N).
