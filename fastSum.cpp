//2019.10.02 1부터 n까지의 합을 구하는 분할 정복 알고리즘
#include <stdio.h>

int fastSum(int n){
	if(n==1) return 1;
	if(n%2==1) return n+fastSum(n-1);//n값이 홀수일때 n-1까지의 합을 구하고 n을 더해주면 n까지의 합이다. 
	return 2*fastSum(n/2)+n*n/4;
} 

int main(){
	int data=0;
	scanf("%d",&data);
	printf("%d",fastSum(data));
}
