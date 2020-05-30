#include <iostream>
#include <fstream>
int main()
{
	std::ofstream text;
	int input;
	bool run = true;
	while (run)
	{
		std::cin >> input;
		switch (input)
		{
		case 1:
			text.open("test.txt");
			text << "Test succesful \n";
			text.close();
			run = false;
			break;
		default:
			std::cout << "Input a 1 \n";
			break;
		}
	}
	return 0;
}