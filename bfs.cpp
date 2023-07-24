#include "bfs.h"

const int windowWidth = 800;
const int windowHeight = 600;
const int nodeRadius = 20;
const int edgeThickness = 2;

using namespace std;
using namespace sf;

const int NUM_ROW  = 3;
const int MAX_N = 12;

// Here create connected graph
//    0       NUM_ROW
//    1      NUM_ROW+1
// NUM_ROW-1    ....


std::map<int, std::vector<int>> m = {
    {0, {4, 1, 3}},
    {1, {0,2}},
    {2, {1,4}},
    {3, {0,6}},
    {4, {0,2,5,8}},
    {5, {4}},
    {6, {3,7}},
    {7, {6}},
    {8, {4,9}},
    {9, {8,10}},
    {10, {9,11}},
    {11, {10}},
};
int start = 0;
int dest = 11;

std::vector<int> used(MAX_N, false);
std::vector<int> popped(MAX_N, false);

void drawGraph(sf::RenderWindow& window, const std::map<int, std::vector<int>>& graph, int currentNode) {
    window.clear(sf::Color::White);

    for (const auto& [node, neighbors] : graph) {
        sf::CircleShape nodeCircle(nodeRadius);
        int x = 50 + (node/NUM_ROW) * 100;
        int y = windowHeight / 2 + (node%NUM_ROW)*100;
        nodeCircle.setPosition(x,y);
        nodeCircle.setOutlineThickness(2);
        nodeCircle.setOutlineColor(sf::Color::Black);

        if (node == currentNode) {
            nodeCircle.setFillColor(sf::Color::Red);
        } else if (popped[node]) {
            nodeCircle.setFillColor(sf::Color::Green);
        }else if (used[node]) {
            nodeCircle.setFillColor(sf::Color::Blue);
        } else {
            nodeCircle.setFillColor(sf::Color::Black);
        }


        for (int neighbor : neighbors) {
            int x1 = 50 + (neighbor/NUM_ROW) * 100;
            int y1 = windowHeight / 2 + (neighbor%NUM_ROW)*100;
            sf::Vertex line[] = {
                sf::Vertex(sf::Vector2f(x + nodeRadius, y  + nodeRadius),sf::Color::Black),
                sf::Vertex(sf::Vector2f(x1  + nodeRadius, y1  + nodeRadius), sf::Color::Black)
            };
            window.draw(line, 2, sf::Lines);
        }
        window.draw(nodeCircle);
    }

    window.display();
}

void runBfs(sf::RenderWindow& window){
    std::queue<int> q;
    q.push(start);
    used[start] = true;
    drawGraph(window, m, start);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        popped[u] = true;
        drawGraph(window, m, u);
        if (dest == u) {
            sf::sleep(sf::seconds(1));
            break;
        }
        for (int v : m[u]) {
            if (!used[v]) {
                q.push(v);
                used[v] = true;
            }
        }
        sf::sleep(sf::seconds(1));
        drawGraph(window, m, u);
        sf::sleep(sf::seconds(1));
        drawGraph(window, m, -1);
    }
}

void bfsVisualizer(){
    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "BFS Visualization");

    // Visualization: Draw the final state of the graph
    drawGraph(window, m, -1);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == Event::KeyPressed) {
                if (event.key.code == Keyboard::Space) {
                    runBfs(window);
                    window.close();
                }
            }
        }
    }
}