# include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int number[n];
    for(int i=0;i<n;i++){
        scanf("%d",&number[i]);
    }
    int current=1;
    int max=1;
    for(int i=0;i<n-1;i++){
        if(number[i]==number[i+1]-1){
            current++;
        }else{
            if(current>max){
                max=current;
            }
            current=1;
        }
    }

    if(current>max){
        max=current;
    }
    //由于这里的变量不需要挨个保存，只需要确定一个最大的留下来就行了，我们使用一个变量保存需要比较的变量，而不是费劲的用数组
    //也不是一股脑的用循环，而是用一个变量储存（表示判断条件），并在分支的条件中调用它来控制，并最后让该变量回归初始值以便于下一轮控制
    //此处检查的重要性：循环结束时可能一直在执行if分支而全部跳过了else分支，导致赋值无法进行，e.g.1,2,3,4,5
    //于是需要对这种情况单独处理，i.e.做最后的检查
    printf("%d",max);
    return 0;
}
