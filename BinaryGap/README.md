# c0d1l1ty Lesson 1
## Exercise 1: [BinaryGap](https://codility.com/programmers/task/binary_gap/)

The task is to count that longest gap of zeros (0) bounded on both sides by a
one (1) in the binary representation of a number.

For example;
    N = 5144, in binary is 0b1010000011000.
    The longest gap of zeros is 5.

##My solution

1. Always operate on the Least Significant Bit (N & 1).
2. Shift right (e.g. `N >>= 1`) until the bottom bit is 1 (and N is not 0).
3. Shift right while N is not 0.
   1. If the bottom bit is 0 then +1 to gap count.
   2. If the bottom bit is 1, then if the gap count is the longest count yet
       store it. Reset the gap count to 0.
4. Return the longest gap.
