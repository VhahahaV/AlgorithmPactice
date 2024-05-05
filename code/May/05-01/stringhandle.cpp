//
// Created by VhahahaV on 2024/5/1.
//

///题目链接： https://notes.sjtu.edu.cn/s/RcJ6mS3NS

#include "bits/stdc++.h"

using namespace std;

const std::vector<char> OP = {'=', '{', '}', '+', '-', '*', '/', '(', ')'};
///mapping from param's name to index in formula
std::map<std::string, int> params;
///param nums
int nums = 0;

enum TAG {
    num,
    op,
    param
};

struct Word {
    string name;
    TAG tag;

    explicit Word() = default;

    explicit Word(const string_view &n, TAG t) {
        name = string(n);
        tag = t;
    }

    void checkValidVariableName() {
        if (tag == num) {
            int first = 0, i = 0;
            while (i < name.size()) {
                if (name[i] == '.') {
                    if (first) throw runtime_error("Digit must have only one .");
                    else first = i;
                }
                i++;
            }
            if (first && first == name.size() - 1)
                throw runtime_error("The last digit of the number cannot be .");
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
    using value = pair<double,pair<int, TAG>>;
    explicit Formula(vector<Word>& words) {
        coefficient.resize(params.size()+1, 0.0);  // Ensure coefficients are sized correctly
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
        auto res = parseExpression(0,int(words.size()-1),words);
        for(auto val : res){
            if (val.second.second == num)
                coefficient.back() -= val.first;
            else
                coefficient[val.second.first] += val.first;
        }
    }

    vector<value> parseExpression(int start,int end, vector<Word>& words) {
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
            int haveParams = (a.front().second.second == param) + (b.front().second.second == param);
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
                        it.first *= flag;
                        res.emplace_back(it);
                    }
                    return res;
                }
            }
//            param (op) num
            else if(haveParams == 1){
                if(b.front().second.second == param && op == '/')
                    throw runtime_error("not linear");
//                a is param
                if (a.front().second.second == num)
                    swap(a,b);
                double n = b.front().first;
                if (precedence(op) == 2){
                    if (op == '*'){
                        for(auto &it : a){
                            it.first *= n;
                            res.emplace_back(it);
                        }
                    }
                    else{
                        for(auto &it : a){
                            it.first /= n;
                            res.emplace_back(it);
                        }
                    }
                }
                else if(precedence(op) == 1){
                    if (op == '-')
                        n *= -1;
                    if (a.back().second.second == num)
                        a.back().first += n;
                    else
                        a.emplace_back(n, make_pair(-1,num));
                    for(auto &it : a)
                        res.emplace_back(it);

                }
            }
//            num (op) num
            else{
                double aNum = a.front().first, bNum = b.front().first,ans;
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
                res.emplace_back(ans, make_pair(-1,num));
            }
            return res;
        };
        auto calculateOnce = [&]()->void{
            if (values.empty())
                throw runtime_error("The number of elements required by the calculation does not match");
            auto val2 = values.top();
            values.pop();
            if (values.empty())
                throw runtime_error("The number of elements required by the calculation does not match");
            auto val1 = values.top();
            values.pop();
            char op = ops.top();
            ops.pop();
            values.push(applyOp(val1, val2, op));
        };
        for (int i = start; i <= end; ++i) {
            if (words[i].tag == num) {
                vector<value> v{ {stod(words[i].name), make_pair(-1, num)} };
                values.emplace(v);
            }
            else if (words[i].tag == param){
                vector<value> v{ { 1.0, make_pair(params[words[i].name],param) } };
                values.emplace(v);
            }
            else if (words[i].tag == op) {
                if (words[i].name == "(") {
//                    recursion the content in ()
                    int s = ++i, n=1;
                    while(n){
                        if (words[i].name == ")")
                            n--;
                        else if (words[i].name == "(")
                            n++;
                        i++;
                    }
                    i--;
                    int e = i-1;
                    values.push(parseExpression(s,e,words));
                } else {
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

    void displayCoefficients() const {
        for (auto coef : coefficient) {
            cout << coef << " ";
        }
    }
};

class Calculator {
private:
    map<string, double> ans;
    vector<Formula> formulas;

public:
    explicit Calculator() = default;

    static vector<Word> split(const string_view &str) {
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
            try {
                w.checkValidVariableName();
            }
            catch (const runtime_error &e) {
                cerr << "Caught an exception: " << e.what() << endl;
                exit(-1);
            }
            words.push_back(w);
        }

        return words;
    }

    void readAndParse() {
        vector<vector<Word>> equations;
        vector<string> line(100);
        int i = 0;

        // read data until EOF
        while (getline(cin, line[i])) {
            if (line.empty()) {
                break;
            }

            vector<Word> words = split(line[i++]);
            equations.emplace_back(words);
        }
        // sort variable
        int index = 0;
        for (auto &pair: params) {
            // 对每个键的值进行修改，这里以增加10为例
            pair.second = index++;
        }
        for(auto &words : equations){
            formulas.emplace_back(words);
        }
    }

    void solute(){

        auto Regularization = [this](vector<double> &f,int offset){
            double size = f[offset];
            for (int i = offset; i < f.size(); ++i) {
                f[i] /= size;
            }
        };

        auto Elimination = [this](const vector<double> &f1,vector<double> &f2,int offset){
            double size = f2[offset];
            for (int i = offset; i < f2.size(); ++i) {
                f2[i] -= (size * f1[i]);
            }
        };
        int M = params.size();
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

    void displayFormulas(){
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
        exit(-1);
    }

    return 0;
}
