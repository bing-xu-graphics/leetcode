#include"utils.h"
class Solution {
public:
    int fib(int N) {
        if(N<1) return 0;
        int a = 0, b = 1;
        for(int i=0;i<N-1;++i){
            int c = a+b;
            a = b;
            b = c;
        }
        return b;
    }
};