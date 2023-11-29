#include <stdio.h>

// 定義一個遞迴函數 recursiveMaximum，參數為整數陣列和陣列大小，回傳陣列中的最大元素
int recursiveMaximum(int arr[], int size)
{
    // 如果陣列大小為 1，則回傳陣列的第一個元素，這是遞迴的基本情況
    if (size == 1)
    {
        return arr[0];
    }
    // 否則，比較陣列的第一個元素和剩餘元素中的最大值，並回傳較大者，這是遞迴的一般情況
    else
    {
        int max = recursiveMaximum(arr + 1, size - 1); // 遞迴呼叫函數，陣列往後移一位，大小減一
        return arr[0] > max ? arr[0] : max; // 用三元運算子判斷較大者
    }
}

int main()
{
    int a;
    printf("需要輸入幾個整數");
    scanf("%d",&a);
    int array[100];
    printf("整數內容");
    for(int i=0;i<a;i++){
        scanf("%d",&array[i]);
    }
    int max = recursiveMaximum(array,a); // 呼叫遞迴函數，傳入陣列和大小，得到最大值
    printf("陣列中的最大元素是 %d\n", max); 
    return 0;
}
