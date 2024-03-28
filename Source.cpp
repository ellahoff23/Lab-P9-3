#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void displayRun(int values[], int size) {
    bool inRun = false;

    for (int i = 0; i < size; i++) {
        if (i > 0 && values[i] == values[i - 1]) {
            if (!inRun) {
                cout << "(" << values[i];
                inRun = true;
            }
            else {
                cout << " " << values[i];
            }
        }
        else {
            if (inRun) {
                cout << ")";
                inRun = false;
            }
            cout << " " << values[i];
        }
    }

    if (inRun) {
        cout << ")";
    }
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

    for (int i = 0; i < size; i++) {
        dieValues[i] = rand() % 6 + 1;
    }

    cout << "Die values with runs encapsulated:" << endl;
    displayRun(dieValues, size);
    cout << endl;

    // Check if a run is present and print the result
    if (hasRun(dieValues, size)) {
        cout << "The sequence has a run." << endl;
    }
    else {
        cout << "The sequence does not have a run." << endl;
    }

    return 0;
}