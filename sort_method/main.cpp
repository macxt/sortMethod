#include <iostream>
#include <string>
#include "CSort.h"
using namespace std;


int main(int argc, char **argv)
{
	std::vector<int> vSortArr = { 2, 7, 4, 8, 0, -1 };
	std::vector<int> vSortArr2 = { -99, -200, 4, 1, 0, 17, -173, 15 };
	std::vector<double> vSortArr3 = { -9.787, -20.21932, 4.32, 1.0001, 0.891, 17.27609, -173.21734, 15.28763 };
	std::vector<float> vfloatArr = { 2.345, -0.231, 42.891, 21.7436, 23.90876, 213.89301 };
	CSort csort;

	csort.SelectSort<false>(vSortArr.begin()+1, vSortArr.end()-1);
	std::cout << vSortArr << std::endl;

	csort.SelectSort(vfloatArr.begin() + 2, vfloatArr.end() - 1);

	csort.BubbleSort<false>(vSortArr3.begin()+1, vSortArr3.end()-1);
	
	std::cout << vSortArr3 << std::endl;

	int arr[] = { 23, 1, -20, 8, 198, 34, 21, 501, -321 };
	csort.BubbleSort<false>(std::begin(arr), std::end(arr));

	std::vector<int> vTmp;
	vTmp.insert(vTmp.end(), std::begin(arr), std::end(arr));
	
	std::cout << vTmp << std::endl;

	return 0;
}