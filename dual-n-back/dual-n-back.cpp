#include "dual-n-back.hpp"

void play(float time, float between_signal_time, const int &level)
{
	int *total_time = new int;
	char random_letter;
	int *random_square = new int;
	std::tuple<int, int> score; //number of errors, number of correct
	std::tuple<int, int> *answer = new std::tuple<int, int>; //0/1 sound, 0/1 visual
	std::tuple<int, int> *expected = new std::tuple<int, int>;
	std::vector<std::tuple<char, int>> history;

	*total_time = time;
	*total_time = *total_time / between_signal_time;
	between_signal_time *= 1000000;
	std::thread t1(get_answer, answer, expected, random_square, total_time);
	while(*total_time > 0)
	{
		std::get<0>(*answer) = 0;
		std::get<1>(*answer) = 0;
		random_letter = get_random_letter(history, level);
		*random_square = get_random_square(history, level);
		history.push_back(std::make_tuple(random_letter, *random_square));
		draw_squares(random_square);
		sound_letter(random_letter);
		get_expected(expected, history, level);
		usleep(between_signal_time - between_signal_time/15);
		if (std::get<0>(*answer) == -1)
			break ;
		if ((int)history.size() > level)
			get_score(answer, expected, score, random_square);
		usleep(between_signal_time/15);
		*total_time -= 1;
	}
	if (std::get<0>(*answer) != -1)
	{
		std::cout << "Errors: " << std::get<0>(score) << "\nCorrect: " << std::get<1>(score) << std::endl;
		std::cout << "Final Score: " << ((float)std::get<1>(score) / 
				(float)(std::get<0>(score) + std::get<1>(score)))*100 << "/100!" << std::endl;
	}
	t1.join();
	delete random_square;
	delete total_time;
	delete answer;
	delete expected;
}
