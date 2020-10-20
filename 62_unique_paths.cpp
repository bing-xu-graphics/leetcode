#include "utils.h"
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> records(n, 1);
        for(int i=1;i<m;i++){
            for(int j=1; j<n;j++){
                records[j] = records[j-1] + records[j];
            }
        }
        return records[n-1];
    }
};