#include "CalendarUI.h"
#include <iostream>
#include <vector>

void CalendarUI::renderCalendar(std::vector<std::string> dataDays, std::string dt, int countDays)
{
	int indexDay = 0, index = 0;

	for (auto i : dataDays)
	{
		std::cout << i << "\t";
		std::size_t found = dt.find(i);
		if (found != std::string::npos)
			indexDay = index;
		index++;
	}

	for (size_t i = 0; i < countDays + indexDay; i++)
	{
		if (i % 7 == 0)
			std::cout << "\n";

		if (i < indexDay)
			std::cout << " \t";
		else
			std::cout << i - indexDay + 1 << "\t";
	}
	std::cout << "\n";
}
