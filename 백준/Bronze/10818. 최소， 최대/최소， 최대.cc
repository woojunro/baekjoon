#include <iostream>

int main() {
	int max, min, n, num;
	
	max = -1000001;
	min = 1000001;
	
	std::cin >> n;
	
	for (int i = 0; i < n; i++) {
		std::cin >> num;
		if (num > max) max = num;
		if (num < min) min = num;
	}
	
	std::cout << min << " " << max << std::endl;
	
	return 0;
}
