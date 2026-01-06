//normal
void permute(char *str,int left,int right){
    if(left==right){
        printf("%s\n",str);
        return;
    }else{
        for(int i=left;i<right;i++){
            swap(&str[i],&str[left]);
            permute(str,left+1,right);
            swap(&str[i],&str[left]);
        }
    }
}
//strengthened
bool repeat(char *str,int start,int current){
    for(int i=start;i<current;i++){
        if(str[i]==str[current]){
            return false;
        }
    }
    return true;
}
void permute(char *str,int left,int right){
    if(left==right){
        printf("%s\n",str);
        return;
    }
    for(int i=left;i<right;i++){
        if(repeat(str,left,right)){
            swap(&str[i],&str[left]);
            permute(str,left+1,right);
            swap(&str[i],&str[i]);
        }
    }
}
