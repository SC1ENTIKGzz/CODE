#include<bits/stdc++.h>
using namespace std;
//dem so lan xuat hien cua xau , in ra so lan xuat hien cua moi ki tu trong xau
int main()
{
    map < string , int > mp ;
     int n ; cin >> n ;
     for ( int i =0 ;  i < n ; i ++ )
     {
         string s ; cin >> s ;
         mp[s]++ ;
     }
     int max_freq = 0 ;
     string res ;
     for ( auto it : mp )
     {
         cout << it.first << " " << it.second << endl ;
     }
     for ( auto it : mp )
     {
         if ( it.second > max_freq )
         {
             max_freq = it.second ;
             res = it.first ;
         }
     }
}