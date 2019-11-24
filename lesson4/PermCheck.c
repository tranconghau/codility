/* Ref: https://app.codility.com/programmers/lessons/4-counting_elements/perm_check/
A non-empty array A consisting of N integers is given.

A permutation is a sequence containing each element from 1 to N once, and only once.

For example, array A such that:

    A[0] = 4
    A[1] = 1
    A[2] = 3
    A[3] = 2
is a permutation, but array A such that:

    A[0] = 4
    A[1] = 1
    A[2] = 3
is not a permutation, because value 2 is missing.

The goal is to check whether array A is a permutation.

Write a function:

int solution(int A[], int N);

that, given an array A, returns 1 if array A is a permutation and 0 if it is not.

For example, given array A such that:

    A[0] = 4
    A[1] = 1
    A[2] = 3
    A[3] = 2
the function should return 1.

Given array A such that:

    A[0] = 4
    A[1] = 1
    A[2] = 3
the function should return 0.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [1..100,000];
each element of array A is an integer within the range [1..1,000,000,000].
Copyright 2009–2019 by Codility Limited. All Rights Reserved. Unauthorized copying, publication or disclosure prohibited.
*/
void merge(int A[], int left, int mid, int right)
{
    int n1,n2;
    int i,j,k;
    
    n1 = mid - left + 1;
    n2 = right - mid;
    
    int L[n1], R[n2];
    
    for(i = 0; i < n1; i ++)
        L[i] = A[left+i];
        
    for(i = 0; i < n1; i ++)
        R[i] = A[mid+i+1];
        
    
    i = 0, j = 0, k = left;
    while(i < n1 && j < n2)
    {
        if(L[i] < R[j])
        {
            A[k] = L[i];
            i++;
        }
        else
        {
            A[k] = R[j];
            j++;
        }
        k++;
    }
    
    //copy the rest
    while(i < n1)
    {
        A[k] = L[i];
        i++, k++;
    }
    
    while(j < n2)
    {
        A[k] = R[j];
        j++, k++;
    }
}

void mergeSort(int A[], int left, int right)
{
    int mid = left + (right - left)/2;
    if(right > left)
    {
        mergeSort(A, left, mid);
        mergeSort(A, mid+1, right);
        
        merge(A,left,mid,right);
    }
}
void printArray(int A[], int N)
{
    printf("[");
    int i = 0;
    for(; i < N; i++)
    {
        if(i == N-1)
            printf("%d", A[i]);
        else
            printf("%d,", A[i]);
    }
    printf("]\n");
}

int solution(int A[], int N) {
    // write your code in C99 (gcc 6.2.0)
    int i;
    //printArray(A, N);
    mergeSort(A, 0, N-1);
    //printArray(A, N);
    if(N == 1 && A[0] == 1)
        return 1;

    if(A[0] != 1)
        return 0;
        
    if(A[N-1] != N)
        return 0;

    for(i = 0; i < N-1; i++)
    {
        if(A[i] != A[i+1]-1)
            return 0;
    }
    
    return 1;
}