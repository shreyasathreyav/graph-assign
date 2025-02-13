#pragma once
#include<vector>
#include<queue>
#include<iostream>
#include<set>
#include<algorithm>
// #define DEBUG

using namespace std;

class Edge;

class Node{
    public:
    Node(int id) 
    {
        this->id = id;
    }
    int id;
    vector<Node*> connected_nodes;
    vector<Edge*> connected_edges;

    void addNode(Node* n)
    {
        connected_nodes.push_back(n);
    }

    void addEdge(Edge* e)
    {
        connected_edges.push_back(e);
    }
};

class Edge{
    public:
    Edge(Node* n1, Node* n2, char label)
    {
        this->n1 = n1;
        this->n2 = n2;
        this->lable = label;
        n1->addEdge(this);
        n2->addEdge(this);
    }

    char lable;
    Node* n1;
    Node* n2;
};

class Graph{

    public:

    int numberOfVertices;
    int numberOfEdges;
    int numFinalVertices;
    Node* initial_vertex;
    vector<Node*> vertices;
    vector<Node*> final_vertices;
    vector<Edge*> edgeList;
    vector<vector<Edge*>> path_to_final_vertices;
    vector<vector<Edge*>> minimum_paths;

    Graph()
    {
        int numVertices; cin >> numVertices; 
        int numEdges; cin >> numEdges; 
        setNumberofVertices(numVertices);
        setNumberofEdges(numEdges);

#ifdef DEBUG
        printnumberofVertices();
        printnumberofEdges();
#endif
        while(numEdges--)
        {
            int n1_id; cin >> n1_id; 
            int n2_id; cin >> n2_id;
            Node* n1 = nullptr;
            Node* n2 = nullptr;
            for(auto i: vertices)
            {
                if(i->id == n1_id)
                {
                    n1 = i;
                }
                if(i->id == n2_id)
                {
                     n2 = i;
                }
            }
            if(n1 == nullptr)
            {
                n1 = new Node(n1_id);
                addVertex(n1);
            }
            if(n2 == nullptr)
            {
                n2 = new Node(n2_id);
                addVertex(n2);
            }

            char label; cin >> label;
            
            Edge* e = new Edge(n1, n2, label);
            
            n1->addNode(n2);
            n2->addNode(n1);

            addedges(e);
        }

        int initial_node; cin >> initial_node; 
        setInitialVertex(initial_node);

        int numFinal_vertices; cin >> numFinal_vertices;

        setnumFinalVertices(numFinal_vertices);

        while(numFinal_vertices--)
        {
        int vertex; cin >> vertex;
        addFinalVertices(vertex);
        }
#ifdef DEBUG
        printGraph();
        printInitalVertex();
        PrintfinalVertices();
        printConnectedVertices();

#endif
    }
    
    Graph(int numVertices, int numEdges, vector<tuple<int, int, char>> edges_with_labels, int source_node, vector<int> final_vertices_ids)
    {
        setNumberofVertices(numVertices);
        setNumberofEdges(numEdges);

        for (auto edge_info : edges_with_labels)
        {
            int n1_id = get<0>(edge_info);
            int n2_id = get<1>(edge_info);
            char label = get<2>(edge_info);

            Node* n1 = nullptr;
            Node* n2 = nullptr;

            for (auto node : vertices)
            {
                if (node->id == n1_id)
                {
                    n1 = node;
                }
                if (node->id == n2_id)
                {
                    n2 = node;
                }
            }

            if (n1 == nullptr)
            {
                n1 = new Node(n1_id);
                addVertex(n1);
            }
            if (n2 == nullptr)
            {
                n2 = new Node(n2_id);
                addVertex(n2);
            }

            Edge* e = new Edge(n1, n2, label);
            addedges(e);
            n1->addNode(n2);
            n2->addNode(n1);
        }

        setInitialVertex(source_node);
        setnumFinalVertices(final_vertices_ids.size());
        for (int id : final_vertices_ids)
        {
            addFinalVertices(id);   
        }
    }

    Graph(Node *initial_node, vector<Node*> final_vertices ,vector<Edge *> edges)
    {
        this->final_vertices = final_vertices;
        initial_vertex = initial_node;
        edgeList = edges;
    
        set<Node *> unique_nodes;
        for (auto edge : edges)
        {
            unique_nodes.insert(edge->n1);
            unique_nodes.insert(edge->n2);
        }
    
        for (auto node : unique_nodes)
        {
            addVertex(node);
        }
    
        setNumberofVertices(vertices.size());
        setNumberofEdges(edges.size());
    
        for (auto node : vertices)
        {
            if (is_final_vertex(node))
            {
                final_vertices.push_back(node);
            }
        }
        setnumFinalVertices(final_vertices.size());

    }


    void setNumberofEdges(int e)
    {
        numberOfEdges = e;
    }
    void setNumberofVertices(int v)
    {
        numberOfVertices = v;
    }
    void setnumFinalVertices(int num)
    {
        this->numFinalVertices = num;
    }
    void setLabel(char c, Edge* e)
    {
        e->lable = c;
    }
    void setInitialVertex(int id)
    {
        for(auto i: vertices)
        {
            if(i->id == id)
            {
                initial_vertex = i;
            }
        }
    }
    
    void addVertex(Node* vertex)
    {
        vertices.push_back(vertex);
    }
    
    void addFinalVertices(int id)
    {
        for(auto i: vertices)
        {
            if(i->id == id)
            {
                final_vertices.push_back(i);
            }
        }
    }
    void addedges(Edge* e)
    {
        edgeList.push_back(e);
    }

    void printnumberofVertices()
    {
        cout << "# of Vertices " << numberOfVertices <<endl;
    }

    void printnumberofEdges()
    {
        cout << "# of Edges " << numberOfEdges <<  endl;
    }

    void printGraph()
    {
        for(auto i: edgeList)
        {
            cout << "Edge : " << i->n1->id << "-" << i->n2->id << " -> "  << (char)i->lable << endl;
        }
    }

    void printLables(vector<Edge*> list)
    {
        for(auto i: list)
        {
            cout << i->lable << " ";
        }
        cout << endl;
    }

    void printInitalVertex()
    {
        cout << "Inital Vertex " << initial_vertex->id << endl;
    }
    void PrintfinalVertices()
    {
        cout << "Final Vertices ";
        for(auto i: final_vertices)
        {
            cout << i->id << " ";
        }
        cout << endl;
    }
    void printConnectedVertices()
    {
        cout << "Connected Vertices " << vertices.size() << endl;
        for(auto i: vertices)
        {
            cout << "For " << i->id << ": "; 
            for(auto j: i->connected_nodes)
            {
                cout << j->id << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    void print_all_paths() 
    {

        cout << "Paths found:" << endl;

        int path_number = 1;
        for (auto path : path_to_final_vertices) 
        {
            cout << "Path " << path_number++ << ": ";
            for (auto edge : path) 
            {
                cout << edge->lable << " ";
            }
            cout << endl;
        }
    }

    void print_shortest_paths() 
    {
        cout << "Shortest path:" << endl;

        int path_number = 1;
        for (auto path : minimum_paths) 
        {
            cout << "Path " << path_number++ << ": ";
            for (auto edge : path) 
            {
                cout << edge->lable << " ";
            }
            cout << endl;
        }
    }

    void printQueue(queue<pair<Node*, vector<Edge*>>> q) 
    {
        cout << "Queue State:" << endl;
        if (q.empty()) 
        {
            cout << "[Queue is Empty]" << endl;
            return;
        }

        while (!q.empty()) 
        {
            auto current_pair = q.front();
            Node* current_node = current_pair.first;
            vector<Edge*> path_so_far = current_pair.second;

            cout << "Node ID: " << current_node->id << " | Path Labels: ";
            for (auto edge : path_so_far) 
            {
                cout << edge->lable << " ";
            }
            cout << endl;

            q.pop();
        }
    }


    bool is_final_vertex(Node* node) 
    {
        for (auto i : final_vertices) 
        {
            if (i->id == node->id) 
            {
                return true;
            }
        }
        return false;
    }

    bool is_connected(Edge* edge, Node* node1, Node* node2) 
    {
        return (edge->n1 == node1 && edge->n2 == node2) || (edge->n2 == node1 && edge->n1 == node2);
    }

    void path_finder() 
    {
        queue<pair<Node*, vector<Edge*>>> q;
        
        q.push({initial_vertex, {}}); 
        while (!q.empty()) 
        {
#ifdef DEBUG
            cout << "Before " <<endl;
            printQueue(q);
#endif
            auto current_pair = q.front();
            Node* current_node = current_pair.first;
            vector<Edge*> path_so_far = current_pair.second;
            q.pop();

            if (is_final_vertex(current_node)) 
            {
                path_to_final_vertices.push_back(path_so_far);
            }

            set<int> visited_in_path;
            for (auto edge : path_so_far) 
            {
                visited_in_path.insert(edge->n1->id);
                visited_in_path.insert(edge->n2->id);
            }

            for (auto neighbor : current_node->connected_nodes) 
            {
                if (!visited_in_path.count(neighbor->id) || is_final_vertex(neighbor)) 
                {
                    for (auto edge : edgeList) 
                    {
                        if (is_connected(edge, current_node, neighbor)) 
                        {
                            vector<Edge*> new_path = path_so_far;
                            new_path.push_back(edge);
                            q.push({neighbor, new_path});
                            break;  
                        }
                    }
                }
            }
#ifdef DEBUG
            cout << "After " <<endl;
            printQueue(q);
#endif
        }
    }

    void shortest_paths() 
    {
        int shortest_size = path_to_final_vertices[0].size();
        minimum_paths.push_back(path_to_final_vertices[0]); 

        for (size_t i = 1; i < path_to_final_vertices.size(); ++i) 
        {
            int current_path_size = path_to_final_vertices[i].size();

            if (current_path_size < shortest_size) 
            {
                shortest_size = current_path_size;
                minimum_paths.clear();
                minimum_paths.push_back(path_to_final_vertices[i]);
            } 
            else if (current_path_size == shortest_size) 
            {
                minimum_paths.push_back(path_to_final_vertices[i]);
            }
        }
    }


    ~Graph()
    {
        for(int i = 0; i < edgeList.size(); i++)
        {
            delete edgeList[i];
            edgeList[i] = nullptr;
        }

        for(int i =0; i < vertices.size(); i++)
        {
            delete vertices[i];
            vertices[i] = nullptr;
        }
    }

};

