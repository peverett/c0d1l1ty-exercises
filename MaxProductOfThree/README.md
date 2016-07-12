# c0d1l1ty Lesson 6: Sorting
## Exercise 3: [MaxProductOfThree](https://codility.com/programmers/task/max_product_of_three/)

Given a non-empty zero-indexed array A of N integers. Write a function that
returns the maximum of a triplet of value from A, such that (P, Q, R) equates
to A[P] * A[Q] * A[R] and 0 <= P < Q < R < N.

Example:
* Inputs: A = [-3, 1, 2, -2, 5, 6], N = 6
* Expected: P=2, Q=5, R=6, maximum product 60.

Complexity:
* Expected worst-case time complexity is O(N*log(N)).
* Expected worst-case space complexity is O(1).

## My solution

To quote Admiral Ackbar, it's a trap!

The simplest solution is to sort the list and multiply the highest three
elements in the list (the last three). Except that
multiplying two negative values creates a positive value.

So it's either the lowest two negative numbers values (P, Q), if negative,
multiplied by the highest positive value (R) or the highest three values.

This is probably not the best solution but it gets the job done and scores 100%.

1. If there are three values, just return the product of those three.
2. Sort the input array A.
3. Calculate A[0] * A[1] * A[N-1], into X.
4. Calculate A[N-3] * A[N-2] * A[N-1], into Y.
5. Return whichever is higher of X or Y.


## Test Cases

1. Minimum N = 3
    * Inputs: A = [1, 2, 3], N = 3
    * Expected: 6
2. Example
    * Inputs: A = [-3, 1, 2, -2, 5, 6], N = 6
    * Expected: 60
3. Product is 0
    * Inputs: A = [-10, 15, 0], N =3
    * Expected: 0
4. Only one positive value.
    * Inputs: A = [-33, -22, -11, -5, 5], N = 5
    * Expected: 3650
5. Two lowest negative + highest positive is max product.
    * Inputs: A = [-33, -22, 0, 5, 3], N = 5
    * Expected: 3650
6. Highest product is negative.
    * Inputs: A = [-33, -22, -11, -5, -4, -1], N 5
    * Expected: -20
7. N = 100000, random values in A
    * Inputs: A = [?, ?, ?, ... ?], N = 100000
    * Expected: ?
8. N = 100000, all maximum negative values in A
    * Inputs: A = [-1000, -1000, -1000, ... -1000], N = 100000
    * Expected: -1000000000

## Score

My solution scored 100% overall:
 - 100% for correctness.
 - 100% for required performance.

