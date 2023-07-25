#ifndef SQUARESORT_H
#define SQUARESORT_H

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
void RunInsertionSort();
void RunSelectionSort();

#endif // SQUARE_H