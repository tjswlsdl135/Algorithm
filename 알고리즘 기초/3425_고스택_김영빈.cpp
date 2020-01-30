#include<iostream>
#include<stack>
#include<vector>
#include<cmath>
#include<string>
using namespace std;

vector<string> command;
stack<long long> _stack;
//num값이 여러개일때
vector<long long> num_vector;
int check;
int N;
string str;
int param;

int NUM(long long x) {
	_stack.push(x);
	return 0;
}

int POP() {
	if (_stack.empty()) {
		return 1;
	}
	_stack.pop();
	return 0;
}

int INV() {
	if (_stack.empty()) {
		return 1;
	}
	else {
		long long temp = -_stack.top();
		_stack.pop();
		_stack.push(temp);
		return 0;
	}
}

int DUP() {
	if (_stack.empty()) {
		return 1;
	}
	else {
		long long temp = _stack.top();
		_stack.push(temp);
		return 0;
	}
}

int SWP() {
	if (_stack.size() < 2) {
		return 1;
	}
	else {
		long long temp = _stack.top();
		_stack.pop();
		long long temp_second = _stack.top();
		_stack.pop();
		_stack.push(temp);
		_stack.push(temp_second);
		return 0;
	}
}

int ADD() {
	if (_stack.size() < 2) {
		return 1;
	}
	else {
		long long temp = _stack.top();
		_stack.pop();
		long long temp_second = _stack.top();
		_stack.pop();
		_stack.push(temp + temp_second);
		return 0;
	}
}

int SUB() {
	if (_stack.size() < 2) {
		return 1;
	}
	else {
		long long temp_first = _stack.top();
		_stack.pop();
		long long temp_second = _stack.top();
		_stack.pop();
		_stack.push(temp_second - temp_first);
		return 0;
	}
}

int MUL() {
	if (_stack.size() < 2) {
		return 1;
	}
	else {
		long long temp_first = _stack.top();
		_stack.pop();
		long long temp_second = _stack.top();
		_stack.pop();
		_stack.push(temp_second * temp_first);
		return 0;
	}
}


int DIV() {
	if (_stack.size() < 2) {
		return 1;
	}
	else {
		long long temp_first = _stack.top();
		_stack.pop();
		long long temp_second = _stack.top();
		_stack.pop();
		if (temp_first == 0) {
			return 1;
		}
		else if ((temp_second < 0 && temp_first>0)) {
			temp_second = -temp_second;
			_stack.push(-(temp_second / temp_first));
		}
		else if (temp_second > 0 && temp_first < 0) {
			temp_first = -temp_first;
			_stack.push(-(temp_second / temp_first));
		}
		else {
			_stack.push(temp_second / temp_first);
		}
	}
	return 0;
}

int MOD() {
	if (_stack.size() < 2) {
		return 1;
	}
	else {
		long long temp_first = _stack.top();
		_stack.pop();
		long long temp_second = _stack.top();
		_stack.pop();
		if (temp_first == 0) {
			return 1;
		}
		else if ((temp_second < 0 && temp_first>0)) {
			temp_second = -temp_second;
			_stack.push(-(temp_second % temp_first));
		}
		else if (temp_second > 0 && temp_first < 0) {
			temp_first = -temp_first;
			_stack.push((temp_second % temp_first));
		}
		else {
			_stack.push(temp_second % temp_first);
		}
	}
	return 0;
}



int main() {
	while (1) {
		check = 0;
		while (1) {
			cin >> str;
			if (str == "NUM") {
				cin >> param;
				num_vector.push_back(param);
			}
			if (str == "END") {
				break;
			}
			if (str == "QUIT") {
				return 0;
			}
			command.push_back(str);
		}

		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> param;
			int index = 0;
			_stack.push(param);
			for (int j = 0; j < command.size(); j++) {
				if (command[j] == "NUM") {
					check = NUM(num_vector[index]);
					index++;
				}
				if (command[j] == "POP") {
					check = POP();
				}
				if (command[j] == "INV") {
					check = INV();
				}
				if (command[j] == "DUP") {
					check = DUP();
				}
				if (command[j] == "SWP") {
					check = SWP();
				}
				if (command[j] == "ADD") {
					check = ADD();
				}
				if (command[j] == "SUB") {
					check = SUB();
				}
				if (command[j] == "MUL") {
					check = MUL();
				}
				if (command[j] == "DIV") {
					check = DIV();
				}
				if (command[j] == "MOD") {
					check = MOD();
				}
				if (!_stack.empty() && (_stack.top() > 1000000000 || _stack.top() < -1000000000)) {
					check = 1;
				}
				if (check == 1) {
					break;
				}
			}
			if (check == 1 || _stack.size() != 1){
				cout << "ERROR\n";
			}
			else {
				cout << _stack.top() << '\n';
			}
			while (!_stack.empty()) {
				_stack.pop();
			}
		}
		num_vector.clear();
		command.clear();
		cout << '\n';
	}
	return 0;
}
