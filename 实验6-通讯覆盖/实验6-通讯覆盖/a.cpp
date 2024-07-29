#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<ctime>
#include <iomanip>
#include<cmath>
using namespace std;
const float inf = 1e-6;
void solve() {
    // 岛屿的数量
    int n;
    n = rand() % 10 + 5;
    int d;
    d = rand() % 30 + 10;
    // 第一个int 代表 横坐标， 第二个int 代表 纵坐标方向
    vector<pair<int,int>> site(n);
    for(int i = 0; i < n; ++i){
        site[i].first = rand() %  100;
        site[i].second = rand() % d;
    }
    cout<<"现在有"<<n<<"个岛屿"<<endl;
    cout<<"分别在"<<endl;
    for(int i = 0; i < n; ++i){
        cout<<"横坐标为："<<site[i].first<<" 纵坐标为："<<site[i].second<<endl;
    }
    cout<<"-----------------------"<<endl;
    cout<<"d的大小为: "<<d<<endl;
    // 排序岛屿
    // 首先根据 岛屿 画一个圆 然后会和 x轴产生 两个交点（当然一个交点可以理解为两个交点结合)
    // 这样就会在x轴构成多个区间 ， 就可以转换为 区间问题 来进行 求解

    // 在x轴的映射
    vector<pair<double,double>> x(n);
    cout<<"-----------------------"<<endl;
    cout<<"在x轴的映射为"<<endl;
    for(int i = 0; i < n; ++i){
        // dx =  sqrt(d^2 - site[i].second)
        double dx = sqrt(d * d - site[i].second * site[i].second);
        x[i].first = site[i].first - dx;
        x[i].second = site[i].first + dx;
        cout<<"开始位置："<<x[i].first<<"结束位置："<<x[i].second<<endl;
    }
    // 根据岛屿在x轴的后边的那一段进行映射
    sort(x.begin(), x.end(), [&](auto p1, auto p2){
        return p1.second < p2.second;
    });
    double cursor = -1.0;
    int cnt = 0;
    vector<double>pos;
    for(int i = 0; i < n; ++i){
        if((x[i].first - cursor) <= inf) continue;
        cursor = x[i].second;
        // 建立一个基站 
        pos.push_back(x[i].second);
        cnt++;
    }
    cout<<"需要建立基站"<<cnt<<" 个"<<endl;
    cout<<"基站的x轴位置(横坐标)分别为"<<endl;
    for(int i = 0; i < cnt; ++i){
        cout<<pos[i]<<" ";
    }

}   
int main() {
    int t;
    t = 1;
    srand(time(nullptr));
    while(t--){
        solve();
    }
    return 0;
}