//字符串运算
/*// 模拟手工二进制加法
while(还有数字或进位) {
    当前位 = a的当前位 + b的当前位 + 进位;
    结果位 = 当前位 % 2;   // 二进制，所以模2
    进位 = 当前位 / 2;     // 二进制，所以除以2
}*/
char *addBinary(char* a,char* b){
    int len_a=strlen(a);
    int len_b=strlen(b);
    int i=len_a-1;
    int j=len_b-1;
    int carry=0;
    int k=0;
    int max_len=(len_a>len_b?len_a:len_b)+2;
    char *result=(char*)malloc(max_len*(sizeof(char)));
    if(result==(char*)NULL) exit(1);
    while(i>=0||j>=0||carry!=0){
        int bit_a=(i>=0)?a[i]-'0':0;
        int bit_b=(j>=0)?b[j]-'0':0;
        int sum=bit_a+bit_b+carry;
        result[k++]=(sum%2)+'0';
        carry=sum/2;
        if(i>=0)i--;
        if(j>=0)j--;
    }
    result[k]='\0';
    for(int left=0,right=k-1;left<right;left++,right--){
        char temp=result[left];
        result[left]=result[right];
        result[right]=temp;
    }
    return result;
}

//数制转换
# include<math.h>
long long bi_de(char *a,int n){
    long long number=0;
    for(int i=0;i<n;i++){
        number+=(a[n-i-1]-'0')*(int)pow(2,i);
    }
    return number;
}
char *de_bi(long long number,int len){
    char *result=(char *)malloc((len+1)*sizeof(char));
    for(int i=0;i<len;i++){
        int flag=0;
        if((number/(int)pow(2,len-1-i))>=1){
            flag=1;
            number-=(int)pow(2,len-1-i);
        }
        result[i]='0'+flag;
    }
    result[len]='\0';
    int start=0;
    while(result[start]=='0'&&start<len-1){
        start++;
    }
    if(start>0){
        int new_len=len-start;
        char*trimmed=(char*)malloc((new_len+1)*sizeof(char));
        strcpy(trimmed,result+start);
        free(result);
        return trimmed;
    }
    return result;
}
char *addBinary(char *a,char *b){
    int len_a=strlen(a);
    int len_b=strlen(b);
    int max=(len_a>len_b?len_a:len_b)+1;
    long long number_a=bi_de(a,len_a);
    long long number_b=bi_de(b,len_b);
    long long number=number_a+number_b;
    return de_bi(number,max);
}
