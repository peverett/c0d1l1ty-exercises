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
    if (N==3) return (A[0] * A[1] * A[2]);
    // Use a quicksort on the input array.

    qsort(A, N, sizeof(int), comp);

    int x = A[0] * A[1] * A[N-1];
    int y = A[N-3] * A[N-2] * A[N-1];
    return (x > y) ? x : y;

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

void test_case(int A[], int N, int exp_res)
{
    int res;

    printf("\nInputs: ");
    print_array('A', A, 'N', N);

    res = solution(A, N);
    printf("Result: %d\n", res);

    if (exp_res >= 0) {
        printf("Expected: %d\n", exp_res);
        printf("%s\n", (exp_res == res) ? "PASS" : "FAIL");
    }
}

int main(void)
{
    printf("Distinct\n");

    const int max = 100000;
    int test0[] = {1, 2, 3};                // Only three elements
    int test1[] = {-3, 1, 2, -2, 5, 6};     // Example
    int test2[] = { -10, -15, 0 };          // Result is 0
    int test3[] = { -33, -22, -11, -5, 5};  // Max product is -33 * -22 * 5
    int test4[] = { -33, -22, 0, 5, 3};     // Max product is -33 * -22 * 5
    int test5[] = { -33, -22, -11, -5, -4, -1};     // Max product is negative.
    int testmax[max];

    test_case(test0, sizeof(test0)/sizeof(int), 6);
    test_case(test1, sizeof(test1)/sizeof(int), 60);
    test_case(test2, sizeof(test2)/sizeof(int), 0);
    test_case(test3, sizeof(test3)/sizeof(int), 3630);
    test_case(test4, sizeof(test4)/sizeof(int), 3630);
    test_case(test5, sizeof(test5)/sizeof(int), -20);

    // Max N (N=100000), random values between -1000 .. 1000.
    for (int i=0; i<max; i++) {
        int val = (rand() % 1001);
        if ((rand() % 2)) {
            val = 0 - val;
        }
        testmax[i] = val;
    }
    test_case(testmax, max, -1);

    // All max negative value
    for (int i=0; i<max; i++) {
        testmax[i] = -1000;
    }
    test_case(testmax, max, -1000000000);
}

