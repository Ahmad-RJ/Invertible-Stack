#include <iostream>
using namespace std;
template <class T>
class stack {
	T* data;
	int maxsize;
	bool flipped;
	int currsize;
	int rev;
	int forw;
public:
	stack(int s) {
		maxsize = s;
		rev = maxsize - 1;
		forw = 0;
		currsize = 0;
		flipped = false;
		data = new T[maxsize];
	}
	int getsize() {
		return currsize;
	}
	bool isEmpty() {
		if (currsize == 0)
			return true;
		else
			return false;
	}
	bool isFull() {
		if (currsize == maxsize)
			return true;
		else
			return false;
	}
	void flipstack() {
		if (flipped)
			flipped = false;
		else
			flipped = true;
	}
	void push(const T& e) {
		if (!flipped) {
			//changeMaxsize();
			// calling in main to make sure push is of O(1).
			data[forw] = e;
			currsize++;
			forw++;
		}
		else if (flipped) {
			//changeMaxsize();
			// calling in main to make sure push is of O(1).
			data[rev] = e;
			currsize++;
			rev--;
		}
	}
	void pop() {
		if (!flipped) {
			if (!isEmpty()) {
				forw--;
				currsize--;
				//changeMaxsize();
				// calling in main to make sure pop is of O(1).
			}
			else
				cout << "Stack is Empty! :(" << endl;
		}
		else if (flipped) {
			if (!isEmpty()) {
				rev++;
				currsize--;
				//changeMaxsize();
				// calling in main to make sure pop is of O(1).
			}
			else
				cout << "Stack is Empty! :(" << endl;
		}
	}
	void print() {
		if (!flipped) {
			for (int i = 0; i < forw; i++) {
				cout << data[i] << " ";
			}
			for (int i = rev + 1; i < maxsize; i++) {
				cout << data[i] << " ";
			}
			cout << endl;
		}
		else if (flipped) {
			for (int i = rev + 1; i < maxsize; i++) {
				cout << data[i] << " ";
			}
			for (int i = 0; i < forw; i++) {
				cout << data[i] << " ";
			}
			cout << endl;
		}
	}
	void changeMaxsize() {
		if (currsize == maxsize) {
			int oldms = maxsize - 1;
			maxsize *= 2;
			int newms = maxsize - 1;
			T* dat = new T[maxsize];
			for (int i = 0; i < forw; i++) {
				dat[i] = data[i];
			}
			for (int i = oldms; i > rev; i--) {
				dat[newms] = data[i];
				newms--;
			}
			delete data;
			data = dat;
			rev = newms;
		}
		else if (currsize < (maxsize / 2)) {
			int oldms = maxsize - 1;
			maxsize /= 2;
			int newms = maxsize - 1;
			T* dat = new T[maxsize];
			for (int i = 0; i < forw; i++) {
				dat[i] = data[i];
			}
			for (int i = oldms; i > rev; i--) {
				dat[newms] = data[i];
				newms--;
			}
			delete data;
			data = dat;
			rev = newms;
		}
		else
			return;
	}
};

int main() {
	stack <int> s1(6);
	s1.push(1);
	s1.changeMaxsize();
	s1.push(2);
	s1.changeMaxsize();
	s1.push(3);
	s1.changeMaxsize();
	s1.flipstack();
	s1.push(4);
	s1.changeMaxsize();
	s1.push(5);
	s1.changeMaxsize();
	s1.push(6);
	s1.print();

	s1.pop();
	s1.changeMaxsize();
	s1.print();
	s1.pop();
	s1.changeMaxsize();
	s1.print();
	s1.flipstack();
	s1.pop();
	s1.flipstack();
	s1.changeMaxsize();
	s1.print();
	return 0;
}