#include <stdio.h>

int solution(int X, int A[], int N)
{
    if (N < X)
        return -1;
    else
    {
        // Calculate the sum of the arithmetic sequence 1..X.
        long long sum = (long long)(X) * (long long)(X+1) / 2;

        // Allocate and intialise count array to all 0.
        int count[X];
        for (int i=0; i<X; i++)
            count[i] = 0;

        // Loop through all the elements of A (leaves on the river, as they
        // fall).
        for (int i=0; i<N; i++) {
            // If not previously recorded in the count array
            if (!count[A[i]-1]) {
                // Subtract from sum
                sum -= A[i];
                // If sum is 0 return the index, this is the second the
                // frog can cross the river.
                if (sum == 0)
                   return i;
                // Indicate this leaf has been counted.
                count[A[i]-1] = 1;
            }
        }

        // If the loop finished, there is no way across.
        return -1;
    }
}

#define MIN(X,Y) (((X)<(Y)) ? (X) : (Y))
void test_case(int X, int A[], int N, int exp_res)
{
    int res = solution(X, A, N);
    int max = MIN(N, 9);

    printf("\nInput: X = %d, A = [ ", X);

    for (int i=0; i<max; i++) printf("%d ", A[i]);
    if (max == 9) {
        printf("... %d ", A[N-1]);
    }
    printf("], N = %d\n", N);
    printf("Result: %d\n", res);

    printf("Expected: %d\n", exp_res);
    printf("%s\n", (res == exp_res) ? "PASS" : "FAIL");
}

int main(void)
{
    const int max = 100000;               // X = N = 1..100,000
    int test0[] = { 1 };
    int test1[] = { 1, 3, 1, 4, 2, 3, 5, 4 };   // Example
    int test2[] = { 1, 3, 1, 4, 2, 4, 3, 4 };   // Frog can't make it.
    int test3[max];

    // Initialise the array with maximum N elements, sequence 1..100000.
    for (int i=0; i<max; i++) {
        test3[i] = i + 1;
    }

    printf("FrogRiverOne\n");

    // X = 1, A = [1], N = 1, frog can cross.
    test_case(1, test0, sizeof(test0)/sizeof(int), 0);
    // X = 2, A = [1], N = 1, frog can't cross.
    test_case(2, test0, sizeof(test0)/sizeof(int), -1);
    // Example, frog can make it.
    test_case(5, test1, sizeof(test1)/sizeof(int), 6);
    // Frog can't get across.
    test_case(5, test2, sizeof(test2)/sizeof(int), -1);
    // X = N = 100000, frog can cross.
    test_case(100000, test3, max, 99999);

    // X = N = 100000, frog can't cross. Change test data so there is a
    // gap.
    test3[666] = 777;
    test_case(100000, test3, max, -1);

    return 0;
}
