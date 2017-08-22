//
// Created by pwu5 on 8/20/2017.
//

#ifndef LEETCODE_SUBSEQUENCE_H
#define LEETCODE_SUBSEQUENCE_H

#include <vector>
#include <unordered_map>
#include <bits/unordered_map.h>

using namespace std;

template <typename T>
class SubSequence {
    vector<T> original;
    vector<vector<T>> subSequences;
    vector<int>   timesTable;
    unordered_map<T,int>   dupMap;
public:
    const vector<vector<T>> getSubSequences(bool ascending=true) ;

private:
    void subSequencesHelper(vector<T> sequence);
    void createDuplicateTable();
public:
    SubSequence (vector<T> sequence);
    void generateSubSequences();
    void displaySubSequences();


    void subSequencesHelper( vector<T> sol, int pos, int length);
};



#endif //LEETCODE_SUBSEQUENCE_H
