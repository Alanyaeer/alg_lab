#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<functional>
#include <cstdlib>
#include<map>
#include<set>
#include <iomanip>
#include<cstdio>
#include<cstring>
#include<windows.h>
#include <ctime>
using namespace std;
int k = 0;
pair<int,int> getFourIndex (int x, int y) {
    return make_pair((x / 2), (y / 2));
}
vector<vector<int>>graph; 
void solve() {
    int n = (1 << k);
    // 分配一个初始空间 
    graph.resize(n);
    for(int i = 0; i < n; ++i){
        graph[i] = vector<int>(n, -1);
    }

    int zeroX,   zeroY;
    zeroX = rand() % n; // 随机生成 x， y
    zeroY = rand() % n;
    // 添加0的位置 
    graph[zeroX][zeroY] = 0;
    int nowTag = 1; 
    // 查找象限
    function<void(int ,int,int, int)> fillempty = [&](int left, int right, int up , int down){
        for(int i = left ; i <= right; ++i){
            for(int j = up; j <= down; ++j){
                if(graph[i][j] == -1) {
                    graph[i][j] = nowTag;
                }
            }
        }
        nowTag++;
    };
    function<vector<pair<int,int>>(int, int, int, int)> fillDimension = [&](int x, int y, int curX, int curY){
        vector<pair<int,int>> nums;
        // 第一象限判断
        if(curX <= x && curY <= y) {
            nums.push_back(make_pair(curX, curY));
        }
        else{
            nums.push_back(make_pair(x, y));
            graph[x][y] = nowTag;
        }
        // 第二象限判断

        if(curX <= x && curY >= y + 1){
            nums.push_back(make_pair(curX, curY));
        }
        else{
            nums.push_back(make_pair(x , y + 1));
            graph[x][y + 1] = nowTag;
        }

        // 第三象限判断
        if(curX >= x + 1 && curY <= y){
            nums.push_back(make_pair(curX, curY));
        }
        else {
            nums.push_back(make_pair(x + 1, y));
            graph[x + 1][y] = nowTag;

        }
        // 第四象限
        if(curX >= x + 1 && curY >= y + 1){
            nums.push_back(make_pair(curX, curY));
        }
        else{
            nums.push_back(make_pair(x + 1, y + 1));
            graph[x + 1][y + 1] = nowTag;
        }
        nowTag++;
        // fill
        return nums;
    };
    // left right up down
    function<void(int ,int, int ,int, int ,int)> div = [&](int left, int right, int up, int down, int curX, int curY){
        // 如果当前区块的长度为 2 的 时候 就 终止
        if(right - left == 1 && down - up == 1){
            fillempty(left, right, up, down);
            return ;
        }
        // 它们的 中轴 
        int midx = (left + right)>>1;
        int midy = (up + down)>>1;

        // 给每个象限的 进行一个 填充 获取到一个数组， 存入 第一象限 第二 第三 第四
        auto nums =  fillDimension(midy, midx, curX, curY);

        // 分成四个区块
        div(left, midx, up, midy, nums[0].first, nums[0].second); // 第一象限
        div(midx + 1, right , up, midy, nums[1].first, nums[1].second); // 第二象限
        div(left, midx, midy + 1, down, nums[2].first, nums[2].second); // 第三象限
        div(midx + 1, right, midy + 1, down, nums[3].first, nums[3].second); // 第四象限

    };
    function<void()> printGraph = [&](){
        cout<<"当前x = "<<zeroX<<" 当前y = "<<zeroY<<endl;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                cout<<setw(3)<<graph[i][j];
            }
            cout<<endl;
        }
    };
    div(0, n - 1, 0, n -1, zeroX, zeroY);
    printGraph();
}
int main(){
    int t;
    t = 5;
    while((t--) > 2){
        srand(time(nullptr));
        DWORD t1,t2;
        t1 = GetTickCount();
        k = 6 - t;
        cout<<"k = "<<k<<"第1次操作"<<endl;
        solve();
        cout<<"k = "<<k<<"第2次操作"<<endl;
        solve();
        t2 = GetTickCount();
        cout<<"time = "<<((t2-t1)*1.0)<<endl;  //输出时间（单位：ｓ）
    }

}
