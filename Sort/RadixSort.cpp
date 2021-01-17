#include <iostream>
using namespace std;
void RadixSort(int a[], int n);
void CountSort(int a[], int n, int exp);
int GetMax(int arr[], int n);
int main(void) { return 0; }
void CountSort(int a[], int n, int exp) {
  int output[n];
  int i;
  int buckets[10] = {0};
  for (i = 0; i < n; i++) {
    buckets[(a[i] / exp) % 10]++;
  }
  for (i = 1; i < 10; i++) {
    buckets[i] += buckets[i - 1];
  }
  for (i = n - 1; i >= 0; i--) {
    output[buckets[(a[i] / exp) % 10] - 1] = a[i];
    buckets[(a[i] / exp) % 10]--;
  }
}

int GetMax(int arr[], int n) {
  int max = arr[0];
  for (int i = 1; i < n; i++) {
    if (arr[i] > max) {
      max = arr[i];
    }
  }
  return max;
}

void RadixSort(int a[], int n) {
  int exp;
  int max = GetMax(a, n);
  for (exp = 1; max / exp != 0; exp *= 10) {
    CountSort(a, n, exp);
  }
}