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
미로 주위를 0으로 둘러싸고 미로는 scanf(“%1d”) 를 이용했다.

## ExitMaze함수
```c++
    sp.at(1).at(1) = 1;
    for(int i=1; i<c; i++){
        for(int j=1; j<r; j++){
            if(visit.at(i).at(r) == true)
                continue;
            queue <int> x;
            queue <int> y;
            
            x.push(i);
            y.push(j);
            
            while(!x.empty()){
                int xt = x.front();
                int yt = y.front();
                visit.at(xt).at(yt) = true;
                x.pop();
                y.pop();
                
                if(xt == c && yt == r){
                    cout << sp.at(xt).at(yt);
                    return ;
                }
                
                //동
                if(maze.at(xt).at(yt+1) == 1 && visit.at(xt).at(yt+1) == false){
                    if(sp.at(xt).at(yt) + 1 < sp.at(xt).at(yt+1))
                        sp.at(xt).at(yt+1) = sp.at(xt).at(yt) + 1;
                    x.push(xt);
                    y.push(yt+1);
                    visit.at(xt).at(yt+1) = true;
                }
                
                //서
                if(maze.at(xt).at(yt-1) == 1 && visit.at(xt).at(yt-1) == false){
                    if(sp.at(xt).at(yt) + 1 < sp.at(xt).at(yt-1))
                        sp.at(xt).at(yt-1) = sp.at(xt).at(yt) + 1;
                    x.push(xt);
                    y.push(yt-1);
                    visit.at(xt).at(yt-1) = true;
                }

                //남
                if(maze.at(xt+1).at(yt) == 1 && visit.at(xt+1).at(yt) == false){
                    if(sp.at(xt).at(yt) + 1 < sp.at(xt+1).at(yt))
                        sp.at(xt+1).at(yt) = sp.at(xt).at(yt) + 1;
                    x.push(xt+1);
                    y.push(yt);
                    visit.at(xt+1).at(yt) = true;
                }

                //북
                if(maze.at(xt-1).at(yt) == 1 && visit.at(xt-1).at(yt) == false){
                    if(sp.at(xt).at(yt) + 1 < sp.at(xt-1).at(yt))
                        sp.at(xt-1).at(yt) = sp.at(xt).at(yt) + 1;
                    x.push(xt-1);
                    y.push(yt);
                    visit.at(xt-1).at(yt) = true;
                }
                
            }
        }
    }
```
BFS를 이용해서 미로를 탐색하고 최단거리를 초기화 하며 진행한다. 끝을 만나면 return 한다.

# main.cpp
```c++
    int c, r;
    cin >> c >> r;
    Maze maze(c, r);
    
    //미로 초기화 -> maze클래스 선언시 바로 진행
    
    //미로 만들기
    maze.MakeMaze();
    
    //미로 탈출
    maze.ExitMaze();

```


# 2차원 동적 vector이용방법
선언할 때 vector의 자료형을 vector로 주는 원리이다. 2차원 배열의 i인덱스에 해당하는 값을 늘려줄 때는 v.push_back(vector<int>()) 로 준다. 그리고 y인덱스에 해당하는 값을 늘려줄 때는 v.at(i).push_back(0) 으로 초기화하며 늘려줄 수 있다. 원소에 접근할 때는 v.at(i).at(y) 로 접근하면 된다.
    
## 예시
```c++
vector<vector<int> > maze; // >>쉬프트 연산자와 헷갈리지 않도록 띄어쓰기
maze.push_back(vector<int>()); //push_back안에도 ()가 있다.
maze.at(0).push_back(1); // 배열로 치면 maze[0][0] = 1 과 같다 
cout << maze.at(0).at(0); // cout << maze[0][0] ; 과 같다.
```


