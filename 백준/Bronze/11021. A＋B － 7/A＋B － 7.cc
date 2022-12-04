#include <iostream>

int main() {
	int t, a, b;
	
	std::cin >> t;
	
	for (int i = 1; i <= t; i++) {
		std::cin >> a >> b;
		std::cout << "Case #" << i << ": " << a + b << std::endl;
	}
	
	return 0;
}
