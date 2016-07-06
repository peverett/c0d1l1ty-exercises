#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Results {
    int *A;
    int M;
};

int get_nuc_map(char c) {
    switch (c) {
        case 'A': return 0;
        case 'C': return 1;
        case 'G': return 2;
        case 'T': return 3;
    }
    return -1;
}

struct Results solution(char *S, int P[], int Q[], int M) {
    const int max_nuc=4;
    unsigned int N = strlen(S);
    struct Results result;

    // Allocate and initialise results
    result.A = (int *)malloc(M * sizeof(int));
    result.M = M;

    // Allocate postfix sums for the postition of the next nucleotide.
    // Intialise element[N] to -1, for each.
    int *nextnuc[max_nuc];
    for (int i=0; i<max_nuc; i++) {
        nextnuc[i] = (int *)malloc((N+1) * sizeof(int));
        nextnuc[i][N] = -1;
    }

    // For all nucleotides in in S, postfix count the position the last
    // for each type.
    for (int i=N-1; i>=0; i--) {
        for (int j=0; j<max_nuc; j++) {
            if (get_nuc_map(S[i]) == j)
                nextnuc[j][i] = i;
            else
                nextnuc[j][i] = nextnuc[j][i+1];
        }
    }

    // Go through the P[] - Q[] slices. For each element of a slice, go through
    // the nucleotide next index position for P[K]. If it is Q[K] is <= then
    // return it's impact value.
    for (int i=0; i<M; i++) {
        for (int j=0; j<max_nuc; j++) {
            if (nextnuc[j][P[i]] != -1 && nextnuc[j][P[i]] <= Q[i]) {
                result.A[i] = j + 1;
                break;
            }
        }
    }

    return result;
}

#define MIN(X,Y) (((X)<(Y)) ? (X) : (Y))
void print_array( char array_legend, int arr[], char len_legend, int len)
{
    int max = MIN(len, 7);

    printf("%c = [ ", array_legend);
    for (int i=0; i<max; i++) printf("%d ", arr[i]);
    if (max == 7) {
        printf("... %d ", arr[len-1]);
    }
    printf("], %c = %d\n", len_legend, len);
}

void test_case(char *S, int P[], int Q[], int M, struct Results *exp_res)
{
    struct Results res;
    int fail = 0;
    unsigned int i;
    unsigned int N = strlen(S);

    printf("\nInputs: S = ");
    for (i=0; i<N && S[i] != 0 && i < 20; i++) {
        printf ("%c", S[i]);
    }
    if (N > i) {
        printf("...\n");
    }
    else {
        printf("\n");
    }

    printf("        ");
    print_array( 'P', P, 'M', M);
    printf("        ");
    print_array( 'Q', Q, 'M', M);

    res = solution(S, P, Q, M);

    printf("Result: ");
    print_array( 'A', res.A, 'C', res.M);

    if (exp_res) {
        printf("Expected: ");
        print_array('A', exp_res->A, 'C', exp_res->M);

        if (exp_res->M != res.M)
            fail = 1;
        else {
            for(int i=0; i< res.M; i++) {
                if (exp_res->A[i] != res.A[i]) {
                    fail = 1;
                    break;
                }
            }
        }
        printf("%s\n", (fail) ? "FAIL" : "PASS");
    }
}

int main(void)
{
    const int max_n = 100000;             // N = 100,000
    const int max_m = 50000;              // N = 50,000

    // Example given
    char S0[] = "CAGCCTA";
    int P0[] = {2, 5, 0};
    int Q0[] = {4, 5, 6};
    int A0[] = {2, 4, 1};
    int M0 = sizeof(P0)/sizeof(int);
    struct Results res0 = { A0, M0 };

    char S1[max_n+1];
    int P1[max_m];
    int Q1[max_m];

    test_case(S0, P0, Q0, M0, &res0);

    // Max sure S1 is 0 terminated
    S1[max_n] = '\0';

    // Maximum random slices
    for (int i=0; i<max_m; i++) {
        // two random numbers, range 1..N, set lowest to P, highest to Q.
        int r1 = (rand() % max_n) + 1;
        int r2 = (rand() % max_n) + 1;
        if (r1 <= r2)
            P1[i] = r1, Q1[i] = r2;
        else
            P1[i] = r2, Q1[i] = r1;
    }

    // Maximum random S
    for (int i=0; i<max_n; i++) {
        switch (rand() % 4) {
            case 0:
                S1[i] = 'A';
                break;
            case 1:
                S1[i] = 'C';
                break;
            case 2:
                S1[i] = 'G';
                break;
            case 3:
                S1[i] = 'T';
                break;
        }
    }

    test_case(S1, P1, Q1, max_m, NULL);

    // Maxmum S all the same nucleotide T.
    for (int i=0; i<max_n; i++) {
        S1[i] = 'T';
    }
    test_case(S1, P1, Q1, max_m, NULL);


}


