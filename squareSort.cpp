#include "squareSort.h"


const int windowWidth = 800;
const int windowHeight = 600;
const int barWidth = 50;
const int barSpacing = 20;
const int ANIMATION = 500;
const int LEN = 10;

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

void RunBubbleSort() {

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
                    window.close();
                }
            }
        }
    }
}

void drawBars(sf::RenderWindow& window, const std::vector<int>& array, int currentIndex) {
    window.clear(sf::Color::White);
    int n = array.size();
    for (int i = 0; i < n; ++i) {
        sf::RectangleShape bar(sf::Vector2f(barWidth, array[i]));
        bar.setPosition(i * (barWidth + barSpacing), windowHeight - array[i]);
        bar.setFillColor((i == currentIndex) ? sf::Color::Red : sf::Color::Black);
        window.draw(bar);
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(ANIMATION));

    window.display();
}
void insertionSort(std::vector<int>& array, sf::RenderWindow& window) {
    int n = array.size();
    for (int i = 1; i < n; ++i) {
        int key = array[i];
        int j = i - 1;
        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            --j;
            // Animate the sorting process
            drawBars(window, array, j + 1);
        }

        array[j + 1] = key;
        // Animate the sorting process
        drawBars(window, array, i);
    }
}

void RunInsertionSort(){
    RenderWindow window(VideoMode(windowWidth, windowHeight), "Insertion Sort Visualization");
    vector<int> array = generateRandomList();
    

    // Wait for user input to start the visualization
    drawBars(window, array, -1);
    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }
            if (event.type == Event::KeyPressed) {
                if (event.key.code == Keyboard::Space) {
                    insertionSort(array, window);
                    window.close();
                }
            }
        }
    }
}


void drawBarsSel(sf::RenderWindow& window, const std::vector<int>& array, int currentIndex, int minIndex) {
    window.clear(sf::Color::White);
    int n = array.size();
    for (int i = 0; i < n; ++i) {
        sf::RectangleShape bar(sf::Vector2f(barWidth, array[i]));
        bar.setPosition(i * (barWidth + barSpacing), windowHeight - array[i]);
        if (i == currentIndex)
            bar.setFillColor(sf::Color::Red);
        else if (i == minIndex)
            bar.setFillColor(sf::Color::Green);
        else
            bar.setFillColor(sf::Color::Black);
        window.draw(bar);
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(ANIMATION));
    window.display();
}

void selectionSort(std::vector<int>& array, sf::RenderWindow& window) {
    int n = array.size();

    for (int i = 0; i < n - 1; ++i) {
        int minIndex = i;

        for (int j = i + 1; j < n; ++j) {
            drawBarsSel(window, array, j, -1);
            if (array[j] < array[minIndex]) {
                minIndex = j;
                // Animate the selection process
            }
        }
        drawBarsSel(window, array, -1, minIndex);

        if (minIndex != i) {
            drawBarsSel(window, array, i, minIndex);
            std::swap(array[i], array[minIndex]);
            drawBarsSel(window, array, i, minIndex);
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(ANIMATION));
    }
}

void RunSelectionSort(){
    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Selection Sort Visualization");


    std::vector<int> array = generateRandomList();

    drawBarsSel(window, array, -1, -1); // Initial visualization

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Space) {
                    selectionSort(array, window);
                    drawBarsSel(window, array, -1, -1);
                    window.close();
                }
            }
        }
    }
}