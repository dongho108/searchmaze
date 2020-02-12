# searchmaze
미로탐색 vector이용 + 클래스이용 입니다.

# Maze.h
```c++
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
```
# Maze.cpp

## Maze class 생성자
```c++
Maze :: Maze(int tc, int tr){
    c = tc;
    r = tr;
    
    for(int i=0; i<c+2; i++){
        sp.push_back(vector<int>());
        visit.push_back(vector<bool>());
        for(int j=0; j<r+2; j++){
            sp.at(i).push_back(10000000);
            visit.at(i).push_back(false);
        }
    }
}

```
