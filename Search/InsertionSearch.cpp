#include <iostream>
using namespace std;


//插值查找
/*
    插值查找由二分查找优化而得到,二分查找中,mid=(low+high)/2, 即mid=low+1/2*(high-low)
    则改进为:
    mid=low+(key-a[low])/(a[high]-a[low])*(high-low)
    将1/2改进为自适应,mid的值更接近关键字key.
*/
int InsertionSearch(int a[], int value, int low, int high)
{
    int mid = low + (value - a[low]) / (a[high] - a[low]) * (high - low);
    if (a[mid] == value)
        return mid;
    else if (high - low <= 0)
        return -1;
    if (a[mid] > value)
        return InsertionSearch(a, value, low, mid - 1);
    if (a[mid] < value)
        return InsertionSearch(a, value, mid + 1, high);
}
int InsertionSearch(int a[], int value, int low, int high)
{
    int mid = low + (value - a[low]) / (a[high] - a[low]) * (high - low);
    if (a[mid] == value)
        return mid;
    else if (high - low <= 0)
        return -1;
    if (a[mid] > value)
        return InsertionSearch(a, value, low, mid - 1);
    if (a[mid] < value)
        return InsertionSearch(a, value, mid + 1, high);
}

int main(void)
{

    return 0;
}