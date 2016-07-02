#include <stdio.h>

int solution(int X, int Y, int D)
{
    return ((Y - X) + D - 1) / D;
}

void test_case(int X, int Y, int D, int exp_res)
{
    int res = solution(X, Y, D);
    printf("\nInput: X = %d, Y = %d , D = %d\n", X, Y, D);
    printf("Expected: %d\n", exp_res);
    printf("Result: %d\n", res);
    printf("%s\n", (res == exp_res) ? "PASS": "FAIL");
}

int main(void)
{
    printf("FrogJmp\n");

    test_case(1, 1000000000, 1000000000, 1);        // Worst case.
    test_case(10, 85, 30, 3);                       // Given example.

    return 0;
}

