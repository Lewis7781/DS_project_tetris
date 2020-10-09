//
//  main.cpp
//  DS_project-tetris_game
//
//  Created by 李呂元 on 2020/10/8.
//  Copyright © 2020 李呂元. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;
class block{
public:
    int x;
    int y;
    string name;
    
    block(int x,int y,string name){
        x=x;
        y=y;
        name=name;
    }
};
class gameboard{
public:
    int width;
    int height;
    int cubecnt;
    block *cube;
    
    void addcube(int x,int y,string st){
        cube[cubecnt++]=block(x,y,st);
    }
    gameboard(int w,int h){
        width=w;
        height=h;
        cubecnt=0;
    }
};
int main(int argc, const char * argv[]) {
    int n,m;
    int x,y;
    string str;
    cin>>m>>n;
    gameboard board(n,m);
    while( (cin>>str && str!="End") && (cin>>x>>y) ){
        
    }
    
    return 0;
}
