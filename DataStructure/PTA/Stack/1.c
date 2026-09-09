#include <stdio.h>  
#include <stdlib.h>  
#include <math.h> // 用于计算幂函数  

// 记录移动的函数  
void move(int from, int to, char** moves, int* moveCount) {  
    static const char* disks[3] = { "a", "b", "c" }; // 将索引映射到对应的柱子  
    // 构造移动字符串  
    sprintf(moves[*moveCount], "%s -> %s", disks[from], disks[to]);  
    (*moveCount)++; // 移动计数器加1  
}  

// 递归解决塔汉诺伊问题的函数  
void towerOfHanoi(int n, int from, int by, int to, char** moves, int* moveCount) {  
    if (n == 1) {  
        move(from, to, moves, moveCount); // 只有一个盘子的时候直接移动  
    } else {  
        towerOfHanoi(n - 1, from, to, by, moves, moveCount); // 将 n-1 个盘子从 A 移动到 C 用 B 辅助  
        move(from, to, moves, moveCount);                  // 移动一个盘子从 A 到 B  
        towerOfHanoi(n - 1, by, from, to, moves, moveCount); // 将 n-1 个盘子从 B 移动到 C 用 A 辅助  
    }  
}  

int main() {  
    int n;  
    // 输入盘子的数量  
    scanf("%d", &n);  

    // 计算移动的总次数  
    int totalMoves = pow(2, n) - 1;   

    // 动态分配内存来存储移动记录  
    char** moves = malloc(totalMoves * sizeof(char*));  
    for (int i = 0; i < totalMoves; i++) {  
        moves[i] = malloc(20 * sizeof(char)); // 为每条移动字符串分配空间  
    }  

    int moveCount = 0; // 初始化移动计数器  
    towerOfHanoi(n, 0, 1, 2, moves, &moveCount); // 调用函数解决塔汉诺伊问题  

    // 输出所有的移动记录  
    for (int i = 0; i < moveCount; i++) {  
        printf("%s\n", moves[i]);  
        free(moves[i]); // 在使用后释放每个移动字符串  
    }  

    free(moves); // 释放移动指针数组  
    return 0;  
}