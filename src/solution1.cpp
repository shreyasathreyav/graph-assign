#include <iostream>
#include <vector>
#include <unordered_map>
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


    // vector<Edge*> minimum_path()
    // {
        

    // }
    // vector<Edge*> minimum_path_labels()
    // {
    // }


    int numberOfVertices;
    int numberOfEdges;
    vector<Edge*> edgeList;
};


// };







void solution1()
{
    
    Graph g;
}


int main()
{

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int testcases;
    cin >> testcases;
    
    while(testcases--)
    {
        solution1();
    }
}


