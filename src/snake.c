#include <stdio.h>   // 标准输入输出（printf、scanf等）
#include <stdlib.h>  // 通用工具（rand、exit、srand等）
#include <conio.h>   // Windows控制台输入（_kbhit、_getch）
#include <windows.h> // Windows系统功能（system、Sleep）
#include <time.h>    // 时间相关（用于随机数种子）

#define MAP_WIDTH  20   // 地图宽度
#define MAP_HEIGHT 20   // 地图高度
#define MAX_SNAKE  100  // 蛇身最大长度（数组上限）
#define DIR_UP    1
#define DIR_DOWN  2
#define DIR_LEFT  3
#define DIR_RIGHT 4

// 坐标
typedef struct{
    int x;
    int y;
} Point;

// 蛇
typedef struct{
    Point body[MAX_SNAKE];              //蛇身数组
    // int head;                           // 蛇头位置
    // int length;                         // 蛇身长度
    int len;                          // 蛇身长度
    int dir;                      // 蛇头方向
} Snake;

// 食物
typedef struct{
    Point position;                     // 食物位置
} Food;

Snake snake;
Food food;
int map[MAP_HEIGHT][MAP_WIDTH];     // 地图二维数组

// // 地图
// typedef struct{
//     int map[MAP_HEIGHT][MAP_WIDTH];     // 地图二维数组
//     Snake snake;                        // 蛇
//     Food food;                          // 食物
// } GameMap;

void init_game(){

    // 初始化游戏
    printf("游戏初始化中...\n");
    

    // 初始化地图
    for(int i = 0; i < MAP_HEIGHT; i++){
        for(int j = 0; j < MAP_WIDTH; j++){
            map[i][j] = 0; // 0表示空地
        }
    }

    // 初始化蛇身
    snake.len = 2; // 蛇身长度初始为1
    snake.body[0] = (Point){2,5}; // 蛇头初始位置
    snake.body[1] = (Point){1,5}; // 蛇身初始位置
    snake.dir = DIR_UP; // 蛇头初始方向向上

    for(int i = 0; i < snake.len; i++){
        int x = snake.body[i].x;
        int y = snake.body[i].y;
        map[y][x] = 1; // 1表示蛇身
    }

    // 初始化食物
    srand(time(NULL)); // 设置随机数种子
    do{
        food.position.x = rand() % MAP_WIDTH;
        food.position.y = rand() % MAP_HEIGHT;
    } while (map[food.position.y][food.position.x] != 0);
    map[food.position.y][food.position.x] = 2; // 2表示食物
    printf("游戏初始化完成！\n");

}
