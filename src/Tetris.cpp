#include "Tetris.h"
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#include "Block.h"

#include <windows.h>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")
/**
 * @brief Construct a new Tetris:: Tetris object
 * 
 * @param rows 多少行
 * @param cols 多少列
 * @param left 左边界
 * @param top 右边界
 * @param blockSize 方块大小
 */
#define MAX_LEVEL 5
// const int SPEED_NORMAL = 500;//ms下降速度
const int SPEED_NORMAL[MAX_LEVEL] = {500, 300, 150, 100, 80};//ms下降速度
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
    delay = SPEED_NORMAL[0];

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

    score = 0;
    lineCount = 0;
    level = 1;
}

//开始游戏
void Tetris::play()
{
    init();

    nextBlock = new Block;//预告方块
    curBlock = nextBlock;//当前方块
    nextBlock = new Block;

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
    unsigned char ch = 0;//0 - 255
    bool rotateFlag = false;
    int dx = 0;
    cout << "键值 = " << (int)ch << endl;
    //判断以下是否有输入防止阻塞
    if (_kbhit()) {
        ch = _getch();
        //如果按下方向键, 会自动返回两个字符
        //如果按下 向上方向键,会先后返回: 224 72
        //如果按下 向下方向键,会先后返回: 224 80
        //如果按下 向左方向键,会先后返回: 224 75
        //如果按下 向右方向键,会先后返回: 224 77
        if (ch == 224) {
            ch = _getch();
            cout << "键值 = " << (int)ch << endl;
            switch (ch) {
                case 72: 
                    rotateFlag = true;
                    break;
                case 80: 
                    delay = SPEED_QUICK;
                    break;
                case 75: 
                    dx = -1;
                    break;
                case 77: 
                    dx = 1;
                    break;
                default:
                    break;
            }
        }
        
    }

    if (rotateFlag) {
        //实现旋转
        rotate();
        update = true;
    }
   
    if (dx != 0) {
        //实现左右移动
        moveLeftRight(dx);
        update = true;
    }
}
//更新窗口
void Tetris::updateWindow()
{
    BeginBatchDraw();//为了使画面不闪烁，让其他都好了在渲染 一起渲染
    putimage(0, 0, &imgBg);//绘制背景图片

    //底部固化方块坐标
    IMAGE **imgs = Block::getImages();
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (map[i][j] == 0) {
                continue;
            }
            int x = j * blockSize + leftMargin;
            int y = i * blockSize + topMargin;
            putimage(x, y, imgs[map[i][j] - 1]);//绘制方块
        }
    }

    curBlock->draw(leftMargin, topMargin);//当前方块
    nextBlock->draw(689, 150);//预告方块

    drawScore();//绘制分数

    EndBatchDraw();

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
//下降功能
void Tetris::drop()
{
    bakBlock = *curBlock;
    curBlock->drop();

    //说明方块到底了
    if (!curBlock->blockInMap(map)) {
        // 把方块固化
        bakBlock.solidify(map);
        delete curBlock;
        curBlock = nextBlock;
        nextBlock = new Block;
    }

    delay = SPEED_NORMAL[level - 1];
}

void Tetris::clearLine()
{
    int lines = 0;
    int k = rows - 1;//存储数据的行数
    for (int i = rows - 1; i >= 0; i--) {
        //检查第i行是否满行
        int count = 0;
        for (int j = 0; j < cols; j++) {
            if (map[i][j]) {
                count++;
            }
            map[k][j] = map[i][j];//一边扫描，一边存储
        }

        if (count < cols) {//不是满行
            k--;
        } else {//满行 count = cols
            lines++;
        }
    }

    if (lines > 0) {
        //计算得分
        int addScore[4] = {10, 30, 60, 80};
        score += addScore[lines - 1];
        cout << "行数是: " << lines << "分数是:" << score << endl;

        //播放音效
        mciSendString("play ../img/xiaochu1.mp3", 0, 0, 0);
        update = true;

        //每一百分一个级别 0-100 第一关 101-200第二关 依次类推
        level = (score + 99) / 100;

        lineCount += lines;
    }
}

void Tetris::moveLeftRight(int offset)
{
    bakBlock = *curBlock;
    curBlock->moveLeftRight(offset);

    if (!curBlock->blockInMap(map)) {
        *curBlock = bakBlock;
    }
}

void Tetris::rotate()
{
    if (curBlock->getBlockType() == 7) {
        return;
    }
    bakBlock = *curBlock;
    curBlock->rotate();

    //判断位置是否合法
    if (!curBlock->blockInMap(map)) {
        *curBlock = bakBlock;
    }
}

void Tetris::drawScore()
{
    char scoreText[32];
    sprintf_s(scoreText, sizeof(scoreText), "%d", score);
    
    setcolor(RGB(180, 180, 180));

    //设置字体
    LOGFONT f;
    gettextstyle(&f);//获取当前字体
    f.lfHeight = 60;
    f.lfWidth = 30; 
    f.lfQuality = ANTIALIASED_QUALITY;//抗锯齿效果  设置字体
    strcpy_s(f.lfFaceName, sizeof(f.lfFaceName), _T("Segoe UI Black"));
    settextstyle(&f);

    setbkmode(TRANSPARENT);//设置分数字体透明效果
    //绘制位置
    outtextxy(670, 727, scoreText);

    //绘制消除行数
    sprintf_s(scoreText, sizeof(scoreText), "%d", lineCount);
    gettextstyle(&f);
    int xPos = 224 - f.lfWidth * strlen(scoreText);
    outtextxy(xPos, 817, scoreText);

    //绘制当前是第几关
    sprintf_s(scoreText, sizeof(scoreText), "%d", level);
    outtextxy(224 - 30, 727, scoreText);
}