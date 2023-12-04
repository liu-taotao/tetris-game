/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief 1、创建项目
 *        2、导入素材
 *        3、开发
 *        4、设计模块
 *              Block 表示方块
 *              Tetris 表示方块游戏
 *        5、设计各个模块的主要接口
 *        6、启动游戏
 * @version 0.1
 * @date 2023-12-03
 * 
 * @copyright Copyright (c) 2023
 * 
 */ 

#include <iostream>
#include "Tetris.h"
#include "Block.h"

using namespace std;
int main(void)
{
    
    Tetris game(20, 10, 363, 133, 36);
    game.play();
    return 0;
}
