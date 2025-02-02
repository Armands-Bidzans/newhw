#include <iostream>
using namespace std;
int main() {
	return -1;
}
//#include<iostream>
//using namespace std;
//
//
//int main()
//{
//	int m1{ 5 }, m2{ 5 }, m3{ 2 };
//	
//	int*** ppArr;
//
//	ppArr = new int** [m1];
//	for (int i = 0; i < m1; i++)
//	{
//		ppArr[i] = new int* [m2];
//		for (int i = 0; i < m1; i++)
//		{
//			for (int j = 0; j < m2; j++)
//			{
//				ppArr[i][j] = new int[m3];
//			}
//		}
//	}
//	for (int i = 0; i < m1; i++)
//	{
//		for (int j = 0; j < m2; j++)
//		{
//			delete[]ppArr[i][j];
//		}
//	}
//	for (int i = 0; i < m1; i++)
//	{
//		delete[]ppArr[i];
//	}
//	delete[]ppArr;
//}