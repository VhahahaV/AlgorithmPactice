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
//实现一个词class，用string构造，生成op（运算符）、num（数字）等tag

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
            if (first == name.size() - 1)
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

class Formula {
private:
    vector<double> coefficient{};
    double constant = 0;
public:
    Formula(const vector<Word>& words) {
        coefficient.resize(params.size(), 0.0);  // Ensure coefficients are sized correctly
        parseExpression(words.begin(), words.end(), 1.0, true);
    }

    void parseExpression(vector<Word>::const_iterator it, vector<Word>::const_iterator end, double multiplier, bool addToCoefficient) {
        double currentMultiplier = multiplier; // Tracks current multiplier for parameters and numbers
        double sign = 1.0;  // Tracks signs due to +/- operators
        bool isRightSide = false;
        for (; it != end; ++it) {
            switch (it->tag) {
                case num:
                    currentMultiplier *= stod(it->name) * sign;
                    break;

                case param:
                    if (!isRightSide) {
                        coefficient[params[it->name]] += currentMultiplier;
                    } else {
                        coefficient[params[it->name]] -= currentMultiplier;
                    }
                    // Reset currentMultiplier after applying to a parameter
                    currentMultiplier = 1.0 * sign;
                    break;

                case op:
                    if (it->name == "(") {
                        auto subExprEnd = it;
                        while(subExprEnd->name != ")")
                            subExprEnd++;
                        parseExpression(it + 1, subExprEnd, currentMultiplier * sign, addToCoefficient);
                        it = subExprEnd;
                    } else if (it->name == "+") {
                        sign = 1.0;
                    } else if (it->name == "-") {
                        sign = -1.0;
                    } else if (it->name == "*") {
                        // Handle multiplication by updating currentMultiplier
                        ++it;
                        if (it->tag == num) {
                            currentMultiplier *= stod(it->name);
                        }
                    } else if (it->name == "/") {
                        ++it;
                        if (it->tag == num) {
                            currentMultiplier /= stod(it->name);
                        }
                    } else if (it->name == "=") {
                        isRightSide = true; // Switch sides of the equation
                        sign = -1.0; // Invert contributions on the right side
                    }
                    break;
            }
        }
    }

    void displayCoefficients() const {
        cout << "Coefficients: ";
        for (auto coef : coefficient) {
            cout << coef << " ";
        }
        cout << "\nConstant: " << constant << endl;
    }
};

class Calculator {
private:
    map<string, double> ans;
    vector<Formula> formulas;

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
            try {
                w.checkValidVariableName();
            }
            catch (const runtime_error &e) {
                cerr << "Caught an exception: " << e.what() << endl;
            }
            words.push_back(w);
        }

        return words;
    }

    void read() {
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

    }


};


int main() {
    Calculator calculator;
    calculator.read();

    return 0;
}
