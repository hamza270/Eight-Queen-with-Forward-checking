#include"stdafx.h"
#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
const int m = 8, n = 8;
char ad[m][n];
char temp[m][n];
int temp1;
void cross(int a, int b, char c); // Cross the all side of queen
void uncross(int a, int b, char c); // Uncross the all side of queen 
void Display(); // Display the output
void reset(); // Reset the all Cross values and replace empty block on cross
void set(); // First set all blocks of puzzel with empty char
bool isEmpty(int j); // queen present(false) or not present(true) in temp array column
void forward(int j, int i); // forward keep queen in it  
int findRow(int j); // Find the row in which queen present
void backtrack(int j); // backtrack when found no place to keep queen in it
bool check(int j);// queen present(true) or not present(false) in ad array(actual array) column
bool check1(int j);// tell the current column keep any empty space or not.
char charchk(int j); // return the char accourding to column number 
int found = 0;
int main() {
	int i = 0, j = 0;
	char chr;
	set();
	int a;
	cout << "Enter the Row Where You want to keep Queen(0-7): ";
	cin >> a;
	ad[a][0] = 'Q';
	chr = charchk(j);
	cross(a, 0, '1');
	Display();
	found = 1;
	j++;
	forward(j, 0);
	cout << endl;
	system("pause");
	system("cls");
	reset();
	Display();
	for (int i = 0; i<m; i++) {
		for (int j = 0; j<n; j++) {
			if (ad[i][j] == 'Q') {
				cout << "ad[" << i << "][" << j << "] = " << ad[i][j] << endl;
			}
		}
	}
	system("pause");
}
void forward(int j, int i) {
jump:
	if (check1(j)) {                 // tell the current column keep any empty space or not ad array
		for (i; i < n; i++) {
			if (ad[i][j] == ' ') {
				if (check(j)) {            // queen present(true) or not present(false) in ad array(actual array) column
					int a = findRow(j);
					if (temp[a][j] == 'Q') {
						ad[a][j] = ' ';
					}
				}
				if (temp[i][j] != 'Q') {
					ad[i][j] = 'Q';
					char chr = charchk(j);
					cout << i << " " << j << endl;
					cross(i, j, chr);
					Display();
					found = 1;
					cout << endl;
				}
				else {
					found = 0;
					if (check(j)) {
						int a = findRow(j);
						if (temp[a][j] == 'Q') {
							ad[a][j] = ' ';
						}
					}
				}
			}
		}
	}
	else {
		found = 0;
		if (check(j)) {
			int a = findRow(j);
			if (temp[a][j] == 'Q') {
				ad[a][j] = ' ';
			}
		}
	}
	if (found == 0) {
		backtrack(--j);
	}
	else if (found == 1) {
		if (i == m) {
			j++;
			if (j != n) {
				i = 0;
				goto jump;
			}
		}
	}
}
void cross(int a, int b, char ch) {
	//Row Wise
	for (int j = b + 1; j<n; j++) {
		if (ad[a][j] == ' ') {
			ad[a][j] = ch;
		}
	}
	//Down Diagonal wise
	int i = a + 1;
	for (int j = b + 1; j<n; j++) {
		if (ad[i][j] == ' ') {
			ad[i][j] = ch;
		}
		i++;
	}
	i = 0;
	//UP Diagonals	
	i = a - 1;
	if (i >= 0) {
		for (int j = b + 1; j<n; j++) {
			if (ad[i][j] == ' ') {
				ad[i][j] = ch;
			}
			if (i >= 0) {
				i--;
			}
			else {
				break;
			}
		}
	}
	//Down Col wise 1
	int c = a + 1;
	int d = b;
	for (c; c < m; c++) {
		if (ad[c][d] == ' ') {
			ad[c][d] = ch;
		}
	}
	//Up Col wise 1
	c = a - 1;
	d = b;
	
	for (c; c >= 0; c--) {
		if (ad[c][d] == ' ') {
			ad[c][d] = ch;
		}
	}
}
void Display() {
	//Display() Code 
	cout << "  ";
	for (int i = 0; i<n; i++) {
		cout << " " << i << " |";
	}
	cout << endl;
	for (int i = 0; i<m; i++) {
		cout << i << " ";
		for (int j = 0; j<n; j++) {
			cout << " " << ad[i][j] << " |";
		}
		cout << endl;
	}
}
void reset() {
	for (int i = 0; i<m; i++) {
		for (int j = 0; j<n; j++) {
			if (ad[i][j] == '1' || ad[i][j] == '2' || ad[i][j] == '3' || ad[i][j] == '4' || ad[i][j] == '5' || ad[i][j] == '6' || ad[i][j] == '7' || ad[i][j] == '8')
				ad[i][j] = ' ';
		}
	}
}
void set() {
	for (int i = 0; i<m; i++) {
		for (int j = 0; j<n; j++) {
			ad[i][j] = ' ';
			temp[i][j] = ' ';
		}
	}
}
bool check(int j) {
	bool found = false;
	for (int i = 0; i < 8; i++) {
		if (ad[i][j] == 'Q') {
			found = true;
		}
	}
	return found;
}
char charchk(int j) {
	char a;
	if (j == 0) {
		a = '1';
	}
	else if (j == 1) {
		a = '2';
	}
	else if (j == 2) {
		a = '3';
	}
	else if (j == 3) {
		a = '4';
	}
	else if (j == 4) {
		a = '5';
	}
	else if (j == 5) {
		a = '6';
	}
	else if (j == 6) {
		a = '7';
	}
	else if (j == 7) {
		a = '8';
	}
	return a;
}

void backtrack(int j) {
	if (j >= 0) {
		int a = 0;
		int col = j + 1;
		a = findRow(j);
		if (isEmpty(j)) {
			coljumb:
			if (!isEmpty(col)) {
				for (int i = 0; i < m; i++) {
					if (temp[i][col] == 'Q') {
						temp[i][col] = ' ';
					}
				}
				col++;
				if (!isEmpty(col)) {
					goto coljumb;
				}
				temp[a][j] = 'Q';
				char ch = charchk(j);
				uncross(a, j, ch);
				Display();
				cout << endl;
				forward(j, 0);
			}
			else {
				temp[a][j] = 'Q';
				char ch = charchk(j);
				uncross(a, j, ch);
				Display();
				cout << endl;
				forward(j, 0);
			}
		}
		else {
			temp[a][j] = 'Q';
			char ch = charchk(j);
			uncross(a, j, ch);
			Display();
			cout << endl;
			forward(j, 0);
		}
	}
}
int findRow(int j) {
	int i = 0;
	int b = 0;
	for (i; i<m; i++) {
		if (ad[i][j] == 'Q') {
			b = i;
		}
	}
	return b;
}
bool isEmpty(int j) {
	bool found = true;
	for (int i = 0; i<m; i++) {
		if (temp[i][j] == 'Q') {
			found=false;
		}
	}
	return found;
}
bool check1(int j) {
	bool found = false;
	for (int i = 0; i < 8; i++) {
		if (ad[i][j] == ' ') {
			found = true;
		}
	}
	return found;
}
//int findRow1(int j){
//	int i=0,a;
//	for(i;i<m;i++){
//		if(temp[i][j]=='Q'){
//			a=i;
//		}
//	}
//	return a;
//}
void uncross(int a, int b, char ch) {
	//Row Wise
	for (int j = b + 1; j<n; j++) {
		if (ad[a][j] == ch) {
			ad[a][j] = ' ';
		}
	}
	//Down Diagonal wise
	int i = a + 1;
	for (int j = b + 1; j<n; j++) {
		if (ad[i][j] == ch) {
			ad[i][j] = ' ';
		}
		i++;
	}
	i = 0;
	//UP Diagonals	
	i = a - 1;
	if (i >= 0) {
		for (int j = b + 1; j<n; j++) {
			if (ad[i][j] == ch) {
				ad[i][j] = ' ';
			}
			if (i >= 0) {
				i--;
			}
			else {
				break;
			}
		}
	}
	//Down Col wise 1
	int c = a + 1;
	int d = b;
	//		jump:
	for (c; c < m; c++) {
		if (ad[c][d] == ch) {
			ad[c][d] = ' ';
		}
	}
	//Up Col wise 1
	c = a - 1;
	d = b;
	//		jump:
	for (c; c >= 0; c--) {
		if (ad[c][d] == ch) {
			ad[c][d] = ' ';
		}
	}
}