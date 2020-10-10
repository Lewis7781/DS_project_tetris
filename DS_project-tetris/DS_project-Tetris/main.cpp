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
    void showmap(){
        for(auto r:map){
            for(auto col:r){
                cout<<col<<" ";
            }
            cout<<endl;
        }
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
void showcube(block cu){
    for(auto i:cu.shape){
        for(auto c:i){
            cout<<c<<" ";
        }
        cout<<endl;
    }
    cout<<"========"<<endl;
}
bool checkboundary(block test,int fallingpt){
    bool velidity=false;
   /* for(int i=3;i>=0;i--){
        for(auto c :test.shape[i]){
            
            
        }
    }*/
    
    return velidity;
}
void write_in(int falcol,block test,gameboard &b ){
    falcol+=test.move;
    for(int m=3;m>=0;m--){
        for(int n=0;n<4;n++){
            if(test.shape[m][n]==1){
               // cout<<"NN"<<endl;
                b.map[b.height-4+m][n+falcol]=1;
            }
        }
    }
}
void updatemap(gameboard &board,block test){
   
    int i=-3;     // cube's top node current position(height) in the gameboard
    bool obstruct=false;
    int falling_col=test.reference-1;
    //showcube(test);
    
    while ( i+4<board.height && obstruct==false ) {
        
                //count each dot in the test
        obstruct=false;
        for( int k=3;k>=0;k-- ){                        //check the postion of the cube from below
            int j=0;
            for(auto dot=test.shape[k].begin();dot!=test.shape[k].end();dot++,j++){
                //cout<<*dot<<" ";
                if( i+k <0 ) break;
                if( *dot==1 ){                   // check the dot from downward
                    if(board.map[i+k][falling_col+j]==1){
                        cout<<"catchu"<<endl;
                        cout<<i<<" "<<k<<" "<<j<<endl;
                        obstruct=true;
                        break;
                    }
                }
                
            }
            if( obstruct==true ){       // find obstruction during checking
                //cout<<"i="<<i<<endl;
                
            }
        }
        i++;
    }
    //cout<<"Ob"<<obstruct<<endl;
    if( obstruct==false ){      //touch bottom without obstruction
        write_in(falling_col,test,board);
    }
    
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
    
    //for(auto testcase:board.cube)  updatemap(board,testcase);
    for(int i=0;i<board.cubecnt;i++) updatemap(board, board.cube[i]);
    board.showmap();
    
    return 0;
}
