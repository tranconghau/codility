/* Ref: https://app.codility.com/programmers/lessons/3-time_complexity/tape_equilibrium/
A non-empty array A consisting of N integers is given. Array A represents numbers on a tape.

Any integer P, such that 0 < P < N, splits this tape into two non-empty parts: A[0], A[1], ..., A[P − 1] and A[P], A[P + 1], ..., A[N − 1].

The difference between the two parts is the value of: |(A[0] + A[1] + ... + A[P − 1]) − (A[P] + A[P + 1] + ... + A[N − 1])|

In other words, it is the absolute difference between the sum of the first part and the sum of the second part.

For example, consider array A such that:

  A[0] = 3
  A[1] = 1
  A[2] = 2
  A[3] = 4
  A[4] = 3
We can split this tape in four places:

P = 1, difference = |3 − 10| = 7
P = 2, difference = |4 − 9| = 5
P = 3, difference = |6 − 7| = 1
P = 4, difference = |10 − 3| = 7
Write a function:

int solution(int A[], int N);

that, given a non-empty array A of N integers, returns the minimal difference that can be achieved.

For example, given:

  A[0] = 3
  A[1] = 1
  A[2] = 2
  A[3] = 4
  A[4] = 3
the function should return 1, as explained above.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [2..100,000];
each element of array A is an integer within the range [−1,000..1,000].
Copyright 2009–2019 by Codility Limited. All Rights Reserved. Unauthorized copying, publication or disclosure prohibited.
*/
#include <stdio.h>

int sumArray(int A[], int begin, int end)
{
    int i;
    int N = end - begin + 1;
    int sum = 0;
    for(i = 0; i < N; i++)
        sum = sum + A[begin+i];

    return sum;
}

int solution(int A[], int N) {
    // write your code in C99 (gcc 6.2.0)
    int P = 1;
    int sum = 0, i;
    unsigned int myABS = 0;
    unsigned int miniDif = -1;//max value of unsigned int
    int totalSum = sumArray(A,0,N-1);

    if(N < 2 || N > 100000)
        return -1;

    for (i = 0; P < N && i < N; P++, i++)
    {
        sum = sum + A[i];
        //sum2 = sumArray(A, P, N-1);
        //printf("Sum1: %d\n", sum1);
        //printf("Sum2: %d\n", sum2);
        //printf("=======================\n");
        //myABS = (sum > (totalSum - sum)) ? (sum - (totalSum - sum)) : ((totalSum - sum) - sum);
        myABS = (sum > (totalSum - sum)) ? (2*sum - totalSum) : (totalSum - 2*sum);

        miniDif = (miniDif > myABS) ? myABS : miniDif;

        if (miniDif == 0)
        	break;
    }

    return miniDif;
}

int main()
{
	int A[5] = {3,1,2,4,3};
	if(solution(A, 5) == 1)
		return 0;

	return -1;
}
