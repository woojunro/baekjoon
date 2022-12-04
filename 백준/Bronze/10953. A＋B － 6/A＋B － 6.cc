#include <iostream>

int main() {
	int t, a, b;
	char c;
	
	std::cin >> t;
	
	for (int i = 0; i < t; i++) {
		std::cin >> a >> c >> b;
		std::cout << a + b << std::endl;
	}
	
	return 0;
}
