#include<stdio.h>
#include<stdlib.h> //��̬�ڴ����
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

//��������
void CreateList() {
	/* ����������ʽ
	int* p;
	int a;
	p = &a; //1.�ڴ���ջ�������ɵ��ͷ�
	*/
	//p = (int*)malloc(sizeof(int));//2 �ڴ��ڶ�������Ҫ�û�ȥ�ͷ�
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
	//Ͷ�巨����ڵ�
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
		//�ɻ��ɰ�������,�ж��Ƿ��а���
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