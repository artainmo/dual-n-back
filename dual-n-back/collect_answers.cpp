#include "dual-n-back.hpp"

void get_answer(std::tuple<int, int> *answer, std::tuple<int, int> *expected, const int *random_square, int *total_time)
{
	std::string ret;

	while(*total_time > 0)
	{
		std::getline(std::cin, ret);
		if (*total_time <= 0)
			return ;
		if (ret == "v" || ret == "vs" || ret == "sv")
			std::get<1>(*answer) = 1;
		if (ret == "s" || ret == "vs" || ret == "sv")
			std::get<0>(*answer) = 1;
		if (ret == "q")
		{
			std::get<0>(*answer) = -1;
			return ;
		}
		draw_squares(random_square);
		if (ret == "vs" || ret == "sv")
			draw_results(std::get<0>(*expected), std::get<1>(*expected), 
					std::get<0>(*answer), std::get<1>(*answer), "all");
		else if (ret == "s")
			draw_results(std::get<0>(*expected), std::get<1>(*expected),
					std::get<0>(*answer), std::get<1>(*answer), "sound");
		else if (ret == "v")
			draw_results(std::get<0>(*expected), std::get<1>(*expected),
					std::get<0>(*answer), std::get<1>(*answer), "visual");
	}
}

void get_expected(std::tuple<int, int> *expected, const std::vector<std::tuple<char, int>> &history, const int &level)
{
	std::get<0>(*expected) = 0;
	std::get<1>(*expected) = 0;
	if (std::get<0>(history[history.size() - level - 1]) == std::get<0>(history.back()))
		std::get<0>(*expected) = 1;
	if (std::get<1>(history[history.size() - level - 1]) == std::get<1>(history.back()))
		std::get<1>(*expected) = 1;
}

void get_score(const std::tuple<int, int> *answer, const std::tuple<int, int> *expected,
		std::tuple<int, int> &score, const int *random_square)
{
	if (std::get<0>(*answer) == std::get<0>(*expected) && std::get<0>(*answer) != 0)
		std::get<1>(score) += 1;
	else if (std::get<0>(*answer) != std::get<0>(*expected))
		std::get<0>(score) += 1;
	if (std::get<1>(*answer) == std::get<1>(*expected) && std::get<1>(*answer) != 0)
		std::get<1>(score) += 1;
	else if (std::get<1>(*answer) != std::get<1>(*expected))
		std::get<0>(score) += 1;
	draw_squares(random_square);
	draw_results(std::get<0>(*expected), std::get<1>(*expected), std::get<0>(*answer), std::get<1>(*answer), "all");
}
