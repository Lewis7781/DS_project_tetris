//
//  gameboard.hpp
//  DS_project-Tetris
//
//  Created by 李呂元 on 2020/10/9.
//  Copyright © 2020 李呂元. All rights reserved.
//

#ifndef gameboard_hpp
#define gameboard_hpp

#include <stdio.h>
#include <vector>
#include <block.hpp>
#include <algorithm>

class gameboard{
public:
    int width;
    int height;
    int cubecnt;
    block *cube;
    vector<vector<int>>  map;   //  <=15*40
private:
    void addcube(string ,int ,int );

};
#endif /* gameboard_hpp */
