#include <stdio.h>
void merge(int arr[], int l , int m , int r){

  // first sub array : arr[l,..,m]
  // second sub array : arr[m+1,..,r]
  int i,j,k;
  int n1 = m - l      + 1; //size of first sub array
  int n2 = r - (m+1)  + 1; //size of second sub array

  int tmp1[n1] , tmp2[n2];
  for (i=0;i<n1;i++) tmp1[i] = arr[l+i];
  for (j=0;j<n2;j++) tmp2[j] = arr[(m+1)+j];

    
  i = 0;
  j = 0;
  k = l;
  while(i<n1 && j<n2){
    if(tmp1[i] <= tmp2[j]){
      arr[k] = tmp1[i];
      i++;
    }
    else {
      arr[k] = tmp2[j];
      j++;
    }
    k++;
  }

  // copy the remaining elements
  while(i<n1){
    arr[k] = tmp1[i];
    i++;
    k++;
  }

  while(j<n2){
    arr[k] = tmp2[j];
    j++;
    k++;
  }
}

void mergeSort(int arr[], int l, int r){
  if (l<r){
    int m = l+ (r-l)/2;

    mergeSort(arr,l,m);
    mergeSort(arr,m+1,r);

    merge(arr,l,m,r);
  }
}

int main() {
  int arr[] = { 12, 11, 13, 5, 6, 7 };
  int arr_size = sizeof(arr) / sizeof(arr[0]);

  int i = 0;
  printf("Given array is \n");
  for (i =0;i<arr_size;i++){
    printf("%d ", arr[i]);
  }
  printf("\n");

  mergeSort(arr, 0, arr_size - 1);

  printf("\nSorted array is \n");
  for (i =0;i<arr_size;i++){
    printf("%d ", arr[i]);
  }
  printf("\n");
  return 0;

}

