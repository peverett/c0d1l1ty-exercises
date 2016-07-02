#include <stdio.h>
#include <stdlib.h>

struct Results {
    int *A;
    int N;
};

struct Results solution(int A[], int N, int K)
{
    struct Results result;

    /* Initialise the result structure. */
    result.A = (int *)malloc(N * sizeof(int));
    result.N = N;

    /* Map the position in the result array by offset of K, mod N. */
    for (int i=0; i<N; i++) {
        result.A[(i+K)%N] = A[i];
    }
    return result;
}

struct TestData {
    int *A;
    int N;
    int K;
    int *exp_res;
};

void test_case(struct TestData test_data)
{
    struct Results res = solution(test_data.A, test_data.N, test_data.K);
    int fail = 0;

    printf("\nInput:  [ ");
    for (int i=0; i<test_data.N; i++) printf("%d ", test_data.A[i]);
    printf("] N=%d K=%d\n", test_data.N, test_data.K);

    printf("Result: [ ");
    for (int i=0; i<test_data.N; i++) {
        printf("%d ", res.A[i]);
        if (test_data.exp_res[i] != res.A[i]) {
            fail = 1;
        }
    }
    free(res.A);
    printf("]\n%s\n", (fail) ? "FAIL" : "PASS");
}

int main(void)
{
    int input0[] = { 1 };
    int input1[] = { 1, 2, 3, 4, 5 };
    int result1[] = { 3, 4, 5, 1, 2 };
    struct TestData test_data[] = {
      { NULL, 0, 0, NULL },         // Default - empty array
      { input0, 1, 5, input0 },     // 1 element, rotation does nothing
      { input1, 5, 0, input1 },     // No rotation.
      { input1, 5, 3, result1 },    // K < N
      { input1, 5, 8, result1 },    // K > N
      { input1, 5, 5, input1 }      // K == N
    };
    int test_count = sizeof(test_data)/sizeof(struct TestData);

    printf("CyclicRotation\n");

    for (int i=0; i<test_count; i++) {
        test_case(test_data[i]);
    }

    return 0;
}

