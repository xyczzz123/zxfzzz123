#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define MAX 100000
#define VNUM 10+1 /*?啥意思*/

int edge[VNUM][VNUM] = {/*输入邻阶矩阵*/ };
int lowcost[VNUM] = { 0 };
int addvnew[VNUM];
int adjecent[VNUM] = { 0 };

void prim(int start) {
	int sumweigth = 0;
	int i, j, k = 0;

	for (i = 1; i < VNUM; ++i) {//从顶点1开始 
		lowcost[i] = edge[start][i];
		addvnew[i] = 1;
	}
	addvnew[start] = 0;//将起始点start加入VNUM
	adjecent[start] = start;
	for (i = 1; i < VNUM - 1; ++i) {
		int min = MAX;
		int v = -1;
		for (j = 1; j < VNUM; ++j) {
			if (addvnew[j] != -1 && lowcost[j] < min) {
				min = lowcost[j];
				v = j;
			}
		}
		if (v != -1) {
			printf("%d %d %d\n", adjecent[v], v, lowcost[v]);
			addvnew[v] = 0;
			sumweigth += lowcost[v];//计算路径长度的和
			for (j = 1; j < VNUM; ++j) {
				if (addvnew[j] == -1 && edge[v][j] < lowcost[j]) {
					lowcost[j] = edge[v][j];
					adjecent[j] = v;
				}
			}
		}
	}
	printf("最小的权值为",sumweigth);
}                                       