#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void displayRun(int values[], int size) {
    bool inRun = false;

    for (int i = 0; i < size; i++) {
        if (i > 0 && values[i] == values[i + 1] && values[i] != values[i-1]) {
            if (!inRun) {
                cout << " (" << values[i] << " ";
                inRun = true;
            }
            else {
                cout << " " << values[i];
            }
        }
        if (i > 0 && values[i] != values[i + 1] && values[i] == values[i - 1]){
            if (!inRun) {
                cout << values[i] << ")";
                inRun = false;
            }
            cout << " " << values[i];
        }
    }

    //if (inRun) {
        //cout << ")";
    //}
}

bool hasRun(int values[], int size) {
    for (int i = 1; i < size; i++) {
        if (values[i] == values[i - 1]) {
            return true;  
        }
    }
    return false; 
}

int main() {
    const int size = 20;
    int dieValues[size];


    srand(time(nullptr));

    bool hasOneRun = false;

    while (!hasOneRun) {
       
        for (int i = 0; i < size; i++) {
            dieValues[i] = rand() % 6 + 1;
        }

       
        if (hasRun(dieValues, size)) {
            hasOneRun = true;
            cout << "Die values with runs encapsulated:" << endl;
            displayRun(dieValues, size);
            cout << endl << "The sequence has a run." << endl;
        }
    }

    return 0;
}