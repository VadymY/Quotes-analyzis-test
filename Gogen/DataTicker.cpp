#include "DataTicker.h"


DataTicker::DataTicker() : out_fname("output.txt")
{
}


DataTicker::~DataTicker()
{
}

void DataTicker::get_middle_series()
{
	series_middle.clear();
	series_middle.reserve(all_set.size() + 1);
	for (int i = 1; i <= all_set.size(); ++i)
	{
		double sum = 0;
		for (int j = 0; j < i; ++j)
		{
			sum += std::get<0>(all_set[j]);
		}
		sum /= i;
		series_middle.emplace_back(sum);
	}
}
