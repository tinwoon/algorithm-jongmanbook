//2019.10.02 1���� n������ ���� ���ϴ� ���� ���� �˰���
#include <stdio.h>

int fastSum(int n){
	if(n==1) return 1;
	if(n%2==1) return n+fastSum(n-1);//n���� Ȧ���϶� n-1������ ���� ���ϰ� n�� �����ָ� n������ ���̴�. 
	return 2*fastSum(n/2)+n*n/4;
} 

int main(){
	int data=0;
	scanf("%d",&data);
	printf("%d",fastSum(data));
}
