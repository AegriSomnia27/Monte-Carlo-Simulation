#include <iostream>
#include <cmath>
#include <random>
#include <vector>

std::vector<int> randomWalks(int walkLength);
void testDistanceFromHome(std::vector<int> walk);

std::random_device randomDevice;
std::mt19937 el(randomDevice());
std::uniform_int_distribution<int> uniform_dist(0, 3);

int main() {
	const int IterationsNumber = 40000;
	const int distanceToTheStopPoint = 5;
	std::vector<int> walk { 0,0 };

	for (int walkLength = 1; walkLength < 38; walkLength++) {
		int furtherThanStopPointCounter = 0;

		for (int i = 0; i < IterationsNumber; i++) {
			int distance = 0;
			walk = randomWalks(walkLength);

			distance = std::abs(walk[0]) + std::abs(walk[1]);

			if (distance > distanceToTheStopPoint)
				furtherThanStopPointCounter++;
		}
		double furtherThanStopPointPercentage = static_cast<double>(furtherThanStopPointCounter) / IterationsNumber;

		std::cout << "Walk size = " << walkLength << " / % further than the stop point = " 
			<< 100 * furtherThanStopPointPercentage << std::endl;
	}

	return 0;
}

std::vector<int> randomWalks(int walkLength) {
	std::vector<std::vector<int>> cardinalDirections{ {1,0},{0,1},{-1,0},{0,-1} };
	int x = 0; int y = 0; int randomDirection;

	for (int i = 0; i < walkLength; i++) {
		int randomDirection = uniform_dist(el);
		x += cardinalDirections[randomDirection][0];
		y += cardinalDirections[randomDirection][1];
	}

	std::vector<int> position = {x, y};

	return position;
}

void testDistanceFromHome(std::vector<int> walk) {
	for (int i = 0; i < 25; i++) {
		walk = randomWalks(10);
		std::cout << '(' << walk[0] << ", " << walk[1] << ") "
			<< "Distance from home = " << abs(walk[0]) + abs(walk[1]) << std::endl;
	}
}