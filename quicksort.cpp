#include "quicksort.h"
#include "bubble.h"

const int windowWidth = 800;
const int windowHeight = 600;
const int barWidth = 50;
const int barSpacing = 20;
const int ANIMATION = 200;
const int LEN = 5;

void drawArray(const vector<int>& array, RenderWindow& window, int left, int right, int pivot){
    // Set the window background color to white
    int n = array.size();
    window.clear(Color::White);
    for (int i = 0; i < n; ++i) {
        RectangleShape bar(sf::Vector2f(barWidth, array[i]));
        bar.setPosition(i * (barWidth + barSpacing), windowHeight - array[i]);
        if(i == left || i == right){
            bar.setFillColor(Color::Red);
        }else if(array[i] == pivot){
            bar.setFillColor(Color::Green);
        }else{
            bar.setFillColor(Color::Black);
        }
        window.draw(bar);
    }
    window.display();
    this_thread::sleep_for(chrono::milliseconds(ANIMATION));
}


void quickSortHelper(vector<int>& array, int left, int right, RenderWindow& window) {

    if (left < right) {
        int pivot = array[left];
        int i = left;
        int j = right + 1;

        do {
            do {
                drawArray(array, window, i, -1, pivot);
                i++;
            } while (array[i] < pivot && i < right);

            do {
                drawArray(array, window, j, -1, pivot);
                j--;
            } while (array[j] > pivot);

            if (i < j) {
                drawArray(array, window,i,j,-1);
                std::swap(array[i], array[j]);
                drawArray(array, window,-1,-1,-1);
            }
        } while (i < j);
        drawArray(array, window,left,j,-1);
        std::swap(array[left], array[j]);
        drawArray(array, window,-1,-1,-1);
        quickSortHelper(array, left, j - 1, window);
        quickSortHelper(array, j + 1, right, window);
    }
}

void quickSortVisualization(vector<int>& array, RenderWindow& window){
    quickSortHelper(array, 0, array.size() - 1, window);
}

void RunQuickSort() {
    RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Quick Sort Visualization");
    vector<int> array = generateRandomList();

    // Visualization: Render the initial array
    window.clear(Color::White);
    drawArray(array, window,-1,-1,-1);
    window.display();

    // Wait for user input to start the visualization
    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }
            if (event.type == Event::KeyPressed) {
                if (event.key.code == Keyboard::Space) {
                    quickSortVisualization(array, window);
                    window.close();
                }
            }
        }
    }
}