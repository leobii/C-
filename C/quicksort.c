#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int partition(long int a[],long int left,long int right,long int index);
void quicksort(long int a[],long int left,long int right);
void swap(long int *a, long int *b);
long long int steps=0;
int main()
{
	//srand(7);

	long int N=77;
	long int data[] = {77,76,75,74,73,72,71,70,69,68,67,66,65,64,63,62,61,60,59,58,57,56,55,54,53,52,51,50,49,48,47,46,45,44,43,42,41,40,39,38,37,36,35,34,33,32,31,30,29,28,27,26,25,24,23,22,21,20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1};
	clock_t t1,t2;
	//scanf("%d",&N);
	
	//long int data[N+1];
	//for(long int i=1;i<=N;i++)
	//{
	//data[i]=(rand()%100000)+1;
	//}

	quicksort(data,1,N);
	t1=clock();
	steps=0;
	quicksort(data,1,N);
	
	t2=clock();
	printf("%lfsec\n",(t2-t1)/(double)(CLOCKS_PER_SEC));
	printf("steps:%d\n",steps);
	
	
}

void quicksort(long int a[],long int left,long int right)
{
	
	if(right<=left){
		steps++;
		return;
	}
	else
	{
		long int index=right;
		
		long int newindex=partition(a,left,right,index);
		
		quicksort(a,left,newindex-1);
		quicksort(a,newindex+1,right);
	}
}
int partition(long int a[],long int left,long int right,long int index)
{
	int keep=a[index];
	swap(&a[right],&a[index]);
	long int count=left;
	
	for(long int i=left;i<=right-1;i++)
	{
		steps++;
		if(a[i]<=keep)
		{
			swap(&a[i],&a[count]);
			count++;
			
		}
	} 
	swap(&a[count],&a[right]);
	return count;
}
void swap(long int *a, long int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
	steps++;
}
