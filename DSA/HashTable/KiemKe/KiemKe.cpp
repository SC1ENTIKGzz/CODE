
#include <bits/stdc++.h>
using namespace std;


int N;

int count_distinct(const vector<string>& ids){

	map<string,int> Hash; 
	for ( const string& id : ids )
    {
        Hash[id] ++ ;
        //neu ma da ton tai trong hash , tang gia tri tuong ung len 1
        //neu ma hash chua ton tai , them ma hash voi gia tri ban dua la 1
    }
    return Hash.size() ;
    // tra ve so luong phan tu trong hash de bt so luong khac nhau
  



}

int main(){
	ios::sync_with_stdio(false); cin.tie(nullptr);
	
	cin >> N;
	vector<string> ids(N);
	
	for (int i = 0; i < N; i++) cin >> ids[i];
		
	cout << count_distinct(ids);

	return 0;
}

