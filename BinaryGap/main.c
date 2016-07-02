#include <stdio.h>

/* BinaryGap
 * https://codility.com/programmers/task/binary_gap/
 */

int solution(int N)
{
    int gap = 0;
    int longest = 0;

    /* Find the first '1', moving from Least Significant Bit (LSB) up towards
     * the Most Significant Bit (MSB).
     */
    while (N && (N & 1) == 0) {
        N >>= 1;
    }

    /* if bit is 0, increase gap count. If bit is 1, record gap count if it
     * is the longest so far, then reset the gap count.
     */
    while (N) {
        if ((N & 1) == 0) {
            gap++;
        }
        else {
            if (gap > longest) longest = gap;
            gap = 0;
        }
        N >>= 1;
    }

    return longest;
}

struct Test {
    int N;
    int exp_res;
};

void print_bin(int N)
{
    if (N) print_bin(N >> 1);
    printf("%d", (N&1) ? 1 : 0);
}

void test_case(struct Test test_data)
{
    int res = solution(test_data.N);

    printf("\nInput: %d 0x%X 0b", test_data.N, test_data.N);
    print_bin(test_data.N);
    printf("\nGap:     %d\n", res);

    if (res == test_data.exp_res)
        printf("PASS\n");
    else
        printf("FAIL\n");
}

int main(void)
{
    struct Test test[] = {
    { 0, 0 },       // No gap.
    { 1, 0 },       // No gap
    { 3, 0 },       // All 1's - No gap.
    { 5, 1 },
    { 15, 0 },      // All 1's - No gap.
    { 9, 2 },
    { 529, 4 },
    { 20, 1 },
    { 0x1418, 5 },
    { 1041, 5 },
    };

    int test_count = sizeof(test)/sizeof(struct Test);

    printf("BinaryGap\n");

    for(int i=0; i<test_count; i++) {
        test_case(test[i]);
    }

    return 0;
}

