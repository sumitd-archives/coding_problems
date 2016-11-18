#include <iostream>
#include <list>
using namespace std;

class graph {
    int v;
    list<int> * adj;
    bool isCyclicUtil(int v , bool * local_visit , bool * global_visit);
    public:
    graph(int v) {
        this->v = v;
        adj = new list<int>[v];
    }
    void addEdge(int v , int w) {
        adj[v].push_back(w);
    }
    bool isCyclic() {
        bool * local_visit = new bool[v];
        bool * global_visit = new bool[v];
        int i;
        for (i = 0 ; i < v ; i++) {
            local_visit[i] = false;
        }
        for (i = 0 ; i < v ; i++) {
            global_visit[i] = false;
        }
        for (i = 0 ; i < v ; i++) {
            if(global_visit[i]) {
                continue;
            }
            if(isCyclicUtil(i , local_visit , global_visit)) {
                return true;
            }
        } 
        return false;
    }
};

bool graph::isCyclicUtil(int v , bool * local_visit , bool * global_visit) {
    if (local_visit[v]) {
        return true;
    }
    local_visit[v] = true;
    global_visit[v] = false;
    list<int>::iterator i;
    for(i = adj[v].begin() ; i != adj[v].end() ; i++) {
        if(isCyclicUtil(*i , local_visit , global_visit)) {
            return true;
        }           
    }
    local_visit[v] = false;  
    return false;
}

int main()
{
    graph g(5);    
    g.addEdge(0 , 1);
    g.addEdge(1 , 2);
    g.addEdge(2 , 0);
    g.addEdge(3 , 4);
    if (g.isCyclic()) {
        cout << "Graph is cyclic \n";
    }
    else {
        cout << "Graph is acylic \n";
    }
}   
