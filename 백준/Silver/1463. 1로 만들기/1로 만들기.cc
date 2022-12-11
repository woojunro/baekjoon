#include <iostream>
#include <algorithm>

int results[1000001];

int main() {
	int x;
	
	std::cin >> x;
	
	for (int i = 2; i <= x; i++) {
		if (i <= 3) {
			results[i] = 1;
		} else {
			results[i] = results[i - 1] + 1;
			if (i % 3 == 0) results[i] = std::min(results[i / 3] + 1, results[i]);
			if (i % 2 == 0) results[i] = std::min(results[i / 2] + 1, results[i]);
		}
	}
	
	std::cout << results[x] << std::endl;
	
	return 0;
}
