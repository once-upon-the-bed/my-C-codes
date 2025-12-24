int romanToInt(char* s){
    int sum=0;
    while(*s!='\0'){
        if(*s=='I'){
            if(*(s+1)=='V'||*(s+1)=='X'){
                sum-=1;
            }else{
                sum+=1;
            }
        }else if(*s=='X'){
            if(*(s+1)=='L'||*(s+1)=='C'){
                sum-=10;
            }else{
                sum+=10;
            }
        }else if(*s=='C'){
            if(*(s+1)=='D'||*(s+1)=='M'){
                sum-=100;
            }else{
                sum+=100;
            }
        }else if(*s=='V'){
            sum+=5;
        }else if(*s=='L'){
            sum+=50;
        }else if(*s=='D'){
            sum+=500;
        }else if(*s=='M'){
            sum+=1000;
        }
        s++;
    }
    return sum;
}

int romanToInt(char* s) {
    int sum = 0;
    while (*s) {
        int current = value(*s);
        int next = value(*(s + 1));
        if (current < next)
            sum -= current;
        else
            sum += current;
        s++;
    }
    return sum;
}
int value(char c) {
    switch (c) {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
    }
    return 0;
}
