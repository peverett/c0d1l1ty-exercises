# c0d1l1ty Lesson 2
## Exercise 1: [CyclicRotation](https://codility.com/programmers/task/cyclic_rotation/)

Given a zero indexed array of N integers, rotate the array to the right by K.

For example;
    - Given array [1, 2, 3, 4, 5] to be shifted by K = 3.
    - The expected result would be [3, 4, 5, 1, 2]

##My solution

The solution requires the return of `stuct Results`, which is:
```
struct Results {
    int *A;
    int N;
};
```

Map the input array A to result.A at index (i) plus the required offset K,
mod N.

## Test Cases

1. Empty Array
    - Inputs: A = [], N = 0, K = 0
    - Expected: result.A = [], result.N = 0
2. One element array, any rotation.
    - Inputs: A = [1], N = 1, K = 10
    - Expected: result.A = [1], result.N = 1
3. No rotation
    - Inputs: A = [1, 2, 3, 4, 5], N = 5, K = 0
    - Expected: result.A = [1, 2, 3, 4, 5], result.N = 5
4. Rotation K < N
    - Inputs: A = [1, 2, 3, 4, 5], N = 5, K = 3
    - Expected: result.A = [3, 4, 5, 1, 2], result.N = 5
5. Rotation K > N
    - inputs: A = [1, 2, 3, 4, 5], N = 5, K = 8
    - Expected: result.A = [3, 4, 5, 1, 2], result.N = 5
6. Rotation K == N
    - inputs: A = [1, 2, 3, 4, 5], N = 5, K = 5
    - Expected: result.A = [1, 2, 3, 4, 5], result.N = 5

## Score
My solution scored 100% for correctness. This exercise is not measured for
efficiency
