//============================================================================
// Name        : Pack
// Author      : Alexander Diop
// Created     : 12/10/20
// Version     : 0.0.1
// Project     : Graphs_IT279_
// Description : Class of bin packing algorithms
//============================================================================

#pragma once

#include <vector>
#include <string>
#include <fstream>

using namespace std;


class Pack{
private:
    int capacity;
    struct greater
    {
        template<class T>
        bool operator()(T const &a, T const &b) const { return a > b; }
    };
public:
    Pack(int capacity, vector<int> &items);

    int nextFit(vector<int> &items, ostream &outputStream);


    int firstFit(vector<int> &itemsList, string method, ostream &outputStream);


    int bestFit(vector<int> &itemsList, string method, ostream &outputStream);


    int offFirstFit(vector<int> &items, ostream &outputStream);


    int offBestFit(vector<int> &items, ostream &outputStream);
private:

    int getCapacity(vector<int> &bin);

    int getRemainder(vector<int> &bin);

    static void printBins(const string& method, vector<int> &items, vector< vector<int> > &bins, vector<int> &placements, ostream &outputStream);
};