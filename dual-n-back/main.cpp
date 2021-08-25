#include "dual-n-back.hpp"

void get_settings(float &total_time, float &between_signal_time, int &level)
{
	std::ifstream fd;

	fd.open("dual-n-back/settings.txt");
	if (!fd.is_open())
	{
		std::cout << "Error: settings file opening" << std::endl;
		exit(0);
	}
	fd >> total_time >> between_signal_time >> level;
	fd.close();		
}

void set_settings(const float &total_time, const float &between_signal_time, const int &level)
{
	std::ofstream fd;

	fd.open("dual-n-back/settings.txt");
	if (!fd.is_open())
	{
		std::cout << "Error: settings file opening" << std::endl;
		exit(0);
	}
	fd.clear();
	fd << total_time << "\n" << between_signal_time << "\n" << level;
	fd.close();		
}

void settings(float &total_time, float &between_signal_time, int &level)
{
	std::string input;
	std::string input2;

	while(1)
	{
		system("clear");
		std::cout << "LEVEL: " << level << " | ";
		std::cout << "TIME: " << total_time << " | ";
		std::cout << "TIME_BETWEEN_SIGNAL: " << between_signal_time << std::endl;
		std::cout << "Option (LEVEL/TIME/TIME_BETWEEN_SIGNAL/EXIT) : ";
    	std::getline(std::cin, input);
		if (input == "LEVEL" || input == "TIME" || input == "TIME_BETWEEN_SIGNAL")
		{
			std::cout << "NEW VALUE : ";
    		std::getline(std::cin, input2);
		}
    	if (input == "LEVEL")
		{
			if (std::stoi(input2) > 1 && std::stoi(input2) < 11)
			{
				level = std::stoi(input2);
      			set_settings(total_time, between_signal_time, level);
			}
		}
    	else if (input == "TIME")
		{
			total_time = std::stof(input2);
      		set_settings(total_time, between_signal_time, level);
		}
    	else if (input == "TIME_BETWEEN_SIGNAL")
		{
			between_signal_time = std::stof(input2);
      		set_settings(total_time, between_signal_time, level);
		}
    	else if (input == "EXIT")
      		break ;
	}
}

void manual()
{
	std::string ret;

	system("clear");
	std::cout << "Play dual-n-back, indicate pair signals with v, s, vs/sv." << std::endl;
	std::cout << "v for visual signal." << std::endl;
	std::cout << "s for sound signal." << std::endl;
	std::cout << "vs or sv for sound and visual signal." << std::endl;
	std::cout << "\nq to quit the game." << std::endl;
	std::cout << "\nLeft indications are for sounds and right for visuals" << std::endl;
	std::getline(std::cin, ret);
}

int main()
{
	std::string input;
	float total_time;
	float between_signal_time;
	int level;

	get_settings(total_time, between_signal_time, level);
	while(1)
	{
		system("clear");
		std::cout << "LEVEL: " << level << " | ";
		std::cout << "TIME: " << total_time << " | ";
		std::cout << "TIME_BETWEEN_SIGNAL: " << between_signal_time << std::endl;
		std::cout << "Option (PLAY/SETTINGS/MANUAL/EXIT) : ";
    	std::getline(std::cin, input);
    	if (input == "PLAY" || input.size() == 0)
      		play(total_time, between_signal_time, level);
    	else if (input == "SETTINGS")
      		settings(total_time, between_signal_time, level);
    	else if (input == "MANUAL")
      		manual();
    	else if (input == "EXIT")
      		break ;
	}	
}
