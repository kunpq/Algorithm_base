#include <iostream>
using namespace std;
void CountSort(int arrA[], int arrB[], int n);
int main(void) {
  int arrA[9] = {2, 5, 3, 8, 2, 3, 7, 3, 12};
  int arrB[9];
  CountSort(arrA, arrB, 9);
  for (int i = 0; i < 9; i++) {
    cout << arrB[i] << endl;
  }
  return 0;
}

void CountSort(int arrA[], int arrB[], int n) {
  int k = 20;
  int arrC[k];
  int i, j;
  for (i = 0; i < k; i++) {
    arrC[i] = 0;
  }
  for (j = 0; j < n; j++) {
    arrC[arrA[j]] += 1;
  }

  for (i = 1; i < k; i++) {
    arrC[i] = arrC[i] + arrC[i - 1];
  }

  for (j = n - 1; j >= 0; j--) {
    arrB[arrC[arrA[j]] - 1] = arrA[j];
    arrC[arrA[j]] -= 1;
  }
}