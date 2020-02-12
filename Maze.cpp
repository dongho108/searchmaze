#include <iostream>
#include "Maze.h"
using namespace std;

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

void Maze::MakeMaze(){ //미로 주위를 0으로 둘러쌈 ( 벽으로 둘러쌈 )
    
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
}

void Maze::ExitMaze(){
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
}
