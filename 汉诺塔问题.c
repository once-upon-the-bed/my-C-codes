void hanoi(int n,char from,char to,char temp){
    if(n==0)return;
    hanoi(n-1,from,temp,to);
    printf("No.%d: %c->%c\n",n,from,to);
    hanoi(n-1,temp,to,from);
}
