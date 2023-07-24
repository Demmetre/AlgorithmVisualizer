#include <SFML/Graphics.hpp>
#include <vector>
#include <algorithm>
#include <chrono>
#include <thread>

const int windowWidth = 800;
const int windowHeight = 600;
const int barWidth = 50;
const int barSpacing = 20;
const int ANIMATION = 500;
const int LEN = 1;

using namespace std;
using namespace sf;

void animateList(vector<int>& array, RenderWindow& window, int i){
    // Set the window background color to white
    int n = array.size();
    window.clear(Color::White);
    for (int j = 0; j < n; ++j) {
        RectangleShape bar(Vector2f(barWidth, array[j]));
        bar.setPosition(j * (barWidth + barSpacing), windowHeight - array[j]);
        if(j == i-1 || j == i){
            bar.setFillColor(Color::Red);
        }else{
            bar.setFillColor(Color::Black);
        }
        window.draw(bar);
    }
    window.display();
    // Add a short delay for animation
    this_thread::sleep_for(chrono::milliseconds(ANIMATION));
}

void bubbleSortVisualization(vector<int>& array, RenderWindow& window) {
    bool swapped = true;
    int n = array.size();
    while (swapped) {
        swapped = false;
        for (int i = 1; i < n; ++i) {
            if (array[i - 1] > array[i]) {
                swap(array[i - 1], array[i]);
                swapped = true;
                animateList(array, window, -1);
            }else{
                animateList(array, window, i);
                animateList(array, window, -1);
            }
        }
        n--;
    }
}
vector<int> generateRandomList(){
    vector<int> res;
    srand(time(NULL));
    for(int i = 0; i < LEN; i++ ){
        int temp = rand()%50 + 5;
        res.push_back(temp*10);
    }
    return res;
}

int main() {

    RenderWindow window(VideoMode(windowWidth, windowHeight), "Bubble Sort Visualization");
    vector<int> array = generateRandomList();
    animateList(array, window, -1);

    // Wait for user input to start the visualization
    bool sortingStarted = false;
    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }
            if (event.type == Event::KeyPressed) {
                if (event.key.code == Keyboard::Space && !sortingStarted) {
                    sortingStarted = true;
                    bubbleSortVisualization(array, window);
                }
            }
        }
    }
    return 0;
}