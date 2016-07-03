# c0d1l1ty Lesson 4: Counting Elements
## Exercise 3: [MissingInteger](https://codility.com/programmers/task/missing_integer/)

Given a zero-indexed array A fo N integers, return the minimal positive
integer (greater than 0) that does not occur in A.

For example:
- Inputs: A = [1, 3, 6, 4, 1, 2], N = 6
- Expected: 5 - as this is the lowest missing postive integer.

Constraints:
- N is an integer in the range 1..100,000
- Elements of array A can be in the range -2,147,483,638 .. 2,146,483,647,
that's a standard 32-bit integer on most platforms these days.

##My solution

You only need to count integers in the range 1..N. Any value over N or
less than 1 can be discarded. Once the elements of Array A that can be counted
have been counted, loop through the count array until the first uncounted index
and that is the required minimum positive integer.

1. Allocate a count array of size N+1 and intialise to all 0.
2. Loop through array A
    - If current element value >= 1 and <= N and not already counted, then
    record the value as counted.
3. Loop through the count array (1..N)
    - If the count element is 0 return the index as the minimum missing positive
    integer.
4. Loop finished, the minimum missing positive integer must be N+1, return that.

## Test Cases

1. N = 1, lowest missing int is N+1
    - Inputs: A = [1], N = 1
    - Expected:  2
2. N = 1, lowest missing int is 1
    - Inputs: A = [2], N = 1
    - Expected: 1
3. Example given
    - Inputs: A = [1, 3, 6, 4, 1, 2], N = 6
    - Expected: 5
4. N = 100000, lowest missing int is 1
    - inputs: A = [2 .. 100001], N = 1
    - Expected: 1
5. N = 100000, lowest missing int is N+1
    - Inputs: A = [1 .. 100000], N = 100000
    - Expected: 100001
6. N = 100000, array contains maximum range values
    - inputs: A = [1 .. 99998, -2147483638, 2146483647] N = 100000
    - Expected: 99999


## Score
This solution scored:
 - 100% for correctness.
 - 100% for required performance, which is O(N).

However, I am not sure if this is correct. Surely, this solution is worst-case
time complexity of O(N+N+N) because:
- Loop 1..N to initialise the count array;
- loop 1..N through A array to mark integers counted;
- Loop 1..N through count array to find the missing minimum positive int;

