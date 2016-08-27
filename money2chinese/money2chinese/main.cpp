#include <iostream>
#include <string>
using namespace std;

class CMoney
{
public:
	CMoney(double a = 0.0) { amount = a; }
	//重载强转操作符string()
	operator string();
private:
	//数字
	double amount;
};

CMoney::operator string()
{
	//单位 注意万之后，是拾，佰，仟，要处理拾万，百万，千万的情况
	char* basestr[15] = { "分", "角", "元", "拾", "佰", "仟", "万", "拾", "佰", "仟", "亿","拾", "佰", "仟", "万" };
	//数字
	char* datastr[10] = { "零", "壹", "贰", "叁", "肆", "伍", "陆", "柒", "捌", "玖" };

	static char strResult[80];
	//实际处理的数字
	double temp = 1.0; 
	double base = 1.0;
	int n = 0;	
	//扩大100倍，处理小数点后的情况
	temp = amount * 100.0;
	strcpy_s(strResult, "金额为: ");
	//为零的情况
	if (temp < 1.0)  strcpy_s(strResult, "金额为: 零元零角零分");
	else
	{
		// 计算位数，前面放大了100倍，所以至少大于10
		while (temp >= 10.0)
		{
			base = base * 10.0;
			temp = temp / 10.0;			
			n++;
		}
		if (n >= 15)  strcpy_s(strResult, "金额超过范围！");
		else
		{
			//还原temp
			temp = amount * 100.0;
			for (int m = n; m >= 0; m--)
			{
				//取该位的数字
				int d = (int)(temp / base);
				//去掉最高位的数字
				temp = temp - base*(double)d;
				//下一数的位数
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