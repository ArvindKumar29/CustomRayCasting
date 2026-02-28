#include "Physics.h"
#include "SFML/Graphics.hpp"
#include <fstream>
#include <iostream>
#include <algorithm>
#include <cmath>

int main()
{
	Physics phy;
	std::vector<Vec2> hitPoints;
	//std::cout << "Starting program..." << std::endl;
	std::fstream fin("Level.txt");
	if (!fin.is_open()) {
		std::cout << "Failed to open Level.txt" << std::endl;
		return -1;
	}
	//std::cout << "Successfully opened Level.txt" << std::endl;
	std::string type;
	Vec2 point1, point2;
	std::vector<Vec2> points;
	std::vector<std::pair<Vec2, Vec2>> lines;
	while(fin >> type){
		if (type == "Line") {
			fin >> point1.x >> point1.y >> point2.x >> point2.y;
			lines.push_back(std::make_pair(point1, point2));
			//std::cout << "Line added: " << point1.x << point1.y << point2.x << point2.y << std::endl;
			points.push_back(point1);
			points.push_back(point2);
		}
	}
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "Custom Ray Casting");
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear(sf::Color::Black);
		sf::Vector2i mousePos = sf::Mouse::getPosition(window);

		std::vector<std::pair<Vec2, Vec2>> rays;
		for (auto p : points) {
			float angle = std::atan2(p.y - mousePos.y, p.x - mousePos.x);
			float angleleft = angle - 0.00001f;
			float angleright = angle + 0.00001f;
			rays.push_back(std::make_pair(Vec2(mousePos.x, mousePos.y), p));
			rays.push_back(std::make_pair(Vec2(mousePos.x, mousePos.y), Vec2(mousePos.x + std::cosf(angleleft) * 3000.0f, mousePos.y + std::sinf(angleleft) * 3000.0f)));
			rays.push_back(std::make_pair(Vec2(mousePos.x, mousePos.y), Vec2(mousePos.x + std::cosf(angleright) * 3000.0f, mousePos.y + std::sinf(angleright) * 3000.0f)));
		}

		for (auto l : lines) {
			sf::Vertex line[] =
			{
				sf::Vertex(sf::Vector2f(l.first.x, l.first.y)),
				sf::Vertex(sf::Vector2f(l.second.x, l.second.y))
			};
			window.draw(line, 2, sf::Lines);
		}
		for (auto r : rays) {
			sf::Vertex ray[2];
			ray[0] = sf::Vertex(sf::Vector2f(mousePos), sf::Color::Red);
			bool isHit = false;
			Vec2 bestPoint;
			float minDist = 999999.0f;
			for (auto l : lines) {
				auto res = phy.IsIntersect(l.first, l.second, r.first, r.second);

				if (res.isIntersecting) {
					float currentDist = r.first.dist(res.intersectionPoint);
					if (currentDist < minDist) {
						minDist = currentDist;           
						bestPoint = res.intersectionPoint;
						isHit = true;
					}
				}
			}
			if (isHit == true) {
				ray[1] = sf::Vertex(sf::Vector2f(bestPoint.x, bestPoint.y));
				hitPoints.push_back(bestPoint);
			}
			else {
				ray[1] = sf::Vertex(sf::Vector2f(r.second.x, r.second.y));
				//hitPoints.push_back(r.second);

			}
			//window.draw(ray, 2, sf::Lines);
		}

		std::sort(hitPoints.begin(), hitPoints.end(), [&](const Vec2& a, const Vec2& b) {
			float angleA = std::atan2(a.y - mousePos.y, a.x - mousePos.x);
			float angleB = std::atan2(b.y - mousePos.y, b.x - mousePos.x);
			return angleA < angleB;
			});

		sf::VertexArray light(sf::TriangleFan, hitPoints.size() + 2);
		light[0] = sf::Vertex(sf::Vector2f(mousePos.x, mousePos.y), sf::Color(255, 255, 255, 100));
		for (size_t i = 0; i < hitPoints.size(); i++) {
			light[i + 1] = sf::Vertex(sf::Vector2f(hitPoints[i].x, hitPoints[i].y), sf::Color(255, 255, 255, 100));
		}
		if (hitPoints.size() > 0) {
			light[hitPoints.size() + 1] = light[1];
		}

		window.draw(light);
		hitPoints.clear();
		rays.clear();
		//lines.clear();
		window.display();
	}

	return 0;
}