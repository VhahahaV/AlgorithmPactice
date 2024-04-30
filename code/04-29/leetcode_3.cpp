//
// Created by VhahahaV on 2024/4/29.
//

// 主要学习了string的erase函数和string的find函数

// find函数写法：
// find(str.begin(), str.end(), 'a') != str.end() 返回索引
// str.find('a')//返回的是下标的值而不是上面的指针或是迭代器
// npos可以表示string的结束位子，是string::type_size 类型的，
// 也就是find（）返回的类型。find函数在找不到指定值得情况下会返回string::npos。
// 注意，只有string的find方法是返回的下标，因为string是顺序索引，set,map,multiset,multimap都不是顺序索引的数据结构，所以返回的是迭代器。

// erase 方法：
// 使用索引删除
// 1. basic_string & erase(size_type pos=0, size_type n=npos);
// 即从给定起始位置pos处开始删除, 要删除字符的长度为n, 返回值修改后的string对象引用

// 2. iterator erase(const_iterator position)
// 删除迭代器位置处的单个字符, 并返回下个元素的迭代器

// 3. iterator erase(const_iterator first, const_iterator last)
// 删除迭代器[first, last)区间的所有字符,返回一个指向被删除的最后一个元素的下一个字符的迭代器.


#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        string sub = "";
        int res = 0;
        for(int i = 0; i < s.size() ;i++){
            auto index = sub.find(s[i]);
            if(index == string::npos){
                sub += s[i];
                res = max<int>(res,sub.size());
                continue;
            }
            else{
                sub.erase(sub.begin(),sub.begin()+index+1);
                sub += s[i];
            }
        }
        return res;
    }
};