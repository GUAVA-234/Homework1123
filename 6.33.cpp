
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 36000 // 投擲次數
#define M 13 // 點數範圍

// 遞迴的 binarySearch 函數，參數為陣列、起始下標、結束下標和搜尋鍵
int binarySearch(int arr[], int low, int high, int key)
{
    if (low <= high) // 如果起始下標小於等於結束下標
    {
        int mid = (low + high) / 2; // 計算中間下標
        if (arr[mid] == key) // 如果中間元素等於搜尋鍵
        {
            return mid; // 回傳中間下標
        }
        else if (arr[mid] > key) // 如果中間元素大於搜尋鍵
        {
            return binarySearch(arr, low, mid - 1, key); // 在左半部繼續搜尋
        }
        else // 如果中間元素小於搜尋鍵
        {
            return binarySearch(arr, mid + 1, high, key); // 在右半部繼續搜尋
        }
    }
    else // 如果起始下標大於結束下標
    {
        return -1; // 回傳 -1 表示沒找到
    }
}

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

    // 使用 binarySearch 函數來搜尋某個點數的頻率
    int key = 7; // 要搜尋的點數
    int index = binarySearch(freq, 2, 12, key); // 呼叫 binarySearch 函數，起始下標為 2，結束下標為 12
    if (index == -1) // 如果回傳 -1
    {
        printf("沒有找到點數 %d 的頻率\n", key); // 印出沒找到的訊息
    }
    else // 如果回傳其他值
    {
        printf("點數 %d 的頻率是 %d\n", key, freq[index]); // 印出找到的頻率
    }
    return 0;
}
