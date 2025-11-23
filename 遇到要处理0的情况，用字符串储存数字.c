# include<stdio.h>
# include<string.h>
int main()
{
    int m;
    char n[1000];
    scanf("%d %s",&m,&n);
    int length=strlen(n);
    for(int i=0;i<length;i++){
        int number=n[i]-'0';
        if(i!=0&&number!=0){
            printf("+");
        }
        if(number!=0){
            printf("%d*%d^%d",number,m,length-(i+1));
        }
    }
    return 0;
}
