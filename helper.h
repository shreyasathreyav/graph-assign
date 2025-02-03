#include <iostream>

#include "Graph.h"

// Solution for question 2

vector<set<string>> stringify_paths(Graph *g)
{
    vector<set<string>> result;
    for (auto path : g->path_to_final_vertices)
    {
        set<string> labels;
        string path_str;
        for (auto edge : path)
        {
            path_str += edge->lable;
        }
        labels.insert(path_str);
        result.push_back(labels);
    }
    // cout << "Content of result:" << endl;
    // for (auto path_set : result)
    // {
    //     for (auto path_str : path_set)
    //     {
    //         cout << path_str << " ";
    //     }
    //     cout << endl;
    // }
    return result;
}

vector<string> findIntersection(vector<set<string>> all_paths)
{

    set<string> common_items = all_paths[0];

    for (size_t i = 1; i < all_paths.size(); ++i)
    {
        set<string> temp;
        for (const auto &item : common_items)
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

    // for(auto i: common_items)
    // {
    //     cout << i << " ";
    // }
    // cout << endl;

    return vector<string>(common_items.begin(), common_items.end());
}

unordered_map<char, pair<int, int>> createCommonLabelMap(vector<Graph *> graphList)
{
    vector<set<char>> all_labels;
    for (auto g : graphList)
    {
        set<char> labels;
        for (auto edge : g->edgeList)
        {
            labels.insert(edge->lable);
        }
        all_labels.push_back(labels);
    }

    set<char> common_labels = all_labels[0];
    for (size_t i = 1; i < all_labels.size(); ++i)
    {
        set<char> temp;
        for (auto label : common_labels)
        {
            if (all_labels[i].count(label))
            {
                temp.insert(label);
            }
        }
        common_labels = temp;
        if (common_labels.empty())
        {
            break;
        }
    }

    unordered_map<char, pair<int, int>> label_to_nodes;
    for (auto edge : graphList[0]->edgeList)
    {
        if (common_labels.count(edge->lable))
        {
            label_to_nodes[edge->lable] = {edge->n1->id, edge->n2->id};
        }
    }

    return label_to_nodes;
}

Graph* constructIntersectionGraph(vector<Graph*> graphList)
{
    unordered_map<char, pair<int, int>> label_to_nodes = createCommonLabelMap(graphList);
    set<int> unique_nodes;
    vector<tuple<int, int, char>> edges_with_labels;

    for (auto item : label_to_nodes)
    {
        char label = item.first;
        int node1 = item.second.first;
        int node2 = item.second.second;

        unique_nodes.insert(node1);
        unique_nodes.insert(node2);

        edges_with_labels.push_back({node1, node2, label});
    }

    int number_of_vertices = unique_nodes.size();
    int number_of_edges = edges_with_labels.size();

    int source_node = graphList[0]->initial_vertex->id;
    vector<int> final_vertices_ids;
    for (auto v : graphList[0]->final_vertices)
    {
        final_vertices_ids.push_back(v->id);
    }

    Graph* newGraph = new Graph(number_of_vertices, number_of_edges, edges_with_labels, source_node, final_vertices_ids);

    return newGraph;
}