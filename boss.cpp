#include<iostream>
#include<string>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;
vector<int>order, od;
vector<pair<int, int>>skills;
vector<int>b;
vector<int>get_boss(string& boss) {

    string str;
    for (int i = 1; i < boss.size(); i++) {
        if (isdigit(boss[i]))str += boss[i];
        else {
            b.push_back(stoi(str));
            str.clear();
        }
    }
    return b;
}
vector<pair<int, int>>get_skills(string& skills) {
    bool type = false;
    string str;
    vector<pair<int, int>>s;
    pair<int, int>now;
    for (int i = 1; i < skills.size() - 1; i++) {
        if (skills[i] == '[')continue;
        else if (skills[i] == ']') {
            now.second = stoi(str);
            str.clear();
            s.push_back(now);
        }
        else if (skills[i] == ',') {
            if (!type) {
                now.first = stoi(str);
                str.clear();
                type = true;
            }
            else {
                type = false;
            }
        }
        else if (isdigit(skills[i])) {
            str += skills[i];
        }
    }
    return s;
}
void judge_cost(vector<int>& boss, vector<pair<int,int>>& skills, int*& cd, int cost, int hurt, int num) {
    if (!order.empty() && cost >= order.size())return;
    if (num == boss.size()) {
        order = od;
        return;
    }
    for (int i = 0; i < skills.size(); i++) {
        if (cd[i] <= cost) {
            int temp = cd[i];
            hurt += skills[i].first;
            cd[i] = cost + skills[i].second + 1;
            od.push_back(i);
            if (hurt >= boss[num])judge_cost(boss, skills, cd, cost + 1, 0, num + 1);
            else judge_cost(boss, skills, cd, cost + 1, hurt, num);
            od.pop_back();
            cd[i] = temp;
            hurt -= skills[i].first;
        }
    }
}
bool cmp(const pair<int,int>&a,const pair<int,int>&b){
    if(a.first!=b.first)return a.first>b.first;
    return a.second>b.second;
}
vector<int> BOSS_PK(string &b,string&s) {
    int* cd;
    vector<int>boss = get_boss(b);
    skills = get_skills(s);
    sort(skills.begin(),skills.end(),cmp);
    cd = new int[skills.size()];
    for (int i = 0; i < skills.size(); i++)cd[i] = 0;
    judge_cost(boss, skills, cd, 0, 0, 0);
    return order;
}
