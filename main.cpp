#include <iostream>
#include "Maze.cpp"
using namespaces std;

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
