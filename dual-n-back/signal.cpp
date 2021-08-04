#include "dual-n-back.hpp"

std::mutex g_write_mutex;

void sound_letter(const char &random_letter) 
{
	std::string str;

	str = "say ";
	str.push_back(random_letter);
	system(str.c_str());
}

static int num_square(int i, int l, int width, int height)
{
	if (i < width/3 && l < height/3)
		return 0;
	else if (i < width/3*2 && l < height/3)
		return 1;
	else if (i < width && l < height/3)
		return 2;
	else if (i < width/3 && l < height/3*2)
		return 3;
	else if (i < width/3*2 && l < height/3*2)
		return 4;
	else if (i < width && l < height/3*2)
		return 5;
	else if (i < width/3 && l < height)
		return 6;
	else if (i < width/3*2 && l < height)
		return 7;
	return 8;
}

void draw_results(const bool &sound_exp, const bool &visual_exp, const bool &sound_ans, 
		const bool &visual_ans, const std::string &check)
{
	int width = 80;
	int height = width/2.16/3;
	int i;
	int l;

	l = 0;
	if (!((sound_exp == sound_ans && sound_ans) || (sound_exp != sound_ans) || 
				(visual_exp == visual_ans && visual_ans) || (visual_exp != visual_ans)))
		return ;
	g_write_mutex.lock();
	while (l < height)
	{
		i = 1;
		while (i < width)
		{
			if (i < width/2)
			{
				if (sound_exp == sound_ans && sound_ans && (check == "all" || check == "sound"))
					std::cout << "\033[0;32m" << "." << "\033[0;37m";
				else if (sound_exp != sound_ans && (check == "all" || check == "sound"))
					std::cout << "\033[0;31m" << "." << "\033[0;37m";
				else 
					std::cout << " ";
			}
			else if (i > width/2)
			{
				if (visual_exp == visual_ans && visual_ans && (check == "all" || check == "visual"))
					std::cout << "\033[0;32m" << "." << "\033[0;37m";
				else if (visual_exp != visual_ans && (check == "all" || check == "visual"))
					std::cout << "\033[0;31m" << "." << "\033[0;37m";
				else
					std::cout << " ";
			}
			else
				std::cout << " ";
			i++;
		}
		std::cout << std::endl;
		l++;
	}
	g_write_mutex.unlock();
}

void draw_squares(const int *random_square)
{
	int width = 80;
	int height = width/2.16;
	int i;
	int l;
	int square;

	l = 1;
	square = 0;
	g_write_mutex.lock();
	system("clear");
	while (l < height - 1)
	{
		i = 0;
		while (i < width)
		{
			square = num_square(i, l, width, height);
			if (l == height/3 || l == height/3*2)
				std::cout << "=";
			else if (i == width/3 || i == width/3*2)
				std::cout << "=";
			else if (square == *random_square)
				std::cout << "\u001b[34m" << "-" << "\u001b[0m";
			else
				std::cout << "-";
			i++;
		}
		std::cout << "\n";
		l++;
	}	
	g_write_mutex.unlock();
}
