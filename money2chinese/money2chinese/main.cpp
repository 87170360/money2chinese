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
	char* basestr[15] = { "·Ö", "½Ç", "Ôª", "Ê°", "°Û", "Çª", "Íò",
		"Ê°", "°Û", "Çª", "ÒÚ","Ê°", "°Û", "Çª", "Íò" };
	char* datastr[10] = { "Áã", "Ò¼", "·¡", "Èş", "ËÁ", "Îé", "Â½", "Æâ", "°Æ", "¾Á" };
	static char strResult[80];
	double temp, base = 1.0;
	int n = 0;
	temp = amount * 100.0;
	strcpy_s(strResult, "½ğ¶îÎª: ");
	if (temp < 1.0)  strcpy_s(strResult, "½ğ¶îÎª: ÁãÔªÁã½ÇÁã·Ö");
	else
	{
		while (temp >= 10.0)
		{	// ¼ÆËãÎ»Êı

			base = base * 10.0;
			temp = temp / 10.0;
			n++;
		}
		if (n >= 15)  strcpy_s(strResult, "½ğ¶î³¬¹ı·¶Î§£¡");
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