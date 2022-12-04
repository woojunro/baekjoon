#include <iostream>

int main() {
	int n, length;
	std::cin >> n;
	
	length = n * 2 - 1;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < length / 2 - i; j++) std::cout << ' ';
		for (int j = 0; j < 2 * i + 1; j++) {
			if (j % 2 == 0) std::cout << '*';
			else std::cout << ' ';
		}
		std::cout << std::endl;
	}
	
	return 0;
}
