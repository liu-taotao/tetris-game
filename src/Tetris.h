#pragma once
#include <iostream>
using namespace std;
class Tetris
{
    public:
        //构造函数
        Tetris(int rows, int cols, int left, int top, int blockSize);
        void init();//初始化
        void play();//开始游戏
        
};