#ifndef BUBBLE_H
#define BUBBLE_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <algorithm>
#include <chrono>
#include <thread>

using namespace std;
using namespace sf;

void animateList(std::vector<int>& array, sf::RenderWindow& window, int animationSpeed);
void bubbleSortVisualization(std::vector<int>& array, sf::RenderWindow& window);
vector<int> generateRandomList();
void RunBubbleSort();

#endif // BUBBLE_H