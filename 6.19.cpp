
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 36000 // 投擲次數
#define M 13 // 點數範圍

int main()
{
    int dice1, dice2, sum; // 兩個骰子和總和
    int freq[M] = {0}; // 紀錄各種點數出現的次數
    srand(time(NULL)); // 設定隨機種子
    for (int i = 0; i < N; i++) // 重複投擲 N 次
    {
        dice1 = rand() % 6 + 1; // 產生第一個骰子的點數，範圍是 1 到 6
        dice2 = rand() % 6 + 1; // 產生第二個骰子的點數，範圍是 1 到 6
        sum = dice1 + dice2; // 計算兩個骰子的總和
        freq[sum]++; // 將對應的點數出現次數加一
    }
    printf("點數\t頻率\n"); // 印出表頭
    for (int j = 2; j < M; j++) // 印出各種點數和頻率
    {
        printf("%d\t%d\n", j, freq[j]);
    }
    return 0;
}
