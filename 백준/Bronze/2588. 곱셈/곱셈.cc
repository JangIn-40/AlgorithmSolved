#include <iostream>

int main()
{
	int n, m;
	std::cin >> n >> m;

	int result1 = n * (m % 10);
	int result2 = n * ((m / 10) % 10);
	int result3 = n * (m / 100);
	std::cout << result1 << std::endl;
	std::cout << result2 << std::endl;
	std::cout << result3 << std::endl;
	std::cout << n * m << std::endl;
}