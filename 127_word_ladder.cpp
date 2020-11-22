#include "utils.h"
//这里找最短路径, 所以必须使用bfs 而不是dfs
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        vector<bool> visited(wordList.size(), false);
        vector<int> depth(wordList.size(), 0);
        std::queue<int> qu;
        qu.push(-1);
        int res = bfs(beginWord, endWord, wordList, visited, depth, qu);
        return res;
    }
    int bfs(string beginWord, string endWord, vector<string>& wordList, vector<bool>& visited, vector<int>& depth, std::queue<int>& qu){
        while(!qu.empty()){
            int wordIdx = qu.front(); 
            qu.pop();
            string word;
            if(wordIdx==-1) word = beginWord;
            else word = wordList[wordIdx];
            if(word==endWord) return depth[wordIdx];
            for(int i=0;i<wordList.size(); ++i){
                if(visited[i]) continue;
                if(diffByOne(word, wordList[i])){
                    depth[i] = (wordIdx==-1?1:depth[wordIdx])+1;
                    visited[i] = true;
                    qu.push(i);
                }
            }
        }
        return 0;
        
    }
    void dfs(string beginWord, string endWord, vector<string>& wordList, vector<bool>& visited, int& depth, int& minDepth){
        if(beginWord == endWord) minDepth = min(minDepth, depth);
        int not_visited = 0;
        for(int i=0; i<wordList.size();++i){
            if(visited[i]) continue;
            not_visited++;
            if(diffByOne(wordList[i], beginWord)){
                depth++;
                visited[i] = true;
                dfs(wordList[i], endWord, wordList, visited, depth, minDepth);
                depth--;
                visited[i] = false;
            }
        }
        if(not_visited==0) return;
    }
    bool diffByOne(string& target, string& word){
        int diff = 0;
        for(int i=0;i<target.size(); ++i){
            if(target[i]!=word[i]) diff++;
            if(diff>1) return false; //没有这个优化一直通不过...
        }
        return diff==1?true:false;
    }
};


//稍微做了一点小的改变
class Solution2 {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        vector<bool> visited(wordList.size(), false);
        vector<int> depth(wordList.size(), 0);
        std::queue<int> qu;
        for(int i=0;i<wordList.size(); ++i){
            if(diffByOne(beginWord, wordList[i])){
                depth[i] = 2;
                visited[i] = true;
                qu.push(i);
            }
        }
        int res = bfs(beginWord, endWord, wordList, visited, depth, qu);
        return res;
    }
    int bfs(string beginWord, string endWord, vector<string>& wordList, vector<bool>& visited, vector<int>& depth, std::queue<int>& qu){
        while(!qu.empty()){
            int wordIdx = qu.front(); 
            qu.pop();
            string word = wordList[wordIdx];
            // printf("%s\n", word.c_str());
            if(word==endWord) return depth[wordIdx];
            for(int i=0;i<wordList.size(); ++i){
                if(visited[i]) continue;
                if(diffByOne(word, wordList[i])){
                    depth[i] = depth[wordIdx]+1;
                    visited[i] = true;
                    qu.push(i);
                }
            }
        }
        return 0;
        
    }

    bool diffByOne(string& target, string& word){
        int diff = 0;
        for(int i=0;i<target.size(); ++i){
            if(target[i]!=word[i]) diff++;
            if(diff>1) return false;
        }
        return diff==1?true:false;
    }
};

//省略掉了depth 的记录
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        vector<bool> visited(wordList.size(), false);
        std::queue<string> qu;
        for(int i=0; i<wordList.size();++i){
            if(diffByOne(wordList[i], beginWord)){
                qu.push(wordList[i]);
                visited[i] = true;
            }
        }
        int res = bfs(beginWord, endWord, wordList, visited, qu);
        return res;
    }
    int bfs(string beginWord, string endWord, vector<string>& wordList, vector<bool>& visited, std::queue<string>& qu){
        int depth = 1;
        while(!qu.empty()){
            int level_size = qu.size();
            depth++;
            for(int j=0; j<level_size; ++j){
                string word = qu.front(); 
                qu.pop();
                if(word==endWord) return depth;
                for(int i=0;i<wordList.size(); ++i){
                    if(visited[i]) continue;
                    if(diffByOne(word, wordList[i])){
                        visited[i] = true;
                        qu.push(wordList[i]);
                    }
                }
            }
            
        }
        return 0;
        
    }
    bool diffByOne(string& target, string& word){
        int diff = 0;
        for(int i=0;i<target.size(); ++i){
            if(target[i]!=word[i]) diff++;
            if(diff>1) return false;
        }
        return diff==1?true:false;
    }
};