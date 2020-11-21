//
// Created by tomot on 2020/7/16.
//


#include <stack>
#include "graph.h"


std::ostream &operator<<(std::ostream &os, const tomo::graph &graph) {

}


//cur是当前所在城市编号, dis是当前已经走过的路径

tomo::graph::graph(const std::initializer_list<int> &values) {
    int pos{};
    for (const auto &value : values) {

        edge[pos / 6 + 1][pos % 6 + 1] = value;
        //std::cout<<pos/6+1<<" "<<pos%6+1<<" "<<value<<std::endl;
        ++pos;
    }
}


int tomo::graph::firstNeighbor(const int &i) const {
    for (int j = 1; j < 7; ++j) {
        if (edge[i][j] != 0)
            return j;
    }
    return 0;
}

int tomo::graph::nextNeighbor(const int &i, const int &w) const {

    for (int j = w + 1; j < 7; ++j) {
        if (edge[i][j] != 0)
            return j;
    }
    return 0;
}

/**
 * 深度优先遍历
 * @param v  起始顶点.
 * @param visit  回调函数, 用来访问顶点.
 */
void tomo::graph::dfs(const int &i, callback visit) {
    for (int i = 1; i < 7; ++i) {
        d[i] = INT_MAX;
        path[i] = -1;
        book[i] = false;
    }
    internal_dfs(i,visit);

}

/**
 * 广度优先遍历
 * @param v  起始顶点.
 * @param visit  回调函数, 用来访问顶点.
 */
void tomo::graph::bfs(const int &i, callback visit) {
    for (int i = 1; i < 7; ++i) {
        book[i] = 0;
    }
    std::queue<int> queue{};

    visit(i);//访问

    book[i] = true;
    queue.push(i);
    while (!queue.empty()) {
        int _i = queue.front();
        queue.pop();
        for (int w = firstNeighbor(_i); w > 0; w = nextNeighbor(_i, w)) {
            if (!book[w]) {
                visit(w);//访问
                book[w] = true;
                queue.push(w);
            }
        }
    }

}

/**
 * 最短路径问题_BFS算法
 * @param u
 */
void tomo::graph::bfs_min_distance(const int &i) {
    std::queue<int> queue{};
    for (int i = 1; i < 7; ++i) {
        d[i] = INT_MAX;
        path[i] = -1;
        book[i] = false;
    }
    d[i] = 0;
    book[i] = true;
    queue.push(i);
    while (!queue.empty()) {
        int _i = queue.front();
        queue.pop();
        for (int w = firstNeighbor(_i); w > 0; w = nextNeighbor(_i, w)) {
            if (!book[w]) {
                d[w] = d[_i] + 1;
                path[w] = _i;
                book[w] = true;
                queue.push(w);
            }

        }
    }


}

void tomo::graph::printPath(const int i, const int j) const {
    int index{j};
    std::stack<int> s;
    while (index != -1) {
        s.push(index);
        if (index == i)break;
        index = path[index];
    }
    while (!s.empty()) {
        std::cout << s.top() << " ";
        s.pop();
    }
}

int tomo::graph::internal_dfs(const int &i, tomo::callback visit) {
    visit(i);
    book[i] = true;
    for (int w = firstNeighbor(i); w > 0; w = nextNeighbor(i, w)) {
        if (!book[w]) {
            path[w] = i;
            internal_dfs(w, visit);
        }
    }
}


