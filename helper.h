#include <iostream>
#include <map>
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
        for (auto item : common_items)
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

    // for(auto label : common_labels)
    // {
    //     cout << label << " ";
    // }
    // cout << endl;

    unordered_map<char, pair<int, int>> label_to_nodes;
    for (auto edge : graphList[0]->edgeList)
    {
        if (common_labels.count(edge->lable))
        {
            label_to_nodes[edge->lable] = {edge->n1->id, edge->n2->id};
        }
    }

    // for(auto item : label_to_nodes)
    // {
    //     cout << item.first << ": (" << item.second.first << ", " << item.second.second << ") ";
    // }
    // cout << endl;
    return label_to_nodes;
}

Graph *constructIntersectionGraph(vector<Graph *> graphList)
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

    Graph *newGraph = new Graph(number_of_vertices, number_of_edges, edges_with_labels, source_node, final_vertices_ids);

    return newGraph;
}

map<char, vector<vector<Node *>>> findCommonEdgeLabels(vector<vector<Node *>> current_nodes)
{
    set<char> running_common_labels;
    map<char, vector<vector<Node *>>> label_to_next_nodes;

    for (auto node : current_nodes[0])
    {
        for (Edge *edge : node->connected_edges)
        {
            if (edge->n1 == node)
            {
                running_common_labels.insert(edge->lable);
                label_to_next_nodes[edge->lable].push_back({edge->n2});
            }
        }
    }

    // Finding intersection of labels from each graph
    for (int i = 1; i < current_nodes.size(); ++i)
    {
        set<char> labels_in_current_graph;
        map<char, vector<Node *>> next_nodes_in_current_graph;

        for (auto node : current_nodes[i])
        {
            for (Edge *edge : node->connected_edges)
            {
                if (edge->n1 == node)
                {
                    labels_in_current_graph.insert(edge->lable);
                    next_nodes_in_current_graph[edge->lable].push_back(edge->n2);
                }
            }
        }
        
        //updating common lables
        for (auto it = running_common_labels.begin(); it != running_common_labels.end(); )
        {
            char label = *it;
            if (labels_in_current_graph.count(label))
            {
                label_to_next_nodes[label].push_back(next_nodes_in_current_graph[label]);
                ++it;
            }
            else
            {
                label_to_next_nodes.erase(label);
                it = running_common_labels.erase(it);
            }
        }
    }

    // for (auto [label, nodes_list] : label_to_next_nodes)
    // {
    //     cout << "Label: " << label << " -> Next Nodes: ";
    //     for (auto nodes : nodes_list)
    //     {
    //         cout << "[";
    //         for (auto node : nodes)
    //         {
    //             cout << node->id << " ";
    //         }
    //         cout << "] ";
    //     }
    //     cout << endl;
    // }



    return label_to_next_nodes;
}

bool isFinalnode(vector<Node*> nodes, Graph* g)
{
    for (auto node : nodes)
    {
        if (g->is_final_vertex(node))
        {
            return true;
        }
    }
    return false;
}

vector<vector<int>> getNodeIds(vector<vector<Node *>> nodes)
{
    vector<vector<int>> ids;
    for (auto node_group : nodes)
    {
        vector<int> group_ids;
        for (auto node : node_group)
        {
            group_ids.push_back(node->id);
        }
        ids.push_back(group_ids);
    }
    return ids;
}

Graph *createIntersectionGraph(vector<Graph *> graph_list)
{

    Node *initial_node = new Node(1);
    vector<Node*> final_vertices;
    vector<Edge *> new_edges;
    vector<vector<Node *>> nodes_in_queue;
    queue<pair<vector<vector<Node *>>, Node*>> q;
    set<vector<vector<int>>> visited;

    bool destination_reached = false;

    for (Graph *g : graph_list)
    {
        vector<Node *> temp;
        temp.push_back(g->initial_vertex);
        nodes_in_queue.push_back(temp);
    }
    q.push(make_pair(nodes_in_queue, initial_node));

    int node_id_counter = 2;

    while (!q.empty())
    {
        auto [current_nodes, current_intersection_node] = q.front();

        q.pop();

        if (isFinalnode(current_nodes[0], graph_list[0]))
        {
            destination_reached = true;
            final_vertices.push_back(current_intersection_node);
        }

        map<char, vector<vector<Node *>>> common_labels = findCommonEdgeLabels(current_nodes);

        //cannot proceed && destination not reached
        if (common_labels.empty() && destination_reached == false) 
        {
            return nullptr;
        }
        else
        {
            //for each label create a new node
            if(common_labels.empty() == false)
            {

                for ( auto [label, next_nodes] : common_labels)
                {
                    vector<vector<int>> next_node_ids = getNodeIds(next_nodes);

                    if (visited.count(next_node_ids))
                    {
                        continue; 
                    }

                    visited.insert(next_node_ids);



                    Node* new_node = new Node(node_id_counter++);
                    new_edges.push_back(new Edge(current_intersection_node, new_node, label));
                    
                    current_intersection_node->addNode(new_node);
                    new_node->addNode(current_intersection_node);
                    
                    q.push({next_nodes, new_node});
                }
            }
            else
            {
                //cannot proceed 
                break;
            }
        }
    }
    if (new_edges.empty()) 
    {
        return nullptr;
    }
    else
    {
        // cout  << initial_node->id <<endl; 
        return new Graph(initial_node,final_vertices,  new_edges);
    }
}