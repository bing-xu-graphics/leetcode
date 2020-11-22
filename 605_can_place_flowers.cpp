#include "utils.h"
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if(flowerbed.size()==0) return n==0;
        if(flowerbed.size()==1){
            if(flowerbed[0]==1) return n==0;
            else return n<2;
        }
        int maxPots = 0;
        if(flowerbed[0]==0 && flowerbed[1]==0){
            maxPots++;
            flowerbed[0] = 1;
        }
        for(int i=1; i<flowerbed.size()-2;++i){
            if(flowerbed[i]==1) continue;
            if(flowerbed[i]==0 && flowerbed[i+1]==0 && flowerbed[i+2]==0){
                maxPots++;  
                flowerbed[i+1] = 1;
            }  
        }
        if(flowerbed.size()>2 && flowerbed[flowerbed.size()-2]==0&& flowerbed[flowerbed.size()-1]==0){
            maxPots++;
            flowerbed[flowerbed.size()-1] = 1;
        }
        
        if(n<=maxPots) return true;
        return false;
    }
};