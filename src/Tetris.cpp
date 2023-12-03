#include "Tetris.h"
#include <time.h>
#include <stdlib.h>
#include "Block.h"
/**
 * @brief Construct a new Tetris:: Tetris object
 * 
 * @param rows 多少行
 * @param cols 多少列
 * @param left 左边界
 * @param top 右边界
 * @param blockSize 方块大小
 */

const int SPEED_NORMAL = 500;//ms下降速度
const int SPEED_QUICK = 50;//

Tetris::Tetris(int rows, int cols, int left, int top, int blockSize)
{
   this->rows = rows;
   this->cols = cols;
   this->leftMargin = left;
   this->topMargin = top;
   this->blockSize = blockSize;

   for (int i = 0; i < rows; i++) {
        vector<int> mapRow;
        for (int j = 0; j < cols; j++) {
            mapRow.push_back(0);
        }
        map.push_back(mapRow);
   }

}

//初始化
void Tetris::init()
{
    delay = SPEED_NORMAL;

    //配置随机种子
    srand(time(NULL));

    //创建一个游戏窗口
    initgraph(938, 896);

    //加载背景图片
    loadimage(&imgBg, "../img/bg2.png");
      
    //初始化游戏区中的数据
    char data[20][10];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            map[i][j] = 0;
        }
    }
}

//开始游戏
void Tetris::play()
{
    init();

    nextBlock = new Block;//预告方块
    curBlock = nextBlock;//当前方块
    

    int timer = 0;
    while(1) {
        //接收用户输入
        keyEven();

        timer += getDelay();
        if (timer > delay) {
            timer = 0;
            //方块往下动 下降
            drop();
            //渲染游戏画面
            update = true;
        }

        if (update) {
            update = false;
            //更新游戏的画面
            updateWindow();

            //更新游戏数据
            clearLine();
        }

    }
}

void Tetris::keyEven()
{

}
//更新窗口
void Tetris::updateWindow()
{
    putimage(0, 0, &imgBg);//绘制背景图片

}

int Tetris::getDelay()
{
	static unsigned long long lasttime = 0;

	unsigned long long currentime = GetTickCount();
	if (lasttime == 0)
	{
		lasttime = currentime;
		return 0;
	}
	else {
		int ret = currentime - lasttime;
		lasttime = currentime;
		return ret;
	}
}
void Tetris::drop()
{

}

void Tetris::clearLine()
{

}