#include<iostream>
#include<string>
using namespace std;

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
			state.append(1, (char)('A' + i % 10));
		}
	}
	state.reserve();
	return state;
}

void pTc(char*sp,char*sn,char*se,char*sc) {//加密
	FILE *pp, *np, *ep, *cp;
	if (!(fopen_s(&pp, sp, "r") || fopen_s(&np, sn, "r") || fopen_s(&ep, se, "r") || fopen_s(&cp, sc, "w"))) {
		cout << "文件存在，请检查" << endl;
		return;
	}
	int i;
	long long p=0, n=0, e=0, c=0,t=1;
	fseek(np, 0, SEEK_SET);
	fgets(sn,30,np);
	for (i = strlen(sn);i >=0;i--) {
		if (sn[i] >= 'A' && sn[i] <= 'F') {
			n += t * (10 + (sn[i] - 'A'));
			t *= 16;
		}
		else {
			n += t * (0 + (sn[i] - '0'));
			t *= 16;
		}
	}
	fseek(ep, 0, SEEK_SET);
	fgets(se, 30, ep);
	for (i = strlen(se);i >= 0;i--) {
		if (se[i] >= 'A' && se[i] <= 'F') {
			n += t * (10 + (se[i] - 'A'));
			t *= 16;
		}
		else {
			n += t * (0 + (se[i] - '0'));
			t *= 16;
		}
	}
	string cs;
	fseek(pp, 0, SEEK_SET);
	while (true) {
		if (feof(pp))
			break;
		fgets(sp, 9, pp);
		for (i = strlen(sp);i >= 0;i--) {
			if (sp[i] >= 'A' && sp[i] <= 'F') {
				n += t * (10 + (sp[i] - 'A'));
				t *= 16;
			}
			else {
				n += t * (0 + (sp[i] - '0'));
				t *= 16;
			}
		}
		c = result(n, p, e);
		cs = longlongToString(c);
		fprintf_s(cp, "%s", cs.c_str());
	}
	fclose(pp);
	fclose(np);
	fclose(ep);
	fclose(cp);
}

void numberSign(char*p,char*n,char*e,char*c) {//数字签名

}

long long result(long long n, long long p, long long ed) {//幂运算取模
	
}

void main(int argc, char **argv) {
	if ((argc == 1) && argv[2] == "-h") {
		cout << "e3rsa -p plainfile -n nfile [-e efile] [-d dfile] -c cipherfile " << endl;
		cout << "参数：\n" << "- p plainfile            指定明文文件的位置和名称\n"\
			<< "- n nfile                指定存放整数n的文件的位置和名称\n"\
			<< "- e efile                在数据加密时，指定存放整数e的文件的位置和名称\n"\
			<< "- d dfile                在数字签名时，指定存放整数d的文件的位置和名称\n"\
			<< "- c cipherfile           指定密文文件的位置和名称\n" << endl;
		return;
	}
	if (argc == 9) {
		if (argv[1] == "-p"&&argv[3] == "-n" && (argv[5] == "-e" || argv[5] == "-d") && argv[7] == "-c") {
			if (argv[5] == "-e") {
				pTc(argv[2],argv[4],argv[6],argv[8]);
			}
			else {
				numberSign(argv[2],argv[4],argv[6],argv[8]);
			}
		}
		else
			cout << "参数错误！" << endl;
		return;
	}
	else
		cout << "参数错误！" << endl;
	return;
}