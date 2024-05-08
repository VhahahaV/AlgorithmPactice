//
// Created by VhahahaV on 2024/5/8.
//
//10min
//搞清楚 在vector中  remove函数 和 erase函数的区别
//remove函数并没有真正删除改元素，只是将元素放置在了数组末端并且修改了end指针
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        auto it = nums.begin();
        while (it != nums.end()) {
            if (*it == val)
                nums.erase(it);
            else
                it++;
        }
        return nums.size();
    }
};