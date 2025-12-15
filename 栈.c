//动态链表栈
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# define length 30
struct Name{
    char name[length];
    struct Name *priorAddr;
};
struct Name *top;
void read_push();
void pop_show();
void push(char *);
void pop(char *);
int main()
{
    top=NULL;
    read_push();
    pop_show();
    return 0;
}
void read_push(){
    char name[length];
    while(1){
        gets(name);
        if(strcmp(name,"x")==0){
            break;
        }
        push(name);
    }
}
void pop_show(){
    char name[length];
    while(top!=NULL){
        pop(name);
        printf("%s\n",name);
    }
}
void push(char *name){
    struct Name *newAddr;
    newAddr=(struct Name*)malloc(sizeof(struct Name));
    if(newAddr==(struct Name*)NULL){
        printf("memory allocate failed.");
        exit(1);
    }
    strcpy(newAddr->name,name);
    newAddr->priorAddr=top;
    top=newAddr;
}
void pop(char *name){
    struct Name *tempAddr;
    strcpy(name,top->name);
    tempAddr=top->priorAddr;
    free(top);
    top=tempAddr;
}

//动态数组栈结构
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define INIT_CAPACITY 2  // 初始容量很小
#define NAME_LEN 30
typedef struct {
    char **data;      // 指向字符串数组的指针
    int top;          // 栈顶索引
    int capacity;     // 当前容量
} DynamicArrayStack;
//创建动态数组栈
DynamicArrayStack* createStack() {
    DynamicArrayStack *s = malloc(sizeof(DynamicArrayStack));
    if(!s) return NULL;
    s->capacity = INIT_CAPACITY;
    s->top = -1;
    // 分配初始容量
    s->data = malloc(s->capacity * sizeof(char*));
    if(!s->data) {
        free(s);
        return NULL;
    }
    return s;
}
//扩容
void expandStack(DynamicArrayStack *s) {
    int newCapacity = s->capacity * 2;  // 双倍扩容
    // 使用realloc重新分配内存
    char **newData = realloc(s->data, newCapacity * sizeof(char*));
    if(!newData) {
        printf("扩容失败！\n");
        return;
    }
    s->data = newData;
    s->capacity = newCapacity;
    printf("栈已扩容，新容量：%d\n", newCapacity);
}
//入栈，且自动扩容
void push(DynamicArrayStack *s, const char *name) {
    // 检查是否需要扩容
    if(s->top == s->capacity - 1) {
        expandStack(s);
    }
    // 为新字符串分配内存
    s->data[++s->top] = malloc((strlen(name) + 1) * sizeof(char));
    if(!s->data[s->top]) {
        printf("内存分配失败！\n");
        return;
    }
    
    strcpy(s->data[s->top], name);
    printf("入栈：%s (容量：%d/%d)\n", name, s->top+1, s->capacity);
}
//出栈
char* pop(DynamicArrayStack *s) {
    if(s->top < 0) return NULL;
    
    char *name = s->data[s->top];
    s->top--;
    return name;
}
//释放栈
void freeStack(DynamicArrayStack *s) {
    // 先释放每个字符串
    for(int i = 0; i <= s->top; i++) {
        free(s->data[i]);
    }
    // 再释放数组
    free(s->data);
    // 最后释放栈结构
    free(s);
}
int main() {
    DynamicArrayStack *stack = createStack();
    printf("动态数组栈演示（初始容量2）：\n");
    // 测试自动扩容
    push(stack, "元素1");  // 容量1/2
    push(stack, "元素2");  // 容量2/2（满了）
    push(stack, "元素3");  // 触发扩容到4
    push(stack, "元素4");  // 容量4/4
    push(stack, "元素5");  // 触发扩容到8
    printf("\n弹出所有元素：\n");
    char *name;
    while((name = pop(stack)) != NULL) {
        printf("弹出：%s\n", name);
        free(name);  // 释放弹出的字符串
    }
    freeStack(stack);
    return 0;
}

//静态数组栈
#include <stdio.h>
#include <string.h>
#define MAX_SIZE 100
#define NAME_LEN 30
// 数组栈结构
typedef struct {
    char data[MAX_SIZE][NAME_LEN];  // 二维数组存储字符串
    int top;                        // 栈顶索引
} ArrayStack;
// 1. 初始化
void initStack(ArrayStack *s) {
    s->top = -1;  // -1表示栈空
}
// 2. 判断栈空
int isEmpty(ArrayStack *s) {
    return s->top == -1;
}
// 3. 判断栈满
int isFull(ArrayStack *s) {
    return s->top == MAX_SIZE - 1;
}
// 4. 入栈
int push(ArrayStack *s, const char *name) {
    if(isFull(s)) {
        printf("栈已满！无法添加: %s\n", name);
        return 0;  // 失败
    }
    s->top++;
    strcpy(s->data[s->top], name);
    return 1;  // 成功
}
// 5. 出栈
int pop(ArrayStack *s, char *name) {
    if(isEmpty(s)) {
        printf("栈为空！\n");
        return 0;
    }
    strcpy(name, s->data[s->top]);
    s->top--;
    return 1;
}
// 6. 查看栈大小
int stackSize(ArrayStack *s) {
    return s->top + 1;
}
// 7. 测试程序
int main() {
    ArrayStack stack;
    initStack(&stack);
    printf("数组栈演示：\n");
    // 入栈
    push(&stack, "张三");
    push(&stack, "李四");
    push(&stack, "王五");
    printf("栈中有 %d 个元素\n", stackSize(&stack));
    // 出栈
    char name[NAME_LEN];
    while(!isEmpty(&stack)) {
        pop(&stack, name);
        printf("弹出: %s\n", name);
    }
    // 输出：王五、李四、张三
    return 0;
}
