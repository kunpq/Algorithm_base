#include <cstdlib>
#include <ctime>
#include <iostream>

#define LeftChild(i) (2 * (i) + 1)

using namespace std;

void Swap(int &a, int &b) {
  int tmp = a;
  a = b;
  b = tmp;
}

// 最大堆向下渗透
void PercDown(int arr[], int position, int n) {
  int tmp = arr[position]; //暂时存储向下渗透的节点
  int child;
  for (tmp = arr[position]; LeftChild(position) < n; position = child) {
    child = LeftChild(position);
    if (child != n - 1 && arr[child] < arr[child + 1]) {
      child++;
    }
    if (tmp < arr[child]) {
      arr[position] = arr[child];
    } else { //一旦不满足条件即可根据二叉堆的性质判断出无需再下渗
      break;
    }
  }
  arr[position] = tmp; //找到位置后填进去
}

void HeapSort(int arr[], int n) {
  for (int i = n / 2; i >= 0; i--) {
    PercDown(arr, i, n); //构建最大堆
  }

  for (int i = 0; i < 100; i++) {
    cout << arr[i] << " ";
    if ((i + 1) % 10 == 0) {
      cout << endl;
    }
  }
  //   进行排序,每次将当前最大的项放在数组末端
  for (int i = n; i > 0; i--) {
    Swap(arr[0], arr[i]);
    PercDown(arr, 0, i);
  }
}

int main(void) {
  srand((unsigned int)time(0));
  int tmp;
  int arr[100];
  for (int i = 0; i < 100; i++) {
    tmp = rand() % 100;
    arr[i] = tmp;
  }

  HeapSort(arr, 100);
  for (int i = 0; i < 100; i++) {
    cout << arr[i] << " ";
    if ((i + 1) % 10 == 0) {
      cout << endl;
    }
  }

  return 0;
}