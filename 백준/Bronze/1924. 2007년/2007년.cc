#include <iostream>
#include <vector>
#include <string>

int main() {
	int x, y, daysPassed;
	std::vector<int> daysOfMonth = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	std::vector<std::string> daysOfWeek = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
	
	std::cin >> x >> y;
	daysPassed = 0;
	
	for (int i = 0; i < x - 1; i++) daysPassed += daysOfMonth[i];
	daysPassed += y;
	
	std::cout << daysOfWeek[daysPassed % 7] << std::endl;
	
	return 0;
}
