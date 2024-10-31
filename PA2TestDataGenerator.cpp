#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

int main() {
    fstream fout;

    // cout << "Generating 20000..." << endl;
    fout.open("./inputs/P20000.in", ios::out);
    if (!fout.is_open()) {
        cout << "cannot open file." << endl; 
        return 1;
    }
    fout << 20000 << endl;
    for(int i = 0; i < 10000; i++) {
        fout << i << " " << 19999 - i << endl;
    }
    fout << 0;
    fout.close();

    // cout << "Generating 40000..." << endl;
    fout.open("./inputs/P40000.in", ios::out);
    if (!fout.is_open()) {
        cout << "cannot open file." << endl; 
        return 1;
    }
    fout << 40000 << endl;
    for(int i = 0; i < 10000; i++) {
        fout << i << " " << 19999 - i << endl;
    }
    for(int i = 20000; i < 30000; i++) {
        fout << i << " " << 59999 - i << endl;
    }
    fout << 0;
    fout.close();

    // cout << "Generating 80000..." << endl;
    srand(10);
    fout.open("./inputs/P80000.in", ios::out);
    if (!fout.is_open()) {
        cout << "cannot open file." << endl; 
        return 1;
    }
    fout << 80000 << endl;
    int node1[80000] = {};
    int line = 0;
    int curNode = 0;
    int setNode = 0;
    while(line != 40000) {
        if(node1[curNode] == 1) {
            curNode++;
            continue;
        }

        setNode = rand() % (80000 - curNode - 1) + curNode + 1;
        while(node1[setNode] == 1) {
            setNode = rand() % (80000 - curNode - 1) + curNode + 1;
        }
        node1[setNode] = 1;
        fout << curNode << " " << setNode << endl;
        curNode++;
        line++;
    }
    fout << 0;
    fout.close();

    // cout << "Generating 120000..." << endl;
    srand(20);
    fout.open("./inputs/P120000.in", ios::out);
    if (!fout.is_open()) {
        cout << "cannot open file." << endl; 
        return 1;
    }
    fout << 120000 << endl;
    int node2[120000] = {};
    line = 0;
    curNode = 0;
    setNode = 0;
    while(line != 60000) {
        if(node2[curNode] == 1) {
            curNode++;
            continue;
        }

        setNode = rand() % (120000 - curNode - 1) + curNode + 1;
        while(node2[setNode] == 1) {
            setNode = rand() % (120000 - curNode - 1) + curNode + 1;
        }
        node2[setNode] = 1;
        fout << curNode << " " << setNode << endl;
        curNode++;
        line++;
    }
    fout << 0;
    fout.close();

    // cout << "Generating 180000..." << endl;
    fout.open("./inputs/P180000.in", ios::out);
    if (!fout.is_open()) {
        cout << "cannot open file." << endl; 
        return 1;
    }
    fout << 180000 << endl;
    for(int i = 0; i < 90000; i++) {
        fout << i << " " << i + 90000 << endl;
    }
    fout << 0;
    fout.close();
}