#include "utils.h"

//method time limit exceeded!!!
class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> arr;
        for(int i=0; i<n;i++){
            arr.push_back(i+1);
        }
        set<int> distincts;
        permute( n, k, 0, arr, distincts);
        return arr;
    }
    bool permute(int n, int k, int pos, vector<int>& arr, set<int>& distincts){
        if(pos>=n && distincts.size()==k) return true;
        for(int i=pos;i<n;i++){
            if(pos>0){
                // swap(arr, pos, i); //这个去掉就改一下 absolute_different;
                // int absolute_diff = abs(arr[pos] - arr[pos-1]);
                int absolute_diff = abs(arr[i] - arr[pos-1]);
                if(distincts.size()==k && distincts.find(absolute_diff)==distincts.end()){
                    // swap(arr, pos, i); //这个也可以去掉
                    continue;
                } 
                distincts.emplace(absolute_diff);
                bool res = permute(n, k, pos+1, arr, distincts);
                if(res) return true;
                distincts.erase(absolute_diff);
                swap(arr, pos, i);
            }else{
                swap(arr, pos, i);
                bool res = permute(n, k, pos+1,arr, distincts);
                if(res) return true;
                swap(arr, pos, i);
            }

        }
        return false;
    }

    void swap(vector<int>& arr, int pos1, int pos2){
        int tmp = arr[pos1];
        arr[pos1] = arr[pos2];
        arr[pos2] = tmp;
    }
    
};

//method 2  找规律的题目
class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> arr(n, 0);
        for(int i=0;i<=k;i+=2){
            arr[i] = 1+ i/2;
        }
        for(int i=1;i<=k;i+=2){
            arr[i] = k+ 1- i/2;
        }
        for(int i=k+1;i<n; i++){
            arr[i] = i+1;
        }
        return arr;
    }

    
};