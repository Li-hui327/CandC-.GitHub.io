#include<stdio.h>
#include<easyx.h>	//easyx图形库，需要安装一下才能使用
#include<time.h>
#include<conio.h>
#include<mmsystem.h>
#pragma comment(lib,"winmm.lib")
#define STAR_NUM 520	//小星星数量
#define METEOR_NUM 99	//流星的数量

struct Star //小星星
{
	int x;
	int y;
	COLORREF color;	//颜色 unsigned int
	int speed;		//速度
}star[STAR_NUM];
struct Meteor	//流星
{
	int x;
	int y;
	int speed;
}meteor[METEOR_NUM];

IMAGE img[2];

//开始的表白界面，说出你的心里话
void loveYou()
{
	//播放音乐
	mciSendString(L"open ./images/浪漫空气.mp3 alias love", NULL, NULL, NULL);
	mciSendString(L"play love", NULL, NULL, NULL);

	//设置随机数种子
	srand((unsigned)time(NULL));
	//设置文字样式
	settextstyle(40, 0, L"华文行楷");
	//设置背景模式
	setbkmode(TRANSPARENT);

	//大家把想说的话，发到公屏上

	while (!_kbhit())	//如果没有按键按下，就一直循环，否则退出循环
	{
		//清空屏幕
		cleardevice();

		//让文字居中显示
		WCHAR title[] = L"阿珍我喜欢你♥";
		int x = (getwidth() - textwidth(title)) / 2;
		int y = 20;
		//输出文字
		outtextxy(x, y, title);

		//设置文字颜色
		settextcolor(RGB(rand() % 256, rand() % 256, rand() % 256));
		outtextxy(200, 100, L"记得那是一个夏日的午后");
		outtextxy(200, 150, L"你和我在那棵桃树下");
		outtextxy(200, 200, L"请君入目，夜月皆无。");
		outtextxy(200, 250, L"爱上你是我在这世界上做过的最容易的事");
		outtextxy(200, 300, L"爱上你是我情非得已");
		outtextxy(200, 350, L"我爱你就像风走了千万里从不问归期");
		outtextxy(200, 400, L"那天你问我什么是爱情");
		outtextxy(200, 450, L"我爱你像风走了八千里");
		outtextxy(200, 500, L"");
		outtextxy(200, 550, L"");
		outtextxy(200, 600, L"---------------------------爱你的阿强");

		for (int i = 0; i < 10; i++)
		{
			settextcolor(RGB(rand() % 256, rand() % 256, rand() % 256));
			outtextxy(rand() % getwidth(), rand() % getheight(), L"♥");
		}
		Sleep(800);	
	}
	cleardevice();
}
/***** 初始化小星星 ****/ 
void initStar(int i)
{
	star[i].x = rand() % getwidth();
	star[i].y = rand() % getheight();
	star[i].speed = rand() % 4 + 1;
	star[i].color = RGB(rand() % 256, rand() % 256, rand() % 256);
}
void drawStar()
{
	for (int i = 0; i < STAR_NUM; i++)
	{
		putpixel(star[i].x, star[i].y, star[i].color);
	}
}
void moveStar()
{
	for (int i = 0; i < STAR_NUM; i++)
	{
		star[i].x += star[i].speed;
		if (star[i].x > getwidth())
		{
			star[i].x = 0;
		}
	}
}
/***** 初始化流星 ****/
void loadImg()
{
	loadimage(img, L"./images/1.jpg",50,50);
	loadimage(img+1, L"./images/2.jpg",50,50);
}
void initMeteor(int i)
{
	meteor[i].x = rand() % (2 * getwidth()) - getwidth();	//[0-2400) - 1200  ->[-1200 - 1200)
	meteor[i].y = rand() % 20-200;	//[0-20) -> [-200,-180)
	meteor[i].speed = rand() % 15 + 1;
}
//把流星贴出来
void drawMeteor()
{
	for (int i = 0; i < METEOR_NUM; i++)
	{
		putimage(meteor[i].x, meteor[i].y, img+rand()%2,SRCPAINT);
	}
}
void moveMeteor()
{
	for (int i = 0; i < METEOR_NUM; i++)
	{
		meteor[i].x += meteor[i].speed;
		meteor[i].y += meteor[i].speed;
		if (meteor[i].x >= getwidth() || meteor[i].y >= getheight())
		{
			initMeteor(i);
		}
	}
}
/*
	公开课：今天大大家学习的，讲一些项目，没有压力
	VIP课程：学习路线上面的所有内容都会带你学习，8个月的时间，系统学习

	腾讯课堂教学，直播上课，有高清录播,不懂得直接问老师，一对一答疑
	上课时间：20：00 - 22：00 每天两个小时  

	C语言 C++ windows Qt linux    
	7280元  -  1000元的优惠券   = 6280 元

	分期：腾讯课堂提供的...    百度  京东  信用卡	...
	3 6 9 12  18 24   自由选择...      

	名额只有三个
	利息：

	里奇老师   莫影老师   强森老师  九夏老师  顽石老师     前浪老师
	现在太早了，想等等!    ---    
	




*/
int main()
{
	//1，创建图形窗口
	initgraph(1200, 800);
	loveYou();
	loadImg();

	for (int i = 0; i < STAR_NUM; i++)
	{
		initStar(i);
	}
	for (int i = 0; i < METEOR_NUM; i++)
	{
		initMeteor(i);
	}

	//双缓冲绘图
	BeginBatchDraw();
	while (true)
	{
		cleardevice();
		drawStar();
		moveStar();

		drawMeteor();
		moveMeteor();


		FlushBatchDraw();
	}
	getchar();	//防止闪退
	return 0;
}