#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//19.10.4 카라츠바 알고리즘
//재귀적으로 분할 알고리즘으로 구현했으나 짝수 자릿수가 아니면 불가능하도록 함(예외처리 안함) 
//분할로 구현했음이 최종목적이기에 만족! 

int push_num(int num){//각 자릿수 만큼의 배열에 넣는  것 
	int digit=0;
	int for_digit=num;
	while(for_digit/10>0){
		for_digit=for_digit/10;
		digit++;
	}

	return ++digit;
}

int karatsuba(int a,int b){
	int digit=push_num(a);
	int half_digit=digit/2;
	int a1=a/pow(10,half_digit);
	int a0=a%(int)pow(10,half_digit);
	int b1=b/pow(10,half_digit);
	int b0=b%(int)pow(10,half_digit);
	
	if(digit==2){//기저사례로 자릿수가 2까지만 되면 충분히 계산하기 여유가 있음으로 자릿수가 2이면 계산하도록함. 

		return a1*b1*pow(10,half_digit*2)+(a1*b0+a0*b1)*pow(10,half_digit)+a0*b0;
	}
	else return karatsuba(a1,b1)*pow(10,half_digit*2)+(karatsuba(a1,b0)+karatsuba(a0,b1))*pow(10,half_digit)+karatsuba(a0,b0);//자릿수가 4자리 6자리 등등 두자리 이상이면 재귀적으로 다시 분할 시킴 
	
	
}


   



int main(){
	int num1, num2=0;
	scanf("%d %d",&num1,&num2);
	printf("%d",karatsuba(num1,num2));
	
}

