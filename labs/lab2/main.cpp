

#include <SFML\Graphics.hpp>
#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <string>

typedef long coord_t;
typedef long coord2_t;

struct Point {
	long x, y;
	bool operator <(const Point &p) const {
		return x < p.x || (x == p.x && y < p.y);
	}
};

coord2_t cross(const Point &O, const Point &A, const Point &B)
{
	return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}

std::vector<Point> convex_hull(std::vector<Point> P)
{
	size_t n = P.size(), k = 0;
	if (n <= 3) return P;
	std::vector<Point> H(2 * n);
	// Sort points lexicographically
	sort(P.begin(), P.end());
	// Build lower hull
	for (size_t i = 0; i < n; ++i) {
		while (k >= 2 && cross(H[k - 2], H[k - 1], P[i]) <= 0) k--;
		H[k++] = P[i];
	}
	// Build upper hull
	for (size_t i = n - 1, t = k + 1; i > 0; --i) {
		while (k >= t && cross(H[k - 2], H[k - 1], P[i - 1]) <= 0) k--;
		H[k++] = P[i - 1];
	}
	H.resize(k - 1);
	return H;
}

int main()
{
	std::ifstream fin("data.in");

	sf::RenderWindow window(sf::VideoMode(800, 600), "dorts");
	
	//std::cout << "Enter number (N) of points and their coordinates" << std::endl;
	int N;
	fin >> N;
	std::vector<Point> v_points(N);
	sf::Vertex *points = new sf::Vertex[v_points.size()];

	std::cout << "input coordinates" << std::endl;
	int j = 0;
	for (auto &now : v_points) {
		fin >> now.x >> now.y;
		points[j] = (sf::Vector2f(now.x, now.y));
		points[j++].color = sf::Color::Yellow;
		std::cout << now.x << " " << now.y << std::endl;
	}

	v_points = convex_hull(v_points);
	v_points.push_back(v_points[0]);

	sf::Vertex *lines = new sf::Vertex[v_points.size()];

	std::cout << "convex coordinates (" << v_points.size() << ")" << std::endl;
	for (int i = 0; i < v_points.size(); i++) {
		lines[i] = (sf::Vector2f(v_points[i].x, v_points[i].y));
		//points[i+1] = (sf::Vector2f(v_points[i+1].x, v_points[i+1].y));

		std::cout << "( " << v_points[i].x << " " << v_points[i].y << " ); " << std::endl;
	}

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(points, N, sf::Points);
		window.draw(lines, v_points.size(), sf::LinesStrip);
		window.display();
	}

	fin.close();
	return 0;
}
