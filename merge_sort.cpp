#include <iostream>
using namespace std;

void merge(int array[], const int begin , const int mid \
            , int end){

  // first sub array : arr[l,..,m]
  // second sub array : arr[m+1,..,r]
  
  //size of first sub array
  const int left_array_size   = mid - begin      + 1;
  //size of second sub array
  const int right_array_size  = end - (mid+1)  + 1; 

  auto *left_array = new int[left_array_size];
  auto *right_array = new int[right_array_size];

  for (auto i=0;i< left_array_size;i++) left_array[i] = array[begin+i];
  for (auto j=0;j< right_array_size;j++) right_array[j] = array[(mid+1)+j];
  
  int i = 0, j = 0 ;
  int k = begin;
  while(i<left_array_size && j<right_array_size){
    if(left_array[i] <= right_array[j]){
      array[k] = left_array[i];
      i++;
    }
    else {
      array[k] = right_array[j];
      j++;
    }
    k++;
  }

  // copy the remaining elements
  while(i<left_array_size){
    array[k] = left_array[i];
    i++;
    k++;
  }

  while(j<right_array_size){
    array[k] = right_array[j];
    j++;
    k++;
  }

  delete[] left_array;
  delete[] right_array;
}

void mergeSort(int array[], const int begin, const int end){
  if (begin>=end) return;

  auto mid = begin + (end - begin)/2;

  mergeSort(array,begin,mid);
  mergeSort(array,mid+1,end);

  merge(array,begin,mid,end);
}

int main() {
  int arr[] = { 12, 11, 13, 5, 6, 7 };
  int arr_size = sizeof(arr) / sizeof(arr[0]);

  cout << "Given array is :"<<endl;
  for (auto i =0;i<arr_size;i++){
    cout << arr[i]<<" ";
  }
  cout<<endl;

  mergeSort(arr, 0, arr_size - 1);

  printf("\nSorted array is \n");
  for (auto i =0;i<arr_size;i++){
    cout << arr[i]<<" ";
  }
  cout<<endl;
  return 0;
}

