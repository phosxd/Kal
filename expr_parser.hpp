#include <queue>
#include <deque>
#include <iostream>

bool match(std::string& text, std::string pattern, int& index) {
    int pattern_len = pattern.size();
    bool found = pattern == text.substr(index, pattern_len);
    if(found) {
        index += (pattern_len - 1);
    }
    return found;
}

double mod(double x, double y) {
    x = x < 0 ? -x : x;
    y = y < 0 ? -y : y;
    while(x >= y) {
        x -= y;
    }
    x = x < 0 ? -x : x;
    return x;
}

namespace ops {
    std::string add = "+";
    std::string sub = "-";
    std::string mul = "*";
    std::string div = "/";
    std::string mod = "%";
}

double eval(std::string& expr, int& index) {
    double result = 0;
    std::deque<double> numbers;
    std::queue<std::string> symbols;

    index++;
    while(expr[index - 1] != ')') {
        if(expr[index] == ' ' || expr[index] == '\t' || expr[index] == '\n') {
            index++;
            continue;
        }
        if(expr[index] == '(') {
            double nested_value = eval(expr, index);
            numbers.push_back(nested_value);
        }

        if(match(expr, ops::add, index)) {
            symbols.push(ops::add);
        }
        else if(match(expr, ops::sub, index)) {
            symbols.push(ops::sub);
        }
        else if(match(expr, ops::mul, index)) {
            symbols.push(ops::mul);
        }
        else if(match(expr, ops::div, index)) {
            symbols.push(ops::div);
        }
        else if(match(expr, ops::mod, index)) {
            symbols.push(ops::mod);
        }

        if(expr[index] >= '0' && expr[index] <= '9' || expr[index] == '.') {
            int begin = index;
            while(expr[index] >= '0' && expr[index] <= '9' || expr[index] == '.') {
                index++;
            }
            std::string str_value = expr.substr(begin, index - begin);
            double value = std::stod(str_value);
            numbers.push_back(value);
            index--;
        }
        index++;
    }

    while(numbers.size() != 1) {
        double x = numbers.front();
        numbers.pop_front();
        double y = numbers.front();
        numbers.pop_front();
        std::string op = symbols.front();
        symbols.pop();

        if(op == ops::add) {
            numbers.push_front(x + y);
        }
        else if(op == ops::sub) {
            numbers.push_front(x - y);
        }
        else if(op == ops::mul) {
            numbers.push_front(x * y);
        }
        else if(op == ops::div) {
            numbers.push_front(x / y);
        }
        else if(op == ops::mod) {
            numbers.push_front(mod(x, y));
        }
    }

    result = numbers.front();
    numbers.pop_front();

    return result;
}

int main(int argc, char** argv) {
    std::string expr = "(1 + (2 * 3 / (2 + (0.5 + 0.5))))";
    expr = "((2 * 2) + (5 * 2))";
    expr = "((2 * 3) + 1 / 2)";
    expr = "(1 + 2 * 3)";
    expr = "(10  * - (2 + 2))";
    int index = 0;
    if(argc > 1) {
        expr = std::string(argv[1]);
    }
    double x = eval(expr, index);
    std::cout << expr << " = " << x << std::endl;
    return 0;
}
