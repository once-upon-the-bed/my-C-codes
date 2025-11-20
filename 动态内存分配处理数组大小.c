#include <stdio.h>
#include <stdlib.h>  // 必须包含这个头文件

int main() {
    // 1. 初始容量设置
    int capacity = 10;  // 初始容量，我们先分配能存储10个整数的空间
    
    // 2. 动态分配内存
    int *arr = (int*)malloc(capacity * sizeof(int));
    // malloc函数向系统申请一块内存
    // capacity * sizeof(int) 计算需要多少字节
    // (int*) 将返回的void*指针转换为int*指针
    
    // 3. 检查分配是否成功
    if(arr == NULL) {
        printf("内存分配失败\n");
        return 1;  // 如果分配失败，退出程序
    }
    
    int count = 0;  // 记录当前存储了多少个数字
    int num;
    
    // 读取数字直到遇到0
    while(1) {
        scanf("%d", &num);
        if(num == 0) break;
        
        // 4. 检查是否需要扩展容量
        if(count >= capacity) {
            capacity *= 2;  // 容量翻倍
            arr = (int*)realloc(arr, capacity * sizeof(int));
            // realloc函数重新分配内存，扩大原有内存块
            // 它会保留原有数据，并返回新的指针
            
            // 再次检查是否分配成功
            if(arr == NULL) {
                printf("内存重新分配失败\n");
                return 1;
            }
        }
        
        // 存储数字
        arr[count] = num;
        count++;
    }
    
    // 反着输出
    for(int i = count - 1; i >= 0; i--) {
        printf("%d", arr[i]);
        if(i > 0) {
            printf(" ");
        }
    }
    
    // 5. 释放内存
    free(arr);  // 必须释放动态分配的内存
    
    return 0;
}
/*
1.malloc-内存分配
int *arr = (int*)malloc(capacity * sizeof(int));
作用：向系统申请一块指定大小的内存
参数：需要分配的字节数
返回值：成功返回指向内存的指针，失败返回NULL
注意：分配的内存内容是未初始化的（可能是随机值）
2.realloc-重新分配内存
arr = (int*)realloc(arr, capacity * sizeof(int));
作用：调整已分配内存块的大小
参数：原内存指针和新的大小
返回值：成功返回新指针，失败返回NULL
注意：可能返回新的地址，所以要用原指针接收
3.free-释放内存
free(arr);
作用：释放之前分配的内存
参数：要释放的内存指针
注意：必须配对使用，分配多少就要释放多少
每一个malloc都要对应一个free
对已经释放的指针再次调用free会错误，且释放之后指针就无效了
*/
/*
分配内存格式：数据类型 *指针名 = (数据类型*)malloc(容量 * sizeof(数据类型));
if(指针名 == NULL) { 错误处理 }
扩展内存格式：if(当前数量 >= 容量) {
    容量 *= 2;
    指针名 = (数据类型*)realloc(指针名, 容量 * sizeof(数据类型));
    if(指针名 == NULL) { 错误处理 }
}
*/
//必背格式
#include <stdio.h>
#include <stdlib.h>  // 必须包含这个头文件

int main() {
    // 1. 初始设置
    int capacity = 初始大小;        // 设置初始容量
    int count = 0;                 // 当前元素个数
    
    // 2. 内存分配
    int *arr = (int*)malloc(capacity * sizeof(int));
    if(arr == NULL) {
        printf("内存分配失败\n");
        return 1;
    }
    
    // 3. 使用数组（读取/处理数据）
    // 在这里添加你的数据处理代码
    
    // 4. 检查是否需要扩展（在添加元素时）
    if(count >= capacity) {
        capacity *= 2;  // 容量翻倍
        arr = (int*)realloc(arr, capacity * sizeof(int));
        if(arr == NULL) {
            printf("内存扩展失败\n");
            return 1;
        }
    }
    
    // 5. 释放内存（程序结束前）
    free(arr);
    
    return 0;
}
//完整示例
#include <stdio.h>
#include <stdlib.h>

int main() {
    // === 第一步：初始设置 ===
    int capacity = 10;     // 初始容量（根据题目调整）
    int count = 0;         // 当前元素个数
    
    // === 第二步：内存分配 ===
    int *arr = (int*)malloc(capacity * sizeof(int));
    if(arr == NULL) {
        printf("内存分配失败\n");
        return 1;
    }
    
    // === 第三步：你的数据处理代码 ===
    // [在这里写你的具体逻辑]
    // 例如：
    int num;
    while(scanf("%d", &num) == 1 && num != 0) {
        // === 第四步：检查扩展（在添加元素时）===
        if(count >= capacity) {
            capacity *= 2;
            arr = (int*)realloc(arr, capacity * sizeof(int));
            if(arr == NULL) {
                printf("内存扩展失败\n");
                return 1;
            }
        }
        
        arr[count] = num;
        count++;
    }
    //完整实例：动态数组的实现
  #include <stdio.h>
#include <stdlib.h>

int main() {
    int capacity = 5;  // 初始容量较小，方便测试扩展
    int *arr = malloc(capacity * sizeof(int));
    int count = 0;
    int num;
    
    printf("请输入数字（以0结束）：\n");
    
    while(1) {
        scanf("%d", &num);
        if(num == 0) break;
        
        // 显示当前状态
        printf("当前：count=%d, capacity=%d\n", count, capacity);
        
        // 需要扩展容量
        if(count >= capacity) {
            printf("需要扩展容量...\n");
            capacity *= 2;
            int *new_arr = realloc(arr, capacity * sizeof(int));
            
            if(new_arr == NULL) {
                printf("扩展失败！\n");
                free(arr);
                return 1;
            }
            
            arr = new_arr;
            printf("扩展成功！新容量：%d\n", capacity);
        }
        
        arr[count] = num;
        count++;
    }
    
    printf("\n倒序输出：");
    for(int i = count - 1; i >= 0; i--) {
        printf("%d ", arr[i]);
    }
    
    free(arr);
    return 0;
}
    // === 第五步：释放内存 ===
    free(arr);
    
    return 0;
}
