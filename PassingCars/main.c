#include <stdio.h>

int solution(int A[], int N)
{
    int east = 1;
    int passes = 0;
    int start = 0;
    while (A[start]) start++;

    for (int i=start+1; i<N; i++) {
        if (A[i] != 0) {
            passes += east;
            if (passes > 1000000000)
                return -1;
       }
       else {
            east += 1;
       }
    }
    return passes;
}

#define MIN(X,Y) (((X)<(Y)) ? (X) : (Y))
void test_case(int A[], int N, int exp_res)
{
    int res = solution(A, N);
    int max = MIN(N, 8);

    printf("\nInput: A = [ ");

    for (int i=0; i<max; i++) printf("%d ", A[i]);
    if (max == 8) {
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
    int test0[] = { 1 };                // N = 1 - No passing cars
    int testmax[max];                   // N = 100000
    int test2[] = { 0, 1, 0, 1, 1};     // Example
    int test3[] = { 1, 0, 1, 0, 1, 1};  // Westbound car first.

    // Intialise test1 to all 0
    for (int i=0; i<max; i++)
        testmax[i] = 0;

    printf("PassingCars\n");

    // N = 1 - no passing cars
    test_case(test0, 1,  0);
    // N = 1, min pos int is 1
    test_case(testmax, max, 0);
    // Example
    test_case(test2, sizeof(test2)/sizeof(int), 5);
    // West cars first, last car east.
    test_case(test3, sizeof(test3)/sizeof(int), 5);

    // N = 100000, all passing - should trigger passes > 1000000000 condition.
    for (int i=1; i<max; i+=2)
        testmax[i] = 1;
    test_case(testmax, max, -1);

    return 0;
}


