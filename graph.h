//
// Created by tomot on 2020/11/16.
//

#ifndef TEST_GRAPH_H
#define TEST_GRAPH_H

#include <iostream>
#include <initializer_list>
#include <queue>
#include <functional>

namespace tomo {
    typedef std::function<void(int)> callback;

    class graph {
    private:
        int edge[7][7]{};
        bool book[7]{};
        int d[7]{};
        int path[7];
        int internal_dfs(const int &i, callback visit);
    public:
        void printPath(const int i, const int j)const;

        graph(const std::initializer_list<int> &values);

        friend std::ostream &operator<<(std::ostream &os, const graph &graph);

        void dfs(const int &i, callback visit);

        void bfs(const int &i, callback visit);

        void bfs_min_distance(const int &i);

        int firstNeighbor(const int &i)const;

        int nextNeighbor(const int &i, const int &w)const;
    };
}


#endif //TEST_GRAPH_H
