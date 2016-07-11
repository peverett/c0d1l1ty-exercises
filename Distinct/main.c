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
    int x = 0;

    if (!N) return 0;

    // Use a quicksort on the input array.
    qsort(A, N, sizeof(int), comp);

    // Count unique values;
    for (int i=0; i<N-1; i++) {
        if (A[i] != A[i+1])
            ++x;
    }

    return x+1;
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
        printf("%s\n", (exp_res == res) ? "PASS" : "FAIL");
    }
}

int main(void)
{
    printf("Distinct\n");

    const int max = 100000;
    int test0[] = {};                       // Empty array
    int test1[] = {1};                      // Only one element
    int test2[] = {2, 1, 1, 2, 3, 1};       // Example
    int test3[] = {1, 2, 3, 4, 5, 6};       // Worst case, 6 distinct numbers
    int testmax[max];

    test_case(test0, sizeof(test0)/sizeof(int), 0);
    test_case(test1, sizeof(test1)/sizeof(int), 1);
    test_case(test2, sizeof(test2)/sizeof(int), 3);
    test_case(test3, sizeof(test3)/sizeof(int), 6);

    // Max N (N=100000), random values between -1000000000 .. 1000000000.
    for (int i=0; i<max; i++) {
        int val = (rand() % 1000000001);
        if ((rand() % 2)) {
            val = 0 - val;
        }
        testmax[i] = val;
    }
    test_case(testmax, max, -1);

    // All max negative value
    for (int i=0; i<max; i++) {
        testmax[i] = -1000000000;
    }
    test_case(testmax, max, 1);
}


