//
//  main.cpp
//  DS_project-tetris_game
//
//  Created by 李呂元 on 2020/10/8.
//  Copyright © 2020 李呂元. All rights reserved.
//

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

class block{
private:
    int reference;
    int move;
    string name;
public:
    block(string n,int r,int m){
        name=n;
        reference=r;
        move=m;
    }
    
};

class gameboard{
public:
    int width;
    int height;
    int cubecnt;
    block *cube;
    vector<vector<int>>  map;   //  <=15*40
    
    void addcube(string st,int r,int m){
        cube[cubecnt]= block(st,r,m);
        cubecnt++;
    }
    gameboard(int w,int h){
        width=w;
        height=h;
        cubecnt=0;
        vector< vector<int> > mapp( h,vector<int>(w,0) );
        map=mapp;
    }
};
void output(gameboard m){
    for(auto c=m.map.begin();c!=m.map.end();c++){
        for(auto i:*c){
            cout<<i<<" ";
        }
        cout<<endl;
    }
}
int main(int argc, const char * argv[]) {
    int n,m;
    int refer,mo;
    string str;
    cin>>m>>n;
    gameboard board(n,m);
   // output(board);
    while( (cin>>str && str!="End") && (cin>>refer>>mo) ){
        
        board.addcube(str, refer, mo);
    }
    
    output(board);
    return 0;
}
