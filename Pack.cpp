//============================================================================
// Name        : Pack
// Author      : Alexander Diop
// Created     : 12/10/20
// Version     : 0.0.1
// Project     : Graphs_IT279_
// Description : Implementation of bin-packing algorithms
//============================================================================

#include "Pack.h"
#include <utility>
#include <algorithm>
//#include <fstream>
#include <iostream>

Pack::Pack(int capacity, vector<int> &items) {
    this->capacity = capacity;
}

int Pack::nextFit(vector<int> &items, ostream &outputStream) {

    vector< vector<int> > bins;//the the items and the total weight of each bin
    vector<int>placements(items.size());

    int binsUsed = 1;
    //current bin capacity
    int binCapacity = capacity;
    vector <int> currBin;

    // Place items one by one
    for (int i = 0; i < items.size(); i++){

        // If the value of the current item is too large for current bin
        if (items[i] > binCapacity){
            currBin.push_back(getCapacity(currBin));//add the capacity value to the end of the bin list
            bins.push_back(currBin);
            currBin.clear();// Create a new bin
            currBin.push_back(items[i]);
            binsUsed = binsUsed + 1;
            binCapacity = capacity - items[i];
            placements[i] = binsUsed - 1;
        }
        else{
            currBin.push_back(items[i]);
            binCapacity -= items[i];
            placements[i] = binsUsed - 1;
        }
    }

    currBin.push_back(getCapacity(currBin));//add the capacity value to the end of the bin list
    bins.push_back(currBin);
    printBins("Next Fit", items, bins, placements, outputStream);
    return binsUsed;
}

int Pack::firstFit(vector<int> &itemsList, string method, ostream &outputStream) {

    int binsUsed = 0;
    vector< vector<int> > bins;//the the items and the total weight of each bin
    vector <int> newBin;
    vector<int> placements(itemsList.size());
    bool placed;

    // Place items one by one
    for (int i = 0; i < itemsList.size(); i++){

        int binNum = 0;
        placed = false;

        while(!placed){
            //if the current bin exists
            if(binNum < bins.size()){
                //if the current bin cant fit the current item
                if(itemsList[i] > getRemainder(bins[binNum])){
                    //move to the next bin
                    binNum++;
                }else{//place the item in the bin
                    bins[binNum].push_back(itemsList[i]);
                    placements[i] = binNum;
                    placed = true;
                }
            } else{//if no bin that can fit this item exists already
                newBin.clear();
                bins.push_back(newBin);
                binsUsed++;
                bins[binNum].push_back(itemsList[i]);
                placements[i] = binNum;//may have fault logic
                placed = true;
            }
        }
    }

    for(int i = 0; i < bins.size(); i++){
        bins[i].push_back(getCapacity(bins[i]));//add the capacity value to the end of the bin list
    }

    printBins(method, itemsList, bins, placements, outputStream);
    return binsUsed;
}

int Pack::bestFit(vector<int> &itemsList, string method, ostream &outputStream) {
    int binsUsed = 0;
    vector< vector<int> > bins;//the the items and the total weight of each bin
    vector <int> newBin;
    vector<int> placements(itemsList.size());
    int best = 0;
    bool foundPotential;
    bool foundBest;

    // Place items one by one
    for (int i = 0; i < itemsList.size(); i++){

        int binNum = 0;
        foundPotential = false;
        foundBest = false;
        int valToBeat = 100;

        while(!foundBest){
            //if the current bin exists
            if(binNum < bins.size()){
                //if the current bin cant fit the current item
                if(itemsList[i] > getRemainder(bins[binNum])){
                    //move to the next bin
                    binNum++;
                }else{//found a potential best fit
                    //if this fit is better than the one we have already
                    if((getRemainder(bins[binNum]) - itemsList[i]) < valToBeat){
                        best = binNum;
                        valToBeat = getRemainder(bins[binNum]) - itemsList[i];
                        foundPotential = true;
                    }
                    binNum++;
                }
            } else{
                //if no good fits were found
                if(!foundPotential){
                    newBin.clear();
                    bins.push_back(newBin);// Create a new bin
                    binsUsed++;
                    bins[binNum].push_back(itemsList[i]);
                    placements[i] = binNum;//may have fault logic
                    foundBest = true;
                    placements[i] = binNum;
                }else{
                    bins[best].push_back(itemsList[i]);
                    foundBest = true;
                    placements[i] = best;
                }
            }
        }
    }

    for(int i = 0; i < bins.size(); i++){
        bins[i].push_back(getCapacity(bins[i]));//add the capacity value to the end of the bin list
    }

    printBins(method, itemsList, bins, placements, outputStream);
    return binsUsed;
}

int Pack::offFirstFit(vector<int> &items, ostream &outputStream) {
    vector<int> sortedItems(items.size());
    sortedItems = items;
    sort(sortedItems.begin(), sortedItems.end(), greater());

    return firstFit(sortedItems, "First Fit Decreasing", outputStream);
}

int Pack::offBestFit(vector<int> &items, ostream &outputStream) {
    vector<int> sortedItems(items.size());
    sortedItems = items;
    sort(sortedItems.begin(), sortedItems.end(), greater());

    return bestFit(sortedItems, "Best Fit Decreasing", outputStream);
}

int Pack::getCapacity(vector<int> &bin) {
    int cap = 0;
    for(int i = 0; i < bin.size(); i++){
        cap = cap + bin[i];
    }
    return cap;
}

int Pack::getRemainder(vector<int> &bin) {
    int rem = capacity;
    for(int i = 0; i < bin.size(); i++){
        rem = rem - bin[i];
    }
    return rem;
}


void Pack::printBins(const string& method, vector<int> &items, vector< vector<int> > &bins, vector<int> &placements, ostream &outputStream) {

    outputStream << method <<":\n";

    for(int i = 0; i < items.size(); i++){
        outputStream << items[i] << " " << placements[i]<<endl;
    }

    outputStream <<endl;

    for(int i = 0; i < bins.size(); i++){
        int item = 0;
        while(item < bins[i].size() && bins[i][item]){
            if(item != 0){
                outputStream << " ";
            }
            outputStream <<bins[i][item];
            item++;
        }
        outputStream <<endl;
    }
    outputStream <<endl;//single empty line at the end
}



