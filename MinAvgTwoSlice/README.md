# cod1l1ty Lesson 5: Prefix Sums
## Exercise 4: [MinAvgTwoSlice](https://codility.com/programmers/task/min_avg_two_slice/)

The task is to find the slice in an array A consisting of N integers. The slice
is (P,Q) such that 0 <= P < Q < N. The objective is to return the starting
position of the slice with the lowest average.

Example given:
- Inputs: A =[4, 2, 2, 5, 1, 5, 8], N=7
- Expected: slice(P=1, Q=2) gives the lowest average (2) so the answer is 1.

## My solution

So, I tried a prefix sum approach but still couldn't find a way around O(N**2).
My solution scored 60% overall.

So, I googled it and discovered it's another maths trick question and doesn't
seem to have anything to do with prefix sums. I found the solution [here](https://codesays.com/2014/solution-to-min-avg-two-slice-by-codility/)
and a very nice C implementation that doesn't need to use floats.

I've included the perfect scoring solution in my code too.

## Test Cases

It annoyed me so much that I didn't do a full test range.

1. Example given
    * Inputs: A = [4, 2, 2, 5, 1, 5, 8], N = 7
    * Expected: 1
2. Sequence
    * Inputs: A = [1, 2, 3, 4, 5, 6, 7], N = 7
    * Expected: 0
3. Reverse sequence
    * Inputs: A = [7, 6, 5, 4, 3, 2, 1], N = 7
    * Expected: 5
4. Two minimum slices:
    * Inputs: A = [1, 2, 4, 6, 4, 2, 1], N = 7
    * Expecetd: 0

## Score

My solution scored 60% overall:
 - 100% for correctness.
 - 20% for required performance.
