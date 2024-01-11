#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
using namespace std;
void bubbleSort(std::vector<int>& arr) {
    int n = arr.size();
    bool swapped;
    do {
        swapped = false;
        for (int i = 0; i < n - 1; ++i) {
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
                swapped = true;
            }
        }
    } while (swapped);
}

int main() {
    const int vectorSize = 100000;


    vector<int> data(vectorSize);
    for (int i = 0; i < vectorSize; ++i) {
        data[i] = vectorSize - i;
    }


    auto bubbleStart = chrono::high_resolution_clock::now();
    bubbleSort(data);
    auto bubbleEnd = chrono::high_resolution_clock::now();
    chrono::duration<double> bubbleDuration = bubbleEnd - bubbleStart;


    for (int i = 0; i < vectorSize; ++i) {
        data[i] = vectorSize - i;
    }


    auto stlStart = std::chrono::high_resolution_clock::now();
    sort(data.begin(), data.end());
    auto stlEnd = std::chrono::high_resolution_clock::now();
    chrono::duration<double> stlDuration = stlEnd - stlStart;


    cout << "Bubble Sort Execution Time: " << bubbleDuration.count() << " seconds\n";
    cout << "STL Sort Execution Time: " << stlDuration.count() << " seconds\n";

    
}