#ifndef MAZE_H
#define MAZE_H

#include <iostream>
#include <vector>
#include <queue>
using namespace std;


class Maze{
    int c, r;
    vector<vector<int> > maze;
    vector<vector<int> > sp; //최단거리
    vector<vector<bool> > visit; // 방문확인
public:
    Maze(int tc, int tr);
    void MakeMaze();
    void ExitMaze();
};

#endif
