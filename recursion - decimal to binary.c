void dec_bin(int n){
    if(n==0) return;
    dec_bin(n/2);
    printf("%d",n%2);
}
