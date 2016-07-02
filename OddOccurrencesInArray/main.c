#include <stdio.h>

int solution(int A[], int N)
{
   int odd = 0;
   for (int i=0; i<N; i++) {
       odd ^= A[i];
   }
   return odd;
}

void test_case(int A[], int N, int exp_res)
{
    int res = solution(A, N);

    printf("\nInput: [ ");
    for (int i=0; i<N; i++) printf("%d ", A[i]);
    printf("], N=%d\nExpected: %d\n", N, exp_res);
    printf("Result: %d\n", res);

    printf("%s\n", (res == exp_res) ? "PASS" : "FAIL");
}

int main(void)
{
    int test0[] = { 99 };
    int test1[] = { 7, 3, 9, 3, 9 };
    int test2[] = { 9, 3, 9, 3, 7 };
    int test3[] = { 9, 3, 7, 3, 9 };

    printf("OddOccurrencesInArray\n");

    test_case(test0, 1, 99);
    test_case(test1, 5, 7);
    test_case(test2, 5, 7);
    test_case(test3, 5, 7);

    return 0;
}

