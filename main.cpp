#include "bfs.h"
#include "quicksort.h"
#include "squareSort.h"

using namespace std;

void promptUser(){
    cout<<"Welcome to Algo Visualizer\n";
    cout<<"Press SPACE to start the animation\n";
    cout<<"1.Bubble sort\n";
    cout<<"2.Quick sort\n";
    cout<<"3.Insertion sort\n";
    cout<<"4.Selection sort\n";
    cout<<"5.BFS\n";
    cout<<"6.Exit\n";
    int exit = 6;
    int number = 0;
    while(number != exit){
        cout<<"Enter the number:\n";
        cin>>number;
        switch (number) {
            case 1:
                RunBubbleSort();
                break;
            case 2:
                RunQuickSort();
                break;
            case 3:
                RunInsertionSort();
                break;
            case 4:
                RunSelectionSort();
                break;
            case 5:
                bfsVisualizer();
                break;
            case 6:
                cout << "Exiting...\n";
                break;
            default:
                cout << "No other option currently :(\n";
                break;
        }
    }
}

int main() {
    
    promptUser();

    return 0;
}
