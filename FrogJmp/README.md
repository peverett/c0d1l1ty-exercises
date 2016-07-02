# c0d1l1ty Lesson 3: Time Complexity
## Exercise 1: [FrogJmp](https://codility.com/programmers/task/frog_jmp/)

A frog can jump distance D in one hop and must cross a river from X to Y or
greater in the minimum number of jumps.

The expected time and space complexity for this exercise is O(1) and so this
is a clue that a simple calculation is required for the answer.

##My solution

The obvious answer is to find the distance across the river (Y - X) and divide
it by the size of the frog's jump D, always rounding up to whole numbers.

This can be done by calculating the answer as a float, adding 0.5 to round up,
and then converting back to an int.

A better solution would be to use an integer division and round up e.g.
```
round_up = (dividend + divisor - 1)/divisor;
```

## Test Cases

Note that N must always be an odd number.

X, Y and D are in the range 1..1,000,000,000, so worst case must allow for that.

1. Worst Case
    - Inputs X = 1, Y = 1000000000, D = 1000000000
    - Expected: 1
2. Example
    - Inputs X = 10, Y = 85, D = 30
    - Expected: 3

## Score
This solution scored:
 - 100% for correctness.
 - 100% for required performance, which is O(1) time and space.
