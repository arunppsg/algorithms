#include <iostream>
#include <vector>
#include <list>

#include "graph_utils.h"

void topological_sort(vector <vector<int>> adj_matrix){
    list <int> dfs = depth_first_search(adj_matrix);
    
    for(list<int>::reverse_iterator rit=dfs.rbegin(); rit != dfs.rend(); rit++){
        cout << *rit << " ";
    }
}


int main(int argc, char *argv[]){
    vector <vector<int>> adj_matrix;
    string file_name = argv[1];
    int directed = 1;
    read_graph(adj_matrix, file_name, directed);
    cout << "Topological Sort\n";
    topological_sort(adj_matrix);
    return 0;
}
