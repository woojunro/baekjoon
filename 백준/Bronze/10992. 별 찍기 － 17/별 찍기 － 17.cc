#include <iostream>

int main() {
	int n, length;
	std::cin >> n;
	
	length = n * 2 - 1;
	
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < length / 2 - i; j++) std::cout << ' ';
		for (int j = 0; j < 2 * i + 1; j++) {
			if (j == 0 || j == 2 * i) std::cout << '*';
			else std::cout << ' ';
		}
		std::cout << std::endl;
	}
	
	for (int i = 0; i < length; i++) std::cout << '*';
	std::cout << std::endl;
	
	return 0;
}
