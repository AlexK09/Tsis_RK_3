#include <iostream>
#include <vector>
#include<string>
#include <iomanip>
#include <stdlib.h>
#include <time.h>
using namespace std;

double f(double x, double y) {
	return (sin(x) * sin(x)) / (1 + x * x + y * y);
}

class point {
public:
	double x;
	double y;
	void print() {
		if (x < 0)
			std::cout << fixed << setprecision(4) << x << "  |  ";
		else std::cout << fixed << setprecision(4) << x << "   |  ";
		if (y < 0)
			std::cout << fixed << setprecision(4) << y << "  |  ";
		else std::cout << fixed << setprecision(4) << y << "   |  ";
		std::cout << fixed << setprecision(4) << f(x, y) << "  |   ";

	}
};

bool operator==(point A, point B) {
	if ((A.x == B.x) && (A.y == B.y)) {
		return true;
	}
	else return false;
}

bool operator!=(point A, point B) {
	if ((A.x == B.x) && (A.y == B.y)) {
		return false;
	}
	else return true;
}



void GenAlg() {
	double delta = 0.05;
	double mut = 25;
	srand(time(NULL));
	std::vector<point>NG(4);
	std::vector<double> X(4);
	std::vector<double> Y(4);
	int flag = 0;
	while (NG[0] != NG[1] || NG[2] != NG[3] || NG[0] != NG[2] || flag == 0) {
		if (flag == 0) {
			for (int i = 0; i < 4; i++) {
				double t = rand() % 2;
				X[i] = t + (double)rand() / RAND_MAX;
			}
			for (int i = 0; i < 4; i++) {
				double t = -2 + rand() % 4;
				Y[i] = t + (double)rand() / RAND_MAX;
			}
		}

	
		if (rand() % 100 < mut) {
			{int i = rand() % 4;
			if (rand() % 2 == 0) {
				if (rand() % 2 == 0)
					X[i] += delta;
				else X[i] -= delta;
			}
			else {
				if (rand() % 2 == 0)
					Y[i] += delta;
				else Y[i] -= delta;
			}
			NG[i].x = X[i];
			NG[i].y = Y[i];
			}
			
			flag++;
		
			
			double MAX1 = 0;
			for (int i = 0; i < 4; i++) {

				std::cout << std::endl;
				if (i != 3) std::cout << "    |";
				else {
					if (flag < 10) std::cout << flag << "   |";
					if (flag > 9 && flag < 100) std::cout << flag << "  |";
					if (flag > 99) std::cout << flag << " |";

				}
				NG[i].print();
				if (i != 3) std::cout << "       |            |";
				if (f(NG[i].x, NG[i].y) > MAX1) {
					
					MAX1 = f(NG[i].x, NG[i].y);
				}
								
			}
			double sum = 0;
			for (int k = 0; k < 4; k++) {
				sum += f(NG[k].x, NG[k].y);

			}
			std::cout << sum / 4. << " |   " << MAX1 << "   |  " << std::endl;
			std::cout << "--------------------------------------------------------------" << std::endl;

			continue;
		}

		std::vector<double> Fit(4);

		for (int i = 0; i < 4; i++) {
			Fit[i] = f(X[i], Y[i]);
		}

		double sum = Fit[0] + Fit[1] + Fit[2] + Fit[3];

		std::vector<int>P(4);

		for (int i = 0; i < 4; i++) {
			P[i] = (Fit[i] * 100) / sum;
			P[i] = 100 - P[i];
		}


		double mimo = rand() % (P[0] + P[1] + P[2] + P[3]);
		for (int i = 0; i < 4; i++) {
			if (mimo < P[i]) {
				mimo = i;
				break;
			}
			else {
				P[i + 1] = P[i] + P[i + 1];
				continue;
			}
		}


		if (mimo == 0) {
			int max1 = 0;
			double MAX1 = 0;
			int max2 = 0;
			double MAX2 = 0;
			for (int i = 0; i < 4; i++) {
				if (i == mimo) continue;
				else {
					if (Fit[i] > MAX1) {
						MAX1 = Fit[i];
						max1 = i;
					}


					else {
						if (Fit[i] > max2) {
							max2 = i;
							MAX2 = Fit[i];

						}
						else X[3] = X[i];
					}
				}
			}
			X[1] = X[max1];
			X[2] = X[max2];

			NG[0].x = X[1];
			NG[0].y = Y[2];
			NG[1].x = X[1];
			NG[1].y = Y[3];
			NG[2].x = X[2];
			NG[2].y = Y[1];
			NG[3].x = X[3];
			NG[3].y = Y[1];
		}

		if (mimo == 1) {
			int max1 = 0;
			double MAX1 = 0;
			int max2 = 0;
			double MAX2 = 0;
			for (int i = 0; i < 4; i++) {
				if (i == mimo) continue;
				else {
					if (Fit[i] > MAX1) {
						MAX1 = Fit[i];
						max1 = i;
					}
					else {
						if (Fit[i] > max2) {
							max2 = i;
							MAX2 = Fit[i];
						}
						else X[3] = X[i];
					}
				}
			}
			X[0] = X[max1];
			X[2] = X[max2];
			NG[0].x = X[0];
			NG[0].y = Y[2];
			NG[1].x = X[0];
			NG[1].y = Y[3];
			NG[2].x = X[2];
			NG[2].y = Y[0];
			NG[3].x = X[3];
			NG[3].y = Y[0];
		}

		if (mimo == 2) {

			int max1 = 0;
			double MAX1 = 0;
			int max2 = 0;
			double MAX2 = 0;
			for (int i = 0; i < 4; i++) {
				if (i == mimo) continue;
				else {
					if (Fit[i] > MAX1) {
						MAX1 = Fit[i];
						max1 = i;
					}


					else {
						if (Fit[i] > max2) {
							max2 = i;
							MAX2 = Fit[i];

						}
						else X[3] = X[i];
					}
				}
			}
			X[0] = X[max1];
			X[1] = X[max2];
			NG[0].x = X[0];
			NG[0].y = Y[1];
			NG[1].x = X[0];
			NG[1].y = Y[3];
			NG[2].x = X[1];
			NG[2].y = Y[0];
			NG[3].x = X[3];
			NG[3].y = Y[0];
		}

		if (mimo == 3) {

			int max1 = 0;
			double MAX1 = 0;
			int max2 = 0;
			double MAX2 = 0;
			for (int i = 0; i < 4; i++) {
				if (i == mimo) continue;
				else {
					if (Fit[i] > MAX1) {
						MAX1 = Fit[i];
						max1 = i;
					}


					else {
						if (Fit[i] > max2) {
							max2 = i;
							MAX2 = Fit[i];

						}
						else X[2] = X[i];
					}
				}
			}
			X[0] = X[max1];
			X[1] = X[max2];
			NG[0].x = X[0];
			NG[0].y = Y[1];
			NG[1].x = X[0];
			NG[1].y = Y[2];
			NG[2].x = X[1];
			NG[2].y = Y[0];
			NG[3].x = X[2];
			NG[3].y = Y[0];
		}

		if (rand() % 100 < mut) {
			{ int i = rand() % 4;
			if (rand() % 2 == 0) {
				if (rand() % 2 == 0)
					X[i] += delta;
				else X[i] -= delta;
			}
			else {

				if (rand() % 2 == 0)
					Y[i] += delta;
				else Y[i] -= delta;
			}

			NG[i].x = X[i];
			NG[i].y = Y[i];

			}
			
			flag++;
			
			
			double MAX1 = 0;
			for (int i = 0; i < 4; i++) {
				std::cout << std::endl;
				if (i != 3) std::cout << "    |";
				else {
					if (flag < 10) std::cout << flag << "   |";
					if (flag>9&&flag<100) std::cout << flag << "  |";
					if (flag>99) std::cout << flag << " |";

				}
				NG[i].print();
				if (i != 3) std::cout << "       |            |";
				if (f(NG[i].x, NG[i].y) > MAX1) {

					MAX1 = f(NG[i].x, NG[i].y);
				}
			}
			std::cout << sum / 4. << " |   " << MAX1 << "   |  " << std::endl;
			std::cout << "--------------------------------------------------------------" << std::endl;
		
			continue;
		}


		for (int i = 0; i < 4; i++) {
			X[i] = NG[i].x;
			Y[i] = NG[i].y;
		}
		flag++;

		for (int i = 0; i < 4; i++) {
			Fit[i] = f(X[i], Y[i]);
		}

		 sum = Fit[0] + Fit[1] + Fit[2] + Fit[3];

	
		double MAX1 = 0;
		for (int i = 0; i < 4; i++) {
			std::cout << std::endl;
			if (i != 3) std::cout << "    |";
			else {
				if (flag < 10) std::cout << flag << "   |";
				if (flag > 9 && flag < 100) std::cout << flag << "  |";
				if (flag > 99) std::cout << flag << " |";

			}
			NG[i].print();
			if (i != 3) std::cout << "       |            |";
			if (f(NG[i].x, NG[i].y) > MAX1) {

				MAX1 = f(NG[i].x, NG[i].y);
			}
		}

		std::cout << sum / 4. << " |   " << MAX1 <<"   |  "<< std::endl;
	
		std::cout << "--------------------------------------------------------------" << std::endl;
	}

}




int main() {
	std::cout << " N  |    X    |      Y    |    Fit   |   Sredn  |    MaxFit  |";
	GenAlg();
	return 0;
}