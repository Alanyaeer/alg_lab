#include<iostream>
#include<algorithm>
#include<ctime>
#include <numeric>
#include<vector>
#include<string>
#include <iomanip>
#include<functional>
#include<cstdio>
#include<cstring>
using namespace std;
int n = 0;
void solve() {
    vector<int> value(n);
    vector<int> cost(n);
    int packSum = rand() % 1000 + 500;

    // 初始化
    for(int i = 0; i < n; ++i) {
        value[i] = rand()%1000 + 2;
        cost[i]  =  rand() % 1000 + 2;
    }
    function<void()> pagAlg = [&](){
        // 计算总的 和 
        int dp[packSum + 1];
        memset(dp, 0, sizeof dp);
        for(int i = 0; i < n; ++i){
            for(int j = packSum; j >= cost[i]; --j){
                dp[j] = max(dp[j], dp[j - cost[i]] + value[i]);
            }
        }
        cout<<"-----01背包算法-----"<<endl;
        cout<<"当背包的容量为: "<<packSum<<endl;
        cout<<"获得的价值为: "<<dp[packSum]<<endl;
    };
    function<vector<int>(int, int, vector<int>, vector<int>)> divDo = [&](int l, int r, vector<int> nums1, vector<int> nums2){
        vector<int> nums(packSum + 1, 0);
        for(int i = 0; i <= packSum; ++i){
            for(int j = 0; j + i <= packSum; ++j){
                // i 和 j 的 价值 为 左边的 dp[i] 和 右边 dp[j] 最优的 进行抉择 
                nums[i + j] = max(nums[i + j], nums1[i] + nums2[j]);
            }
        }
        // 后面的容量可能会劣于 前面的容量
        for(int j = 1; j <=packSum; ++j) nums[j] = max(nums[j], nums[j - 1]);
        return nums;
    };
    function<vector<int>(int ,int)> divAlg = [&](int l,int r){
        if(l > r) {return vector<int>(packSum + 1, 0);}
        if(l == r){
            vector<int> nums(packSum + 1, 0);
            if(cost[l] <= packSum)
            nums[cost[l]] = value[l];
            return nums;
        }
        int mid = (l + r)>>1;
        // 分治
        vector<int> nums1 =  divAlg(l, mid);
        vector<int> nums2 = divAlg(mid + 1, r);
        // 干活
        return divDo(l, r, nums1, nums2);
    };
    int start = clock();
    pagAlg();
    int end = clock();
    cout<<"消耗的时间为"<<end - start<<"ms"<<endl;
    cout<<endl;
    start = clock();
    vector<int> temp =  divAlg(0, n - 1);
    end = clock();
    cout<<"-----分治法-----"<<endl;
    cout<<"当背包的容量为："<<packSum<<endl;
    cout<<"获得的价值为："<<temp[packSum]<<endl;
    cout<<"消耗的时间为"<<end - start<<"ms"<<endl;
    cout<<endl;
}
int main() {
    srand(time(nullptr));
    int numsN[5] = {5, 10, 20, 30, 40};
    int t = 4;
    int k = 0;
    while(t--){

        n = numsN[k];
        cout<<"当前的n为："<<n<<endl;
        solve();
        k++;
    }
    return 0;
}