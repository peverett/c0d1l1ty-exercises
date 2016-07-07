#include <stdio.h>

int solution(int A[], int N)
{
    int minimal = N;
    float smallest = 10000.0;
    float avg;

    int sums[N+1];
    sums[0] = 0;
    for (int i=1; i<N+1; i++) {
       sums[i] = sums[i-1] + A[i-1];
    }

    for (int p=0; p<N-1; p++) {
        for (int q=p+1; q<N; q++ ) {
            avg = (sums[q+1] - sums[p]) / (float)((q-p) + 1);
            if (avg < smallest) {
                   smallest = avg;
                   minimal = p;
            }
        }
    }
    return minimal;
}

int solution1(int A[], int N)
{
    int val, pos = 0, min = 60000;

    for (int i=0; i<N-1; i++) {
        val = (A[i] + A[i+1]) * 3;
        if (val < min) {
            min = val;
            pos =i;
        }
    }
    for (int i=0; i<N-2; i++) {
        val = (A[i] + A[i+1] + A[i+2]) * 2;
        if (val < min) {
            min = val;
            pos =i;
        }
    }
    return pos;
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
    int res, res1;

    printf("Inputs: ");
    print_array('A', A, 'N', N);

    res = solution(A, N);
    printf("Result my solution  : %d\n", res);

    res1 = solution1(A, N);
    printf("Result best solution: %d\n", res1);

    if (exp_res > 0) {
        printf("%s\n", (exp_res == res) ? "PASS" : "FAIL");
    }
}

int main(void)
{
    printf("MinAvgTwoSlice\n");

    int test0[] = {4, 2, 2, 5, 1, 5, 8};
    int test1[] = {1, 2, 3, 4, 5, 6, 7};
    int test2[] = {7, 6, 5, 4, 3, 2, 1};
    int test3[] = {1, 2, 4, 6, 4, 2, 1};

    test_case( test0, sizeof(test0)/sizeof(int), 1);
    test_case( test1, sizeof(test1)/sizeof(int), 0);
    test_case( test2, sizeof(test2)/sizeof(int), 5);
    test_case( test3, sizeof(test3)/sizeof(int), 0);
    return 0;
}

