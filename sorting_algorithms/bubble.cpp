#include <iostream>
#include <algorithm>

using namespace std;

void bubble_sort(int array[], int length){
    for (int pass = 0; pass < length; pass++)
        for (int i = 1; i < length-pass; i++)
            if (array[i-1] > array[i])
                swap(array[i-1], array[i]);
}

int main(){
    int array_to_sort[] = {5,4,3,2,1,0};
    bubble_sort(array_to_sort, 6);
    
    cout<< "Sorted array: ";
    for (int i = 0; i < 6; i++)
        cout<<array_to_sort[i];
    cout<<endl;

    return 0;
}