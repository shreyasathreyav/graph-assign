#include <iostream>

#include "Graph.h"

// Solution for question 2

vector<set<string>>  stringify_paths(Graph* g) 
{
    vector<set<string>> result;

    for (auto path : g->path_to_final_vertices) 
    {

        set<string> labels;
        for (auto edge : path) 
        {
            labels.insert(string(1, edge->lable));
        }
        // for(auto i: labels) cout << i << " ";
        // cout << endl;
        result.push_back(labels);
    }

    return result;
}

    vector<string> findIntersection(vector<set<string>> all_paths)
    {

        set<string> common_items = all_paths[0];

        for (size_t i = 1; i < all_paths.size(); ++i)
        {
            set<string> temp;
            for (const auto& item : common_items)
            {
                if (all_paths[i].count(item))
                {
                    temp.insert(item);
                }
            }
            common_items = temp; 

            if (common_items.empty())
            {
                break;
            }
        }

        for(auto i: common_items)
        {
            cout << i << " ";
        }
        cout << endl;


        return vector<string>(common_items.begin(), common_items.end());
    }

