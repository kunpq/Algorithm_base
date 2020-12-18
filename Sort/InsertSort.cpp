#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

void InserSort(int arr[], int n) {
  int j, p;
  int tmp;
  for (p = 1; p < n; p++) {
    tmp = arr[p];
    for (j = p; j > 0 && tmp < arr[j - 1]; j--) {
      arr[j] = arr[j - 1];
    }
    arr[j] = tmp;
  }
}

int main(void) {
  srand((unsigned int)time(0));
  int arr[100];
  for (int i = 99; i >= 0; i--) {
    arr[i] = rand() % 100;
  }
  InserSort(arr, 100);
  for (int i = 0; i < 100; i++) {
    std::cout << arr[i] << std::endl;
  }
  return 0;
}