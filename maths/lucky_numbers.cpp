#include <iostream>
using namespace std;

bool isLuckyNumberHelper(int pos, int cnt) {
	if(cnt > pos)
		return true;
	else if(pos%cnt == 0)
		return false;
	else{
		pos = pos - pos/cnt;
		cnt++;
		return isLuckyNumberHelper(pos, cnt);
	}
}

bool isLuckyNumber(int num) {
	return isLuckyNumberHelper(num, 2);
}

int main() {
	for(int i=1; i<=50; i++) {
		if(isLuckyNumber(i))
			cout << i << " is lucky :)" << endl;
		else
			cout << i << " is not lucky :(" << endl;
	}
	return 0;
}