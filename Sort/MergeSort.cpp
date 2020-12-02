/*
归并排序
divide-conquer,"分而治之"思想
*/

#include <iostream>
using namespace std;
// 定义存储数据的结构
typedef struct item {
  string str;
} Item, *ptrToItem;

// 操作的核心，将两个已排好序的数组归并为新的有序数组（利用双指针法）
// l_poos,r_pos,LeftEnd,rightEnd是为标记数组中的位置，tmpPos标记tmpArr的位置
void Merge(ptrToItem arr[], ptrToItem tmpArr[], int l_pos, int r_pos,
           int rightEnd) {
  int i, leftEnd, num, tmpPos;
  leftEnd = r_pos - 1;
  tmpPos = l_pos;
  num = rightEnd - l_pos + 1;

  while (l_pos <= leftEnd && r_pos <= rightEnd) {
    if (arr[l_pos]->str[0] <= arr[r_pos]->str[0]) {
      tmpArr[tmpPos++] = arr[l_pos++];
    } else {
      tmpArr[tmpPos++] = arr[r_pos++];
    }
  }

  //   将剩下的有序项全部添加到tmpArr中
  while (l_pos <= leftEnd) {
    tmpArr[tmpPos++] = arr[l_pos++];
  }
  while (r_pos <= rightEnd) {
    tmpArr[tmpPos++] = arr[r_pos++];
  }

  //   将tmpArr存储的值拷贝回原数组（若用链表实现则不需要）
  for (i = 0; i < num; i++, rightEnd--) {
    arr[rightEnd] = tmpArr[rightEnd];
  }
}

//递归排序的整体流程：分割再归并
void MSort(ptrToItem arr[], ptrToItem tmpArr[], int left, int right) {
  int center;
  if (left < right) {
    center = (left + right) / 2;
    MSort(arr, tmpArr, left, center);
    MSort(arr, tmpArr, center + 1, right);
    Merge(arr, tmpArr, left, center + 1, right);
  }
}

// 排序函数接口
void MergeSort(ptrToItem arr[], int n) {
  ptrToItem *tmpArr = (ptrToItem *)malloc(sizeof(ptrToItem) * n);
  if (tmpArr != nullptr) {
    MSort(arr, tmpArr, 0, n - 1);
    free(tmpArr);
  } else {
    cout << "Error,out of space." << endl;
  }
}

int main(void) {

  Item arr[5] = {{"y"}, {"b"}, {"z"}, {"d"}, {"cq"}};
  ptrToItem item_arr[5] = {&arr[0], &arr[1], &arr[2], &arr[3], &arr[4]};
  MergeSort(item_arr, 5);
  for (int i = 0; i < 5; i++) {
    cout << item_arr[i]->str << " ";
  }
  return 0;
}