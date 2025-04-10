#include <iostream>
#include <cmath>
#include <fstream>

int main() {
	int N1 = 0;
	int N2 = 0;
	int N3 = 0;
	int N4 = 0;
	int N5 = 0;
	int N6 = 0;
	int N7 = 0;
	int N8 = 0;
	int N9 = 0;
	int N10 = 0;
	const int SIZE = 100000;
	float m_r = 0;
	float d_r = 0;
	float sum = 0;
	float sum_mr = 0;

	for (int i = 0; i < SIZE; ++i) {
		float x = (float)rand() / (RAND_MAX + 1.0);
		if (x >= 0.0 && x <= 0.1) {
			++N1;
		}
		else if (x > 0.1 && x <= 0.2) {
			++N2;
		}
		else if (x > 0.2 && x <= 0.3) {
			++N3;
		}
		else if (x > 0.3 && x <= 0.4) {
			++N4;
		}
		else if (x > 0.4 && x <= 0.5) {
			++N5;
		}
		else if (x > 0.5 && x <= 0.6) {
			++N6;
		}
		else if (x > 0.6 && x <= 0.7) {
			++N7;
		}
		else if (x > 0.7 && x <= 0.8) {
			++N8;
		}
		else if (x > 0.8 && x <= 0.9) {
			++N9;
		}
		else if (x > 0.9 && x <= 1.0) {
			++N10;
		}

		sum += x;
		sum_mr += x * x;
	}

	m_r = sum / SIZE;
	d_r = (sum_mr / SIZE) - (m_r * m_r);
	float g_r = sqrt(d_r);
	std::cout << "m_r = " << m_r << '\n';
	std::cout << "D_r = " << d_r << '\n';
	std::cout << "g_r = " << g_r << '\n';
	std::ofstream file("result.txt");
	file << N1 << '\n' << N2 << '\n' << N3 << '\n' << N4 << '\n'
		<< N5 << '\n' << N6 << '\n' << N7 << '\n' << N8 << '\n' << N9  << '\n' << N10 << '\n';
	file.close();
	return 0;
}