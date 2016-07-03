#include <stdio.h>

int solution(int A[], int N)
{
    // Allocate and intialise count array N+1 elements to all 0.
    int count[N+1];
    for (int i=0; i<N+1; i++)
        count[i] = 0;

    // Loop through all elements of array A.
    for (int i=0; i<N; i++) {
        // If 1 <= current element <= N and has not been counted,
        // mark that value as counted.
        if (1 <= A[i] && A[i] <= N && !count[A[i]])
            count[A[i]] = 1;
    }
    // Loop through all elements in the count array
    for (int i=1; i<N+1; i++) {
        // If the index at this count element has not been counted,
        // then this is the minimum positive missing int, return that.
        if (!count[i])
            return i;
    }
    // If the loop finished, the minimum missing positive int is N+1
    return N + 1;
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
    int test0[] = { 1 };                // min pos int is N + 1
    int test1[] = { 2 };                // min pos int is 1
    int test2[] = { 1, 3, 6, 4, 1, 2};  // Example, min pos int is 6
    int testmax[max];

    // Initialise the array with maximum N elements, sequence 1..100000.
    // Largest valid permutation.
    for (int i=0; i<max; i++) {
        testmax[i] = i + 1;
    }

    printf("PermCheck\n");

    // N = 1, min pos int is N + 1
    test_case(test0, 1,  2);
    // N = 1, min pos int is 1
    test_case(test1, 1,  1);
    // Example
    test_case(test2, sizeof(test2)/sizeof(int), 5);

    // N = 100000, A = [1 .. 100000],  min pos int is 100001
    test_case(testmax, max, 100001);

    // N = 100000, [1 .. 99998, -2147483638, 2146483647]
    // Min pos int is 99999
    testmax[99999] = 2146483647;
    testmax[99998] = -2147483638;
    test_case(testmax, max, 99999);

    return 0;
}
