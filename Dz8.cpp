#include <iostream> 
#include <Windows.h>
using namespace std;

class Time {
private:
    int hours;
    int minutes;
    int seconds;

public:
    Time() : hours(0), minutes(0), seconds(0) {}

    Time(int  hoursP, int minutesP, int secondsP) : hours(hoursP), minutes(minutesP), seconds(secondsP) {
        check();
    }

    void check() {
        while (seconds >= 60) {
            seconds -= 60;
            minutes++;
        }
        while (minutes >= 60) {
            minutes -= 60;
            hours++;
        }
        while (hours >= 24) {
            hours -= 24;
        }
    }

    void check(int sec, int min = 0, int hr = 0) {
        seconds -= sec;
        minutes -= min;
        hours -= hr;

        while (seconds < 0) {
            seconds += 60;
            minutes--;
        }
        while (minutes < 0) {
            minutes += 60;
            hours--;
        }
        while (hours < 0) {
            hours += 24;
        }
    }

    void addingSeconds() {
        seconds++;
        check();
    }

    Time& operator++() {
        addingSeconds();
        return *this;
    }

    Time& operator--() {
        check(1);
        return *this;
    }

    bool operator==(const Time& t) const {
        return (hours == t.hours && minutes == t.minutes && seconds == t.seconds);
    }

    bool operator!=(const Time& t) const {
        return !(*this == t);
    }

    friend bool operator>(const Time& t1, const Time& t2) {
        if (t1.hours > t2.hours) {
            return true;
        }
        else if (t1.hours < t2.hours) {
            return false;
        }
        else {
            if (t1.minutes > t2.minutes) {
                return true;
            }
            else if (t1.minutes < t2.minutes) {
                return false;
            }
            else {
                if (t1.seconds > t2.seconds) {
                    return true;
                }
                else {
                    return false;
                }
            }
        }
    }

    friend bool operator<(const Time& t1, const Time& t2) {
        if (t1.hours < t2.hours) {
            return true;
        }
        else if (t1.hours > t2.hours) {
            return false;
        }
        else {
            if (t1.minutes < t2.minutes) {
                return true;
            }
            else if (t1.minutes > t2.minutes) {
                return false;
            }
            else {
                if (t1.seconds < t2.seconds) {
                    return true;
                }
                else {
                    return false;
                }
            }
        }
    }

    friend istream& operator>>(istream& input, Time& t) {
        cout << "Введіть години: ";
        input >> t.hours;
        cout << "Введіть хвилини: ";
        input >> t.minutes;
        cout << "Введіть секунди: ";
        input >> t.seconds;
        t.check();
        return input;
    }

    friend ostream& operator<<(ostream& output, const Time& t) {
        if (t.hours < 10) {
            output << "0";
        }
        output << t.hours << ":";

        if (t.minutes < 10) {
            output << "0";
        }
        output << t.minutes << ":";

        if (t.seconds < 10) {
            output << "0";
        }
        output << t.seconds;

        return output;
    }

    Time& operator=(const Time& t) {
        if (this != &t) {
            hours = t.hours;
            minutes = t.minutes;
            seconds = t.seconds;
        }
        return *this;
    }

    Time& operator+=(int sec) {
        seconds += sec;
        check();
        return *this;
    }

    Time& operator-=(int sec) {
        check(sec);
        return *this;
    }

    void operator()() const {
        cout << *this << endl;
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Time t1(12, 59, 29);
    Time t2(9, 1, 1);

    cout << "Час №1: " << t1 << endl;
    cout << "Час №2: " << t2 << endl;

    Time t3;
    cout << "Введіть час №3:\n";
    cin >> t3;
    cout << "Введений час №3: " << t3 << endl;

    Time t4 = t3;
    cout << "Час №4 (№4 = №3): " << t4 << endl;

    if (t1 == t2) {
        cout << "Час №1 дорівнює №2" << endl;
    }
    else if (t1 != t2) {
        cout << "Час №1 не дорівнює №2" << endl;
    }

    if (t1 < t2) {
        cout << "Час №1 менше №2" << endl;
    }
    else if (t1 > t2) {
        cout << "Час №1 більше №2" << endl;
    }

    cout << "№1 ++ (зміна на 1 сек): " << ++t1 << endl;

    cout << "№1 -- (зміна на 1 сек): " << --t1 << endl;

    t1 += 3600;
    cout << "Після додавання 3600 секунд до часу №1: " << t1 << endl;

    t1 -= 3600;
    cout << "Після віднімання 3600 секунд до часу №1: " << t1 << endl;

    cout << "Виклик часу №1 через (): ";
    t1();

    return 0;
}
