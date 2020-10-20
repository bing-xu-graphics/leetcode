//method1 顺序不对
class Solution {
public:
    string getPermutation(int n, int k) {
        string current = ""; int i=1;
        while(i<=n){
            current += std::to_string(i++);
        } 
        int count = 0;
        return dfs(n, k, 1, count, current);
    }

    string dfs(int n, int k, int pos, int& count, string& current){
        if(pos == n){
            count++;
            printf("count=%d current = %s \n", count, current.c_str());
            if(count==k) return current;
            else return "";
        }
        for(int i=pos;i<=n;i++){
            current = swap(current, pos-1, i-1);
            string res = dfs(n, k, pos+1, count, current);
            if(res!="") return res;
            current = swap(current, pos-1, i-1);
        }
        return "";
    }
    string swap(string& str, int i, int j){
        if(i==j) return str;
        string ans = str.substr(0,i) + str.substr(j, 1) + str.substr(i+1, j-i-1) + str.substr(i, 1)+ str.substr(j+1, str.size()-j-1);
        // printf("i=%d, j=%d, before: %s, after: %s\n",i,j, str.c_str(), ans.c_str());
        return ans;   
    }
};

//method 2 超出时间限制
class Solution {
public:
    string getPermutation(int n, int k) {
        vector<bool> visited(n, false);
        vector<char> current;
        int count = 0;
        dfs(n, k, visited, current, 0, count);
        string s(current.begin(), current.end());
        return s;


    }
    bool dfs(int n, int k, vector<bool>& visited, vector<char>& current, int pos, int& count){
        if(pos==n){
            count++;
            if(count == k) return true;
            else return false;
        }
        for(int i=1;i<=n;++i){
            if(!visited[i-1]){
                current.push_back('0'+i);
                visited[i-1] = true;
                bool res = dfs(n, k, visited, current, pos+1, count);
                if(res) return true;
                visited[i-1] = false;
                current.pop_back();
            } 
        }
        return false;
    }

    
};