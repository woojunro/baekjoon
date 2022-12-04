#include <iostream>

int main() {
	int n;
	std::cin >> n;
	
	// 가운데까지
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i + 1; j++) std::cout << '*'; // 왼쪽 별
		for (int j = 0; j < n * 2 - i * 2 - 2; j++) std::cout << ' '; // 공백
		for (int j = 0; j < i + 1; j++) std::cout << '*'; // 오른쪽 별
		std::cout << std::endl;
	}
	
	// 나머지
	for (int i = n - 2; i >= 0; i--) {
		for (int j = 0; j < i + 1; j++) std::cout << '*'; // 왼쪽 별
		for (int j = 0; j < n * 2 - i * 2 - 2; j++) std::cout << ' '; // 공백
		for (int j = 0; j < i + 1; j++) std::cout << '*'; // 오른쪽 별
		std::cout << std::endl;
	}
	
	return 0;
}
