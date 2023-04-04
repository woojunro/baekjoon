#include <iostream>
#include <string>
#include <stack>

int main() {
    bool valid;
    std::string str;
    std::stack<char> s;
    
    while (std::getline(std::cin, str)) {
        if (str == ".") {
            break;
        }
        
        while (!s.empty()) {
            s.pop();
        }
        
        valid = true;
        
        for (int i = 0; i < str.length(); i++) {
            switch (str[i]) {
                case '(':
                case '[':
                    s.push(str[i]);
                    break;
                case ')':
                    if (!s.empty() && s.top() == '(') {
                        s.pop();
                    } else {
                        valid = false;
                    }
                    break;
                case ']':
                    if (!s.empty() && s.top() == '[') {
                        s.pop();
                    } else {
                        valid = false;
                    }
                    break;
                default:
                    break;
            }
            
            if (!valid) {
                break;
            }
        }
        
        if (!s.empty()) {
            valid = false;
        }
        
        std::cout << (valid ? "yes" : "no") << "\n";
    }
    
    return 0;
}