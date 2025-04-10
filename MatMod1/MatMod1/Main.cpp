#include <iostream>
#include <fstream>

int main() {	
	int const XT{ 15 };
	double z1{ 0 }, z2{ 0 }, z3{ 0 }, h{ 0.2 }, y{ 0 };
	double dz1{ 0 }, dz2{ 0 }, dz3{ 0 };

	std::ofstream file("result.txt");
	for (int t{ 0 }; t <= 350; t++) {
		dz1 = z1 + h * z2;
		dz2 = z2 + h * z3;
		dz3 = z3 + h * (XT - z1 - 9 * z2 - 24 * z3) / 20;
		y = z1 - z2 - 12 * z3;

//До шага 166 выводится каждое значение, после каждое десятое значение
		if (t <= 166) {
			file << t << "\t" << y << '\n';
		}
		if (t > 166 && t % 10 == 0) {
			file << t << "\t" << y << '\n';
		}
		z1 = dz1, z2 = dz2, z3 = dz3;
	}
	file.close();
	return 0;
}