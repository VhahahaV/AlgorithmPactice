//
// Created by VhahahaV on 2024/5/8.
//
//4min
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int last = nums.front();
        auto it = nums.begin() + 1;;
        while(it != nums.end()){
            if(last != *it)
                last = *(it++);
            else
                nums.erase(it);

        }
        return nums.size();
    }
};