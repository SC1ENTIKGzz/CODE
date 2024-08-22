#include<bits/stdc++.h>
using namespace std ;
int linearSearch(int arr[], int n, int x){
  
    for(int i = 0; i < n; i++)
        if (arr[i] == x)
            return i + 1;
        
    return -1;
}
int linearSearch( int arr[] , int n , int x )
{
    for ( int i = 0 ; i < n ; i++)
    if( arr[i] == x )
    return i + 1 ;
    return -1 ;
}
int main()
{
    int n ; cin>> n ;
    int a[n] ;
    for ( int i = 0 ; i < n ; i++)
    {
        cin>> a[i] ;
    }
    int x ; cin >> x ;
    cout << linearSearch(a , n , x) ;

}