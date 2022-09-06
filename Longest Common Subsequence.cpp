#include <algorithm>
#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;

int main()
{

	/*
	ابتدا چون طول رشته های ورودی از کاربر مشخص نیست باید دو آرایه ی دو بعدی  پویا تعریف کنیم 
	در اینجا من از وکتور ها استفاده کردم

	یک آرایه برای بحث عدد ها و یک آرایه برای جهت ها

	*/
	vector<vector<int>>Numeric_table;       //آرایه ی عدد ها
	vector<vector<string>>vector_table;       //آرایه ی جهت ها                                              
	string s1, s2;
	cout << "Enter First Sequence :";
	cin >> s1;
	cout << "Enter Second Sequence :";
	cin >> s2;

	string first__loop,second__loop;    
	if (s1.length() > s2.length())  // در اینجا من برای این که تعداد سطر های آرایه ها برابر با طول کوتاه ترین رشته باشد 
			// این مقایسات را انجام میدم
	{//length()=یک متود برای رشته هاست که طول رشته را برمیگرداند 
		first__loop = s2;
		second__loop = s1;
	}
	else
	{
		first__loop = s1;
		second__loop = s2;
	}

	for (int i = 0; i <= first__loop.length(); i++)//مقدار اولیه آرایه ی عددی را صفر و آرایه ی جهت ها که رشته هست را رشته ی تهی در نظر میگیریم
	{
		Numeric_table.push_back(vector<int>());//push_back()= متودی برای وارد کردن عنصر به وکتور هاست
		vector_table.push_back(vector<string>());
		for (int j = 0; j <= second__loop.length(); j++)
		{
			Numeric_table[i].push_back(0);
			vector_table[i].push_back(" ");
		}
	}
	for (int i = 0; i <=first__loop.length(); i++)//پیمایش آرایه و عملی کردن الگوریتم
	{	
		for (int j = 0; j <= second__loop.length(); j++)

			if (i == 0 || j == 0) Numeric_table[i][j] = 0;//در الگوریتم یک سطر و ستون اضافی با مقادیر صفر داشتیم
			
			else if (first__loop.at(i - 1) == second__loop[j - 1]) {//الگوریتم برای برابر بودن کاراکترهای رشته های اول و دوم
				Numeric_table[i][j] = Numeric_table[i - 1][j - 1] + 1;
				vector_table[i][j] = "diagonal";
			}
			else {
				
				if (Numeric_table[i - 1][j] > Numeric_table[i][j - 1])//الگوریتم برای بیشتر بودن ستون قبل نسبت به سطر قبل
				{
					Numeric_table[i][j] = Numeric_table[i - 1][j];
					vector_table[i][j] = "up";
				}
				else {
					Numeric_table[i][j] = Numeric_table[i][j-1];//الگوریتم برای بیشتر بودن سطر قبل نسبت به ستون قبل
					vector_table[i][j] = "left";
				}
			}

	}
	
	int row = first__loop.length();
	int col = second__loop.length();
		stack <char> lcs;//حالا میرسیم به چاپ بلند ترین زیررشته که چون در آرایه ی جهت ها از آخر به اول میرویم
		//من از پشته استفاده میکنم که حاصل را معکوس کند
	

	while (row != 0 && col != 0)
	{
		if (vector_table[row][col] == "diagonal") { //اگر مورب باشه وارد پشته میکند و مقادیر سطر و ستون را یکی کم میکند طبق

			lcs.push(first__loop.at(row-1));
		
			row = row - 1;
			col = col - 1;
		}
		else if (vector_table[row][col] == "left")
			col = col - 1;
		else
			row = row - 1;  
	}
	cout << "The Longest common Subsequence is : ";
	if (lcs.empty()) cout << "There is No Common Subsequence";
	else while (!lcs.empty())//چاپ و بیرون کشیدن کاراکتر ها از پشته 
	{
		cout << lcs.top();
		lcs.pop();
	}
	return 0;


}
