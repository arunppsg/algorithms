#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

size_t split_string(const string &txt, vector<string> &strs, char ch){
    // Splits a string
    size_t pos = txt.find(ch);
    size_t initial_pos = 0;
    while(pos != string::npos){
        strs.push_back(txt.substr(initial_pos, pos - initial_pos));
        initial_pos = pos + 1;
        pos = txt.find(ch, initial_pos);
    }   
    strs.push_back(txt.substr(initial_pos, min(pos, txt.size()) - initial_pos));
    return strs.size();
}


void display_graph(vector<vector<int>> adj_matrix){
    for(int i=0; i<adj_matrix.size(); i++){
        cout << "\n";
        for(int j=0; j<adj_matrix.size(); j++){
            cout << adj_matrix[i][j] << " ";
        }
    }   
}


void read_graph(vector<vector<int>> &adj_matrix, string &file_name){
    string text;
    ifstream fp(file_name);
    bool edge_line = 0;
    int n, e; // number of vertices, number of edges
    while(getline(fp, text)){
        if(text[0] == '#'){
            continue;
        }
        vector <string> tokens;
        int token_count = split_string(text, tokens, ' '); 
        if(token_count != 2)
            cout << "Invalid line\n";
        n = stoi(tokens[0]);
        e = stoi(tokens[1]);
        break;
    }

    adj_matrix.resize(n, vector<int>(n));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            adj_matrix[i][j] = 0;
        }
    }
    for(int i=0; i<e; i++){
        getline(fp, text);
        vector <string> tokens;
        int token_count = split_string(text, tokens, ' ');
        if(token_count != 2)
            cout << "Invalid line\n";
        adj_matrix[stoi(tokens[0])][stoi(tokens[1])] = 1;
        if(directed == 0)
            adj_matrix[stoi(tokens[1])][stoi(tokens[0])] = 1;
    }
    fp.close();
}


void dfs_visit(vector<vector<int>> &adj_matrix, vector<int> &v_color, vector<int> &d, vector<int> &f, 
    vector<int> &parent, int &time, int vertex, list <int> &dfs){
    time++;
    d[vertex] = time;
    v_color[vertex] = 0;
    for(int i=0; i<adj_matrix.size(); i++){
        if(v_color[i] == -1 && adj_matrix[vertex][i] == 1){ 
            parent[i] = vertex;
            dfs_visit(adj_matrix, v_color, d, f, parent, time, i, dfs);
        }
    }   
    v_color[vertex] = 1;
    time++;
    f[vertex] = time;
    dfs.push_back(vertex);
}

list <int> depth_first_search(vector <vector<int>> adj_matrix){
    int n = adj_matrix.size();
    vector <int> vertex_color(n), vertex_d(n), vertex_f(n), parent(n);
    list <int> dfs;
    for(int i=0; i<n; i++){
        vertex_color[i] = -1; 
        vertex_d[i] = -1; 
        vertex_f[i] = -1; 
        parent[i] = -1; 
    }   

    int time = 0;
    for(int i=0; i<n; i++){
        if(vertex_color[i] == -1){
            dfs_visit(adj_matrix, vertex_color, vertex_d, vertex_f, parent, time, i, dfs);
        }
    }
    return dfs; 
}
