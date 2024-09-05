#include <iostream>
#include <vector>
#include <iomanip>
#include <sstream>
#include <string>

using namespace std;

struct Process {
    int id;
    int size;
    bool allocated = false;
    int blockIndex = -1;
};

struct MemoryBlock {
    int size;
    bool allocated = false;
    int processIndex = -1;
};

int main() {
    string input;
    getline(cin, input);
    int numBlocks = stoi(input);

    vector<MemoryBlock> blocks(numBlocks);

    getline(cin, input);
    stringstream ss(input);
    for (int i = 0; i < numBlocks; i++) {
        int blockSize;
        ss >> blockSize;
        blocks[i].size = blockSize;
    }

    getline(cin, input);
    int numProcesses = stoi(input);

    vector<Process> processes(numProcesses);

    getline(cin, input);
    stringstream ss2(input);
    for (int i = 0; i < numProcesses; i++) {
        int processSize;
        ss2 >> processSize;
        processes[i].id = i;
        processes[i].size = processSize;
    }

    for (int i = 0; i < numProcesses; i++) {
        bool allocated = false;
        for (int j = 0; j < numBlocks; j++) {
            if (!blocks[j].allocated && processes[i].size <= blocks[j].size) {
                blocks[j].allocated = true;
                blocks[j].processIndex = i;
                processes[i].allocated = true;
                processes[i].blockIndex = j;
                allocated = true;
                break;
            }
        }
        if (!allocated) {
            cout << "Process " << processes[i].id << " (size: " << processes[i].size << ") could not be allocated.\n";
        }
    }

    cout << "\nMemory Allocation:\n\n";
    cout << setw(15) << left << "Process_no:"
         << setw(15) << left << "Process_size:"
         << setw(15) << left << "Block_no:"
         << setw(15) << left << "Block_size:" << endl;

    for (int i = 0; i < numProcesses; i++) {
        cout << setw(15) << left << processes[i].id
             << setw(15) << left << processes[i].size
             << setw(15) << left << (processes[i].allocated ? to_string(processes[i].blockIndex) : "-")
             << setw(15) << left << (processes[i].allocated ? to_string(blocks[processes[i].blockIndex].size) : "-")
             << endl;
    }

    return 0;
}
