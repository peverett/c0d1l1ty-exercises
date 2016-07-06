#include <stdio.h>

int solution(int A, int B, int K)
{
    int inclusive = ((A%K)==0) ? 1 : 0;
    return (B/K) - (A/K) + inclusive;
}

void test_case(int A, int B, int K, int exp_res)
{
    int res = solution(A, B, K);

    printf("\nInput: A = %d, B = %d, K = %d\n", A, B, K);
    printf("Result: %d\n", res);
    printf("Expected: %d\n", exp_res);

    printf("%s\n", (exp_res == res) ? "PASS" : "FAIL");
}

int main(void)
{
    printf("CountDiv\n");

    // Minimum values
    test_case(0, 0, 1, 1);

    // Example
    test_case(6, 11, 2, 3);

    // Maximum Range, Maximum K
    test_case(0, 2000000000, 2000000000, 2);

    // Maximum Range, Minimum K
    test_case(0, 2000000000, 1, 2000000001);

    return 0;
}

