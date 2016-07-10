#include <stdio.h>
#include <stdlib.h>

int comp(const void *left, const void *right)
{
    int l = *((int*)left);
    int r = *((int*)right);
    if (r < l) return 1;
    if (r > l) return -1;
    return 0;
}

int solution(int A[], int N)
{
    // Remove values < 1 from A.
    int x = 0;
    for (int i=0; i<N; i++) {
        if (A[i] < 1) continue;
        else A[x++] = A[i];
    }
    N = x;

    // At least three elements needed.
    if (N < 3) return 0;

    // Sort the input array
    qsort(A, N, sizeof(int), comp);

    // P for all elements of A to N-2
    for(int P=0; P<N-2; P++) {
        long long p = A[P];
        // Q from P+1 to N-1;
        for (int Q=P+1; Q < N-1; Q++) {
            long long q = A[Q];
            // R is Q + 1
            long long r = A[Q+1];
            // If P + Q > R, this is a triangle, return 1.
            if (r < (q + p)) return 1;
        }
    }
    return 0;
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

void triangle(int N)
{
    // All the valid numbers from 1 to N that make a triangle
    for (int p=1; p<=N; p++) {
        for (int q=p; q<=N; q++) {
            for (int r=q; r<=N; r++) {
                if (p+q > r && q+r > p && r+p > q)
                    printf("P = %d, Q = %d, R = %d\n", p, q, r);
            }
        }
    }
}


void test_case(int A[], int N, int exp_res)
{
    int res;

    printf("\nInputs: ");
    print_array('A', A, 'N', N);

    res = solution(A, N);
    printf("Result: %d\n", res);

    if (exp_res >= 0) {
        printf("%s\n", (exp_res == res) ? "PASS" : "FAIL");
    }
}

int main(void)
{
    printf("Triangle\n");

    const int max = 100000;
    int test0[] = {};
    int test1[] = {1, 2};
    int test2[] = {5, 8, 4};
    int test3[] = {5, 8, 2};
    int test4[] = {10, 2, 5, 1, 8, 20};
    int test5[] = {2147483647, 2147483647, 2147483647};
    int test6[] = {2, 2147483646, 2147483647};
    int testmax[max];

    //triangle(10);

    test_case(test0, sizeof(test0)/sizeof(int), 0);
    test_case(test1, sizeof(test1)/sizeof(int), 0);
    test_case(test2, sizeof(test2)/sizeof(int), 1);
    test_case(test3, sizeof(test3)/sizeof(int), 0);
    test_case(test4, sizeof(test4)/sizeof(int), 1);
    test_case(test5, sizeof(test5)/sizeof(int), 1);
    test_case(test6, sizeof(test6)/sizeof(int), 1);

    // Max N (N=100000), random values in 32-bit range.
    for (int i=0; i<max; i++) {
        int val = rand();
        if ((rand() % 2)) {
            val = 0 - val;
        }
        testmax[i] = val;
    }
    test_case(testmax, max, -1);

    // Max M (N=100000), all negative
    for (int i=0; i<max; i++) {
        testmax[i] = -1;
    }
    test_case(testmax, max, -1);
    return 0;
}

