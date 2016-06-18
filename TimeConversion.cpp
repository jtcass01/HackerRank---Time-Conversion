#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

void displayMilitaryTime(string);
void printMilitaryTime(int,int,int);
int stringToNumber(const string&);

int main(){
    string time;
    cin >> time;
    displayMilitaryTime(time);
    return 0;
}

void displayMilitaryTime(string input){
    int hour=0,minute=0,second=0;
    string amOrPM = input.substr(8,2);
    
    //Hour
    hour = stringToNumber(input.substr(0,2));
    if((amOrPM == "PM") && (hour!=12)){
        hour+=12;
    } else if ((amOrPM == "AM") && (hour == 12)){
        hour = 0;
    }
    //Minute
    minute = stringToNumber(input.substr(3,2));
    //Second
    second = stringToNumber(input.substr(6,2));
    printMilitaryTime(hour,minute,second);
}

void printMilitaryTime(int hour, int minute, int second){
    //Hour
    if(hour < 10){
        cout << 0 << hour;
    } else if (hour >= 10) {
        cout << hour;
    }
    cout << ":";
    //minute
    if(minute<10){
        cout << 0 << minute;
    } else if (minute >= 10){
        cout << minute;
    }
    cout << ":";
    //second
    if(second < 10){
        cout << 0 << second;
    } else if (second >= 10) {
        cout << second;
    }
}

int stringToNumber(const string&Text){
    stringstream ss(Text);
    int result;
    return ss >> result ? result: 0;
}
