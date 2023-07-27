#include<stdio.h>
#include <stdbool.h>
bool isPresent(int fn, int a, int frame[]) {
    for (int i = 0; i < fn; i++) {
        if (frame[i] == a) {
            return true;
        }
    }
    return false;
}

int main()
{
    int n,f,fn,fifo;//fifo stores the index if the element to be replaced
    int arr[100];
    int frame[10];
    printf("enter page numbers : ");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("\nenter page number of page %d ",i+1);
        scanf("%d",&arr[i]);        
    }
    for(int i=0;i<fn;i++)
    {
        frame[i]=NULL;
    }
    
    printf("\nenter frame number");
    scanf("%d",&fn);
    fifo=0;
    int miss=0;
    int cur=0,hit=0;
    for(int i=0;i<n;i++)
    {
        if(cur!=fn)
        {                    
            frame[cur]=arr[i];
            cur++;   
            miss++;        
        }
        else
        {
            if(isPresent(fn,arr[i],frame))
            {
                hit++;
            }
            else
            {
                frame[fifo]=arr[i];
                fifo=(fifo+1)%fn;
                miss++;
            }
        }

    }
    printf("\nhits : %d",hit);
    printf("\nmiss : %d",miss);
    
    
    

}
