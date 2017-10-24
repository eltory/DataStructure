//
//  AdjacencyLists.cpp
//  Algorithm_study_group
//
//  Created by LSH on 2017. 10. 24..
//  Copyright © 2017년 LSH. All rights reserved.
//

#include <stdio.h>
#include <vector>
using namespace std;
vector<vector<int>> adjLists;

int main(){
    // Number of Vertex, Edge
    int nv, ne;
    scanf("%d %d", &nv, &ne);
    adjLists.resize(nv);
    // G(u, v) is a graph
    for(int i = 0; i < ne; ++i){
        int u, v;
        scanf("%d %d", &u, &v);
        // If the graph is directed graph
        adjLists[u].push_back(v);
        adjLists[v].push_back(u);
        // If the graph is undirected graph
        adjLists[u].push_back(v);
    }
    return 0;
}
