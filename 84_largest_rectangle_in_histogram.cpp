#include "utils.h"

//O(n^2)
class Solution1 {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> left;
        vector<int> right;
        for(int k=0;k<heights.size();++k){
            int i=0,j=0;
            while(k-i>=0 && heights[k-i]>=heights[k]) ++i;
            while(k+j<heights.size() && heights[k+j]>=heights[k]) ++j;
            left.push_back(i-1);
            right.push_back(j-1);
        }
        // for(int k=0; k<heights.size();++k){
        //     printf("left=%d, right=%d \n",left[k], right[k]);
        // }
        int max_rec = 0;
        for(int k=0; k<heights.size();++k){
            int rec = heights[k]*(left[k]+right[k]+1);
            max_rec = max(max_rec, rec);
        }
        return max_rec;
        
    }
};

//使用一个单调的stack, 这样的化, 左边的一个就是第一个比它小的, 右边遇上的需要pop的就是第一个比它小的.
class Solution2 {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int max_rec = 0;
        for(int i=0; i<heights.size(); ++i){
            if(st.empty()) st.push(i);
            else if(!st.empty() && heights[st.top()]<=heights[i]) st.push(i);
            else{
                while(!st.empty() && heights[st.top()]>heights[i]){
                    int top = st.top(); //先记录再pop
                    st.pop();
                    int left = st.empty()?-1:st.top(); //这边需要注意一下.
                    int rec = (i-left-1) * heights[top];
                    max_rec = max_rec > rec? max_rec: rec;
                }
                st.push(i);//一开始忘记了这一句了.
            }
        }
        int i=heights.size();
        while(!st.empty()){
            int top = st.top();
            st.pop();
            int left = st.empty()?-1:st.top();
            int rec = (i-left-1) * heights[top];
            max_rec = max_rec > rec? max_rec: rec;
        }
        return max_rec;
    }
};


//代码稍微精简一下
class Solution22 {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int max_rec = 0;
        for(int i=0; i<heights.size(); ++i){
            while(!st.empty() && heights[st.top()]>heights[i]){
                int top = st.top();
                st.pop();
                int left = st.empty()?-1:st.top();
                int rec = (i-left-1) * heights[top];
                max_rec = max_rec > rec? max_rec: rec;
            }
            st.push(i);
            
        }
        int i=heights.size();
        while(!st.empty()){
            int top = st.top();
            st.pop();
            int left = st.empty()?-1:st.top();
            int rec = (i-left-1) * heights[top];
            max_rec = max_rec > rec? max_rec: rec;
        }
        return max_rec;
    }
};