//
//  SpanningTree.cpp
//  Algorithm_study_group
//
//  Created by LSH on 2017. 10. 24..
//  Copyright © 2017년 LSH. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;
const int MAX = 100;
const int nv = 10; // Number of vertex

bool adjMatrix[MAX][MAX];
vector<vector<int>> adjLists;
vector<int> discovered = {0};
vector<bool> visited;

// Spanning tree using DFS
void DepthFirstSearch_List(int here, int from){
    visited[here] = true;
    
    for(int i = 0; i < adjLists[here].size(); ++i){
        int there = adjLists[here][i];
        if(!visited[there])
            DepthFirstSearch_List(there, here);
        else if(there != from)
            adjLists[here].erase(adjLists[here].begin() + i);
    }
}

// Spanning tree using BFS
void BreadthFirstSearch_List(int start){
    queue<int> Q;
    discovered[start]++;
    Q.push(start);
    
    while(!Q.empty()){
        int here = Q.front();
        Q.pop();
        discovered[here]++;
        for(int i = 0; i < adjLists[here].size(); ++i){
            int there = adjLists[here][i];
            if(discovered[there] == 0){
                discovered[there]++;
                Q.push(there);
            }
            else if(discovered[there] != 2)
                adjLists[here].erase(adjLists[here].begin() + i);
        }
    }
}
