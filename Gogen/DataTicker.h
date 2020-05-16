#pragma once
#include <map>
#include <vector>
#include <memory>
#include <list>
using namespace ZedGraph;


struct classcomp {
	bool operator() (const double& lhs, const double& rhs) const
	{
		return lhs<rhs;
	}
};

struct trade_data{
	trade_data(){};
	trade_data(double val, int vol): value(val), volume(vol){}
	double value;
	int volume;
};

ref class Quotes_manage
{

};

class DataTicker
{
public:
	DataTicker();
	~DataTicker();
	void get_middle_series();
	int iter_number;
	double loss;
	double profit;
	double max_gap;
	int size_quotes;
	std::multimap<double, trade_data> dat;
	std::vector<std::pair<double, trade_data>> dat_vec;
	std::list<std::pair<double, trade_data>> dat_list;

	std::vector <std::tuple<double, double, double, double, double, bool, int, int>> profit_set;
	std::vector <std::tuple<double, double, double, double, double, bool, int, int>> loss_set;
	std::vector <std::tuple<double, double, double, double, double, bool, int, int>> all_set;
	double middle;
	double dispersion;
	std::vector<double> series_middle;

	std::string name;
	std::string out_fname;
	std::string out_full_fname;
	std::string out_path;
};

