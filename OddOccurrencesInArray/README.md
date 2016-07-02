# c0d1l1ty Lesson 2: Arrays
## Exercise 2: [OddOccurrencesInArray](https://codility.com/programmers/task/odd_occurrences_in_array//)

Non-empty zero-indexed Array A of odd N elements. The array contains pairs of
numbers except for one number which is not paired (hence the array's odd
length).

The exercise is to find and return the odd number.

For example;
    - For input; A = [ 9, 3, 9, 3, 9, 7, 9 ], N = 7
    - The expected result is 7, because 7 is the number that is not paired.

Notice, multiple pairs of the same number can occur.

##My solution

To achieve the require efficiency, you must know the XOR trick. You may be
familiar with using XOR for swapping variables, from K&R. e.g.
```
 x ^= y, y ^= x, x ^= y;
```

If you XOR a number with itself, the result is 0.

The solution is to iterate through the array and XOR every value. The value
left will be the unpaired number because without a paired number to XOR against,
it's bits cannot be zeroed.

## Test Cases

Note that N must always be an odd number.

1. N = 1
    - Inputs: A = [99], N = 1
    - Expected:  1
2. Unpaired at start
    - Inputs: A = [7, 3, 9, 3, 9], N = 5
    - Expected:  7
3. Unpaired at end
    - Inputs: A = [3, 9, 3, 9, 7], N = 5
    - Expected:  7
4. Unpaired inbetween
    - Inputs: A = [3, 9, 7, 3, 9], N = 5
    - Expected:  7

## Score
This solution scored:
 - 100% for correctness.
 - 100% for required performance, which is O(N).
