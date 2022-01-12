#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

int main(int argc,char* argv[])
{
    std::cout<<"HelloWorld!"<<std::endl;
    return 0; 
}

class Solution {
public:
    bool containsDuplicate(std::vector<int>& nums) {
        sort(nums.begin(),nums.end(),greater<int>())；
        for_each(nums.begin(),nums.end(),);
    }
};