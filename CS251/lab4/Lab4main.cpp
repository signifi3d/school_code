/*******************
 * NAME: Blake Eakin
 * ASSIGNMENT: Lab 4
 * SOURCES: None
 ******************/

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>


class WeightedGraph {
    public:
        WeightedGraph(int vertices = 0);
        ~WeightedGraph();
        void insertNewRow(std::string);//Space delimited ints in a string
        int numOfVertices();//How many vertices this graph contains
        int weightAt(int, int);//Retrieve any weight at any point (row, col)
        void updateEdge(int, int, int);//Change weight of edge
        int totalWeight(); //Returns the sum of all edge weights
        WeightedGraph prims();//Enacts prims algorithm on the WeightedGraph
        int dijkstraLength(int, int);
    private:
        std::vector<std::vector<int>> graph;
};


int main() {

    std::string inputBuffer;
    WeightedGraph inputGraph, mST;

    std::cout << "Blake Eakin" << std::endl;

    //Take in first line of WAM to determine # of vertices in graph
    std::cout << "Enter WAM please." << std::endl;
    std::getline(std::cin, inputBuffer);
    inputGraph.insertNewRow(inputBuffer);

    //Grab the remaining rows of the WAM based on input of first line
    for (int i = 0; i < inputGraph.numOfVertices()-1; ++i) {
        std::getline(std::cin, inputBuffer);
        inputGraph.insertNewRow(inputBuffer);
    }

    //Output the original WAM, standard double looped matrix output
    std::cout << "The WAM entered is: " << std::endl;
    for (int i = 0; i < inputGraph.numOfVertices(); ++i) {
        for (int j = 0; j < inputGraph.numOfVertices(); ++j) {
            std::cout << std::setw(4) << inputGraph.weightAt(i, j) << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
/*
    mST = inputGraph.prims(); //Run Prim's Algorithm and output

    std::cout << "The output from Prim's algorithm: " << std::endl;
    for (int i = 0; i < mST.numOfVertices(); ++i) {
        for (int j = 0; j < mST.numOfVertices(); ++j) {
            std::cout << std::setw(4) << mST.weightAt(i, j) << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "The total weight of the graph is " << mST.totalWeight() 
        << std::endl;
*/
    std::cout << "The shortest length from 6 to 1 is: " << inputGraph.dijkstraLength(6,1) << std::endl;

    return 0;
}


WeightedGraph::WeightedGraph(int vertices) {
    if ( vertices > 0 ) {
        this->graph.resize(vertices);

        for (int i = 0; i < vertices; ++i) {
            this->graph[i].resize(vertices, 0); //Initialize values to 0
        }
    }
}


WeightedGraph::~WeightedGraph() {

}


//Use a stringstream for simpler extraction from input string
void WeightedGraph::insertNewRow(std::string newRow) {
    std::vector<int> rowHolder;
    int intBuffer;
    std::stringstream newRowStream(newRow);

    //Add each int into the rowHolder vector
    while ( newRowStream >> intBuffer ) {
        rowHolder.push_back(intBuffer);
    }

    //Then insert that as a new row into the matrix
    this->graph.push_back(rowHolder);
}


int WeightedGraph::numOfVertices() {
    //If there aren't any rows yet then # of vertices isn't known
    if ( this->graph.size() == 0 ) {
        return 0;
    } else { //Otherwise it's just the size of any of the rows
        return this->graph[0].size();
    }
}


int WeightedGraph::weightAt(int x, int y) {
    return this->graph[x][y];
}


void WeightedGraph::updateEdge(int v1, int v2, int weight) {
    this->graph[v1][v2] = weight;
    this->graph[v2][v1] = weight; //Change weights both since undirected
}


int WeightedGraph::totalWeight() {
    int totalWeight = 0;

    for (int i = 0; i < this->graph.size(); ++i) {
        //Only need to sum the weights on one side since undirected
        for (int j = i; j < this->graph.size(); ++j) {
            totalWeight += this->graph[i][j];    
        }
    }

    return totalWeight;
}


WeightedGraph WeightedGraph::prims() {
    //Not so fast buddy
}


int WeightedGraph::dijkstraLength(int from, int to) {
    bool F[this->numOfVertices()] = { false };
    bool V[this->numOfVertices()] = { false };
    int L[this->numOfVertices()];
    int v = from;

    for (int i = 0; i < this->numOfVertices(); ++i) {
        L[i] = 9999;
    }

    F[from] = true;
    V[from] = true;
    L[from] = 0;

    while ( !V[to] ) {
        if ( F[v] ) {
            F[v] = false;
        }

        for ( int i = 0; i < this->numOfVertices(); ++i) {
            if ( this->graph[v][i] > 0 && !V[i] ) {
                if ( L[v] + this->graph[v][i] < L[i] ) {
                    L[i] = L[v] + this->graph[v][i];
                }

                if ( !F[i]) {
                    F[i] = true;
                }
            }

        }

        int minWeight = 9999;
        int minIndex = 0;

        for ( int i = 0; i < this->numOfVertices(); ++i ) {
            if ( F[i] ) {
                if ( L[i] < minWeight ) {
                    minWeight = L[i];
                    minIndex = i;
                }
            }
        }

        V[minIndex] = true;
        v = minIndex;
    }

    return L[to];
}
