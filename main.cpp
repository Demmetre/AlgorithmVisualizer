#include "bfs.h"
#include "quicksort.h"
#include "bubble.h"

using namespace std;

void promptUser(){
    cout<<"Welcome to Algo Visualizer\n";
    cout<<"Press SPACE to start the animation\n";
    cout<<"1.Bubble sort\n";
    cout<<"2.Quick sort\n";
    cout<<"3.BFS\n";
    cout<<"4.Exit\n";
    int number = 0;
    while(number != 4){
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
                bfsVisualizer();
                break;
            case 4:
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
