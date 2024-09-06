#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
  sort(nums.begin(),nums.end());
    int n=nums.size();
    if(n==0)
        return 0;
    int count=1;
    map<int,int> m;
    for(int i=0;i<n;i++)
    {
        m[nums[i]]++;

    }
    int maxcount=1;
    for(int i=0;i<n-1;i++)
    {
        if(nums[i+1]==nums[i]+1)
        {
            count++;
        }
        else if(nums[i+1]==nums[i])
        {
            continue;
        }
        else
        {
            count=1;
        }
        maxcount=max(maxcount,count);
    }
    return maxcount;
    }

    
};
int main()
{
    Solution s;
    vector<int> nums={100,4,200,1,3,2};
    cout<<s.longestConsecutive(nums);
}

