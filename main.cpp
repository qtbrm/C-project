#include<stdio.h>
#include<stdlib.h> //动态内存分配
#include<windows.h>
#include<graphics.h>
#include<conio.h>
#pragma warning(disable:4996)

typedef struct Node {
	int x;
	int y;
	struct Node* pnext;
}NODE;

NODE* pZidan = NULL;
NODE* pMine = NULL;

//创建链表
void CreateList() {
	/* 两种声明方式
	int* p;
	int a;
	p = &a; //1.内存在栈区，自由的释放
	*/
	//p = (int*)malloc(sizeof(int));//2 内存在堆区，需要用户去释放
	pZidan = (NODE*)malloc(sizeof(NODE));
	pZidan->pnext = NULL;

	pMine = (NODE*)malloc(sizeof(NODE));
	pMine->pnext = NULL;
	pMine->x = 320;
	pMine->y = 450;


}
void AddNode() {
	NODE* pnew = (NODE*)malloc(sizeof(NODE));
	pnew->x = pMine->x+21;
	pnew->y = 420;
	//投插法插入节点
	pnew->pnext = pZidan->pnext;
	pZidan->pnext = pnew;
}



int main() {
	initgraph(640, 480);
	char key;
	CreateList();
	while (1) {
		system("cls");
		AddNode();
		Sleep(100);
		cleardevice();
		roundrect(pMine->x, pMine->y, pMine->x + 50, pMine->y + 20, 50, 10);
		NODE* P = pZidan->pnext;
		while (P != NULL) {
			roundrect(P->x, P->y, P->x + 10, P->y + 15, 5, 5);
			//printf("%d, %d\n", P->x, P->y);
			P->y -= 20;
			P = P->pnext;
		}
		//飞机由按键控制,判断是否有按键
		if (kbhit()) {
			key = getch();
			switch (key) {
			case 72 :
				pMine->y -= 5;
				break;
			case 80:
				pMine->y += 5;
				break;
			case  75:
				pMine->x -= 5;
				break;
			case 77:
				pMine->x += 5;
				break;
			}

		}
		
		

	}
	return 0;
}