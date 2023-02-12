#include "OdeSolver.h"
#include <iostream>


int main() {
	setlocale(0, "");
	OdeSolver<double> odeSolver = {
		{
			[](double x, const std::vector<double>& y) {return y[1]; },
			[](double x, const std::vector<double>& y) {return -y[0]; }
		},
		0.1e-6,
		RUNGE_KUTTA_FELDBERG
	};
	const auto sol = odeSolver.solve(0, 1, { 0,1 });
	for (auto x : sol)
	{
		std::cout << x << std::endl;
	}
	std::cout << "Аналитическое решение:" << std::endl;
	std::cout << sin(1.0) << " " << cos(1.0) << std::endl;
	system("pause");

}