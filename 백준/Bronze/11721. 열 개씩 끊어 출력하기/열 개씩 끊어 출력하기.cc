#include <iostream>

int main() {
	int characters = 0;
	char s;
	
	while (std::cin >> s) {
		if (characters == 10) {
			std::cout << std::endl;
			characters = 0;
		}
		std::cout << s;
		characters++;
	}
	
	return 0;
}
