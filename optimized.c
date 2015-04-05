
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
  

	// Optimized code begins:
	for(i = 0; i < N; ++i)
		for(j = 0; j < N; ++j)
			B[i][j] = 2*(B[i][j] + 2);
   	// Old unoptimized code begins:
	//for(j = 0; j < N; ++j)
        //      for(i = 0; i < N; ++i)
        //              B[i][j] = 2*(B[i][j] + 2);
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

  for(i = 0; i < DIM; ++i)
  {
	A[i][i] = 0;
	// Optimization Code begins:
	for (j = 0; j < DIM; ++j)
		A[i][i] += B[i][j];
	// Old unoptimized code:
	// for( j = 0; j < DIM; j++)
	// A[i][i] += B[j][i];
  }

  /* Do NOT change the the next few lines till the end of this function */
  i = random () % DIM;
  for(j = 0; j < DIM; j++)
    temp += B[i][j];
  
  if( temp == A[i][i] )
    printf("level 2 ... Success!\n");
}

/***********************************************/

void level_3()
{
  int i, j;
  int temp;
  int c[N][N];

	int begin = c[0][0];
	// Optimized code start:
	for (i = 0; i < N; ++i)
	{
		// Switches the position to be flipped
		for (j = 1; j < N >> 1; ++j)
		{
			// swap(c[i][j], c[i][N - j]);
			temp = c[i][j];
			c[i][j] = c[i][N-j];
			c[i][N-j] = temp;
		}
		// Deals with the first column
		c[i][0] = c[i + 1][0];
	}
	c[N][0] = begin;
	// Old code:
//	  for( i = 0; i < N >> 1; i++)
//	    for( j = 0; j < N; j++)
//	    {
//	      temp = c[j][i];
//	      c[j][i] = c[j][N-i];
//	      c[j][N-i] = temp;
//	    }

/* Do NOT change the the next few lines till the end of this function */
    printf("level 3 ... Success!\n");

}

/***********************************************/

/* This one is for honor students only */
void level_4()
{
  int i, j;
  int temp;
  
  for( j = LARGE; j >=2; j--)
    for(i = 1; i < j; i++)
      if( list[i-1] > list[i] )
      {
	temp = list[i-1];
	list[i-1] = list[i];
	list[i] = temp;
      }
      
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
