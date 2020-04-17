#include<stdio.h>
void solve()
{
int burst_time[20],p[20];
int wt[20],turn_around_time[20],pr[20];
int i,j,n,total=0,pos,temp,avg_wt,avg_turn_around_time;

    printf("Enter Total Number of Process:");
    scanf("%d",&n);
 
    printf("\nEnter Burst Time and Priority\n");
    for(i=0;i<n;i++)
    {
        printf("\nP[%d]\n",i+1);
        printf("Burst Time:");
        scanf("%d",&burst_time[i]);
        printf("Priority:");
        scanf("%d",&pr[i]);
        p[i]=i+1;           
    }
 

    for(i=0;i<n;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(pr[j]<pr[pos])
                pos=j;
        }
 
        temp=pr[i];
        pr[i]=pr[pos];
        pr[pos]=temp;
 
        temp=burst_time[i];
        burst_time[i]=burst_time[pos];
        burst_time[pos]=temp;
 
        temp=p[i];
        p[i]=p[pos];
        p[pos]=temp;
    }
 
    wt[0]=0;	
    for(i=1;i<n;i++)
    {
        wt[i]=0;
        for(j=0;j<i;j++)
            wt[i]+=burst_time[j];
 
        total+=wt[i];
    }
 
    avg_wt=total/n;     
    total=0;
 
    printf("\nProcess\t    Burst Time    \tWaiting Time\tTurnaround Time");
    for(i=0;i<n;i++)
    {
        turn_around_time[i]=burst_time[i]+wt[i];    
        total+=turn_around_time[i];
        printf("\nP[%d]\t\t  %d\t\t    %d\t\t\t%d",p[i],burst_time[i],wt[i],turn_around_time[i]);
    }
 
    avg_turn_around_time=total/n;     //average turnaround time
    printf("\n\nAverage Waiting Time=%d",avg_wt);
    printf("\nAverage Turnaround Time=%d\n",avg_turn_around_time);
 
	return 0;	
}
 
int main()
{
	solve();
    
}
