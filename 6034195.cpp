#include <vector>
#include <iostream>
using namespace std;


int solution(vector<vector<int> > seat){
    vector<vector<bool>> sold(100001, vector<bool>(100001, false));
    int count = 0;

    for(int i = 0; i < seat.size(); i++){
        int x = seat.at(i).at(0);
        int y = seat.at(i).at(1);
        //cout<<x<<", "<<y<<endl;
        //cout<<sold.at(x).at(y)<<endl;
        if(sold.at(x).at(y) != true){
            sold.at(x).at(y) = true;
            count++;
        }
    }
    return count;
}
