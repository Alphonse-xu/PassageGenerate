#include<iostream>

#include "genBullshit.h"

int main()
{
	std::string theme;
	std::cout << "please enter your theme:" << std::endl;
	std::cin >> theme;

	generateShit newArticle(theme);

	return 0;
}