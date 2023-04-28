#include<cstdio>
#include<cmath>
#include<algorithm>
#include<stack>
#include<iostream>
#include <iomanip>
#include<vector>
#include<algorithm>
#include<string>


using namespace std;

int s[101];

int judge(int floorr, int ceill, int k)//三分法
{
	if (floorr+1==ceill)
	{

		if (s[floorr] == s[k])
		{
			cout << "硬币" << floorr << "和硬币" << ceill << "称重一次: 前者重量轻" << endl;
			cout << "硬币" << k << "是假币";
			return 1;
		}
		else if (s[ceill] == s[k])
		{
			cout << "硬币" << floorr << "和硬币" << ceill << "称重一次: 后者重量轻" << endl;
			cout << "硬币" << k << "是假币";
			return 1;
		}
		else {
			cout << "查找失败，请检查输入";
			return 0;
		}
	}
	int sum1 = 0;
	int sum2 = 0;
	for (int j = floorr; j <= floorr + ceil((ceill - floorr) / 3); j++)//前1/3堆
	{
		sum1 += s[j];
	}
	for (int k = floorr + ceil((ceill - floorr) / 3) + 1; k <= floorr + ceil((ceill - floorr) / 3) + 1 + ceil((ceill - floorr)/3); k++)//中1/3堆
	{
		sum2 += s[k];
	}
	//cout << sum1 << " " << sum2;
	if (sum1 < sum2)//前堆轻
	{
		cout << "硬币" << floorr << "-" << floorr + ceil((ceill - floorr) / 3) << "和硬币" << floorr + ceil((ceill - floorr) / 3) + 1 << "-" << floorr + ceil((ceill - floorr) / 3) + 1 + ceil((ceill - floorr) / 3) << "称重一次: 前者重量轻" << endl;
		judge(floorr, floorr + ceil((ceill - floorr) / 3), k);
	}
	if (sum1 > sum2)//中堆轻
	{
		cout << "硬币" << floorr << "-" << floorr + ceil((ceill - floorr) / 3) << "和硬币" << floorr + ceil((ceill - floorr) / 3) + 1 << "-" << floorr + ceil((ceill - floorr) / 3) + 1 + ceil((ceill - floorr) / 3) << "称重一次: 后者重量轻" << endl;
		judge(floorr + ceil((ceill - floorr) / 3) + 1, floorr + ceil((ceill - floorr) / 3) + 1 + ceil((ceill - floorr) / 3), k);
	}
	if (sum1 == sum2)//后堆轻
	{
		cout << "硬币" << floorr << "-" << floorr + ceil((ceill - floorr) / 3) << "和硬币" << floorr + ceil((ceill - floorr) / 3) + 1 << "-" << floorr + ceil((ceill - floorr) / 3) + 1 + ceil((ceill - floorr) / 3) << "称重一次: 两者重量相同" << endl;
		judge(floorr + ceil((ceill - floorr) / 3) + 1 + ceil((ceill - floorr) / 3) + 1, ceill, k);
	}
}

int main()
{
	int n, k;//硬币数量,假币编号
	scanf("%d,%d", &n, &k);
	//cout << n << " " << k << endl;
	if (n < 3 || n>100)
	{
		cout << "硬币数量超标，无法查找" << endl;
	}
	if (k < 1 || k>100)
	{
		cout << "假币编号错误，请检查编号是否合法" << endl;
	}
	cout << "一共" << n << "枚硬币" << endl;
	cout << "伪币编号是" << k << endl;
	cout << "求解过程" << endl;
	for (int i = 1; i <= n; i++)
	{
		if (i == k)
		{
			s[i] = 0;
		}
		else s[i] = 1;
	}
	judge(1, n, k);
	return 0;
}

