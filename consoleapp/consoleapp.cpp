#include <iostream>  // for std::cout and std::cin
#include <vector>
#include <stdlib.h>     
#include <time.h> 
#include <fstream>

int main()
{
	srand(time(NULL));

	std::ofstream file; 

	std::vector<char> symbols = { '.', ',', ';', ':', '!', '?','`', '-', '(', ')', '[', ']', '{', '}', '/', '|', '@', '#', '$', '%', '^', '&', '*', '_', '+', '=', '<', '>' }; 
	std::vector<char> alphabet = { 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
	std::vector<char> alphabetLower = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };
	std::vector<char> nums = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
	std::vector<char> password; // assign later in loop

	std::cout << "What is this password for? " << '\n';

	std::string fileName; 

	std::cin >> fileName; 

	file.open(fileName + ".txt");

	std::cout << "How many characters do you want your password? " << '\n';

	int sizeOfPass = 0; 

	std::cin >> sizeOfPass;

	std::cout << '\n'; 

	for (int i = 0; i < sizeOfPass; i++) {
		std::vector<char> buffer;

		// don't - 1 because lower bound becomes -1 and not 0
		int indexAlpha = rand() % alphabet.size();
		int indexAlphaLower = rand() % alphabetLower.size();
		int indexNums = rand() % nums.size();
		int indexSymbols = rand() % symbols.size();
		
		// store random 3 chars then choose random char and clear vec
		buffer.push_back(alphabet[indexAlpha]);
		buffer.push_back(nums[indexNums]);
		buffer.push_back(symbols[indexSymbols]);
		buffer.push_back(alphabetLower[indexAlphaLower]);

		char randChar = buffer[rand() % 4]; 

		password.push_back(randChar); 

		buffer.clear();
	}


	std::string finalPassword(password.begin(), password.end());
	std::cout << finalPassword << '\n'; 

	if (!file.is_open()) return 1; // exit if error opening file

	file << finalPassword << '\n'; 

	file.close(); 
	return 0; 
}