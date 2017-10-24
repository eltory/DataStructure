//
//  DFS.cpp
//  Algorithm_study_group
//
//  Created by LSH on 2017. 10. 24..
//  Copyright © 2017년 LSH. All rights reserved.
//

#include <stdio.h>
#include <vector>
using namespace std;
const int MAX = 100;
const int nv = 10; // Number of vertex

bool adjMatrix[MAX][MAX];
vector<vector<int>> adjLists;
vector<bool> visited;

/* From a node, visit one adjacent node recursively, until there is no new adjacent node.
 * Then backtrack, and visit the next adjacent node recursively.
 * Finish when every adjacent node of the initial node has been recursively traversed.
 */

// DFS_ using adjlists
void DepthFirstSearch_List(int here){
    visited[here] = true;

    for(int i = 0; i < adjLists[here].size(); ++i){
        int there = adjLists[here][i];
        if(!visited[there])
            DepthFirstSearch_List(there);
    }
}

// DFS_ using adjmatrix
void DepthFirstSearch_Matrix(int here){
    visited[here] = true;
    
    for(int i = 0; i < nv; ++i){
        if(adjMatrix[here][i]){
            int there = adjMatrix[here][i];
            if(!visited[there])
                DepthFirstSearch_Matrix(there);
        }
    }
}
