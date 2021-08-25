#include "dual-n-back.hpp"

char get_random_letter(std::vector<std::tuple<char, int>> history, const int &level) //abcfhkjlo
{
	int i;
	char s[10] = "abcfhkjlo";

	srand(time(NULL)); //If srand not initialized, random name will always be the same
	i = rand() % 5; //In range 0-4
	if (i == 2 && (int)history.size() > level) //1/5 times have similar signal
		return std::get<0>(history[history.size() - level]);
	srand(time(NULL)); //If srand not initialized, random name will always be the same
	i = rand() % 6; //In range 0-5
	if (i == 0 && (int)history.size() > level) //1/6 times create pitfall
		return std::get<0>(history[history.size() - level + 1]);
	srand(time(NULL)); //If srand not initialized, random name will always be the same
	i = rand() % 9; //In range 0-8
	return s[i];
}

int get_random_square(std::vector<std::tuple<char, int>> history, const int &level) 
{ 
	int i;

	srand(time(NULL)); //If srand not initialized, random name will always be the same
	i = rand() % 5; //In range 0-4
	if (i == 0 && (int)history.size() > level) //1/5 times have similar signal
		return std::get<1>(history[history.size() - level]);
	srand(time(NULL)); //If srand not initialized, random name will always be the same
	i = rand() % 6; //In range 0-5
	if (i == 2 && (int)history.size() > level) //1/6 times create pitfall
		return std::get<1>(history[history.size() - level + 1]);
	return rand() % 9; //In range 0-8
}
