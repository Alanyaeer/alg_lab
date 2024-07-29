#include<iostream>
#include<vector>
#include <ctime>
#include <cstdlib>
#include<functional>
using namespace std;
// int Length = 10000001;
vector<int> qNums;
vector<int> mergeNums;

void quickSort(vector<int> & nums){
    // 左边的元素比他小， 右边的元素比他大 
    function<int(vector<int> &, int , int)> partition = [&](vector<int>& num, int left, int right){
        // 选择l 作为 哨兵
        int l = left,  r = right; 
        int tmp = left; 
        while(l < r){
            while(l < r && num[r] >= num[left]) r--;
            while(l < r && num[l] <= num[left]) l++;
            swap(num[l], num[r]);
        }
        // 将 当前 l 和 哨兵的位置进行替换
        swap(num[l], num[tmp]);
        return l;
    };
    function<void(vector<int> &, int, int)> qs = [&](vector<int>&  num, int left, int right){
        if(left >= right) return ;        
        int mid = partition(num, left, right);
        qs(num, left, mid - 1);
        qs(num, mid + 1, right);
    };
    // 调用函数
    qs(nums, 0, nums.size() - 1);
}
void mergeSort(vector<int> & nums){
    
    function<void(vector<int> &, int , int ,int)> mergeNums = [&](vector<int> & num, int left, int mid , int right){
        vector<int> tmp (right - left + 1);
        int i = left,  j = mid + 1, k = 0;
        while(i <= mid && j <= right){
            if(num[i] <= num[j])
                tmp[k++] = num[i++];
            else tmp[k++] = num[j++];
        }
        //将剩余的归并
        while(i <= mid) tmp[k++] = num[i++];
        while(j <= right) tmp[k++] = num[j++];
        // 归还到原数组
        for(k = 0; k < tmp.size(); ++k) num[k + left] = tmp[k];
    };
    function<void(vector<int> &, int , int)> spNums = [&](vector<int> & num, int left, int right){
        if(left >= right) return ;
        int mid = (left + right) / 2;
        spNums(num, left, mid);
        spNums(num, mid + 1, right);
        mergeNums(num, left, mid , right);
    };  
    spNums(nums, 0, nums.size() - 1); 
}
/**
 * 动态代理 的功能 
*/
void proxy(int type,  vector<int> & testNumber){
    long startTime = clock();
    if(type == 1){
        cout<<"----------快速排序----------"<<endl;
        cout<<"开始执行"<<endl;
        quickSort(testNumber);
    }
    else{
        cout<<"----------归并排序----------"<<endl;
        cout<<"开始执行"<<endl;
        mergeSort(testNumber);
    }   
    long endTime = clock();
    // cout<<<<endl;
    cout<<"程序结束--  当前测试的数组大小为" + to_string(testNumber.size())<<endl;
    cout<<"耗费的时间为" + to_string(endTime - startTime) + "s"<<endl;
}
void solve(int length) {
    srand(time(nullptr));
    // vector<int> nums(length);
    qNums.resize(length);
    mergeNums.resize(length);
    for(int i = 0; i < length ; ++i){
        // 将范围 压缩在 -100000000 ~ 1000000000
        qNums[i] = rand() % 1000000000;
        mergeNums[i] = qNums[i];
    }
    /**
     * 快速排序
     * 归并排序
    */
    for(int i = 0; i < qNums.size(); ++i) cout<<qNums[i]<<" ";

    proxy(1, qNums);
    for(int i = 0; i < qNums.size(); ++i) cout<<qNums[i]<<" ";
    // proxy(2, mergeNums);
}

int main(){
    int t = 9;
    int testCases[] = {5, 200000, 400000, 700000, 1000000, 2000000, 4000000, 6000000, 9000000};
    for(int i = 0; i < 1; ++i){
        solve(testCases[i]);
    }
    return 0;
}