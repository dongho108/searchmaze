# searchmaze
미로탐색 문제를 stl vector이용 + 클래스이용해 해결한 프로그램 입니다.

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
main에서 Maze클래스를 선언하면 미로의 가로길이, 세로길이를 인자로 넘겨주게된다. 받은 인자를 이용해서 최단거리 vector(sp)와 방문확인 vector(visit)을 초기화 해준다. sp는 가장 큰 값인 10의7승, visit은 false로 초기화한다.

## MakeMaze함수

```c++
    for(int i=0; i<c+2; i++)
        maze.push_back(vector<int>());
    
    //천장
    for(int i=0; i<r+2; i++)
        maze.at(0).push_back(0);
    
    //왼쪽 벽
    for(int i=1; i<c+1; i++)
        maze.at(i).push_back(0);
    
    //미로
    int temp;
    for(int i=1; i<c+1; i++){
        for(int j=1; j<r+1; j++){
            scanf("%1d", &temp);
            maze.at(i).push_back(temp);
        }
    }
    
    //오른쪽 벽
    for(int i=1; i<c+1; i++)
        maze.at(i).push_back(0);
    
    //바닥
    for(int i=0; i<r+2; i++)
        maze.at(c+1).push_back(0);
```
