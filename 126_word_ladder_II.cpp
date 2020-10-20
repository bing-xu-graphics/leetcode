#include "utils.h"

//dfs 是错误的,不满足shortest 路径的要求,必须要用bfs
class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> res;
        vector<bool> visited(wordList.size(), false);
        vector<string> tmp_res;
        dfs(beginWord, endWord, wordList, visited, res, tmp_res);
        return res;
    }

    void dfs(string beginWord, string endWord, vector<string>& wordList, vector<bool>& visited, vector<vector<string>>&res,vector<string>& tmp_res){
        if(beginWord==endWord){
            res.push_back(tmp_res);
            return;
        } 
        for(int i=0; i<wordList.size();++i){
            if(visited[i]) continue;
            if(diffByOne(wordList[i], beginWord)){
                visited[i] = true;
                tmp_res.push_back(wordList[i]);
                dfs(wordList[i], endWord, wordList, visited, res, tmp_res);
                tmp_res.pop_back();
                visited[i] = false;
            }
        }
        return;
    }
    bool diffByOne(string& target, string& word){
        int diff = 0;
        for(int i=0;i<target.size();++i){
            if(target[i]!=word[i]) diff++;
        }
        return diff==1? true: false;
    }
};



class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> res;
        vector<bool> visited(wordList.size(), false);
        vector<int> up(wordList.size(), -2);
        std::queue<int> qu;
        for(int i=0; i<wordList.size();++i){
            if(diffByOne(wordList[i], beginWord)){
                if(wordList[i]==endWord) return {{beginWord, endWord}};
                visited[i] = true;
                up[i] = -1;
                qu.push(i);
            }
        }
        bfs(beginWord, endWord, wordList, visited, up, qu, res);
        return res;
    }
    void bfs(string beginWord, string endWord, vector<string>& wordList, vector<bool>& visited, vector<int>& up, std::queue<int>& qu, vector<vector<string>>& res){  
        int stop = -2;
        while(!qu.empty()){
            int size = qu.size();
            if(stop==0) return;
            for(int j=0; j<size; j++){
                int wordIdx = qu.front();
                qu.pop();
                for(int i=0; i<wordList.size();++i){
                    if(visited[i]) continue;
                    if(diffByOne(wordList[i], wordList[wordIdx])){
                        if(wordList[i]==endWord){
                            vector<string> tmp_res;
                            tmp_res.push_back(endWord);
                            int currentIdx = wordIdx;
                            while(currentIdx!=-1){
                                tmp_res.push_back(wordList[currentIdx]);
                                currentIdx = up[currentIdx];
                            }
                            
                            tmp_res.push_back(beginWord);
                            reverse(tmp_res.begin(), tmp_res.end());
                            res.push_back(tmp_res);
                            stop = 0;
                            
                        }
                        if(wordList[i]!=endWord)visited[i] = true;
                        qu.push(i);
                        up[i] = wordIdx;
                    }
                }
            }   
        }
    }
    bool diffByOne(string& target, string& word){
        int diff = 0;
        for(int i=0;i<target.size();++i){
            if(target[i]!=word[i]) diff++;
            if(diff>1) return false;
        }
        return diff==1? true: false;
    }
};



//这个是正确的, 只有先用bfs 建树, 然后用dfs 搜索.
// 这里建树用的是vector<set<int>> 来记录他的ancester
//另外 一个比较有技巧的地方在于, 分level 进行遍历. 同层级visited 过得, 要记录ancester ,但是不加入queue 不然就会重复.
//这里用了2个  level_visited 和visited
class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> res;
        vector<set<int>> up(wordList.size(), set<int>());
        vector<bool> level_visited(wordList.size(), false);
        vector<bool> visited(wordList.size(), false);
        std::queue<int> qu;
        for(int i=0; i<wordList.size();++i){
            if(diffByOne(wordList[i], beginWord)){
                if(wordList[i]==endWord) return {{beginWord, endWord}};
                up[i].insert(-1);
                qu.push(i);
                visited[i] = true;
            }
        }

        bfs(beginWord, endWord, wordList, up, qu, res, visited, level_visited);
        return res;
    }
    void bfs(string beginWord, string endWord, vector<string>& wordList, vector<set<int>>& up, std::queue<int>& qu, vector<vector<string>>& res, vector<bool>& visited, vector<bool>& level_visited){  
        bool stop = false;
        while(!stop && !qu.empty()){
            int level_size = qu.size();
            // printf("level_size = %d\n", level_size);
            for(int k=0; k<level_size; ++k){
                int wordIdx = qu.front();
                // printf("wordIdx=%d ", wordIdx);
                qu.pop();
                if(wordList[wordIdx]==endWord){
                    // printf("here in DFS\n");
                    vector<string> tmp_res;
                    dfs(wordList, up, res, tmp_res,wordIdx, beginWord);
                    stop = true;
                }
                // std::set<int> ancestors;
                // int currentIdx = wordIdx;
                // do{
                //     ancestors.insert(currentIdx);
                //     currentIdx = up[currentIdx];
                // }while(currentIdx!=-1);

                for(int i=0; i<wordList.size();++i){
                    // if(ancestors.find(i)!=ancestors.end()) continue;
                    if(visited[i]) continue;
                    if(!diffByOne(wordList[i], wordList[wordIdx])) continue;
                    if(!level_visited[i])qu.push(i);
                    if(up[i].find(wordIdx)==up[i].end()) up[i].insert(wordIdx);
                    // up[i] = wordIdx;
                    level_visited[i] = true;
                }
            }
            // printf("\n");
            for(int i=0;i<level_visited.size(); ++i){
                if(level_visited[i]) visited[i] = true;
            }
        }
    }
    //注意这里tmp_res 不要用引用的化, 就不需要push 完了再pop 恢复数据 ,, 这里其实是这个reverse 才发现了这个问题.
    void dfs(vector<string>& wordList, vector<set<int>>& up, vector<vector<string>>& res, vector<string> tmp_res, int currentIdx, string beginWord){
        if(currentIdx==-1){
            tmp_res.push_back(beginWord);
            reverse(tmp_res.begin(), tmp_res.end());
            res.push_back(tmp_res);
            // tmp_res.pop_back();
            return;
        }
        tmp_res.push_back(wordList[currentIdx]);
        set<int> father = up[currentIdx];
        // printf("size of father=%d\n", (int)father.size());
        for(auto iter=father.begin(); iter!= father.end(); ++iter){
            // printf("*iter=%d  ", *iter);
            dfs(wordList, up, res, tmp_res, *iter, beginWord);
        } 
        // tmp_res.pop_back();
    }

    bool diffByOne(string& target, string& word){
        int diff = 0;
        for(int i=0;i<target.size();++i){
            if(target[i]!=word[i]) diff++;
            if(diff>1) return false;
        }
        return diff==1? true: false;
    }
};