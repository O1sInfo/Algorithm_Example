#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// FFT 求时域的倒位序：将自然顺序的二进制数按位倒序
// M = log2(N), n = 0,1,...,N-1
unsigned reverse(unsigned n, unsigned M){
	unsigned rev_n = 0;
	for(int i = 0; i < M; ++i){
		rev_n <<= 1;
		rev_n += (n & 0x01);
		n >>= 1;
	}
	return rev_n;
}

// 测试
int main(int argc, char const *argv[])
{
	unsigned M = 4;
	std::vector<unsigned> v;
	for (int i = 0; i < pow(2, M); ++i){
		v.push_back(i);
	}
	std::vector<unsigned> v1;
	for (std::vector<unsigned>::iterator i = v.begin(); i != v.end(); ++i){
		unsigned n;
		n = reverse(*i, M);
		v1.push_back(n);
	}
	for (int i = 0; i < v.size(); ++i){
		cout <<  v[i] << " reverse to " << v1[i] << endl;
	}
	return 0;
}
