#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

void check(bool &flag, int step, vector<bool> visit, vector<int> num, int n, int a, int b){
	if(flag) return;
	int digit = pow(10.0, step);

	int len = visit.size();
	if(step == len/2){
		if(a*b == n and !(a%10 == 0 and b%10 == 0)){
			flag = true;
			if(a > b) swap(a,b);
			cout<<"It is a Vampire number"<<endl;
			cout<<"Two numbers are "<<a<<" "<<b<<endl;
		}
		return;
	}

	for(int i=0; i<len; i++){
		if(visit[i]) continue;
		else if(i>0 and num[i-1] == num[i] and !visit[i-1]) continue;
		visit[i] = true;

		a += num[i] * digit;

		for(int j=0; j<len; j++){
			if(visit[j]) continue;
			else if(j>0 and num[j-1] == num[j] and !visit[j-1]) continue;
			visit[j] = true;
			b += num[j] * digit;
			if(a*b%(digit*10) == n%(digit*10)){
				check(flag, step+1, visit, num, n, a, b);
			}
			b -= num[j] * digit;
			visit[j] = false;
		}
		a -= num[i] * digit;
		visit[i] = false;
	}
}

int main(){
	int n, number;
	cin >> number;
	n = number;
	vector<int> num;
	while(n){
		num.push_back(n%10);
		n /= 10;
	}
	int len = num.size();
	sort(num.begin(), num.end());
	vector<bool> visit(len, false);
	bool flag = false;
	check(flag, 0, visit, num, number, 0, 0);
	return 0;
}
