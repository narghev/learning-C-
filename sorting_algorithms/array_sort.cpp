#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

void bubble_sort(int array[], int length){
    for (int pass = 0; pass < length; pass++)
        for (int i = 1; i < length-pass; i++)
            if (array[i-1] > array[i])
                swap(array[i-1], array[i]);
}

void insertion_sort(int a[], int length)
{
    for (int pass = 1; pass < length; pass++)
        for (int element = pass; element > 0 && a[element] < a[element - 1]; element--)
            swap(a[element - 1], a[element]);
}

void quick_sort(int a[], int length)
{
    if (length > 1){
        int *left=a, *right=&a[length - 1], dir=1;
        while (left != right){
            for (;*left * dir< *right * dir;right-=dir);
            swap(*left, *right);
            swap(left, right);
            dir = -dir;
        }
        quick_sort(a, left - a);
        quick_sort(left + 1, length - 1 - (left - a));
    }
}

void radix_sort(int a[], int length)
{
    queue<int> bin[10];
    int i;
    for (int order=1; order <= 1e+9; order *= 10){
        for (i = 0; i < length; i++)
            bin[a[i] / order % 10].push(a[i]);
        i = 0;
        for (int next = 0; next < 10; next++)
            while (!bin[next].empty()) {
                a[i++] = bin[next].front();
                bin[next].pop();
            }
    }
}

int main(){
    int array_to_sort[] = {5,4,3,2,1,0};
    radix_sort(array_to_sort, 6);
    
    cout<< "Sorted array: ";
    for (int i = 0; i < 6; i++)
        cout<<array_to_sort[i];
    cout<<endl;

    return 0;
}