#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int MAX=77;
long long int steps=0;
#define SWAP(x,y) {long int t; t = x; x = y; y = t;steps++;}

void createheap(long int[]);
void heapsort(long int[]);

int main(void) {
	clock_t t1,t2;
	//scanf("%d",&MAX);
	//long int number[MAX+1];
    long int i, num; 

    //srand(32123);

    //printf("排序前：");
    //for(i = 1; i <= MAX; i++) {
        //number[i] = (rand() % 100000)+1;
        
   // }

	int number[] = {77,76,75,74,73,72,71,70,69,68,67,66,65,64,63,62,61,60,59,58,57,56,55,54,53,52,51,50,49,48,47,46,45,44,43,42,41,40,39,38,37,36,35,34,33,32,31,30,29,28,27,26,25,24,23,22,21,20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1};

   // printf("\n建立堆積樹：");
    t1=clock();
    createheap(number);
    /*for(i = 1; i <= MAX; i++)
        printf("%d ", number[i]);
    printf("\n");*/

    heapsort(number);
	t2=clock();
    printf("%lfsec\n",(t2-t1)/(double)(CLOCKS_PER_SEC));
printf("steps:%d\n",steps);
    return 0;
}

void createheap(long int number[]) {
    long int i, s, p;
    long int heap[MAX+1];

    for(i = 1; i <= MAX; i++) {
    	steps++; 
        heap[i] = number[i];
        s = i;
        p = i / 2;
        while(s >= 2 && heap[p] > heap[s]) {
        	steps++;
            SWAP(heap[p], heap[s]);
            s = p;
            p = s / 2;
        }
    }

    for(i = 1; i <= MAX; i++)
        number[i] = heap[i];
   
}

void heapsort(long int 
number[]) {
    long int i, m, p, s;

    m = MAX;
    while(m > 1) {
    	steps++; 
        SWAP(number[1], number[m]);
        m--;

        p = 1;
        s = 2 * p;

        while(s <= m) {
        	steps++; 
			if(s < m && number[s+1] < number[s])
             {steps++;
			   s++;
		}
            if(number[p] <= number[s])
               {steps++; 
			    break;
        		}
			SWAP(number[p], number[s]);
            p = s;
            s = 2 * p;
        }

       /* prlong intf("\n排序中：");
        for(i = MAX; i > 0; i--)
            printf("%d ", number[i]);*/
    }
}
