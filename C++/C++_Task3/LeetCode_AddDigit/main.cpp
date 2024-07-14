#include<iostream>

class Solution {
public:
    int addDigits(int num) {
        if (num == 0)
            return 0;
        if (num % 9 == 0)
            return 9;
        return num % 9;
    }
};

int main(){
    Solution s;
    std::cout << s.addDigits(2) << std::endl;
    std::cout << s.addDigits(38) << std::endl;
    std::cout << s.addDigits(0) << std::endl;
}