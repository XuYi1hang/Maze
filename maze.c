#include <stdio.h>
#include <getch.h>
#include <stdlib.h>
#include <time.h>

int main(int argc,const char* argv[])
{
	char maze[10][10] = {
		{'#','#','#','#','#','#','#','#','#','#'},	
		{'#',' ',' ',' ','#','#','#','#','#','#'},	
		{'#','#','#','@','#','#','#','#','#','#'},	
		{'#','#','#',' ','#','#','#','#','#','#'},	
		{'#','#','#',' ',' ','#','#','#','#','#'},	
		{'#','#','#','#',' ',' ','#','#','#','#'},	
		{'#','#','#','#','#',' ',' ',' ',' ',' '},	
		{'#','#','#','#','#','#','#','#','#','#'},	
		{'#','#','#','#','#','#','#','#','#','#'},	
		{'#','#','#','#','#','#','#','#','#','#'},	
	};

	// 记录游戏开始时间
	time_t seconds1 = time(NULL);

	// 记录角色位置
	char man_x = 2,man_y = 3;

	for(;;)
	{
		// 清理屏幕
		system("clear");
		// 显示地图
		for(int i=0; i<10 ; i++)
		{
			for(int j=0; j<10; j++)
			{
				printf("%c ",maze[i][j]);	
			}
			printf("\n");
		}
		// 判断是否到达出口
		if(6 == man_x && 9 == man_y)
		{
			printf("游戏结束，总共用时%lu秒",time(NULL)-seconds1);
			break;
		}

		// 获取方向键并处理
		switch(getch())
		{
			case 183:  //向上
				if(' ' == maze[man_x-1][man_y])
				{
					maze[man_x][man_y] = ' ';
					maze[--man_x][man_y] = '@';
				}
				break;
			case 184:  //向下
				if(' ' == maze[man_x+1][man_y])
				{
					maze[man_x][man_y] = ' ';
					maze[++man_x][man_y] = '@';
				}
				break;
			case 186:  //向左
				if(' ' == maze[man_x][man_y-1])
				{
					maze[man_x][man_y] = ' ';
					maze[man_x][--man_y] = '@';
				}
				break;
			case 185:  //向右
				if(' ' == maze[man_x][man_y+1])
				{
					maze[man_x][man_y] = ' ';
					maze[man_x][++man_y] = '@';
				}
				break;
			default:
				break;
		}
	}
}
