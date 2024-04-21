#include <iostream>
#include <string>
#include <limits>
#include <vector>
#include <stack>
#include <cstdint>

using llu = uint64_t;
using namespace std;

class BigInt{
    static const llu LOW_BITS_MASK = static_cast<llu>(numeric_limits<uint32_t>::max());
    static const llu HIGH_BITS_MASK = static_cast<llu>(numeric_limits<uint32_t>::max()) << 32;
private:
    vector<llu> mDigits{};// little endian
    void plus(uint32_t x){
        llu carry = 0;
        for(llu& digit : mDigits){
            digit *= x;
            llu carry1 = digit >> 32;
            digit &= LOW_BITS_MASK;
            digit += carry;
            llu carry2 = digit >> 32;
            digit &= LOW_BITS_MASK;
            carry = carry1 + carry2;
        }
        while (carry != 0){
            mDigits.emplace_back(carry & LOW_BITS_MASK);
            carry >>= 32;
        }
    }
    void add(uint32_t x) {
        llu carry = x;
        for (llu &digit: mDigits) {
            digit += carry;
            carry = digit >> 32;
            digit &= LOW_BITS_MASK;
            if(carry == 0) break;
        }
        if(carry > 0){
            mDigits.emplace_back(x);
        }
    }
    uint32_t div(uint32_t x){
        llu res = 0;
        for(int i=int(mDigits.size())-1; i>=0; i--){
            auto& digit = mDigits[i];
            digit += res << 32;
            res = (digit % x);
            digit /= x;
        }
        return res;
    }
    void pad(size_t count){
        mDigits.reserve(count);
        while (mDigits.size() < count){
            mDigits.emplace_back(0);
        }
    }
    void squeeze(){
        while(!mDigits.empty() && mDigits.back() == 0){
            mDigits.pop_back();
        }
    }
public:
    BigInt() = default;
    explicit BigInt(uint32_t x): mDigits({x}){}
    explicit BigInt(const string& x){
        for(char digit: x){
            if(isdigit(digit)) {
                plus(10);
                add(uint32_t(digit - '0'));
            }
        }
    }
    BigInt operator+(const BigInt& x) const {
        BigInt result;
        result.pad(std::max(mDigits.size(), x.mDigits.size()));
        int i=0, j=0;
        for(;i<mDigits.size() && j<x.mDigits.size(); i++, j++){
            result.mDigits[i] = mDigits[i]+x.mDigits[j];
        }
        while (i<mDigits.size()){
            result.mDigits[i] = mDigits[i];
            i++;
        }
        while (j<x.mDigits.size()){
            result.mDigits[j] = x.mDigits[j];
            j++;
        }
        result.add(0);
        return result;
    }
    bool operator==(uint32_t x) const{
        if(x==0 && mDigits.empty()) return true;
        if(mDigits[0] != x) return false;
        for(int i=1; i<mDigits.size(); i++){
            if(mDigits[i] != 0) return false;
        }
        return true;
    }
    bool operator!=(uint32_t x) const{
        return !operator==(x);
    }
    friend ostream& operator<<(ostream& os, BigInt x){
        if(x == 0){
            return os << '0';
        }
        stack<int> stk;
        while(x != 0){
            stk.emplace(x.div(10));
        }
        while(!stk.empty()){
            os << stk.top();
            stk.pop();
        }
        return os;
    }
};

int main() {
    string aStr, bStr;
    getline(cin, aStr);
    getline(cin, bStr);
    BigInt a(aStr), b(bStr);
//    cout << a<< '\n' << b << '\n' << a+b << endl;
    cout << a+b << endl;
    return 0;
}