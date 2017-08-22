/*
/ Created by pwu5 on 8/20/2017.
/ Deal with subsequences problem
/ given any sequence, generate all unique subsequences
/ The generated Subsequences are ordered by the length of the sequence
*/

#include "SubSequence.h"
#include <iostream>
#include <algorithm>


template <typename T>
SubSequence<T>::SubSequence(vector<T> sequence) {
    original = sequence;
    timesTable = vector<int>(sequence.size(),0);
    createDuplicateTable();
}


template <typename T>
void SubSequence<T>::subSequencesHelper(vector<T> sol, int pos, int length) {
    sol.push_back(original[pos]);
    if (length == 1 ) {
        subSequences.push_back(sol);
    } else {
        length--;
        T last ;
        for (int i = pos+1; i < original.size() - length +1; ++i) {
            if (last == original[i] && i != pos+1) continue;
            if (timesTable[i] > length + sol.size()) continue;
            subSequencesHelper(sol, i, length);
            last = original[i];
        }
    }
    sol.pop_back();
}

template <typename T>
void SubSequence<T>::generateSubSequences() {
    vector<T> sol;

    for (int length = 1; length <= original.size(); length++) {
        T last;
        for (int i = 0; i < original.size() - length + 1; i++) {
            if (last == original[i] && i != 0) continue;
            if (timesTable[i] > length ) continue;
            subSequencesHelper(sol, i, length);
            last = original[i];
        }

    }
}

template <typename T>
void SubSequence<T>::displaySubSequences() {
    for (int i=0; i < subSequences.size(); i++) {
        vector<T> sub = subSequences[i];
        for (int j=0; j< sub.size(); j++)  {
            T ele = sub[j];
            std::cout << ele ;
        }
        cout << endl;
    }
}

template <typename T>
void SubSequence<T>::createDuplicateTable() {
    for (int  i = 0;  i < original.size(); ++i) {
        if (dupMap.find(original[i]) == dupMap.end()) {
            dupMap[original[i]] = 1;
        }
        else
            dupMap[original[i]]++;

        timesTable[i] = dupMap[original[i]];
    }
}

template <typename T>
const vector<vector<T>> SubSequence<T>::getSubSequences(bool ascending)  {
    if (ascending) return subSequences;
    else {
        vector<vector<T>> desendingSequences = subSequences;
        std::sort(desendingSequences.begin(),desendingSequences.end(), [](vector<T> x, vector<T> y){return x.size()>y.size();});
        return  desendingSequences;
    }
}

/*
template <typename T>
void SubSequence<T>::createKmpTable() {

    for (int i = 1; i < original.size(); i++) {
        int j = kmpTable[i - 1];
        while (j > 0 && original[i] != original[j])
            j = kmpTable[j - 1];
        kmpTable[i] = (j += original[i] == original[j]);
    }
    for (auto i:kmpTable) {
        cout << i << "," ;
    }
    cout << endl << "KMP table created!" << endl;
}
*/
