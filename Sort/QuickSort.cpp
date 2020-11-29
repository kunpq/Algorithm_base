#include <cstdlib>
#include <iostream>
void QuickSort(int *start, int *end);
void Swap(int &a, int &b);

int main(void) {

  int size = 100;
  srand((unsigned int)time(nullptr));
  int arr[100];
  for (int i = 0; i < size; i++) {
    arr[i] = rand() % 200;
  }

  QuickSort(arr, arr + size - 1);

  for (int i = 0; i < size; i++) {
    std::cout << arr[i] << std::endl;
  }
  return 0;
}

void QuickSort(int *start, int *end) {
  int *p1, *p2;
  //   设置界限
  if (end - start == -1 || end == start) {
    return;
  }
  // 设定首尾指针
  p1 = start;
  p2 = end;

  bool check = true;
  int middle = *p1;

  while (p2 - p1) {
    // check为真，middle与后面的依次比较
    if (check) {
      if (middle > *p2) {
        Swap(*p1, *p2);
        p1++;
        check = false; //准备从前面比较
      } else {
        p2--;
      }
    }
    // check为假，middle与前面的依次比较
    else {
      if (middle < *p1) {
        Swap(*p2, *p1);
        p2--;
        check = true; //准备从后面比较
      } else {
        p1++;
      }
    }
  }
  *p1 = middle;
  //   递归调用直到全部排序完毕
  QuickSort(start, p1 - 1);
  QuickSort(p1 + 1, end);
}

void Swap(int &a, int &b) {
  int tmp = a;
  a = b;
  b = tmp;
}