#include <stdio.h>
#include <stdlib.h>

int solution(int A[], int N)
{
    int difference;
    int lowest_difference = 1000 * 100000;
    int right_sum = 0;
    int left_sum = 0;

    /* Calculate the sum of the entire array. */
    for (int i=0; i<N; i++) right_sum += A[i];

    /* Now loop through, recalculating left and right as we go and
     * store the lowest difference.
     */
    for (int i=0; i<N-1; i++) {
        left_sum += A[i];
        right_sum -= A[i];
        difference = abs(right_sum - left_sum);
        if (difference < lowest_difference)
            lowest_difference = difference;
    }
    return lowest_difference;
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
    printf("], N=%d\n", N);
    printf("Result: %d\n", res);

    if (exp_res >= 0) {
        printf("Expected: %d\n", exp_res);
        printf("%s\n", (res == exp_res) ? "PASS" : "FAIL");
    }
}

int main(void)
{
    const int max = 100000;               // N = 2..100,000
    int test0[] = { 3, 1, 2, 4, 3 };
    int test1[max];
    int test2[max];

    // Initialise array with maximum N elements, random elements in range.
    // -1000 to 1000.
    for (int i=0; i<max; i++) {
        test1[i] = (rand() % 2001) - 1000;
    }

    // Initialise the array with maximum N elements, all 1000.
    for (int i=0; i<max; i++) {
        test2[i] = 1000;
    }

    printf("TapeEquilibrium\n");
    test_case(test0, sizeof(test0)/sizeof(int), 1);
    test_case(test1, max, -1);
    test_case(test2, max, 0);

    return 0;
}

