
#include <stdio.h>

// 定義一個遞迴函數 stringReverse，參數為字元陣列
void stringReverse(char str[])
{
    // 如果字元陣列不為空
    if (str[0] != '\0')
    {
        // 先遞迴呼叫下一個字元
        stringReverse(str + 1);
        // 再印出當前字元
        printf("%c", str[0]);
    }
}

int main()
{
    char str[60]; // 宣告一個字元陣列
    printf("請輸入一個字串：\n"); // 提示使用者輸入
    scanf("%s", str); // 讀取使用者輸入的字串
    printf("反向印出字串：\n"); // 提示反向印出
    stringReverse(str); // 呼叫 stringReverse 函數
    printf("\n"); // 換行
    return 0;
}
