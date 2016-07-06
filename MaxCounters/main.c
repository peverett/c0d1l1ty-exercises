#include <stdio.h>
#include <stdlib.h>

struct Results {
    int *C;
    int L;
};

struct Results solution(int N, int A[], int M) {
    struct Results result;
    int max_count = 0;
    int highest_count = 0;

    // Allocate and initialise results
    result.C = (int *)calloc(N, sizeof(int));
    result.L = N;

    // Loop through all elements of array A
    for (int i=0; i<M; i++) {
        // If current element == N+1
        if (A[i] == N+1) {
            // Set the Max Count to the Highest Count so far.
            max_count = highest_count;
        }
        else {
            // If the count for the Current Element is less than the
            // Max Count so far
            if (result.C[A[i]-1] < max_count)
                // Set the count to the Max Count
                result.C[A[i]-1] = max_count;
            // Increment the count for the Current Element
            result.C[A[i]-1]++;
            // If the count for the Current Element is the Highest Count so far
            if (result.C[A[i]-1] > highest_count)
                // Store it as the Highest Count
                highest_count = result.C[A[i]-1];
        }
    }

    // Loop through all the counters
    for (int i=0; i<N; i++) {
        // If the current counter is less than the Max Count
        if (result.C[i] < max_count)
            // Make the counter equal to the Max Count.
            result.C[i] = max_count;
    }

    return result;
}

#define MIN(X,Y) (((X)<(Y)) ? (X) : (Y))
void print_array( char array_legend, int arr[], char len_legend, int len)
{
    int max = MIN(len, 8);

    printf("%c = [ ", array_legend);
    for (int i=0; i<max; i++) printf("%d ", arr[i]);
    if (max == 8) {
        printf("... %d ", arr[len-1]);
    }
    printf("], %c = %d\n", len_legend, len);
}

void test_case(int N, int A[], int M, struct Results *exp_res)
{
    struct Results res; // = solution(N, A, M);
    int fail = 0;

    printf("\nInput: N = %d, ", N);
    print_array( 'A', A, 'M', M);

    res = solution(N, A, M);

    printf("Result: ");
    print_array( 'C', res.C, 'L', res.L);

    if (exp_res) {
        printf("Expected: ");
        print_array('C', exp_res->C, 'L', exp_res->L);

        if (exp_res->L != res.L)
            fail = 1;
        else {
            for(int i=0; i< res.L; i++) {
                if (exp_res->C[i] != res.C[i]) {
                    fail = 1;
                    break;
                }
            }
        }
        printf("%s\n", (fail) ? "FAIL" : "PASS");
    }
}

int main(void)
{
    const int max = 100000;             // N = M = 1..100,000

    // N = 1, A = [1], M = 1
    int test0[] = { 1 };
    int res0[] = { 1 };
    struct Results exp_res0 = { res0, 1 };

    // Exercise example
    int test1[] = { 3, 4, 4, 6, 1, 4, 4 };
    int res1[] = { 3, 2, 2, 4, 2 };
    struct Results exp_res1 = { res1, 5 };

    // All max counters
    int test2[] = { 6, 6, 6, 6, 6, 6, 6 };
    int res2[] = { 0, 0, 0, 0 , 0 };
    struct Results exp_res2 = { res2, 5 };

    // Two Max Counters
    int test3[] = { 3, 4, 4, 6, 1, 6, 4 };
    int res3[] = { 3, 3, 3, 4, 3 };
    struct Results exp_res3 = { res3, 5 };

    // Maximum values
    int testmax[max];
    for (int i=0; i<max; i++) {
        testmax[i] = (rand() % max) + 1;   // 1..100001.
    }

    printf("MaxCounters\n");

    // N = 1, A = [1], M = 1
    test_case(1, test0, 1, &exp_res0);

    // Exercise example
    test_case(5, test1, 7, &exp_res1);

    // All max counters
    test_case(5, test2, 7, &exp_res2);

    // Two max counters
    test_case(5, test3, 7, &exp_res3);

    // Maximum values
    test_case(max, testmax, max, NULL);
    return 0;
}
