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

    private:
        int delay;
        bool update; //是否更新


        void keyEven();    
        void updateWindow();   
        //返回距离上一次调用该函数，间隔了多少秒
        //第一次调用该函数，返回0    
        int getDelay();
        void drop();
        void clearLine();
        
    
};