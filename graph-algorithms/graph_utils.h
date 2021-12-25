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
        adj_matrix[stoi(tokens[0])-1][stoi(tokens[1])-1] = 1;
        adj_matrix[stoi(tokens[1])-1][stoi(tokens[0])-1] = 1;
    }
    fp.close();
}
