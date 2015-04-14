/* Name: Jason Yao */

#include <stdlib.h>
#include <stdio.h>


#define N	1024
#define DIM     512
#define LARGE   10000

int list[LARGE];

int level_1();
void level_2();
void level_3();
void level_4();

/* Do not change anything above this line */


/***********************************************/

int level_1()
{
  int B[N][N];
  
  int i, j;
  
  for(i = 0; i < N; i++)
    for(j = 0; j < N; j++)
      B[i][j] = 2*(B[i][j] + 2);
   
  /* Do NOT change the the next few lines till the end of this function */  
  i = random () % N;
  j = random () % N;
  
  return(B[i][j]);
  
}

/***********************************************/

void level_2()
{
  int temp = 0;
  int i, j;
  int A[DIM][DIM];
  int B[DIM][DIM];

  for(i = 0; i < DIM; i++)
  {
    A[i][i] = 0;
    for( j = 0; j < DIM; j++)
      A[i][i] += B[i][j];
  }

  /* Do NOT change the the next few lines till the end of this function */  
  i = random () % DIM;
  for(j = 0; j < DIM; j++)
    temp += B[j][i];
  
  if( temp == A[i][i] )
    printf("level 2 ... Success!\n");
}

/***********************************************/

void level_3()
{
  int i, j;
  int temp;
  int c[N+1][N+1];
  
  for( j = 0; j < N; j++)
    for( i = 0; i < N >> 1; i++)
    {
      temp = c[j][i];
      c[j][i] = c[j][N-i];
      c[j][N-i] = temp;
    }
      
/* Do NOT change the the next few lines till the end of this function */  
    printf("level 3 ... Success!\n");

}

/***********************************************/

/** Merge function
 * Note: Since I'm not supposed to be doing lab 4 anyways, I'll be a bit lazy.
 * Merge code is sourced from Wikipedia's mergeSort page, listed at:
 * https://en.wikipedia.org/wiki/Merge_sort#Bottom-up_implementation
 */
void merge(int A[], int iLeft, int iRight, int iEnd, int B[])
{
  int i0 = iLeft;
  int i1 = iRight;
  int j;
 
  /* While there are elements in the left or right runs */
  for (j = iLeft; j < iEnd; j++)
    {
      /* If left run head exists and is <= existing right run head */
      if (i0 < iRight && (i1 >= iEnd || A[i0] <= A[i1]))
        {
          B[j] = A[i0];
          i0 = i0 + 1;
        }
      else
        {
          B[j] = A[i1];
          i1 = i1 + 1;
        }
    }
} // End of merge function

/* Copy array function  */
void CopyArray(int B[], int A[], int n)
{
	int i;
	for(i = 0; i < n; i++)
		A[i] = B[i];
}

#define min(X,Y) ((X) < (Y) ? (X) : (Y))

/* Iterative MergeSort */
void mergeSort(int A[], int B[], int n)
{
int i, width;
  /* Each 1-element run in A is already "sorted". */
  /* Make successively longer sorted runs of length 2, 4, 8, 16... until whole array is sorted. */
  for (width = 1; width < n; width = 2 * width)
    {
      /* Array A is full of runs of length width. */
      for (i = 0; i < n; i = i + 2 * width)
        {
          /* Merge two runs: A[i:i+width-1] and A[i+width:i+2*width-1] to B[] */
          /* or copy A[i:n-1] to B[] ( if(i+width >= n) ) */
          merge(A, i, min(i+width, n), min(i+2*width, n), B);
        }
      /* Now work array B is full of runs of length 2*width. */
      /* Copy array B to array A for next iteration. */
      /* A more efficient implementation would swap the roles of A and B */
      CopyArray(B, A, n);
      /* Now array A is full of runs of length 2*width. */
    }
}

/* This one is for honor students only */
void level_4()
{
  int i, j;
  int temp;
	int helper[LARGE];

	// Mergesorts instead of bubble sort
	mergeSort(list, helper, LARGE);

	// Test to see if array is actually sorted
		//int k;
		//for (k = 0; k < LARGE; ++k)
		//{printf("%d%s", list[k], k == LARGE - 1 ? "\n" : " ");}

/* Do NOT change the the next few lines till the end of this function */
  i = random () % LARGE;
  if( list[0] < list[i] )
    printf("level 4 ... Success!\n");

}


/***********************************************/



/* Do not change anything below this line */

int main(int argc, char *argv[])
{
  int i, j;
 
  for(i = 0; i < LARGE; i++)
    list[i] = random() % LARGE;
  
  if( level_1() % 2 == 0)
    printf("level 1 ... Success!\n");
  
  level_2();
  level_3();
  level_4();
  
  return 1;
}
