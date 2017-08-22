#include <iostream>
#include "SubSequence.cpp"

int main() {
    //std::cout << "Hello, World!" << std::endl;
    vector<char>  intVector = {'a','a','b','b','c','c','a','a'};
    /*for (int i=1; i < 4; i++) {
        intVector.push_back(i);
        intVector.push_back(i);
    }*/


    SubSequence<char> sub(intVector);


    sub.generateSubSequences();
    //sub.displaySubSequences();

    vector<vector<char>> descendingSeq = sub.getSubSequences(false);
    for (int i=0; i < descendingSeq.size(); i++) {
        vector<char> sub = descendingSeq[i];
        for (int j=0; j< sub.size(); j++)  {
            char ele = sub[j];
            std::cout << ele << "," ;

        }
        cout << endl;
    }

    return 0;
}