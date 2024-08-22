#include<bits/stdc++.h>
using namespace std ;
void printArray(int arr[], int n)  
{  
    int i;  
    for (i = 0; i < n; i++)  
        cout << arr[i] << " ";  
    cout << endl; 
}  
void insertionSort(int arr[], int n)
{
   int i, key, j;
   for (i = 1; i < n; i++)
   {
       key = arr[i];
       j = i-1;
  
       /* Di chuyển các phần tử có giá trị lớn hơn giá trị 
       key về sau một vị trí so với vị trí ban đầu
       của nó */
       while (j >= 0 && arr[j] > key)
       {
           arr[j+1] = arr[j];
           j--;
       }
        printArray(arr , n ) ;
        arr[j+1] = key;
      
   }
}

void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}
void insertionSortDesc(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
         key = arr[i];
         j = i-1;
  
         /* Move elements of arr[0..i-1], that are
             greater than key, to one position ahead
             of their current position */
         while (j >= 0 && arr[j] < key)
         {
              arr[j+1] = arr[j];
              j--;
         }
         arr[j+1] = key;
    }
}

int main()
{
     vector<int> myVector = {12, 11, 13, 5, 6};
    insertionSort(myVector);
    for (int num : myVector) {
        cout << num << " ";
    }
    cout << endl;
    int b[5] = { 6 , 5 , 7 , 9 , 0 };
    insertionSort( b , 5 ) ;
    printArray( b , 5) ;
    
 


}