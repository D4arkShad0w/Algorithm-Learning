#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class activity
{
private:
	int index;
	int start_time;
	int finish_time;
public:

	activity();
	~activity();
	void set_index(int);
	int get_index(void);
	int get_finish_time(void);
	int get_start_time(void);
	void set_start_time(int);
	void set_finish_time(int);


};



activity::activity()
{
	
	index = 0;
	start_time = 0;
	finish_time = 0;
}

activity::~activity()
{
}

void activity::set_index(int a)
{
	index = a;
}

int activity::get_index(void)
{
	return index ;
}

int activity::get_finish_time(void)
{
	return finish_time;

}

int activity::get_start_time(void)
{
	return start_time;
}

void activity::set_start_time(int start)
{
	start_time = start;
}

void activity::set_finish_time(int finish)
{
	finish_time = finish;
}

bool compare(activity a, activity b)
{
	return  a.get_finish_time() < b.get_finish_time();
}

int main()
{
	
	int number__activity;
	activity* temp_pointer=NULL;
	int start_temp,finish_temp;
	
	vector<activity> __activity__;
	cout << "Enter Number of Activities : ";
	cin >> number__activity;
	for (int i = 0; i < number__activity; i++)
	{

		cout << "Enter Start and Finish of " << i + 1 << " st Activites : ";
		cin >> start_temp >> finish_temp;
		temp_pointer = new activity;
		temp_pointer->set_start_time(start_temp);
		temp_pointer->set_finish_time(finish_temp);
		temp_pointer->set_index(i + 1);
		__activity__.push_back(*temp_pointer);
	}
	delete temp_pointer;

	

	sort(__activity__.begin(), __activity__.end(), compare);
	vector<int> result;
	int i = 0;
	cout << __activity__.at(0).get_index()<<" ";
	for (int j = 1; j < __activity__.size(); j++)
	{

		
		if (__activity__.at(j).get_start_time() >= __activity__.at(i).get_finish_time()) {
			result.push_back(__activity__.at(j).get_index());
			i = j;
		}
		
	}
	if (result.empty()) cout << "There is No Compatible Activites";
	else
	for (int i = 0; i < result.size(); i++)
		cout << result.at(i) << " ";
	

	return 0;

}