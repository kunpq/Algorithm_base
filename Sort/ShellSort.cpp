#include <iostream>
using namespace std;

template <typename T>

void ShellSort(T *arr, int n) {
  // increment为跨度
  int i, j, increment;
  T tmp;
  for (increment = n / 2; increment > 0; increment /= 2) {
    for (i = increment; i < n; i++) {
      tmp = arr[i];
      // 局部插入排序
      for (j = i; j >= increment; j -= increment) {
        if (tmp < arr[j = increment]) {
          arr[j] = arr[j - increment];
        } else {
          break;
        }
      }
      arr[j] = tmp;
    }
  }
}

int main(void) {
  int a[100];
  for (int i = 99, j = 0; i >= 0; i--, j++) {
    a[j] = i;
  }
  for (int i = 0; i < 100; i++) {
    cout << a[i] << endl;
  }
  cout << "********************" << endl;

  ShellSort(a, 100);
  for (int i = 0; i < 100; i++) {
    cout << a[i] << " ";
  }
  return 0;
}