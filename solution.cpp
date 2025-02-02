#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include "Graph.h"
#include "helper.h"

#define DEBUG
using namespace std;

// Doing string matching 
void solution2a()
{
    int numGraphs; cin >> numGraphs;
    cout << "Number of Graphs: "<< numGraphs <<endl; 
    vector<Graph*> graphList;
    while(numGraphs--)
    {
        Graph* g = new Graph();
        g->path_finder();
        g->shortest_paths();
        graphList.push_back(g);
    }


    vector<set<string>> all_paths;
    
    for (auto g : graphList) 
    {
        set<string> paths_in_g;
        auto paths = stringify_paths(g);
        
        for (auto path : paths) 
        {
            paths_in_g.insert(path.begin(), path.end());
        }

        all_paths.push_back(paths_in_g);
    }


    vector<string> intersection_paths =  findIntersection(all_paths);


    string smallest_string = intersection_paths[0];
    // cout << smallest_string <<endl;
    for (string path : intersection_paths) 
    {
        if(path.size() < smallest_string.size()) 
        {
            smallest_string = path;
        }
    }

    cout << "Shortest Path :" << smallest_string << endl;
}



void solution1()
{
    Graph* g = new Graph();

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

    // freopen("input.txt", "r", stdin);
    freopen("input1.txt", "r", stdin);
    
    int testcases;
    cin >> testcases;

    cout << "Testcases : " << testcases <<endl;
    
    while(testcases--)
    {
        // solution1();
        solution2a();
    }
}


