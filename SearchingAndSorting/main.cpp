#include <iostream>
#include "Searching.cpp"
#include "Sorting.cpp"

void PrintArray(int arr[], int size)
{
   for (int i = 0; i < size; i++)
   { 
      std::cout << arr[i] << " ";
   }
   std::cout << std::endl;
}

int main()
{
   int arr[5] = { 4,7,1,2,5 };
   int size = 5;
   PrintArray(arr, size);

   Searching search;
   Sorting sort;

   //sort.BubbleSort(arr, size);
   //sort.InsertionSort(arr, size);
   //sort.SelectionSort(arr, size);
   //sort.QuickSort(arr, 0, size - 1);
   //sort.MergeSort(arr, 0, size - 1);

   //search.BinarySearch(arr, 0, size - 1, 5);
   //std::cout << BinarySearch(arr, 0, size - 1, 5)<<std::endl;

   PrintArray(arr, size);

   system("pause");
   return 0;
}

