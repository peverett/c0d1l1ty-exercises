# c0d1l1ty Lesson 5: Prefix sums
## Exercise 1: [PassingCars](https://codility.com/programmers/task/passing_cars/)

A non-empty zero-indexed array A consists of N integers. Consecuticve elements 
of the array represent cars on a road
* 0 - represents a car travelling East
* 1 - represents a car travelling West

The task is to count passing cars. A pair of cars (P, Q) is passing when P is
travelling East and Q is travelling West.

Example:
* Input: A = [ 0, 1, 0, 1, 1 ]
* Expects: five pairs of passing cars:
    - (0, 1), (0, 3), (0, 4), (2, 3), (2, 4)
    
Write a function:
```
    int solution(int A[], int N);
```
That returns the number of passing pairs. Return -1 if the number of passing 
cars exceeds 1,000,000,000.

##My solution

My first solution only scored 80% for correctness. It failed one of the 'double'
element test cases. I made the assumption that which ever car started first,
East or West-bound, would pass the next going in the other direction.

### 1st solution
1. Initialise `passes` to 0 and `dir` to 1.
2. loop though elements 1 to N-1 of the array A
    * If the current element is != to the first element A[0].
        * Increment `passes` by cars in the opposite direction `dir`
        * if `passes` > 1,000,000,000, return -1;
    * else
        * Increment the cars going in the same direction `dir` as the first.
3. Return `passes`

It seems this assumption was incorrect. Passes are only counted from the
first east bound car -> see this [following feedback](https://codility.uservoice.com/forums/34245-general/suggestions/5471389-passing-cars-test-case-not-correct)
on 'Passing Cars'.

### 2nd Solution.

1. Initialise `passes` to 0 and `east` to 1;
2. Loop through A until the first East-bound car (0), this is the 'first'
3. Loop through A from 'first' + 1 to N-1
    * If current car (element) is not East bound (not 0)
        * Increment `passes' by cars going `east`
        * if `passes` > 1,000,000,000, return -1
    * Else
        * Increment the cars going `east` by 1
4. Return `passes`

## Test Cases

1. Minimal inputs - no passing cars
    * Inputs: A = [ 1 ], N = 1
    * Expected: 0
2. N = 100000 - no passing cars
    * Inputs: A = [ 0, 0, ... 0], N = 1
    * Expected: 0
3. Example
    * Inputs: A = [ 0, 1, 0, 1, 1 ], N = 0;
    * Expected: 5
4. N = 100000, maximum passing cars
    * Inputs: A = [ 0, 1, 0, 1, .. 1], N = 100000
    * Expected = -1
5. West-bound cars first - only count from first East-bound
    * Inputs: A = [ 1, 0, 1, 0, 1, 1 ], N = 0;
    * Expected: 5

Test case 5 was added to test my 2nd implementation.

## Score

1st attempt scored:
- 80% for correctness.
- 100 for performance, which is O(N).

2nd attempt scored:
 - 100% for correctness.
 - 100% for required performance.
