# cod1l1ty Lesson 5: Prefix Sums
## Exercise 3: [GenomicRangeQuery](https://codility.com/programmers/task/genomic_range_query/)

Briefly, a string S of length N contains a Genmoic sequence of nucleotides,
consisting of  'A', 'C'
'G' and 'T', which have the impact factors A = 1, C = 2, G =3 and T = 4. Given
two arrays, P and Q, both of M integers which describe a slice into the Genomic
string, return the minimal impact factors of the nucleotides in those slices.

Example:
- Inputs: S = "CAGCCTA", P = [2, 5, 0], Q = [4, 5, 6], M = 3
- Expected operation:
    - Slice P[0] = 2 to Q[0] = 4 contains 'GCC', the lowest impact is 'C' = 2.
    - Slice P[1] = 5 to Q[1] = 5 contains 'T', the lowest imact is 'T' = 4.
    - Slice P[2] = 0 to Q[2] = 6 contains the whole genome, the lowest imact
    is 'A' = 1.
- Expected: Results { A = [2, 4, 1], M = 3 }

Expected worst-case time complexity is O(N+M), and worst-case space complexity
is O(N) beyond input storage.

## My solution

This one really stumped me for a while. The trick is to use postfix count for
each nucleotide of it's last index position.

For example, with the example given, use 4 arrays, one for each nucleotide, and
then process the genom string into those arrays such that the last postion of
each type of nucleotide is recorded for that index. This is done postfix i.e.
make the arrays N+1 and set the last element -1. Then process the Genome string
from the back to front.

For the example the postfix sums for the example should be as follows:
```
    nuc_A[] = [  1,  1,  6,  6,  6,  6, -1 ]
    nuc_C[] = [  0,  3,  3,  3,  4, -1, -1 ]
    nic_G[] = [  2,  2,  2, -1, -1, -1, -1 ]
    nic_T[] = [  5,  5,  5,  5,  5, -1, -1 ]
```

After processing the postfix sums, process the slices. The minimal impact well
be the the nucleotide for which the postfix value at index P[K] is <= Q[K], in
order A to T.

## Test Cases

1. Example given
    * Inputs: S = "CAGCCTA", P = [2, 5, 0], Q = [4, 5, 6], M = 3
    * Expected: Results { A = [2, 4, 1], M = 3 }
2. N = 100000, M = 50000, genome is random
    * Inputs: S = "????..." P & Q have M random elements such that 1 <=P <=Q
3. N = 100000, M = 50000, genome is all one nucleotide.
    * Inputs: S = "TTTT ... T", P & Q as before.

## Score

This solution scored:
 - 100% for correctness.
 - 100% for required performance, which is O(N+M).
