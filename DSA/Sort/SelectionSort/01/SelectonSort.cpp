#include<bits/stdc++.h>
using namespace std ;
void selectionSort(int a[] , int n )
{
    for(int i =0 ;  i< n ; i++)
    {
        //dung 1 bien de khoi tao gia tri nho nhat
        int min_pos = i ;
        //Duyet cac phan tu phia sau phan tu hien tai
        for (int j = i+1; j <n ; j++)
        {
            if ( a[j] < a[min_pos]) min_pos = j;
        }
        swap(a[i], a[min_pos]);

    }
}
int main()
{
    int a[10] ;
    int n =10 ;
    srand(time(NULL)) ;
    for ( int i = 0 ; i < n ; i ++)
    {
        a[i] = rand()%10 ;
    }
    selectionSort(a , n) ;
    for ( int j = 0; j< n ; j++ )
    {
        cout << a[j] << " " ;
    }
    return 0 ;

}