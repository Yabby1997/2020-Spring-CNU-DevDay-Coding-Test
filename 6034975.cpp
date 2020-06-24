#include <string>
#include <vector>
#include <iostream>

using namespace std;

int timeByMinute(string test){
    return (((test[0] - 48) * 10) + test[1] - 48) * 60 + ((test[3] - 48) * 10) + test[4] - 48;
}

vector<string> solution(vector<vector<string>> booked, vector<vector<string>> unbooked) {
    vector<string> answer;
    int minuteTime = 0;
    int bookedIndex = 0;
    int unbookedIndex = 0;
    int booked_time = 0;
    int unbooked_time = 0;

    while(true){
        if(bookedIndex == booked.size()){
            for(int i = unbookedIndex; i < unbooked.size(); i++){
                answer.push_back(unbooked.at(i).at(1));
            }
            break;
        }
        if(unbookedIndex == unbooked.size()){
            for(int i = bookedIndex; i < booked.size(); i++){
                answer.push_back(booked.at(i).at(1));
            }
            break;
        }

        booked_time = timeByMinute(booked.at(bookedIndex).at(0));
        unbooked_time = timeByMinute(unbooked.at(unbookedIndex).at(0));

        if(booked_time <= minuteTime){
            answer.push_back(booked.at(bookedIndex).at(1));
            bookedIndex++;
            minuteTime = minuteTime + 10; 
        }
        else if(unbooked_time <= minuteTime){
            answer.push_back(unbooked.at(unbookedIndex).at(1));
            unbookedIndex++;
            minuteTime = minuteTime + 10;
        }
        else{
            if(booked_time <= unbooked_time){
                answer.push_back(booked.at(bookedIndex).at(1));
                bookedIndex++;
                minuteTime = booked_time + 10; 
            }
            else{
                answer.push_back(unbooked.at(unbookedIndex).at(1));
                unbookedIndex++;
                minuteTime = unbooked_time + 10;
            }
        }
    }
    return answer;
}
