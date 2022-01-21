//============================================================================
// Name        : GenerateBins
// Author      : Alexander Diop
// Created     : 12/10/20
// Version     : 0.0.1
// Project     : Graphs_IT279_
// Description : Program to perform a 10 bin packing experiment
//============================================================================

#include <iostream>
//#include <fstream>
//#include <iostream>
#include <algorithm>
#include <iomanip>
#include "Pack.h"

//generate sequences of 100 random integers between 1 and 100
//  (instead of the traditional 0.01 to 1).
vector<int> generateItems(int randSeed);

int main(int argc, char **argv) {

    int nextWinsONL = 0;
    int firstWinsONL = 0;
    int bestWinsONL = 0;
    int nextWins = 0;
    int firstWins = 0;
    int bestWins = 0;
    int offFirstWins = 0;
    int offBestWins = 0;

    int nextBinsTotal = 0, firstBinsTotal = 0, bestBinsTotal = 0, FFDecBinsTotal = 0, BFDecBinsTotal = 0;

    // gather the file name arguments
    if (argc < 2)
    {
        // we didn't get enough arguments, so complain and quit
        cout << "Usage: " << argv[0] << " randSeed" << endl;
        exit(1);
    }

    int randSeed = atoi(argv[1]);
    vector<int> items;
    vector< vector<int> > results (10);
    Pack pack = Pack(100, items);

    ofstream rawDataFile;
    rawDataFile.open("rawdata.txt", ios_base::trunc); // append file "trunc instead of app to overwrite"

    ofstream resultsFile;
    resultsFile.open("results.txt", ios_base::trunc); // append file "trunc instead of app to overwrite"

    int nextBins = 0, firstBins = 0, bestBins = 0, FFDecBins = 0, BFDecBins = 0;

    for(int i = 0; i < 10; i++){
        items = generateItems(randSeed);
        rawDataFile << "*Experiment #"<<i+1<<"*"<<endl;
        for(int i = 0; i < items.size(); i++){
            rawDataFile << items[i] << endl;
        }
        rawDataFile<<endl;

        nextBins = pack.nextFit(items, rawDataFile);
        nextBinsTotal += nextBins;
        firstBins = pack.firstFit(items,"First Fit", rawDataFile);
        firstBinsTotal += firstBins;
        bestBins = pack.bestFit(items, "Best Fit", rawDataFile);
        bestBinsTotal += bestBins;
        FFDecBins = pack.offFirstFit(items, rawDataFile);
        FFDecBinsTotal += FFDecBins;
        BFDecBins = pack.offBestFit(items, rawDataFile);
        BFDecBinsTotal += BFDecBins;

        int minimumONL = std::min(nextBins, std::min(firstBins, bestBins));

        cout<<"MIN ONL: " <<minimumONL<<endl;
        if(minimumONL == nextBins){
            nextWinsONL++;
        }else if (minimumONL == firstBins){
            firstWinsONL++;
        }else if (minimumONL == bestBins){
            bestWinsONL++;
        }

        int minimum = std::min(nextBins, std::min(firstBins, std::min(bestBins, std::min(FFDecBins, BFDecBins))));
        //int minimum = min( { nextBins, firstBins, bestBins, FFDecBins, BFDecBins} );
        if(minimum == nextBins){
            nextWins++;
        }else if (minimum == firstBins){
            firstWins++;
        }else if (minimum == bestBins){
            bestWins++;
        }else if (minimum == FFDecBins){
            offFirstWins++;
        }else if (minimum == BFDecBins){
            offBestWins++;
        }

        results[i].push_back(nextBins);
        results[i].push_back(firstBins);
        results[i].push_back(bestBins);
        results[i].push_back(FFDecBins);
        results[i].push_back(BFDecBins);
    }

    //Print a the results.txt header
    resultsFile << setw(10) << right <<"Exp#"<< setw(10) << right <<"Next"<< setw(10) << right <<"First"<< setw(10) << right <<"Best"<< setw(10) << right <<"FFDec"<< setw(10) << right <<"BFDec"<<endl;
    resultsFile << setw(10) << right <<"------"<< setw(10) << right <<"------"<< setw(10) << right <<"------"<< setw(10) << right <<"------"<< setw(10) << right <<"------"<< setw(10) << right <<"------"<<endl;


    //print the results
    for(int i = 0; i < 10; i++){
        resultsFile << setw(10) << right <<i + 1<< setw(10) << right <<results[i][0]<< setw(10) << right <<results[i][1]<< setw(10) << right <<results[i][2]<< setw(10) << right <<results[i][3]<< setw(10) << right <<results[i][4]<<endl;
    }
    resultsFile << setw(10) << right <<"------"<< setw(10) << right <<"------"<< setw(10) << right <<"------"<< setw(10) << right <<"------"<< setw(10) << right <<"------"<< setw(10) << right <<"------"<<endl;
    resultsFile << std::fixed;
    resultsFile << std::setprecision(1);
    resultsFile << setw(10) << right <<"AVG: "<< setw(10) << right <<(double)nextBinsTotal/10<< setw(10) << right <<(double)firstBinsTotal/10<< setw(10) << right <<(double)bestBinsTotal/10<< setw(10) << right <<(double)FFDecBinsTotal/10<< setw(10) << right <<(double)BFDecBinsTotal/10<<endl;
    resultsFile << setw(10) << right <<"------"<< setw(10) << right <<"------"<< setw(10) << right <<"------"<< setw(10) << right <<"------"<< setw(10) << right <<"------"<< setw(10) << right <<"------"<<endl;

    resultsFile << setw(10) << right <<"ONL: "<< setw(10) << right << nextWinsONL<< setw(10) << right << firstWinsONL<< setw(10) << right <<bestWinsONL<< setw(10) << right <<"--"<< setw(10) << right <<"--"<<endl;
    resultsFile << setw(10) << right <<"------"<< setw(10) << right <<"------"<< setw(10) << right <<"------"<< setw(10) << right <<"------"<< setw(10) << right <<"------"<< setw(10) << right <<"------"<<endl;

    resultsFile << setw(10) << right <<"ALL: "<< setw(10) << right <<nextWins<< setw(10) << right <<firstWins<< setw(10) << right <<bestWins<< setw(10) << right <<offFirstWins<< setw(10) << right <<offBestWins<<endl;
    resultsFile << setw(10) << right <<"------"<< setw(10) << right <<"------"<< setw(10) << right <<"------"<< setw(10) << right <<"------"<< setw(10) << right <<"------"<< setw(10) << right <<"------"<<endl;


    rawDataFile.close();
    resultsFile.close();
    return 0;
}

vector<int> generateItems(int randSeed) {
    if(randSeed == 0)
        srand (time(NULL));
    else{
        srand (randSeed);
    }

    vector<int> items;

    for(int i = 0; i < 100; i++){
        items.push_back(rand() % 100 + 1);
    }

    return items;
}




