#include "utils.h"
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        for(int i=0; i<numRows; i++){
            if(i==0) {
                vector<int> row(1,1);
                res.push_back(row);
            }else{
                vector<int> row(i+1,1);
                vector<int> last_row = *(res.end()-1);
                for(int j=1;j<i;j++) row[j] = last_row[j-1]+ last_row[j];
                res.push_back(row);
            }
        }

        return res;
        
    }
};