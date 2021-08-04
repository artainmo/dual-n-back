#ifndef DUAL_N_BACK_HPP
#define DUAL_N_BACK_HPP

#include <iostream>
#include <mutex>
#include <tuple>
#include <vector>
#include <cstdlib>
#include <thread>
#include <string>
#include <unistd.h>
#include <fstream>

void play(float time, float between_signal_time, const int &level);

void sound_letter(const char &random_letter);
void draw_results(const bool &sound_exp, const bool &visual_exp, const bool &sound_ans,
		const bool &visual_ans, const std::string &check);
void draw_squares(const int *random_square);

char get_random_letter(std::vector<std::tuple<char, int>> history, const int &level);
int get_random_square(std::vector<std::tuple<char, int>> history, const int &level); 

void get_answer(std::tuple<int, int> *answer, std::tuple<int, int> *expected, const int *random_square, int *total_time);
void get_score(const std::tuple<int, int> *answer, const std::tuple<int, int> *expected, 
		std::tuple<int, int> &score, const int *random_square);
void get_expected(std::tuple<int, int> *expected, const std::vector<std::tuple<char, int>> &history, const int &level);

#endif
