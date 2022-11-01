#include <iostream>
using namespace std;

class Time {
public:

	Time() {

	}

	Time(int h, int m, int s) {
		hours = h;
		minutes = m;
		seconds = s;
	}

	void setHour(int h) {
		hours = h;
	}

	int getHour() {
		
		return hours;
	}

	void setMinute(int m) {
		minutes = m;
	}

	int getMinutes() {

		return minutes;
	}

	void setSecond(int s) {
		seconds = s;
	}

	int getSeconds() {

		return seconds;
	}

	Time operator+(Time t) {
		Time tmp;

		if (seconds + t.seconds > 59) {
			tmp.seconds = seconds + t.seconds - 60;
			if (minutes + t.minutes + 1 > 59) {
				tmp.minutes = minutes + t.minutes + 1 - 60;
				tmp.hours = hours + t.hours + 1;
			}
			else {
				tmp.minutes = minutes + t.minutes + 1;
				tmp.hours = hours + t.hours;
			}
			if (hours + t.hours + 1 > 23) {
				tmp.hours = hours + t.hours + 1 - 24;
			}
			else
				tmp.hours = hours + t.hours;	

		}
		else {
			tmp.seconds = seconds + t.seconds;
			tmp.minutes = minutes + t.minutes;
			if (minutes + t.minutes > 59) {
				tmp.minutes = minutes + t.minutes - 60;
				tmp.hours = hours + t.hours + 1;
				if (hours + t.hours + 1 > 23) {
					tmp.hours = hours + t.hours + 1 - 24;
				}
			}
			else
				if (tmp.hours = hours + t.hours > 23)
					tmp.hours = hours + t.hours - 24;
				else
					tmp.hours = hours + t.hours;
				
		}
		return tmp;
	}

	Time operator-(Time t) {
		Time tmp;
		if (hours < t.hours) {
			if (seconds < t.seconds) {
				tmp.seconds = 60 - (t.seconds - seconds);
			}
			else
				tmp.seconds = seconds - t.seconds;

			if (minutes < t.minutes) {
				tmp.minutes = 60 - (t.minutes - minutes);
			}
			else
				tmp.minutes = minutes - t.minutes;
			tmp.hours = 24 + (hours - t.hours);
		}
		else {
			if (seconds < t.seconds) {
				tmp.seconds = 60 - (t.seconds - seconds);
			}
			else
				tmp.seconds = seconds - t.seconds;

			if (minutes < t.minutes) {
				tmp.minutes = 60 - (t.minutes - minutes);
			}
			else
				tmp.minutes = minutes - t.minutes;
			tmp.hours = hours - t.hours;
		}
		return tmp;
	}


	bool operator<(Time t) {
		cout << t.hours << ":" << t.minutes << ":" << t.seconds << " < " << hours << ":" << minutes << ":" << seconds << endl;
		return t.hours < hours;
	}

	bool operator>(Time t) {
		cout << t.hours << ":" << t.minutes << ":" << t.seconds << " > " << hours << ":" << minutes << ":" << seconds << endl;
		return t.hours > hours;
	}

	bool operator==(Time t) {
		cout << t.hours << ":" << t.minutes << ":" << t.seconds << " = " << hours << ":" << minutes << ":" << seconds << endl;
		return t.hours == hours;
	}

	bool operator!=(Time t) {
		cout << t.hours << ":" << t.minutes << ":" << t.seconds << " != " << hours << ":" << minutes << ":" << seconds << endl;
		return t.hours != hours;
	}

	Time operator ++(int n) {
		hours++;
		if (hours > 23) {
			hours = 0;
		}
		return *this;
	}

	Time operator --(int n) {
		hours--;
		if (hours < 0) {
			hours = 23;
		}
		return *this;
	}

	void PMtoAM() {
		Time tmp;
		cout << "Enter PM time: \n";
		cin >> tmp;
		if (tmp.hours > 12) {
			tmp.hours -= 12;
			cout << "AM time - " << tmp;
		}
		else
			cout << "AM time - " << tmp;
	}

	friend ostream& operator << (ostream& os, Time& t); 
	friend istream& operator >> (istream& is, Time& t); 

	static void changeGMT() {
		poyas = "GMT + 5";
	}

	

private:
	int hours;
	int minutes;
	int seconds;
	static string poyas;
};

string Time::poyas = "GMT + 3";

int main() {

	Time t1(2, 30, 46);
	Time t2;

	cin >> t2;

	cout << t1 << endl;

	Time t3 = t1 + t2;
	cout << "Addition: " << t3 << endl;

	Time t4 = t1 - t2;
	cout << "Subtraction: " << t4 << endl;

	cout << (t1 < t2) << endl;
	cout << (t1 > t2) << endl;
	cout << (t1 == t2) << endl;
	cout << (t1 != t2) << endl;

	t1++;
	cout << t1 << endl;
	t2--;
	cout << t2 << endl;

	t1.PMtoAM();

	Time::changeGMT();
	cout << endl;

	cout << t1 << endl;

	return 0;
}

ostream& operator<<(ostream& os, Time& t) 
{
	os << t.hours << ":" << t.minutes << ":" << t.seconds << " " << t.poyas;
	return os;
}

istream& operator>>(istream& is, Time& t) 
{
	cout << "Enter hours: ";
	is >> t.hours;
	cout << "Enter minutes: ";
	is >> t.minutes;
	cout << "Enter seconds: ";
	is >> t.seconds;
	return is;
}