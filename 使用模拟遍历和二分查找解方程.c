# include<stdio.h>
int simulate(int n,int departureStation,int x);
int main()
{
    int n,departureStation,m;
    scanf("%d %d %d",&n,&departureStation,&m);
    if(n<5){
        printf("0\n");
    }else{
        int left=0,right=m,answer=0;
        while(left<+right){
            int mid=(left+right)/2;
            int result=simulate(n,departureStation,mid);
            if(result==m){
                answer=mid;
                break;
            }else if(result<m){
                left=mid+1;
            }else{
                right=mid-1;
            }
        }
        printf("%d\n",answer);
    }
    return 0;
}
int simulate(int n,int departureStation,int x){
    int in_first=departureStation;
    int in_second=x;
    int current=departureStation;
    for(int i=3;i<n;i++){
        int in=in_first+in_second;
        int out=in_second;
        current=current+in-out;
        in_first=in_second;
        in_second=in;
    }
    return current;
}
