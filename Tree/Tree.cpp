// Tree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <filesystem>
#include <io.h>
#include <fstream>
#include <string>
using namespace std;
//void tree(string path, vector<string>& files,int);
void tree(string path, vector<string>& files, int depth);
#include <iomanip>
#include <iostream>
#include <string>

int main()
{
	char filePath[] = "E:\\myKE";
	vector<string> files;
	char distAll[] = "AllFiles.txt";
	tree(filePath, files,2);
	//ostream mos(distAll);
	//int size = files.size();
	//cout << size << endl;
	//for (int i = 0; i < size; i++) {
	//	cout << files[i] << endl;

	//}
	//ofn.close();
	//std::cout << "Hello World!\n";
	getchar();
	return 0;
}
void tree(string path, vector<string>& files,int depth) {
	long hFile = 0;
	//文件信息
	struct _finddata_t fileinfo;
	string p;
	if ((hFile = _findfirst(p.assign(path).append("\\*").c_str(), &fileinfo)) != -1) {
		do {
			if ((fileinfo.attrib & _A_SUBDIR)) {
				if (strcmp(fileinfo.name, ".") != 0 && strcmp(fileinfo.name, "..") != 0) {
					//files.push_back(p.assign(path).append("\\").append(fileinfo.name));
					cout << setfill(' ')<<right<< setw(depth * 4 - 7) << ""<<setfill('-') << right << setw(4) << "" << (fileinfo.name) << "\\"<<endl;
					tree(p.assign(path).append("\\").append(fileinfo.name), files ,depth+1);
				}

			}
			else {
				//cout << right << setw(depth * 4-1) <<""<< (fileinfo.name)<<endl;
				cout << setfill(' ') << right << setw(depth * 4 - 7) << "" << setfill('-') << right << setw(4) << "" << (fileinfo.name) << "\\" << endl;
				//files.push_back(p.assign(path).append("\\").append(fileinfo.name));
			
			}

		} while (_findnext(hFile, &fileinfo) == 0);
		_findclose(hFile);

	}

}
void print_has_before_blanks();
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
