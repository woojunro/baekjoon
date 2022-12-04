#include <iostream>

int main() {
	long sum = 0;
	int n;
	
	std::cin >> n;
	
	for (int i = 1; i <= n; i++) sum += i;
	
	std::cout << sum << std::endl;
	
	return 0;
}
