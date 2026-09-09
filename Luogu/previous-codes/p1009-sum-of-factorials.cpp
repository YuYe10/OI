#include <bits/stdc++.h>
using namespace std;
struct megan{
	int d[1000];
	int len;
	megan(){
		memset(d, 0, sizeof(d));
		len = 0;
	}
};
megan add(megan a, megan b);
megan multiply(megan a, int b);
void megaprintf(megan a);

int main(){
	int n;
	scanf("%d",&n);
	megan sum, a;
	a.d[0] = 1;
	a.len = 1;
	for(int i = 1; i <= n; i++){
		a = multiply(a, i);
		sum = add(sum, a);
	}
	megaprintf(sum);
	return 0;
}

megan add(megan a, megan b){
	megan c;
	int carry = 0;
	for(int i = 0; i < a.len || i < b.len; i++){
		int t = a.d[i] + b.d[i] + carry;
		c.d[c.len++] = t % 10;
		carry = t /10;
	}
	if(carry != 0){
		c.d[c.len++] = carry;
	}
	return c;
}

megan multiply(megan a, int b){
	megan c;
	int carry = 0;
	for(int i = 0; i < a.len; i++){
		int t = a.d[i] * b + carry;
		c.d[c.len++] = t % 10;
		carry = t / 10;
	}
	while(carry != 0){
		c.d[c.len++] = carry % 10;
		carry /= 10;
	}
	return c;
}

void megaprintf(megan a){
	for(int i = a.len - 1; i >= 0; i--){
		printf("%d", a.d[i]);
	}	
}