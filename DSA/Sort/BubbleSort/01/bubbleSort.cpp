#include<bits/stdc++.h>
using namespace std ;

void printArray(int arr[], int n)  
{  
    int i;  
    for (i = 0; i < n; i++)  
        cout << arr[i] << " ";  
    cout << endl; 
}  
void bubbleSort(int a[] , int n)
{
    for ( int i = 0 ; i < n- 1  ; i++ )
    {
        for ( int j = 0 ; j < n - i - 1 ; j++  )
        {
            if(a[j] > a[j+1] ) swap( a[j] , a[j+1]) ;
        }
        printArray(a , n) ;
    }
}

int main()
{
    int n ; cin >> n ;
    int a[n] ;
    for (int i = 0; i < n; i++)
    {
       cin >> a[i] ;
    }
    bubbleSort(a , n) ;
    printArray(a , n) ;
    return 0;

    
}