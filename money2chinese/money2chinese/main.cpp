#include <iostream>
#include <string>
using namespace std;

class CMoney
{
public:
	CMoney(double a = 0.0) { amount = a; }
	operator string();
private:
	double amount;
};

CMoney::operator string()
{
	//单位
	char* basestr[15] = { "分", "角", "元", "拾", "佰", "仟", "万",
		"拾", "佰", "仟", "亿","拾", "佰", "仟", "万" };
	//数字
	char* datastr[10] = { "零", "壹", "贰", "叁", "肆", "伍", "陆", "柒", "捌", "玖" };

	static char strResult[80];
	double temp, base = 1.0;
	int n = 0;
	temp = amount * 100.0;
	strcpy_s(strResult, "金额为: ");
	if (temp < 1.0)  strcpy_s(strResult, "金额为: 零元零角零分");
	else
	{
		while (temp >= 10.0)
		{	// 计算位数

			base = base * 10.0;
			temp = temp / 10.0;
			n++;
		}
		if (n >= 15)  strcpy_s(strResult, "金额超过范围！");
		else
		{
			temp = amount * 100.0;
			for (int m = n; m >= 0; m--)
			{
				int d = (int)(temp / base);
				temp = temp - base*(double)d;
				base = base / 10.0;
				strcat_s(strResult, datastr[d]);
				strcat_s(strResult, basestr[m]);
			}
		}
	}
	return strResult;
}

void main()
{
	CMoney money(1234123400009.163);
	cout << (string)money << endl;
}