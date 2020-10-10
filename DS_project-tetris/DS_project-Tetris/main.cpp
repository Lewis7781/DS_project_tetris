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
#include <fstream>

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
    
    void cleanboard();
    void addcube(string st,int r,int m){
        cube[cubecnt]= block(st,r,m);
        cubecnt++;
    }
    bool check();
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
void gameboard::cleanboard(){
    int w=this->width-1;
    int h=this->height-1;
    for(int i=h;i>=0;i--){
        int j=0;
        for(j=0;j<=w;j++){
            if(map[i][j]!=1) break;
        }
        if(j==w+1){
            for(int k=i;k>0;k--){
                for(int m=0;m<=w;m++){
                    map[k][m]=map[k-1][m];
                }
            }
            for(int i=0;i<=w;i++){
                map[0][i]=0;
            }
        }
    }
}
void write_in(int falcol,block test,gameboard &b ,int bottom ){
   
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(test.shape[3-i][j]==1) b.map[bottom-i][j+falcol]=1;
        }
    }
}
bool gameboard::check(){
    bool todelete=false;
    for(int i=0;i<this->height;i++){
        int j=0;
        for(j=0;j<this->width;j++){
            if(this->map[i][j]!=1) break;
        }
        if(j==this->width){
            todelete=true;
            break;
        }
    }
    return todelete;
}
int updatemap( gameboard &board, block test, int i, bool move ){
   
        // cube's top node current position(height) in the gameboard
    bool obstruct=false;
    int falling_col=test.reference-1;
    if( move ==true ) falling_col+=test.move ;
    
    while ( i+4<=board.height && obstruct==false ) {
        
        //cout<<i<<endl;
        obstruct=false;
        for( int k=3;k>=0;k-- ){                        //check the postion of the cube from below
            int j=0;
            for(auto dot=test.shape[k].begin();dot!=test.shape[k].end();dot++,j++){
                //cout<<*dot<<" ";
                if( i+k <0 ) break;
                if( *dot==1 ){                          // check the dot from downward
                    if(board.map[i+k][falling_col+j]==1){
                        //cout<<test.name <<"="<<i+3<<endl;
                        obstruct=true;
                    }
                }
                
            }
            if( obstruct==true ){                       // find obstruction during checking
              //  cout<<i<<endl;
                if(move == true)
                write_in(falling_col,test,board,i+2);     //怪怪的
                return i;
            }
        }
        i++;
    }
   

    if( move==true ){
      
        write_in(falling_col,test,board,i+2);
    }
    return i;
}
int main(int argc, const char * argv[]) {
   /* fstream file;
    file.open("1.data" ,ios::in);
    if(!file) cout<<"fuck no file"<<endl;*/
    
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
    for(int i=0;i<board.cubecnt;i++){
        if( board.cube[i].move == 0 ) updatemap(board, board.cube[i], -3  , true);
        if(board.cube[i].move!=0){
            int tmp=updatemap(board, board.cube[i],-3, false);
            updatemap(board, board.cube[i], tmp  , true);
        }
        //cout<<board.check()<<endl;
        while(board.check()){
            board.cleanboard();
        }
    }
    board.showmap();
    
    return 0;
}
