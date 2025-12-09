# include<stdio.h>
# include<ctype.h>
# include<string.h>
int main()
{
    const int NUMBER1=101;
    const int NUMBER2=100001;
    char word[NUMBER1];
    char article[NUMBER2];
    fgets(word,sizeof(word),stdin);
    fgets(article,sizeof(article),stdin);
    word[strcspn(word,"\n")]='\0';
    article[strcspn(article,"\n")]='\0';
    int word_length=strlen(word);
    int article_length=strlen(article);
    int count=0;
    int first_position=-1;
    if(word_length==0){
        printf("-1");
        return 0;
    }
    for(int i=0;i<=article_length-word_length;i++){
        if(i>0&&article[i-1]!=' '){
            continue;
        }
        int flag=1;
        for(int j=0;j<word_length;j++){
            if(tolower(word[j])!=tolower(article[i+j])){
                flag=0;
                break;
            }
        }
        if(flag){
            if(i+word_length<article_length&&article[i+word_length]!=' '){
                flag=0;
            }
        }
        if(flag){
            count++;
            if(first_position==-1){
                first_position=i;
            }
        }
    }
    if(count>0){
        printf("%d %d",count,first_position);
    }else{
        printf("-1");
    }
    return 0;
}
