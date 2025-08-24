#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <ranges>

#include <fmt/format.h>

#include "ctre_inc.h"
#include "timer.h"

struct pt
{
	int x_;
	int y_;
};

auto get_input()
{
	std::vector<pt> v;
	std::string ln;
	while(std::getline(std::cin, ln))
		if(auto[m, x, y] = ctre::match<"(\\d+), (\\d+)">(ln); m)
			v.emplace_back(x.to_number<int>(), y.to_number<int>());
		else
			fmt::println("parse fail: {}", ln);
	return v;
}

auto scan(auto const& in)
{
	pt tl(std::numeric_limits<int>::max(), std::numeric_limits<int>::max());
	pt br(0, 0);
	for(auto p : in)
	{
		if(p.x_ < tl.x_)
			tl.x_ = p.x_;
		if(p.x_ > br.x_)
			br.x_ = p.x_;
		if(p.y_ < tl.y_)
			tl.y_ = p.y_;
		if(p.y_ > br.y_)
			br.y_ = p.y_;
	}
	return std::make_pair(tl, br);
}

int64_t pt1(auto const& in)
{
	timer t("p1");
	auto[tl, br] = scan(in);
	fmt::println("({}, {}) - ({}, {})", tl.x_, tl.y_, br.x_, br.y_);
	return 0;
}

int64_t pt2(auto const& in)
{
	timer t("p2");
	return 0;
}

int main()
{
	auto in = get_input();
	auto p1 = pt1(in);
	auto p2 = pt2(in);
	fmt::println("pt1 = {}", p1);
	fmt::println("pt2 = {}", p2);
}
