//
// Created by VhahahaV on 2024/5/1.
//

///题目链接： https://notes.sjtu.edu.cn/s/RcJ6mS3NS

#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <algorithm>
#include <iomanip>

using namespace std;

static const std::vector<char> OP = {'=', '{', '}', '+', '-', '*', '/', '(', ')'};
enum TAG {
    num,
    op,
    param
};

struct Word {
    string name;
    TAG tag;
    explicit Word():name{}, tag{} {}
    explicit Word(const string_view &n, TAG t) {
        name = string(n);
        tag = t;
    }

    void checkValidVariableName() {
        if (tag == num) {
            int first = 0;
            for (int i = 0;i < name.size();i++) {
                if (name[i] == '.') {
                    if (first) throw runtime_error("Digit must have only one .");
                    else first = i;
                }
            }

        } else if (tag == param) {
            if (name.empty() || (!isalpha(name[0]) && name[0] != '_')) {
                throw runtime_error("Variable name must start with a letter or an underscore");
            }
            for (char c: name) {
                if (!isalnum(c) && c != '_') {
                    throw runtime_error("All characters must be alphanumeric or an underscore");
                }
            }
        }
    }
};

struct Formula {
    vector<double> coefficient{};
//    using value = pair<double,pair<int, TAG>>;
    struct value{
        double val;
        int index;
        TAG tag;
        value(double v,int i , TAG t):val(v),index(i),tag(t){}
    };
    explicit Formula(vector<Word>& words,const map<std::string, int> &params) {
        coefficient.resize(params.size() +1, 0.0);  // Ensure coefficients are sized correctly
        {
            int i = 0;
            while(words[i].name != "=")
                i++;
            words[i].name = "(";
            words.insert(words.begin()+i,Word("-",op));
            words.emplace_back(")",op);

            if (words.front().name == "-"){
                words.erase(words.begin());
                words.front().name = "-" + words.front().name;
            }
        }
        auto res = parseExpression(0,int(words.size()-1),words,params);
        for(auto &it : res){
            if (it.tag == num)
                coefficient.back() -= it.val;
            else
                coefficient[it.index] += it.val;
        }
    }

    vector<value> parseExpression(int start,int end, vector<Word>& words,const map<std::string, int> &params) {
        if (start > end)
            throw runtime_error("error using ()");


        auto precedence = [](char op) {
            if (op == '+' || op == '-') return 1;
            if (op == '*' || op == '/') return 2;
            return 0; // for '=' and '('
        };

        stack<vector<value>> values;
        stack<char> ops;
        auto applyOp = [&](vector<value> &a, vector<value> &b, char op)->vector<value> {
            int haveParams = (a.front().tag == param) + (b.front().tag == param);
            vector<value> res;
//            param (op) param
            if (haveParams == 2){
                if (precedence(op) == 2)
                    throw runtime_error("not linear");
                else{
                    int flag = 1;
                    if (op == '-')
                        flag = -1;
                    for(auto &it : a)
                        res.emplace_back(it);
                    for(auto &it : b){
                        it.val *= flag;
                        res.emplace_back(it);
                    }
                    return res;
                }
            }
//            param (op) num
            else if(haveParams == 1){
                if(b.front().tag == param && op == '/')
                    throw runtime_error("not linear");
//                a is param
                bool swaped = false;
                if (a.front().tag == num){
                    swap(a,b);
                    swaped = true;
                }
                double n = b.front().val;
                if (precedence(op) == 2){
                    if (op == '*'){
                        for(auto &it : a){
                            it.val *= n;
                            res.emplace_back(it);
                        }
                    }
                    else{
                        for(auto &it : a){
                            it.val /= n;
                            res.emplace_back(it);
                        }
                    }
                }
                else if(precedence(op) == 1){
                    if (op == '-'){
                        if (swaped)
                            for(auto &it : a)
                                it.val *= -1;
                        else
                            n *= -1;
                    }
                    if (a.back().tag == num)
                        a.back().val += n;
                    else
                        a.emplace_back(n, -1,num);
                    for(auto &it : a)
                        res.emplace_back(it);

                }
            }
//            num (op) num
            else{
                double aNum = a.front().val, bNum = b.front().val,ans;
                switch (op) {
                    case '+':
                        ans = aNum + bNum;
                        break;
                    case '-':
                        ans = aNum - bNum;
                        break;
                    case '*':
                        ans = aNum * bNum;
                        break;
                    case '/':
                        ans = aNum / bNum;
                        break;
                    default:
                        throw runtime_error("op error");
                }
                res.emplace_back(ans, -1,num);
            }
            return res;
        };
        auto calculateOnce = [&]()->void{
            char op = ops.top();
            ops.pop();
            if (values.empty())
                throw runtime_error("The number of elements required by the calculation does not match");
            auto val2 = values.top();
            values.pop();
            vector<value> val1;
            if (values.empty())
                if(precedence(op) == 1)
                    val1 = vector<value>{ {0, -1, num} };
                else
                    throw runtime_error("Multiplication and division symbols cannot be preceded by no numbers");
            else{
                val1 = values.top();
                values.pop();
            }
            values.push(applyOp(val1, val2, op));
        };
        for (int i = start; i <= end; ++i) {
            if (words[i].tag == num) {
                vector<value> v{ {stod(words[i].name), -1, num} };
                values.emplace(v);
            }
            else if (words[i].tag == param){
                vector<value> v{ { 1.0, params.at(words[i].name),param } };
                values.emplace(v);
            }
            else if (words[i].tag == op) {
                if (words[i].name == "(") {
//                    recursion the content in ()
                    int s = ++i, n=1;
                    while(n && i <= end ){
                        if (words[i].name == ")")
                            n--;
                        else if (words[i].name == "(")
                            n++;
                        i++;
                    }
                    if (n)
                        throw runtime_error("The number of parentheses does not match");
                    i--;
                    int e = i-1;
                    values.push(parseExpression(s,e,words,params));
                }
                else if (words[i].name == ")")
                    throw runtime_error("The number of parentheses does not match");
                else {
                    while (!ops.empty() && precedence(ops.top()) >= precedence(words[i].name[0]))
                        calculateOnce();
                    ops.push(words[i].name[0]);
                }
            }
        }
        while (!ops.empty())
            calculateOnce();
        if (values.size() != 1)
            throw runtime_error("The number of elements required by the calculation does not match");
        else
            return values.top();

    }

    void displayCoefficients() const noexcept {
        for (auto &it : coefficient) {
            cout << it << " ";
        }
    }
};

class Calculator {
private:
    map<string, double> ans;
    vector<Formula> formulas;
    ///mapping from param's name to index in formula
    map<std::string, int> params;
    ///param nums
    int nums = 0;
public:
    explicit Calculator() = default;

    vector<Word> split(const string_view &str) {
        std::vector<Word> words;
        int i = 0;
        while (i < str.size()) {
//            clean ' '
            while (i < str.size() && str[i] == ' ')
                i++;
            int len = 0, start = i;
            string_view content;
            TAG tag;
//            parse number
            if (isdigit(str[i])) {
                while (i < str.size() && isdigit(str[i]) || str[i] == '.')
                    len++, i++;
                content = str.substr(start, len);
                tag = num;
            }
//            parse op
            else if (std::find(OP.begin(), OP.end(), str[i]) != OP.end()) {
                len++, i++;
                content = str.substr(start, len);
                tag = op;
            }
//            parse variable
            else {
                while (i < str.size() && str[i] != ' ' && std::find(OP.begin(), OP.end(), str[i]) == OP.end())
                    len++, i++;
                content = str.substr(start, len);
                tag = param;

                if (!params.count(string(content))) {
                    params[string(content)] = nums++;
                }
            }
            Word w(content, tag);
            w.checkValidVariableName();
            words.push_back(std::move(w));
        }

        return words;
    }

    void readAndParse() {
        vector<vector<Word>> equations;
        // read data until EOF
        while (true) {
            string line;
            if (!getline(cin, line))
                break;
            vector<Word> words = split(line);

            equations.emplace_back(words);
        }
        // sort variable
        int index = 0;
        for (auto &pair: params) {
            // 对每个键的值进行修改，这里以增加10为例
            pair.second = index++;
        }
        for(auto &words : equations){
            formulas.emplace_back(words,params);
        }
    }

    void solute(){

        auto Regularization = [](vector<double> &f,int offset){
            double size = f[offset];
            for (int i = offset; i < f.size(); ++i) {
                f[i] /= size;
            }
        };

        auto Elimination = [](const vector<double> &f1,vector<double> &f2,int offset){
            double size = f2[offset];
            for (int i = offset; i < f2.size(); ++i) {
                f2[i] -= (size * f1[i]);
            }
        };
        int M = int(params.size());
        for (int i = 0; i < M; ++i) {
            auto &f1 = formulas[i].coefficient;
            if(f1[i] == 0){
                int offset = i;
                while (f1[i] == 0) {
                    swap(formulas[i].coefficient,formulas[(offset+1)%M].coefficient);
                    offset = (offset+1)%M;
                    if (!offset){
                        throw std::runtime_error("rank reduction");
                    }
                }

                f1 = formulas[i].coefficient;
            }
            Regularization(f1,i);
            for (int j = i+1; j < M; ++j) {
                auto &f2 = formulas[j].coefficient;
                Elimination(f1,f2,i);
            }
        }

        vector<double> res(M);

        for (int i = M-1; i >= 0 ; --i) {
            auto &f1 = formulas[i].coefficient;
            for (int j = i-1; j >= 0 ; --j) {
                auto &f2 = formulas[j].coefficient;
                Elimination(f1,f2,i);
            }
            if (f1[i] != 1){
                throw std::runtime_error("rank reduction");
            }
            res[i] = f1[M];
        }
        for (auto &[name,index]: params) {
            // 对每个键的值进行修改，这里以增加10为例
            cout << name << " = "<< fixed << setprecision(3) << res[index]<< endl;
        }

    }

    void displayFormulas[[maybe_unused]]() const {
        for(auto &f : formulas){
            f.displayCoefficients();
            cout << '\n';
        }
    }
};


int main() {
    Calculator calculator;
    try{
        calculator.readAndParse();
//    calculator.displayFormulas();
        calculator.solute();
    }
    catch (const runtime_error &e) {
        cerr << "Caught an exception: " << e.what() << endl;
        return 1;
    }

    return 0;
}
