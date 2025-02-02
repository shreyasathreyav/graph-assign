#include <iostream>
#include <vector>
#include <unordered_map>

#include "Graph.h"

#define DEBUG

using namespace std;


void solution()
{
    Graph* g = new Graph();
    // g->minimum_path();ss
    g->path_finder();

    g->print_all_paths();
    g->shortest_paths();
    g->print_shortest_paths();

    delete g;
    g = nullptr;
    cout << endl;
}


int main()
{

    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    int testcases;
    cin >> testcases;
    
    while(testcases--)
    {
        solution();
    }
}


