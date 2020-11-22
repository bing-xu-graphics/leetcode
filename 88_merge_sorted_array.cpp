#include "utils.h"
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for(int i=0;i<m;i++){
            nums1[i+n] = nums1[i];
        }
        // for(int i=0; i<m+n; ++i){
        //     printf("%d ",nums1[i]);
        // }
        // printf(" ");
        int i=0, j=0;
        while(i<m && j<n){
            if(nums1[n+i]<=nums2[j])
                nums1[i+j] = nums1[n+i++]; //这里出了问题
            else nums1[i+j] = nums2[j++];
            for(int i=0; i<m+n; ++i){
                printf("%d ",nums1[i]);
            }
            printf("\n");
        }
        while(i<m) nums1[i+j] = nums1[n+i++];
        while(j<n) nums1[i+j] = nums2[j++];

    }
};

class Solution1 {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for(int i=m-1;i>=0;i--){
            nums1[i+n] = nums1[i]; //这里必须倒着写
        }
        // for(int i=0; i<m+n; ++i){
        //     printf("%d ",nums1[i]);
        // }
        printf(" ");
        int i=0, j=0;
        while(i<m && j<n){
            if(nums1[n+i]<=nums2[j]){
                nums1[i+j] = nums1[n+i];
                ++i;
            }   
            else{
                nums1[i+j] = nums2[j];
                ++j;
            } 
        }
        while(i<m){
            nums1[i+j] = nums1[n+i];
            ++i;
        } 
        while(j<n){
            nums1[i+j] = nums2[j];
            ++j;
        } 

    }
};