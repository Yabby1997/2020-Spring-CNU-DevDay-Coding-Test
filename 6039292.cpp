#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

string solution(string rule, string A, string B) {
    string answer = "";
    vector<int> vecA;
    vector<int> vecB;

    //숫자로 변환해서 AB에 넣기
    for(int i = 0; i < A.size(); i++){
        vecA.push_back(rule.find(A[i]));
    }

    for(int i = 0; i < B.size(); i++){
        vecB.push_back(rule.find(B[i]));
    }

    //zero패딩. A와 B길이맞추기 
    vecB.insert(vecB.begin(), vecA.size() - vecB.size(), 0);

    //A에서 B 빼기
    for(int i = 0; i < A.size(); i++){
        vecA[i] = vecA[i] - vecB[i];
    }

    //뒤부터 앞으로 오면서 음수 양수로 바꿔주면서 캐리 내리기
    for(int i = A.size() - 1; i >= 0; i--){
        while(vecA[i] < 0){
            vecA[i] += rule.size();
            vecA[i - 1] -= 1;
        }
    }

    //최고차 숫자 인덱스 찾기
    int nonZeroIndex = 0;
    while(true){
        if(vecA[nonZeroIndex] != 0){
            break;
        }
        nonZeroIndex++;
    }

    //최고차부터 끝까지 내려가면서 정답 문자로 바꿔서 answer랑 합쳐주기
    for(int i = nonZeroIndex; i < vecA.size(); i++){
        answer = answer + rule[vecA[i]];
        cout<<rule[vecA[i]]<<" ";
    }
    cout<<endl;

    if(answer == "")
        answer += rule[0];

    return answer;
}
