//
//  BFS.cpp
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
vector<bool> discovered;

/* From a node, visit adjacent nodes one at a time.
 * Then visit all unvisited adjacent nodes of each of the adjacent nodes of the original node one at a time.
 * Finish when all nodes on each of the paths from the original node have beeb visited.
 */

// BFS_ using adjlists
void BreadthFirstSearch_List(int start){
    queue<int> Q;
    discovered[start] = true;
    Q.push(start);
    
    while(!Q.empty()){
        int here = Q.front();
        Q.pop();
        for(int i = 0; i < adjLists[here].size(); ++i){
            int there = adjLists[here][i];
            if(!discovered[there]){
                discovered[there] = true;
                Q.push(there);
            }
        }
    }
}

// DFS_ using matrix
void BreadthFirstSearch_Matrix(int start){
    queue<int> Q;
    discovered[start] = true;
    Q.push(start);
    
    while(!Q.empty()){
        int here = Q.front();
        Q.pop();
        for(int i = 0; i < nv; ++i){
            if(adjMatrix[here][i]){
                int there = adjMatrix[here][i];
                if(!discovered[there]){
                    discovered[there] = true;
                    Q.push(there);
                }
            }
        }
    }
}
