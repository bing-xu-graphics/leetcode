#include "utils.h"
/**
 * 
 * 
 */



//method1  一直不成功 报错为reference 被赋予了nullptr

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};


class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node==nullptr) return nullptr;
        Node* source = new Node();
        vector<bool> visited(101, false);
        dfs(node, source, visited);
        return source;
    }
    void dfs(Node* originalNode, Node* newNode, vector<bool>& visited){
        if(visited[originalNode->val-1]) return;
        visited[originalNode->val-1] = true;
        newNode->val = originalNode->val;
        // if(originalNode->neighbors == nullptr){
        //     newNode->neighbors = nullptr;
        //     return;
        // }
        // newNode->neighbors = originalNode->neighbors;
        for(int i=0;i<originalNode->neighbors.size();++i){
            Node* tmp = new Node(newNode->neighbors[i]->val);
            dfs(tmp,newNode->neighbors[i], visited);
            newNode->neighbors.push_back(tmp);
        }
        
    }
};



//还是不对
/**Line 900: Char 9: runtime error: reference binding to null pointer of type 'Node *' (stl_vector.h)
*/



class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node==nullptr) return nullptr;
        vector<Node*> visited(101, nullptr);
        return dfs(node, visited);
    }
    Node* dfs(Node* originalNode, vector<Node*>& visited){
        if(visited[originalNode->val]) {
            return visited[originalNode->val];
        };
        Node* newNode = new Node(originalNode->val);
        visited[originalNode->val] = newNode;        
        // newNode->neighbors = originalNode->neighbors;
        for(int i=0;i<originalNode->neighbors.size();++i){
            if(!newNode->neighbors[i]){ //主要问题是这里错了, 根本没有保证newNode->neighbors 有101 个位置
                Node* tmp = dfs(newNode->neighbors[i], visited);
                newNode->neighbors.push_back(tmp);
            }else{
                newNode->neighbors.push_back(nullptr);
            }
            
        }
        return newNode;
    }
};


//改正之后
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node==nullptr) return nullptr;
        vector<Node*> visited(105, nullptr);
        return dfs(node, visited);
    }
    Node* dfs(Node* originalNode, vector<Node*>& visited){
        if(originalNode==nullptr) return nullptr;
        if(visited[originalNode->val]!=nullptr) {
            return visited[originalNode->val];
        };
        Node* newNode = new Node(originalNode->val);
        visited[originalNode->val] = newNode;        
        // newNode->neighbors = originalNode->neighbors;
        for(int i=0;i<originalNode->neighbors.size();++i){
            // if(originalNode->neighbors[i]!=nullptr){
                Node* tmp = dfs(originalNode->neighbors[i], visited);
                newNode->neighbors.emplace_back(tmp);
            // }else{
                // newNode->neighbors.emplace_back(nullptr);
            // }
            
        }
        return newNode;
    }
};