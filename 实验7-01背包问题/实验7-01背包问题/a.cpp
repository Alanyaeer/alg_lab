#include<iostream>
#include<string>
#include<algorithm>
#include<ctime>
#include<functional>
#include<queue>
#include<vector>
using namespace std;
int n;
void solve(){
    vector<int> value(n);
    vector<int> price(n);
    for(int i = 0; i < n; ++i) value[i] = rand() % 10 + 5;
    for(int i = 0; i < n; ++i) price[i] = rand() % 10 + 1;
    int capcity = rand() % 50 + 20;
    long long startclock = 0;
    long long endclock = 0;
    startclock = clock();
    // 选择的物品
    vector<int> chose;
    int totalValue = 0;
    int currentValue = 0;
    int currentHeavy = 0;
    function<void(int)> dfs = [&](int index){
        if(currentHeavy > capcity) return ;
        if(index == n){
            totalValue = max(totalValue, currentValue);
            return ;
        }
        dfs(index + 1);
        currentValue += price[index];
        currentHeavy += value[index];
        dfs(index + 1);
        currentHeavy -= value[index];
        currentValue -= price[index];
    };
    dfs(0);
    endclock = clock();
    cout<<"现有物品重量为"<<endl;
    for(int i = 0; i < n; ++i) cout<<value[i]<<" ";
    cout<<endl;
    cout<<"现有物品的价值为"<<endl;
    for(int i = 0; i < n; ++i) cout<<price[i]<<" ";
    cout<<endl;
    cout<<"背包可容纳重量为: "<<capcity<<endl;
    cout<<"---------------对于回溯算法来说-------------"<<endl;
    cout<<"对于回溯算法来说， 最优的值为："<<totalValue<<endl;
    cout<<"花费的时间为："<<(endclock - startclock)<<endl;
    currentValue = 0;
    currentHeavy = 0;
    totalValue = 0;

    startclock = clock();
    queue<pair<int,int>>q;
    q.push(make_pair(0, 0));
    for(int i = 0; i < n; ++i){
        int v = value[i];
        int p = price[i];
        queue<pair<int,int>>nq;
        while(q.size()){
            // 可以拿也可以不拿
            auto pItem = q.front();
            nq.push(pItem);
            pItem.first += v;
            pItem.second += p;
            if(pItem.first <= capcity){
                nq.push(pItem);
            }
            q.pop();
        }
        q = nq;
    }
    while(q.size() > 0){
        auto p = q.front();
        q.pop();
        totalValue = max(totalValue, p.second);
    }
    endclock = clock();
    cout<<"---------------对于分支限界法来说-------------"<<endl;
    cout<<"对于分支限界法来说, 最优值为: "<<totalValue<<endl;
    cout<<"花费的时间为："<<(endclock - startclock)<<endl;



}   
int main(){
    int t = 5;
    srand(time(nullptr));
    int testN[5] = {5, 10, 20, 30, 40};
    while(t--) {
        n = testN[4 - t];
        solve();
    }
    return 0;
}