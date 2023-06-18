/* Program to measure the time taken by a function performing Kruskal's Algorithm for random graphs of varying density.
 * Author: Shreya Handigol
 * Date: 31-5-2021
 */


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <malloc.h>
#include <stdbool.h>
#include <limits.h>

int i,j,k,a,b,u,v,n,ne=1;
int min,mincost=0,cost[9][9],track[9];
int find(int);
int uni (int,int);
void kruskals()
{


	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{

			if(cost[i][j]==0)
				cost[i][j]=999;
		}
	}

	while(ne < n)
	{
		for(i=1,min=999;i<=n;i++)
		{
			for(j=1;j <= n;j++)
			{
				if(cost[i][j] < min)
				{
					min=cost[i][j];
					a=u=i;
					b=v=j;
				}
			}
		}
		u=find(u);
		v=find(v);
		if(uni(u,v))
		{
			printf("%d edge (%d,%d) =%d\n",ne++,a,b,min);
			mincost +=min;
		}
		cost[a][b]=cost[b][a]=999;
	}

	getch();
}
int find(int i)
{
	while(track[i])
	i=track[i];
	return i;
}
int uni (int i,int j)
{
	if(i!=j)
	{
		track[j]=i;
		return 1;
	}
	return 0;
}


   int main()
{
   int m,n,i,j,s,z;
   int count;
   clock_t t1,t2;
   clock_t time_taken;


   FILE *fp;
   fp = fopen ("Kruskal's_Algorithm.txt", "w");

   fprintf(fp,"m\tTime Taken\n");

   s=999;
   for(m=1000;m<=10000;m=m+1000,s=s+1000)
   {
      // dynamically create an array of pointers of size `m`
      int **DA = (int **)malloc(m * sizeof(int *));

      // dynamically allocate memory of size `m` for each row
      for (i=0;i<m;i++)
        DA[i] = (int *)malloc(m * sizeof(int));


      for(n=0;n<m;n++)
      {
          //to get graph of varying density
          i=rand()%s;
          j=rand()%s;

          z=rand();

          //to maintain symmetry of the matrix
          DA[i][j]=z;
          DA[j][i]=z;
      }

      //to make sure it is a connected graph
      for(i=0;i<m;i++)
      {
          for(j=0;j<m;j++)
          {
              if(DA[i][j]==0)
                count++;
          }
          if(count==m)
          {
              z=(rand()%100)+1;
              DA[i][j]=z;
              DA[j][i]=z;
          }
      }

      t1=clock();
      kruskals();
      t2=clock();
      time_taken=t2-t1;

      printf("%d\t%ld\n",m,time_taken);

      fprintf(fp,"%d\t%ld\n",m,time_taken);
   }

  fclose(fp);
  return 0;

}

