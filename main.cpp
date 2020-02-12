//
//  main.cpp
//  백준미로고급
//
//  Created by dongho on 2020/02/08.
//  Copyright © 2020 dongho. All rights reserved.
//

//전에 만들었던 미로탈출을 class와 vector를 이용하여 다시 작성하라 (~기한 2월 11일)


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
    Maze(int tc, int tr){
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
    void MakeMaze(){ //미로 주위를 0으로 둘러쌈 ( 벽으로 둘러쌈 )
        int temp;
        
        for(int i=0; i<c+2; i++)
            maze.push_back(vector<int>());
        
        //천장
        for(int i=0; i<r+2; i++)
            maze.at(0).push_back(0);
        
        //왼쪽 벽
        for(int i=1; i<c+1; i++)
            maze.at(i).push_back(0);
        
        //미로
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
    void ExitMaze(){
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
};


int main() {
    int c, r;
    cin >> c >> r;
    Maze maze(c, r);
    
    //미로 초기화 -> maze클래스 선언시 바로 진행
    
    //미로 만들기
    maze.MakeMaze();
    
    //미로 탈출
    maze.ExitMaze();
}
