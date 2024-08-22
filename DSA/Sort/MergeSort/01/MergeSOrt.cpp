#include<bits/stdc++.h>
using namespace std ;

void merge( int a[] , int l , int m , int r)
{
    vector<int> x(a +l , a + m + 1) ;
    vector<int> y(a+m+ 1 ,a + r + 1) ;
    int i = 0 , j = 0 ;
    while( i < x.size() && j < y.size() )
    {
        if( x[i] <= y[j])
        {
            a[l] = x[i] ;
            ++l ;
            ++i ;
        }
    else{
        a[l] = y[j];
        ++l ;
        ++j ;
    }
    }
    while(i< x.size())
    {
       a[l] = x[i] ;
       ++l ; ++i ;
    }
    while(i<y.size())
    {
        a[l]= y[j];
        ++l ; ++i;
    }
    

}
void mergeSort ( int A[] , int l , int r  )
{
    if( l >= r) return ;
        int m = ( l + r )/ 2 ;
        mergeSort(A , l , m) ;
        mergeSort(A , m+1 , r) ;
        merge( A , l , m, r ) ;
    
}
int main()
{
    int n = 10 ;
    int a[10] ;
    srand(time(NULL)) ;
    for ( int i = 0 ; i<n ; i++)
    {
        a[i] = rand()%10 ;
    }
    mergeSort(a , 0 , n - 1 );
    for ( int x : a )
    {
        cout << x << " " ;
    }
    return 0 ;

}