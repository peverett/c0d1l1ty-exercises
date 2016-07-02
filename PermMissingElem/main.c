#include <stdio.h>
#include <limits.h>

int solution(int A[], int N)
{
   // Calculate the sum of the arithmetic sequence of N + 1.
   long long sum = (long long)(N + 1) * (long long)(N + 2) / 2;

   // Loop through the elements and subtract them from the sum.
   for (int i=0; i<N; i++) sum -= A[i];

   // Whatever is left is the missing number in the sequence.
   return (int)sum;
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
    const int max = 100000;
    const int missing = 87654;
    int test0[] = { 1 };                // N = 1
    int test1[] = { 2, 3, 1, 5 };       // Example
    int test2[] = { 2, 3, 4, 5, 6 };    // 1st number missing in sequence.
    int test3[] = { 1, 3, 2, 5, 4 };    // Last number missing in sequence.
    int test4[max];                     // Maximum N

    printf("PermMissingElem\n");

    // Maximum size of N, ensure the 'missing' value is skipped.
    for (int i=1; i<=max; i++) {
        if ( i < missing)
            test4[i-1] = i;
        else
            test4[i-1] = i+1;
    }

    test_case(NULL, 0, 1);                             // N = 0
    test_case(test0, sizeof(test0)/sizeof(int), 2);    // N = 1
    test_case(test1, sizeof(test1)/sizeof(int), 4);
    test_case(test2, sizeof(test2)/sizeof(int), 1);
    test_case(test3, sizeof(test3)/sizeof(int), 6);
    test_case(test4, sizeof(test4)/sizeof(int), missing);

    return 0;
}

