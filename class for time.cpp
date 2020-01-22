#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

class Time {
    private:
        int hour;
        int minute;
        int second;
    public:
        Time(int hour = 0, int minute = 0, int second = 0);
        Time(const Time& time);
        ~Time();
        void setHour(int hour);
        void setMinute(int minute);
        void setSecond(int second);
        int getHour() const;
        int getMinute() const;
        int getSecond() const;
        string toString() const;
        bool isValid() const;
        Time after(int seconds);
        void increment();
};
 
Time::Time(int hh,int mm,int ss)
	{
		setHour(hh);
		setMinute(mm);
		setSecond(ss);
	}
Time::~Time()
    {
    	cout <<"Recycle time" << setfill('0') << setw(2) << hour%12 << ":" << setw(2) << minute << ":" << setw(2) << second << " "
             << " " << ((hour>=12)?"PM":"AM") <<endl;    	
    }
Time::Time(const Time& tt)
{
	hour=tt.getHour();
	minute=tt.getMinute();
	second=tt.getSecond();
}	
void Time::setHour(int hh)
	{
		hour=hh;
	}
void Time::setMinute(int mm)
	{
		minute=mm;
	}
void Time::setSecond(int ss)
	{
		second=ss;
	}
int Time::getHour() const
    {
    	return hour;
    }
int Time::getMinute() const
    {
    	return minute;
    }
int Time::getSecond() const
    {
    	return second;
    }
string Time::toString() const
    {
    	string aaa=(hour%12<10)?("0"+to_string(hour%12)):(to_string(hour%12));
    	string bbb=(minute<10)?("0"+to_string(minute)):(to_string(minute));
    	string ccc=(second<10)?("0"+to_string(second)):(to_string(second));
    	return aaa+bbb+ccc+((hour>=12)?"PM":"AM");
    }
bool Time::isValid() const
    {
    	if(hour>=0&&hour<=23&&minute>=0&&minute<=59&&second>=0&&second<=59)
    	return true;
    	else
    	return false;	
    }
Time Time::after(int ss)
    {
    	second=second+ss;
    	increment();
    	Time aaa;
    	aaa.setHour(hour);
    	aaa.setMinute(minute);
    	aaa.setSecond(second);
    	return aaa;
    }
void Time::increment()
    {
    	int aaa=second;
    	int bbb=minute;
    	second=second%60;
    	minute=(minute+aaa/60)%60;
    	hour=(hour+(bbb+aaa/60)/60)%24;
    } 
    
   int main() {
    Time time0 = Time();
    Time time1 = Time(1, 0);
    Time time2 = Time(23, 12, 34);
    Time time3 = Time(time2);
    cout << time0.toString() << endl;
    cout << time1.toString() << endl;
    cout << time2.toString() << endl;
    cout << time3.toString() << endl;
 
    int h, m, s, random;
    cin >> h >> m >> s >> random;
    Time* time = new Time();
    time->setHour(h);
    time->setMinute(m);
    time->setSecond(s);
 
    cout << "The time is: " << time->getHour() << ":"
        << time->getMinute() << ":" << time->getSecond() << endl;
    if (time->isValid()) {
        cout << "Formatted time is: " << time->toString() << endl;
        cout << "After " << random << " seconds, the time is: ";
        cout << time->after(random).toString() << endl;
    } else {
        cout << "The time is invalid!\n";
    }
    delete time;
} 
