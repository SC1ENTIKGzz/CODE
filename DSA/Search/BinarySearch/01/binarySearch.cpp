#include <iostream>
#include <vector>
using namespace std ;


int binarySearch(const vector<int>& arr, int target) {
    int left = 0;              
    int right = arr.size() - 1; 


    while (left <= right) {
        int mid = left + (right - left) / 2;  

     
        if (arr[mid] == target) {
            return mid;  
        }


        if (arr[mid] < target) {
            left = mid + 1;
        }
   
        else {
            right = mid - 1;
        }
    }


    return -1;
}
int binarySearch_arr(int arr[] , int n  , int X)
{
    int left =0 ;
    int right = n-1 ;
    while ( left <= right )
    {
        int mid = left + ( right - left ) / 2;
        if (arr[mid]== X){
            return mid ;
        }
        if( arr[mid]< X){
            left = mid + 1 ;
        }
        else{
            right = mid -1 ;
        }
    }
    return -1 ;

}
int binarySearch(const vector<int>& arr, int target) {
    int left = 0;              
    int right = arr.size() - 1; 

    while (left <= right) {
        int mid = left + (right - left) / 2;  

        if (arr[mid] == target) {
            return mid;  
        }

        if (arr[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    return -1;
}

int binarySearch_arr(int arr[], int l, int r, int X) {
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (arr[m] == X) {
            return m;
        }
        if (arr[m] < X) {
            l = m + 1;
        }
        else {
            r = m - 1;
        }
    }
    return -1;
}

int main() {

    vector<int> arr = {2, 3, 4, 10, 40, 50, 60, 70};


    int target = 10;


    int result = binarySearch(arr, target);

    if (result != -1) {
        cout << "Element found at index " << result << endl;
    } else {
        cout << "Element not found in the array" << endl;
    }
    int n ;
    cin >> n ;
    int D[n] ;
    for ( int i = 0 ; i < n ; i ++)
    {
        cin>> D[i] ;
    }
   
    int ans = binarySearch_arr(D, n , target ) ;
    cout <<  ans ;

    return 0;
}
