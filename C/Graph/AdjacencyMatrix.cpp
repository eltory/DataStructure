//
//  AdjacencyMatrix.cpp
//  Algorithm_study_group
//
//  Created by LSH on 2017. 10. 24..
//  Copyright © 2017년 LSH. All rights reserved.
//

#include <stdio.h>
const int MAX = 100;
bool adjacencyMatrix[MAX][MAX] = {false};

int main(){
    // G(u, v) is a graph
    for(int i = 0; i < MAX; ++i)
        for (int j = 0; j < MAX; ++j){
            int u, v;
            scanf("%d %d", &u, &v);
            // If the graph is directed graph
            adjacencyMatrix[u][v] = adjacencyMatrix[v][u] = true;
            // If the graph is undirected graph
            adjacencyMatrix[u][v] = true;
        }
    return 0;
}
