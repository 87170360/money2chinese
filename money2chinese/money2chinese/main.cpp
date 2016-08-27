#include <iostream>
#include <string>
using namespace std;

class CMoney
{
public:
	CMoney(double a = 0.0) { amount = a; }
	//����ǿת������string()
	operator string();
private:
	//����
	double amount;
};

CMoney::operator string()
{
	//��λ ע����֮����ʰ���ۣ�Ǫ��Ҫ����ʰ�򣬰���ǧ������
	char* basestr[15] = { "��", "��", "Ԫ", "ʰ", "��", "Ǫ", "��", "ʰ", "��", "Ǫ", "��","ʰ", "��", "Ǫ", "��" };
	//����
	char* datastr[10] = { "��", "Ҽ", "��", "��", "��", "��", "½", "��", "��", "��" };

	static char strResult[80];
	//ʵ�ʴ��������
	double temp = 1.0; 
	double base = 1.0;
	int n = 0;	
	//����100��������С���������
	temp = amount * 100.0;
	strcpy_s(strResult, "���Ϊ: ");
	//Ϊ������
	if (temp < 1.0)  strcpy_s(strResult, "���Ϊ: ��Ԫ������");
	else
	{
		// ����λ����ǰ��Ŵ���100�����������ٴ���10
		while (temp >= 10.0)
		{
			base = base * 10.0;
			temp = temp / 10.0;			
			n++;
		}
		if (n >= 15)  strcpy_s(strResult, "������Χ��");
		else
		{
			//��ԭtemp
			temp = amount * 100.0;
			for (int m = n; m >= 0; m--)
			{
				//ȡ��λ������
				int d = (int)(temp / base);
				//ȥ�����λ������
				temp = temp - base*(double)d;
				//��һ����λ��
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