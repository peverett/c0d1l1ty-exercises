#include <stdio.h>

int solution(int A[], int N)
{
    // Allocate and intialise count array N+1 elements to all 0.
    int count[N+1];
    for (int i=0; i<N+1; i++)
        count[i] = 0;

    // Loop through all elements of array A.
    for (int i=0; i<N; i++) {
        // If current element value > N or already counted, return 0
        if (A[i] > N || count[A[i]])
            return 0;
        // Else count this current element value as seen
        else
            count[A[i]] = 1;
    }
    // If the loop ends, the permutation is valid.
    return 1;
}

#define MIN(X,Y) (((X)<(Y)) ? (X) : (Y))
void test_case(int A[], int N, int exp_res)
{
    int res = solution(A, N);
    int max = MIN(N, 7);

    printf("\nInput: A = [ ");

    for (int i=0; i<max; i++) printf("%d ", A[i]);
    if (max == 7) {
        printf("... %d ", A[N-1]);
    }

    printf("], N = %d\n", N);
    printf("Result: %d\n", res);

    printf("Expected: %d\n", exp_res);
    printf("%s\n", (res == exp_res) ? "PASS" : "FAIL");
}

int main(void)
{
    const int max = 100000;             // N = 1..100,000
    int test0[] = { 1 };                // Smallest valid permutation
    int test1[] = { 2 };                // Smallest invalid permutation
    int test2[] = { 4, 1, 3, 2 };       // Example valid permutation
    int test3[] = { 4, 1, 3 };          // Example invalid permutation
    int test4[] = { 4, 1, 3, 3 };       // Repeated value, invalid permutation
    int testmax[max];

    // Initialise the array with maximum N elements, sequence 1..100000.
    // Largest valid permutation.
    for (int i=0; i<max; i++) {
        testmax[i] = i + 1;
    }

    printf("PermCheck\n");

    // N = 1, valid permutation
    test_case(test0, 1,  1);
    // N = 1, invalid permutation
    test_case(test1, 1,  0);
    // Example valid permutation
    test_case(test2, sizeof(test2)/sizeof(int), 1);
    // Example invalid permutation
    test_case(test3, sizeof(test3)/sizeof(int), 0);
    // Repeated value, invalid permutation
    test_case(test4, sizeof(test4)/sizeof(int), 0);
    // N = 100000, A = [1 .. 10000], valid permutation.
    test_case(testmax, max, 1);
    // N = 100000, A = [1 .. 99999, 1000000000], invalid permutation.
    testmax[99999] = 1000000000;
    test_case(testmax, max, 0);

    return 0;
}
