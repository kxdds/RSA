#pragma once
class RSA {
private :
	long long e,d,n;
public:
	RSA(long long e, long long d, long long n);
	~RSA();
	void pTc();//���ܺ���
	void numberSign();//����ǩ��
};