#ifndef BFS_H
#define BFS_H


#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace sf;
using namespace std;

void drawGraph(sf::RenderWindow& window, const std::map<int, std::vector<int>>& graph, int currentNode);
void runBfs(sf::RenderWindow& window);
void bfsVisualizer();


#endif // BFS_H