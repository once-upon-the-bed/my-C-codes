char* longestCommonPrefix(char** strs,int strsSize){
    if(strsSize==0){
        return "";
    }
    int j;
    for(j=0;strs[0][j]!='\0';j++){
        char c=strs[0][j];
        int flag=1;
        for(int i=1;i<strsSize;i++){
            if(strs[i][j]!=c){
                flag=0;
                break;
            }
        }
        if(!flag){
            break;
        }
    }
    char *common;
    common=(char*)malloc((j+1)*sizeof(char));
    for(int i=0;i<j;i++){
        common[i]=strs[0][i];
    }
    common[j]='\0';
    return common;
}

char* longestCommonPrefix(char** strs, int strsSize) {
    if(strsSize==0){
        return "";
    }
    for(int j=0;strs[0][j]!='\0';j++){
        char c=strs[0][j];
        for(int i=1;i<strsSize;i++){
            if(strs[i][j]!=c){
                strs[0][j]='\0';
                return strs[0];
            }
        }
    }
    return strs[0];
}
