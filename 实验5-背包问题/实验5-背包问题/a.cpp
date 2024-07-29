#include <iostream>
#include<queue>
#include<algorithm>
#include<vector>
using namespace std;
#define ll long long
void solve() {
    int n;
    cin>>n;
    int M;
    cin>>M;
    vector<pair<int,int>> nums(n);
    for(int i = 0; i < n; ++i) cin>>nums[i].first>>nums[i].second;
    sort(nums.rbegin(), nums.rend());   
    ll sumValue = 0;
    int tempM = M;
    for(int i = 0 ;i < n; ++i){
        int temp = min(nums[i].second,  tempM);
        tempM -= temp;
        sumValue += temp * nums[i].first;
        if(tempM < 0) break; 
    }
    cout<<"对价值进行排序后的数据"<<endl;
    for(int i = 0; i < n; ++i){
        cout<<"第"<<i<<"个数据的价值为："<<nums[i].first<<" "<<"剩余量为："<<nums[i].second<<endl;
    }
    cout<<"当背包容量为："<<M<<endl;    
    cout<<"获得的最大收益为"<<sumValue<<endl;
}
int main()
{
    int t;
    t = 1;
    while(t--) solve();
    return 0;
}

