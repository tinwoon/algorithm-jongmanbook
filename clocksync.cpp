#include <stdio.h>
#include <stdlib.h>



//19.10.01 종만북 시계 알고리즘 



const int INF = 9999;
const int SWITCHES =10, CLOCKS =16;

const char linked[SWITCHES][CLOCKS+1]={//CLOCKS+1인 이유는 char형태의 문자열의 맨뒤 에는 null이 들어가야하기 때문이다. 
"xxx.............",
"...x...x.x.x....",
"....x.....x...xx",
"x...xxxx........",
"......xxx.x.x...",
"x.x...........xx",
"...x..........xx",
"....xx.x......xx",
".xxxxx..........",
"...xxx...x...x.."
};

int min(int a, int b){
	return a>b?b:a;
}

bool areAligned(int* clocks){//시계들이 정렬되어 있는가를 반환 
	for(int i=0;i<16;i++){
		if(clocks[i]!=12) return false;
	}
	return true;
}

void push(int* clocks,int swtch){//swtch번 스위치를 누른다. 
	for(int clock=0;clock<CLOCKS;++clock){
		if(linked[swtch][clock]=='x'){//swtch=> swtch-1로 바꿈 
			clocks[clock]+=3;
			if(clocks[clock]==15) clocks[clock]=3;
		}
	}
}

int solve(int *clocks, int swtch){
	if(swtch==SWITCHES) return areAligned(clocks)?0:INF;
	int ret=INF;
	for(int cnt=0; cnt<4;++cnt){
		ret=min(ret,cnt+solve(clocks,swtch+1));
		push(clocks, swtch-1);
	}
	return ret;
}


int main(){
	int case_num=0;
	scanf("%d",&case_num);

	int** clocks=(int**)malloc(sizeof(int*)*case_num);
	for(int i=0;i<case_num;i++){
	clocks[i]=(int*)malloc(sizeof(int)*16);
	scanf("%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d",&clocks[i][0],&clocks[i][1],&clocks[i][2],&clocks[i][3],&clocks[i][4],&clocks[i][5],&clocks[i][6],&clocks[i][7],&clocks[i][8],&clocks[i][9],&clocks[i][10],&clocks[i][11],&clocks[i][12],&clocks[i][13],&clocks[i][14],&clocks[i][15]);
	}
	
	for(int i=0;i<case_num;i++){
		printf("%d\n",solve(clocks[i],1));
	}
	
}

