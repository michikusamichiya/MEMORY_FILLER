#include <iostream>
#include <vector>
#include <chrono>
#include <thread>

void countdown(int seconds) {
    for (int i = seconds; i > 0; --i) {
        std::cout << "Continue " << i << "left..." << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << "\x1B[1A";
        std::cout << "\x1B[K";
    }
    std::cout << "Starting..." << std::endl;
}

void StackMemory(char option) {
    std::vector<int64_t*> memory_blocks;
    long long block_count = 0;

    try {
        while (true) {
            int64_t* block = new int64_t[104857600];
            memory_blocks.push_back(block);
            block_count++;
            if (option == 'y') {
                std::cout << "Memory block: " << "1Mib * " << block_count << std::endl;
            }
        }
    }
    catch (std::bad_alloc& e) {
        std::cerr << "Memory Error:  " << e.what() << std::endl;
        std::cerr << "Reserved memory blocks: " << block_count << std::endl;
        countdown(10);
    }
}

int main() {
    using namespace std;
    char it;
    cout << "<WARNING>This program consumes memory very quickly. Do you want to continue?(y,n): ";
    cin >> it;
    if (it == 'y') {
        cout << "Show stuck memory during execution?(y,n): ";
        char opt;
        cin >> opt;
        cout << "Press Ctrl + c to stop this program. However, it will take some time to finish." << endl;
        countdown(5);
        StackMemory(opt);
    }
    return 0;
}
