#pragma once
#include<vector>
#include<iostream>

using namespace std;

class Node{
    public:
    Node(int id) 
    {
        this->id = id;
    }
    int id;
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
    vector<Edge*> edgeList;

    Graph()
    {
        numberOfEdges = 0;
        numberOfVertices = 0;
        edgeList = {};
    }
    void setNumberofEdges(int numberofEdges)
    {
        this->numberOfEdges;
    }
    void setNumberofVertices(int numberofVertices)
    {
        this->numberOfVertices;
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
            cout << "Edge : " << i->n1->id << "-" << i->n2->id << " -> "  << i->lable << endl;
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

    vector<Edge*> minimum_path();





};

