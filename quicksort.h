#ifndef QUICK_H
#define QUICK_H


#include <SFML/Graphics.hpp>
#include <vector>
#include <algorithm>
#include <chrono>
#include <thread>

using namespace sf;
using namespace std;

void drawArray(const vector<int>& array, RenderWindow& window, int left,int right, int pivot);
void quickSortHelper(vector<int>& array, int left, int right, RenderWindow& window);
void quickSortVisualization(std::vector<int>& array, RenderWindow& window);
void RunQuickSort();

#endif // QUICK_H