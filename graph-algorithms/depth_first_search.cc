#include <iostream>
#include <list>

#include "graph_utils.h"

int main(int argc, char *argv[]){
    vector <vector<int>> adj_matrix;
    string file_name = argv[1];
    read_graph(adj_matrix, file_name, 1);
//    display_graph(adj_matrix);
    cout << "Depth First Search \n";
    list <int> dfs = depth_first_search(adj_matrix);
    for(list<int>::iterator it = dfs.begin(); it!=dfs.end(); it++)
        cout << *it << " ";
    return 0;
}
