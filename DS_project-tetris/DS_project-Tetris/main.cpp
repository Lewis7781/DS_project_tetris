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
public:
    int reference;
    int move;
    int size;
    vector< vector<int> > shape;
    string name;
    block(){
        move=reference=0;
        name ="fuck";
    }
    block(string n,int r,int m){
        name=n;
        reference=r;
        move=m;
        setshape(n);
    }
    void setshape(string a){
        vector< vector<int> > s(4,vector<int>(4,0));
        if(a=="T1"){
            s[3][1]=s[2][2]=s[2][1]=s[2][0]=1;
        }
        else if(a=="T2"){
            s[2][0]=s[2][1]=s[1][1]=s[3][1]=1;
        }
        else if(a=="T3"){
            s[3][0]=s[3][1]=s[3][2]=s[2][1]=1;
        }
        else if(a=="T4"){
            s[1][0]=s[2][0]=s[3][0]=s[2][1]=1;
        }
        else if(a=="L1"){
            s[1][0]=s[2][0]=s[3][0]=s[3][1]=1;
        }
        else if(a=="L2"){
            s[2][2]=s[2][1]=s[3][0]=s[2][0]=1;
        }
        else if(a=="L3"){
            s[3][1]=s[1][1]=s[2][1]=s[1][0]=1;
        }
        else if(a=="L4"){
            s[3][1]=s[3][0]=s[3][2]=s[2][2]=1;
        }
        else if(a=="J1"){
            s[3][0]=s[3][1]=s[2][1]=s[1][1]=1;
        }
        else if(a=="J2"){
            s[2][0]=s[3][0]=s[3][1]=s[3][2]=1;
        }
        else if(a=="J3"){
            s[1][0]=s[2][0]=s[3][0]=s[1][1]=1;
        }
        else if(a=="J4"){
            s[2][1]=s[2][2]=s[2][0]=s[3][2]=1;
        }
        else if(a=="S1"){
            s[3][1]=s[3][0]=s[2][1]=s[2][2]=1;
        }
        else if(a=="S2"){
            s[1][0]=s[2][0]=s[2][1]=s[3][1]=1;
        }
        else if(a=="Z1"){
            s[3][1]=s[3][2]=s[2][1]=s[2][0]=1;
        }
        else if(a=="Z2"){
            s[2][1]=s[1][1]=s[3][0]=s[2][0]=1;
        }
        else if(a=="I1"){
            s[0][0]=s[1][0]=s[2][0]=s[3][0]=1;
        }
        else if(a=="I2"){
            s[3][1]=s[3][0]=s[3][2]=s[3][3]=1;
        }
        else if(a=="O"){
            s[2][0]=s[3][0]=s[2][1]=s[3][1]=1;
        }
        shape=s;
    }
};

class gameboard{
public:
    int width;
    int height;
    int cubecnt;
    block cube[1000];
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
void showcube(gameboard board){
    for(int i=0;i<board.cubecnt;i++){
        for(auto j=board.cube[i].shape.begin();j!=board.cube[i].shape.end();j++){
            for(auto ct: *j){
                cout<<ct<<" ";
            }
            cout<<endl;
        }
        cout<<"========"<<endl;
    }
}

void updatemap(gameboard board,block test){
//    vector <int> lastline(test.shape[3].begin(), test.shape[3].end()-1);
//    lastline.assign(test.shape[3].begin(), test.shape[3].end()-1);   //fuck why exceed boundary
    int i=0;     // cube's current position(height) in the gameboard
    bool obstruct=false;
    while(i<board.height && obstruct==false){
        int j=0;        //count each dot in the test
        int falling_col=test.reference-1;
        obstruct=false;
        for(auto dot=test.shape[3].begin();dot!=test.shape[3].end();dot++,j++){
            
            if( *dot==1 ){  // check the dot downward
                if(board.map[i][falling_col+j]==1){
                    obstruct=true;
                }
            }
            
        }
        if( obstruct==true && test.move!=0){   //to move left or right
            
        }
        i++;
    }
    cout<<endl;
}
int main(int argc, const char * argv[]) {
    int n,m;
    int refer,mo;
    string str;
    cin>>m>>n;
    gameboard board(n,m);

    while( (cin>>str && str!="End") && (cin>>refer>>mo) ){
        board.addcube(str, refer, mo);
    }
    
   // showcube(board);
    
    for(auto testcase:board.cube)  updatemap(board,testcase);
    
    return 0;
}
