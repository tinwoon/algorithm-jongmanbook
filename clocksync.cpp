const int INF = 9999
const int SWITCHES =10, CLOCKS =16

const char linked[SWITCHES][CLOCKS+1]={
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
}

bool areAligned(const vector<int>& clocks);//시계들이 정렬되어 있는가를 반환 

void push(vector<int>& clocks,int swtch){//swtch번 스위치를 누른다. 
	for(int clock=0;clock<CLOCKS;++clock){
		if(linked[swtch][clock]=='x'){
			clocks[clock]+=3;
			if(clocks[clock]==15) clocks[clock]=3;
		}
	}
}
