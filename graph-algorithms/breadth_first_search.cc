#include <iostream>
#include <list>

#include "graph_utils.h"

void breadth_first_search(vector <vector<int>> adj_matrix){
    int n = adj_matrix.size();
    vector <bool> visited(n);
    for(int i=0; i<n; i++){
        visited[i] = 0;
    }

    list <int> queue;
    bool flag = 0;
    int vertex = -1;

    while(flag == 0){
        flag = 1;
        for(int i=0; i<n; i++){
            if(visited[i] == 0){
                vertex = i;
                flag = 0; 
                visited[vertex] = 1;
                queue.push_back(vertex);
                cout << vertex << " ";
                break;
            }
        }

        while(!queue.empty()){
            vertex = queue.front();
            queue.pop_front();
            for(int i=0; i<n; i++){
                if(adj_matrix[vertex][i] == 1 && visited[i] == 0){
                    queue.push_back(i);
                    visited[i] = 1;
                    cout << i << " ";
                }
            }
        }
    }

}

int main(int argc, char *argv[]){
    vector <vector<int>> adj_matrix;
    string file_name = argv[1];
    read_graph(adj_matrix, file_name);
    cout << "Breadth First Search \n";
    breadth_first_search(adj_matrix);
    return 0;
}
