#include <iostream>
using namespace std;
  
// function to heapify the tree
void heapify(int array[], int n, int root)
{
    int largest = root; 
    int l = 2 * root + 1; // left = 2*i + 1
    int r = 2 * root + 2; // right = 2*i + 2
 

    if (l < n && array[l] > array[largest])
        largest = l;
 

    if (r < n && array[r] > array[largest])
        largest = r;
 
    // If largest is not root
    if (largest != root) {
        swap(array[root], array[largest]);
 
 
        heapify(array, n, largest);
    }
}


void heapSort(int array[], int n)
{

    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(array, n, i);
 

    for (int i = n - 1; i >= 0; i--) {

        swap(array[0], array[i]);
 

        heapify(array, i, 0);
    }
}
  

void displayArray(int array[], int n)
{
   for (int i=0; i<n; ++i)
   cout << array[i] << " ";
   cout << "\n";
}
  
// main program
int main()
{
   int heap_arr[] = {41,2,56,90,212,77,34,20,9};
   int n = sizeof(heap_arr)/sizeof(heap_arr[0]);
   cout<<"Input array"<<endl;
   displayArray(heap_arr,n);
  
   heapSort(heap_arr, n);
  
   cout << "Sorted array"<<endl;
   displayArray(heap_arr, n);
}

