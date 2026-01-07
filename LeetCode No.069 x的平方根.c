int mySqrt(int x){
    if(x==0) return 0;
    if(x==1) return 1;
    int result;
    int left=0;
    int right=x;
    while(left<=right){
        int mid=(left+right)/2;
        long long square=(long long)mid*mid;
        if(square==x){
            return mid;
        }else if(square<x){
            result=mid;
            left=mid+1;
        }else{
            right=mid-1;
        }
    }
    return result;
}
