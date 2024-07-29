#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<ctime>
#include <iomanip>
using namespace std;
void solve() {
    // 动态规划法
    int n; 
    n = rand() % 10 + 5;
    vector<int>Denominations(n);
    for(int i = 0; i < n; ++i){
        Denominations[i] = rand() % 20 + 1;
    }
    // 保证答案一定会存在 
    Denominations[0] = 1; 
    int change = rand() % 100 + 30;
    // dp[i] = 0 dp[i] = -1;
    // dp[j] = dp[j - Denominations[now]] + 1
    vector<int>dp(change + 1, -1);
    dp[0] = 0;
    for(int i = 1; i <= change; ++i){
        for(int j = 0; j < n; ++j){
            if(Denominations[j] > i) continue;
            if(dp[i - Denominations[j]] != -1) {
                if(dp[i] == -1) dp[i] = dp[i - Denominations[j]] + 1;
                else dp[i] = min(dp[i],  dp[i - Denominations[j]] + 1);
            }
        }
    }

    cout<<"-------前提---------"<<endl;
    cout<<"当前的找钱数量为"<<change<<endl;
    cout<<"当前的钞票的集合为: "<<endl;
    for(int i = 0; i < n; ++i){
        if(i == 0) cout<<"[";
        cout<<Denominations[i];
        if(i != n - 1){
            cout<<", ";
        }
        else cout<<"]\n"<<endl;
    }

    cout<<"------- 动态规划 -------"<<endl;
    cout<<"当找钱金额为 "<<change<<" 时最小的找钱数量为"<<dp[change]<<endl;

    cout<<"------- 贪心算法 -------"<<endl;
    sort(Denominations.rbegin(), Denominations.rend());
    int billCnt = 0;
    int tempChange =change;
    for(int i = 0; i < n; ++i){
        int billItemCnt =  (tempChange) / Denominations[i];
        billCnt += billItemCnt;
        tempChange -= billItemCnt * Denominations[i];
    }
    cout<<"当前找钱的金额为 "<<change<<" 时最小(这是用这个贪心算法找出来的)的找钱数量为"<<billCnt<<endl;
}
int main() {
    int t;
    t = 1;
    srand(time(nullptr));
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}

