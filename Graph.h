#pragma once
#include<vector>
#include<iostream>
#include<set>
// #define DEBUG

using namespace std;

class Edges;

class Node{
    public:
    Node(int id) 
    {
        this->id = id;
    }
    int id;
    set<Node*> connected_nodes;
    void addNode(Node* n)
    {
        connected_nodes.insert(n);
    }
};

class Edge{
    
    public:
    
    Edge(Node* n1, Node* n2)
    {
        this->n1 = n1;
        this->n2 = n2;
    }

    char lable;
    Node* n1;
    Node* n2;
};

class Graph{

    public:

    int numberOfVertices;
    int numberOfEdges;
    int numFinalV;
    Node* initial_vertex;
    vector<Node*> vertices;
    vector<Node*> final_vertices;
    vector<Edge*> edgeList;

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
            
            Edge* e = new Edge(n1, n2);
            
            n1->addNode(n2);
            n2->addNode(n1);

            addedges(e);
            char label; cin >> label;
            setLabel(label, e);
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
        this->numFinalV = num;
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

    vector<Edge*> minimum_path()
    {
        
    }


};

