#include <iostream>

int main() {
	int n, sum;
	char s;
	
	std::cin >> n;
	sum = 0;
	
	for (int i = 0; i < n; i++) {
		std::cin >> s;
		sum += s - '0';
	}
	
	std::cout << sum << std::endl;
	
	return 0;
}
