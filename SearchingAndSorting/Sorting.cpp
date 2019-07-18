#include <iostream>

class Sorting
{
public:

   //-------------------------------------------------------------------------------------------------------------------------

   void BubbleSort(int arr[], int size)
   {
      for (int i = 0; i < size; i++)
      {
         for (int j = 0; j < size - 1 - i; j++)
         {
            if (arr[j] > arr[j + 1])
            {
               std::swap(arr[j], arr[j + 1]);
            }
         }
      }
   }

   //-------------------------------------------------------------------------------------------------------------------------

   void SelectionSort(int arr[], int size)
   {
      for (int frontIndex = 0; frontIndex < size; frontIndex++)
      {
         int minimum = frontIndex;
         for (int unsortedIndex = frontIndex + 1; unsortedIndex < size; unsortedIndex++)
         {
            if (arr[minimum] > arr[unsortedIndex])
            {
               minimum = unsortedIndex;
            }
         }
         std::swap(arr[minimum], arr[frontIndex]);
      }
   }

   //-------------------------------------------------------------------------------------------------------------------------

   void InsertionSort(int arr[], int size)
   {
      for (int i = 0; i < size; i++)
      {
         int temp = arr[i];
         int lowerIndex = i;
         while (lowerIndex > 0 && temp < arr[lowerIndex - 1])
         {
            arr[lowerIndex] = arr[lowerIndex - 1];
            lowerIndex--;
         }

         arr[lowerIndex] = temp;
      }
   }

   //-------------------------------------------------------------------------------------------------------------------------

   void MergeSort(int A[], int start, int end)
   {
      if (start < end)
      {
         int mid = (start + end) / 2; // defines the current array in 2 parts.
         MergeSort(A, start, mid); // sort the 1st part of array .
         MergeSort(A, mid + 1, end);  // sort the 2nd part of array.

         // merge the both parts by comparing elements of both the parts.
         Merge(A, start, mid, end);
      }
   }

   //-------------------------------------------------------------------------------------------------------------------------

   void QuickSort(int arr[], int startIndex, int endIndex)
   {
      if (startIndex < endIndex)
      {
         int pivotIndex = Partition(arr, startIndex, endIndex);
         QuickSort(arr, startIndex, pivotIndex - 1);
         QuickSort(arr, pivotIndex + 1, endIndex);
      }
   }

   //-------------------------------------------------------------------------------------------------------------------------

private:

   //-------------------------------------------------------------------------------------------------------------------------

   int Partition(int arr[], int startIndex, int endIndex)
   {
      int pivot = arr[startIndex];//first element pivot

      int boundaryLessGreaterPivotIndex = startIndex + 1;
      for (int j = startIndex + 1; j <= endIndex; j++)
      {
         if (pivot > arr[j])
         {
            std::swap(arr[boundaryLessGreaterPivotIndex], arr[j]);
            boundaryLessGreaterPivotIndex++;
         }
      }

      std::swap(arr[startIndex], arr[boundaryLessGreaterPivotIndex - 1]);

      return boundaryLessGreaterPivotIndex - 1;
   }

   //-------------------------------------------------------------------------------------------------------------------------

   void Merge(int A[], int start, int mid, int end)
   {
      //stores the starting position of both parts in temporary variables.
      int p = start, q = mid + 1;
      int  k = 0;
      int* Arr = new int[end - start + 1];

      for (int i = start; i <= end; i++)
      {
         if (p > mid)//checks if first part comes to an end or not .
            Arr[k++] = A[q++];

         else if (q > end)//checks if second part comes to an end or not
            Arr[k++] = A[p++];

         else if (A[p] < A[q])//checks which part has smaller element.
            Arr[k++] = A[p++];

         else
            Arr[k++] = A[q++];
      }
      for (int p = 0; p < k; p++)
      {
         //Now the real array has elements in sorted manner including both parts.
         A[start++] = Arr[p];
      }

      delete[]Arr;
   }

   //-------------------------------------------------------------------------------------------------------------------------

};