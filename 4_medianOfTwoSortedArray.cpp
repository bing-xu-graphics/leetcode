
// There are two sorted arrays nums1 and nums2 of size m and n respectively.

// Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

// You may assume nums1 and nums2 cannot be both empty.

// Example 1:

// nums1 = [1, 3]
// nums2 = [2]

// The median is 2.0
// Example 2:

// nums1 = [1, 2]
// nums2 = [3, 4]

// The median is (2 + 3)/2 = 2.5
#include "utils.h"

//binary search
class Solution{
    public:
    int binarySearch(vector<int> nums, int target){
        return binarySearch(nums, target, 0, nums.size()-1);
    }
private:
    int binarySearch(vector<int> nums, int target, int low, int high){
        if(low>high) return -1;
        if(low == high) return low;
        int median_idx = nums.size()/2;
        int median = nums[median_idx];
        if(target< median){
            return binarySearch(nums, target, low, median_idx-1);
        }else if(target > median){
            return binarySearch(nums, target, median_idx+1, high);
        }else{
            return median_idx;
        }
    }
private:
    int binarySearch_iterative(vector<int> nums, int target, int low, int high){
        while(low<high){
            int median = (low+high)/2;
            if(nums[median]>target){
                high = median -1;
            }else if(nums[median]<target){
                low = median +1;
            }else{
                return median;
            }
        }
        return -1; //contain no items or cannot find the item
    }

private: 
    vector<int> mergeTwoSortedArray(vector<int> nums1, vector<int> nums2){
        int m = nums1.size();
        int n = nums2.size();
        vector<int> merged;
        int i =0, j=0;
        for(int ii=0; ii<m+n; ii++){
            if(i<m && j<n){
                merged.push_back(nums1[i]<nums2[j]? nums1[i++]:nums2[j++]);
            }else if(i<m){
                merged.push_back(nums1[i++]);
            }else{
                merged.push_back(nums2[j++]);
            }
        }   
        return merged;
    }
private:
    int search_kth_By_Merging_two_sorted_arrays(vector<int> nums1, vector<int> nums2, int k){
        int m = nums1.size();
        int n = nums2.size();
        int i =0, j=0;
        int record = -1;
        for(int cnt=0; cnt<k;cnt++){
            if(i<m && j<n){
                record = nums1[i]<nums2[j]?nums1[i++]:nums2[j++];
            }else if(i<m){
                record = nums1[i++];
            }else{
                record = nums2[j++];
            }
        }
        return -1;
        

    }
//time complexity O(n) space O(1)
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(),n = nums2.size();
        int i=0,j=0;
        int median1 = -1, median2 = -1;
        if((m+n)%2 == 0){
            for(int cnt=0;cnt<=(m+n)/2;cnt++){
                if(i<m && j<n){
                    median1 = median2;
                    median2 = nums1[i]<nums2[j]? nums1[i++]:nums2[j++];
                }else if(i<m){
                    median1 = median2;
                    median2 = nums1[i++];
                }else{
                    median1 = median2;
                    median2 = nums2[j++];
                }
                // printf("%d, %d", median1, median2);
            }
            return (median1+median2)/2.0;
        }else{//odd
            for(int cnt=0;cnt<=(m+n)/2;cnt++){
                if(i<m && j<n){
                    median2 = nums1[i]<nums2[j]? nums1[i++]:nums2[j++];
                }else if(i<m){
                    median2 = nums1[i++];
                }else{
                    median2 = nums2[j++];
                }
            }
            return median2;
        }
    }

};

//another
class Solution2 {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        if(m>n) return findMedianSortedArrays(nums2, nums1);
        if(m<1) return findMedianSortedArray(nums2);
        int low = 0, high = nums1.size()-1, i, j, median;
        while(low<=high+1){
            i = floor((low+high)/2.0)+1;
            j = (m+n+1)/2 - i;
            if(j<0){
                high = i-2;
                continue;
            }
            //when we compare from the subarrays , got to check the condition
            if(i<m && j>0 && nums2[j-1]> nums1[i])
                low = i;
            else if(i>0 && j<n && nums2[j]< nums1[i-1])
                high = i-2;
            else // found the desired halves
            {   printf("get!\n");
                if(i==0) median = nums2[j-1];
                else if(j==0) median = nums1[i-1];
                else median = max(nums1[i-1], nums2[j-1]);
                break;
            }
        }
        //calculating the median
        if((m+n)%2 == 1) return (double) median;
        if(i==m)//second half of the nums1 is an empty set
            return (median+nums2[j])/2.0;
        if(j==n)
            return (median + nums1[i])/2.0;
        return (median+min(nums1[i], nums2[j]))/2.0;
    }
    private:
double findMedianSortedArray(vector<int> nums){
    int n = nums.size();
    if(n%2==0) return (nums[n/2-1]+nums[n/2])/2.0;
    else return nums[n/2];
}
};



int main(){
    Solution solution = Solution();
    vector<int> nums = vector<int>{9,4,8,23,45,93,48,28,9,4,5,6,7,2,4,6,7,8,9,9,1,2,3,0};
    int idx = solution.binarySearch(nums, 28);
    printf("%d ", idx);
}