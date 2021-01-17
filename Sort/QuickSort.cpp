#include <iostream>
using namespace std;
// 递归进行快速排序
void QuickSort(int arr[], int start, int end);
// 三数-中值法得到枢纽元
int GetPivot(int arr[], int start, int end);
// 交换值
void Swap(int &a, int &b);

int main(void) {
  int arr[16] = {1, 3, 0, 31, 5, 10, 100, 1000, 2, 88, 234, 4, 8, 11, 121, 7};
  QuickSort(arr, 0, 15);
  for (int i = 0; i < 16; i++) {
    cout << arr[i] << endl;
  }
  return 0;
}

void QuickSort(int arr[], int start, int end) {
  // 出口条件,即只有一个或两个待排数据
  if (end - start == 1 || end == start) {
    if (arr[end] < arr[start]) {
      Swap(arr[end], arr[start]);
    }
    return;
  }

  int pivot;
  // 得到pivot
  pivot = GetPivot(arr, start, end);
  int i = start + 1;
  int j = end - 2;
  bool rightToLeft = true;
  // 主要操作,左右指针反复横跳
  while (j - i != -1) {
    if (rightToLeft) {
      // 相等时亦进行跳转，防止极端情况的发生
      if (arr[j] <= pivot) {
        Swap(arr[i], arr[j]);
        i++;
        rightToLeft = false;
      } else {
        j--;
      }
    } else {
      if (arr[i] >= pivot) {
        Swap(arr[i], arr[j]);
        j--;
        rightToLeft = true;
      } else {
        i++;
      }
    }
  }
  // 将pivot与i处数据交换完成排序
  Swap(arr[i], arr[end]);
  // 递归排序左右两边
  QuickSort(arr, start, j);
  QuickSort(arr, i + 1, end);
}

int GetPivot(int arr[], int start, int end) {
  int left = arr[start];
  int right = arr[end];
  int median = arr[(start + end) / 2];
  int max, min, medium;
  // 先比较两数之间的大小关系并记录
  if (left > right) {
    max = left;
    min = right;
  } else {
    max = right;
    min = left;
  }
  // 再比较第三个数与前两个数的大小关系
  if (max < median) {
    medium = max;
    max = median;
  } else if (median > min) {
    medium = median;
  } else {
    medium = min;
    min = median;
  }
  // 将三个位置重新赋值
  arr[start] = min;
  arr[(start + end) / 2] = max;
  arr[end] = medium;
  // 交换end-1处与max处
  Swap(arr[end - 1], arr[(start + end) / 2]);
  return medium;
}

void Swap(int &a, int &b) {
  int tmp = a;
  a = b;
  b = tmp;
}