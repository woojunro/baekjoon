#include <iostream>
#include <string>
#include <stack>

int main() {
    std::string input, output;
    std::getline(std::cin, input);
    
    std::stack<char> s;
    
    for (int i = 0; i < input.length(); i++) {
        if (input[i] >= 40 && input[i] <= 47) { // 40: ( ) * + , - . / :47
            if (s.empty()) {
                s.push(input[i]);
            } else {
                switch (input[i]) {
                    case '(':
                        s.push(input[i]);
                        break;
                    case ')':
                        while (!s.empty() && s.top() != '(') {
                            output.push_back(s.top());
                            s.pop();
                        }
                        s.pop();
                        break;
                    case '*':
                    case '/':
                        if (s.top() == '+' || s.top() == '-' || s.top() == '(') {
                            s.push(input[i]);
                        } else {
                            while (!s.empty() && s.top() != '+' && s.top() != '-' && s.top() != '(') {
                                output.push_back(s.top());
                                s.pop();
                            }
                            s.push(input[i]);
                        }
                        break;
                    case '+':
                    case '-':
                        if (s.top() == '(') {
                            s.push(input[i]);
                        } else {
                            while (!s.empty() && s.top() != '(') {
                                output.push_back(s.top());
                                s.pop();
                            }
                            s.push(input[i]);
                        }
                        break;
                    default:
                        return -1;
                }
            }
        } else {
            output.push_back(input[i]);
        }
    }
    
    while (!s.empty()) {
        output.push_back(s.top());
        s.pop();
    }
    
    std::cout << output << std::endl;
    
    return 0;
}