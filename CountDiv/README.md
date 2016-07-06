# c0d1l1ty Lesson 5: Prefix sums
## Exercise 2: [CountDiv](https://codility.com/programmers/task/count_div/)

Given three integers A, B and K, return the number of integers in range [A..B]
that are divisible by K i.e.

```
    {i: a <= i <= b, i mod k = 0}
```

For example:
- Inputs A = 6, B = 11 and K = 2
- Expected 3, because there are three numbers in the range 6..11 divisible by 2,
6, 8 and 10.

Constraints:
- A and B are integers in the range [0..2,000,000,000]
- K is an integer in the range [1..2,000,000,000]
- A <= B

##My solution

The obvious solution is to iterate through A to B and count how many times `i`
mod K is 0 but that is O(N) and the required solution indicates O(1) worst-case
time AND space complexity so this is a major clue that there is a simple
calculation to get the answer.

Yeah, I looked it up, it's simple maths (if your good at maths).
```
   (B/K) - (A/K)
```
Almost gets you there but you have to account for the case where A may be
included in the count of divisible numbers between A and B.

```
    int inclusive = ((A % K) == 0) ? 1 : 0;
    return (B/K) - (A/K) + inclusive;
```
Totally works!

Except when I tried the minimum value test case;
- Input: A = 0, B = 0, K = 1
- Expected: 0
- Actual result: 1

Huh!

Turns out 1 is the correct answer. Me math no good. 0 is divisible by any
integer except 0 itself.

## Test Cases

1. Minimal inputs
    * Inputs: A = 0, B = 0, K = 1
    * Expected: 1
2. Example:
    * Inputs: A = 6, B = 1, K = 2
    * Expected: 3
3. Maximum range, maximum K
    * Inputs: A = 0, B = 2000000000, K = 2000000000
    * Expected: 2
4. Maximum range, minimum K
    * Inputs: A = 0, B = 2000000000, K = 1
    * Expected: 2000000001

## Score

This solution scored:
 - 100% for correctness.
 - 100% for required performance.

