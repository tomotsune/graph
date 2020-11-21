#include <iostream>
#include "graph.h"
using namespace std;

void move(int *a, int n);
int main() {
    tomo::graph g{0,1,1,1,0,0,1,0,0,0,1,1,1,0,0,0,1,0,1,0,0,0,0,1,0,1,1,0,0,0,0,1,0,1,0,0};
    g.bfs_min_distance(1);
    g.printPath(1,6);
    std::cout<<std::endl;
    g.dfs(1,[](int e){
          std::cout<<e<<" ";
    });
    std::cout<<std::endl;
    g.printPath(1,6);
}
