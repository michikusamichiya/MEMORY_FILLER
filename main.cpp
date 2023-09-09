#include <iostream>
#include <vector>
using namespace std;

void memoryArea() {
    vector<int*> memorys;
    int* p = new int[10000000];
    try {
        while (true) {
            for (int i = 0; i < 100000; i++) {
                int* p = new int[10000000];
                memorys.push_back(p);
            }
        }
    }
    catch (bad_alloc& e) {
        memoryArea();
    }
}

int main() {
    vector<int*> memory_hogs;
    cout << "This program consumes memory very quickly. Do you want to continue?(y,n): ";
    char it;
    cin >> it;
    cout << "Press Ctrl + c to stop this program. However, it will take some time to finish.\n";
    if (it != 'y') return 0;
    memoryArea();

    return 0;
}
