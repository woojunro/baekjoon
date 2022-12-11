#include <iostream>

int main() {
	int T;
	int results[10];
	
	results[0] = 1;
	results[1] = 2;
	results[2] = 4;
	for (int i = 3; i < 10; i++) {
		results[i] = results[i - 1] + results[i - 2] + results[i - 3];
	}
	
	std::cin >> T;
	
	for (int i = 0; i < T; i++) {
		int n;
		std::cin >> n;
		std::cout << results[n - 1] << std::endl;
	}
	
	return 0;
}
