#include<iostream>
#include<time.h>
#include<stdlib.h>
#include<string>
#include<string.h>
#include<windows.h>
using namespace std;
constexpr auto LEAST = 100000000000;
long long produceBig() {//产生大素数
	long long n;
	long long i;
	while (true) {
		n = (long long)((double)(rand()*LEAST) / RAND_MAX);
		i = n / 10000000000;
		if (!((n / 10000000000) &&( n % 2)))
			continue;
		for (i = 2;i <(long long)sqrtl((long double)n);i++) {
			if (n%i == 0) {
				n = 0;
				break;
			}
		}
		if (n == 0)continue;
		break;
	}
	return n;
}
string longlongToString(long long n) {//将longlong转十六进制字符串
	string state;
	int i;
	while (n) {
		i = n % 16;
		n = n / 16;
		if (i < 10) {
			state.append(to_string(i));
		}
		else {
			state.append(1,(char)('A'+i%10));
		}
	}
	state.reserve();
	return state;
}

bool isCompri(long long x, long long y) {
	if (y == 1 || y == 0)return false;
	long long tmp = 0;
	while (true) {
		tmp = x % y;
		if (tmp == 0)
			break;
		else {
			x = y;
			y = tmp;
		}
	}
	if (y == 0)
		return false;
	return true;
}

long long exgcd(long long a, long long b, long long&x, long long&y) {
	if (b == 0) {
		x = 1;
		y = 0;
		return a;
	}
	long long ret = exgcd(b, a%b, y, x);
	y -= (a / b) * x;
	return ret;
}

long long getInv(long long e, long long fn) {
	long long x, y;
	long long d = exgcd( e,fn , x, y);
	return d == 1 ? (x + fn) % fn : 0;
}

void produceDe(long long p,long long q,long long &d,long long &e) {
	long long de[2];
	long long fn = (p - 1)*(q - 1);
	while (true)
	{
		while (true) {
			e = (long long)(rand() % 10000000);
			if (!(e == 0) || (e == 1))
				break;
		}
		d = getInv(e, fn);
		if (d&&(d*e>1)&&((d*e)%fn)==1)break;
	}
}

void producenpq() {
	FILE *fp;
	errno_t err;
	long long p, q,d,e;
	string pString, qString, n,dString,eString;
	while(true) {
		p = produceBig();
		q = produceBig();
		if ((q*p)>0)break;
	}
	pString = longlongToString(p);
	qString = longlongToString(q);
	n = longlongToString(p*q);
	produceDe(p, q,d,e);
	dString = longlongToString(d);
	eString = longlongToString(e);
	fopen_s(&fp, "D:\\MyCode\\p.txt", "w");
	fprintf_s(fp, "%s\n", pString.c_str());
	fclose(fp);
	fopen_s(&fp, "D:\\MyCode\\q.txt", "w");
	fprintf_s(fp, "%s\n", qString.c_str());
	fclose(fp);
	fopen_s(&fp, "D:\\MyCode\\n.txt", "w");
	fprintf_s(fp, "%s\n", n.c_str());
	fclose(fp);
	fopen_s(&fp, "D:\\MyCode\\e.txt", "w");
	fprintf_s(fp, "%s\n", eString.c_str());
	fclose(fp);
	fopen_s(&fp, "D:\\MyCode\\d.txt", "w");
	fprintf_s(fp, "%s\n", dString.c_str());
	fclose(fp);
}
void main() {
	srand((unsigned)time(NULL));//整个程序随机；
	producenpq();
}