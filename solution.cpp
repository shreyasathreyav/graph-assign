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
    // cout << "Number of Graphs: "<< numGraphs <<endl; 
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

    // cout << "Size of the intersection set "<< intersection_paths.size() << endl;
    // for(auto i: intersection_paths) cout << i << " ";
    // cout << endl;

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

void solution2b()
{
    int numGraphs; cin >> numGraphs;
    // cout << "Number of Graphs: "<< numGraphs <<endl; 
    vector<Graph*> graphList;
    while(numGraphs--)
    {
        Graph* g = new Graph();
        g->path_finder();
        g->shortest_paths();
        graphList.push_back(g);
    }

    Graph* intersection_Graph = constructIntersectionGraph(graphList);

    intersection_Graph->path_finder();
    
    intersection_Graph->shortest_paths();

    intersection_Graph->print_shortest_paths();

    // cout << endl << "Common Labels are : ";
    // for(auto i: commonLables)
    // cout << i.first <<" ";

    // cout <<endl;
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

    // freopen("input.txt", "r", stdin); // to run question 1
    freopen("input1.txt", "r", stdin); // to run question 2
    
    int question; cin >> question;

    int testcases;
    cin >> testcases;

    
    while(testcases--)
    {
        if(question == 1)
        {
            solution1();
        }
        else
        {
            solution2a();
            solution2b();
        }
    }
}


