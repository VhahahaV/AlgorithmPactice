//
// Created by VhahahaV on 2024/5/8.
//
//5min
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> res;
        int i = 0 , j = 0;
        while(i < m && j < n){
            if(nums1[i] <= nums2[j])
                res.emplace_back(nums1[i++]);
            else
                res.emplace_back(nums2[j++]);
        }
        while(i < m) res.emplace_back(nums1[i++]);
        while(j < n) res.emplace_back(nums2[j++]);
        memcpy(nums1.data(),res.data(),(m+n)*sizeof(int));
    }
};