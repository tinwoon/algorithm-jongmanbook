#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//19.10.4 ī������ �˰���
//��������� ���� �˰������� ���������� ¦�� �ڸ����� �ƴϸ� �Ұ����ϵ��� ��(����ó�� ����) 
//���ҷ� ���������� ���������̱⿡ ����! 

int push_num(int num){//�� �ڸ��� ��ŭ�� �迭�� �ִ�  �� 
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
	
	if(digit==2){//������ʷ� �ڸ����� 2������ �Ǹ� ����� ����ϱ� ������ �������� �ڸ����� 2�̸� ����ϵ�����. 

		return a1*b1*pow(10,half_digit*2)+(a1*b0+a0*b1)*pow(10,half_digit)+a0*b0;
	}
	else return karatsuba(a1,b1)*pow(10,half_digit*2)+(karatsuba(a1,b0)+karatsuba(a0,b1))*pow(10,half_digit)+karatsuba(a0,b0);//�ڸ����� 4�ڸ� 6�ڸ� ��� ���ڸ� �̻��̸� ��������� �ٽ� ���� ��Ŵ 
	
	
}


   



int main(){
	int num1, num2=0;
	scanf("%d %d",&num1,&num2);
	printf("%d",karatsuba(num1,num2));
	
}

