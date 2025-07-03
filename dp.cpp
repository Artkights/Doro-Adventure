#include<iostream>
#include<vector>
#include<string>
#include<utility>
#include <iomanip>
using namespace std;
extern vector<int>order;
extern int validCount;
extern const pair<int, int>mov[4] = { {0,1},{0,-1},{1,0},{-1,0} };
extern const char ch[5] = { "RLDU" };
int** dp;
int cost = order.size();
int judge_dp(pair<int, int>now, vector<string>&maze,bool**& vis) {
    switch (maze[now.first][now.second]) {
    case ' ':
        dp[now.first][now.second] = 0;
        break;
    case 'T':
        dp[now.first][now.second] = -30;
        break;
    case 'B':
        dp[now.first][now.second] = -cost;
        break;
    case 'L':
        dp[now.first][now.second] = -validCount;
        break;
    case 'G':
        dp[now.first][now.second] = 50;
        break;
    case '#':
        dp[now.first][now.second] = 0;
        break;
    }
    if (maze[now.first][now.second] == '#')return 0;
    for (int i = 0; i < 4; i++) {
        now.first += mov[i].first;
        now.second += mov[i].second;
        if (now.first >= 0 && now.first < maze.size() && now.second >= 0 && now.second < maze[0].size() && !vis[now.first][now.second]) {
            vis[now.first][now.second] = true;
            dp[now.first - mov[i].first][now.second - mov[i].second] += max(0, judge_dp(now, maze, vis));
            vis[now.first][now.second] = false;
        }
        now.first -= mov[i].first;
        now.second -= mov[i].second;
    }
    return dp[now.first][now.second];
}

void get_way(pair<int, int>now, vector<string>& maze, bool**& vis, string& way, char pos) {
    way.push_back(pos);
    for (int i = 0; i < 4; i++) {
        now.first += mov[i].first;
        now.second += mov[i].second;
        if (now.first >= 0 && now.first < maze.size() && now.second >= 0 && now.second < maze[0].size() && !vis[now.first][now.second]) {
            vis[now.first][now.second] = true;
            if (dp[now.first][now.second] > 0)get_way(now, maze, vis, way, ch[i]);
            vis[now.first][now.second] = false;
        }
        now.first -= mov[i].first;
        now.second -= mov[i].second;
    }
    if (pos == 'L')way.push_back('R');
    if (pos == 'R')way.push_back('L');
    if (pos == 'D')way.push_back('U');
    if (pos == 'U')way.push_back('D');
}

string solve(vector<string> maze, string road) {
    string way;
    int r = maze.size(), c = maze[0].size();
    bool** vis;
    pair<int, int>now, b;
    vis = new bool* [r];
    dp = new int*[r];
    for (int i = 0; i < r; i++) {
        vis[i] = new bool[c];
        dp[i] = new int[c];
        for (int j = 0; j < c; j++) {
            vis[i][j] = false;
            dp[i][j] = 0;
            if (maze[i][j] == 'S')now.first = i, now.second = j;
        }
    }
    vis[now.first][now.second] = true;
    b = now;
    for (int i = 0; i < road.size(); i++) {
        switch (road[i]) {
        case 'R':
            now.second++;
            break;
        case 'L':
            now.second--;
            break;
        case 'D':
            now.first++;
            break;
        case 'U':
            now.first--;
            break;
        }
        vis[now.first][now.second] = true;
    }
    now = b;
    for (int j = 0; j < road.size(); j++) {
        dp[now.first][now.second] = 1000;
        for (int i = 0; i < 4; i++) {
            now.first += mov[i].first;
            now.second += mov[i].second;
            if (now.first >= 0 && now.first < maze.size() && now.second >= 0 && now.second < maze[0].size() && !vis[now.first][now.second]) {
                vis[now.first][now.second] = true;
                judge_dp(now, maze, vis);
                vis[now.first][now.second] = false;
            }
            now.first -= mov[i].first;
            now.second -= mov[i].second;
        }
        switch (road[j]) {
        case 'R':
            now.second++;
            break;
        case 'L':
            now.second--;
            break;
        case 'D':
            now.first++;
            break;
        case 'U':
            now.first--;
            break;
        }
    }

    for (int i = 0; i < maze.size(); i++) {
        for (int j = 0; j < maze[0].size(); j++) {
            cout << std::right << setw(5) << dp[i][j];
        }
        cout << "\n";
    }

    now = b;
    for (int j = 0; j < road.size(); j++) {
        for (int i = 0; i < 4; i++) {
            now.first += mov[i].first;
            now.second += mov[i].second;
            if (now.first >= 0 && now.first < maze.size() && now.second >= 0 && now.second < maze[0].size() && !vis[now.first][now.second]) {
                vis[now.first][now.second] = true;
                if (dp[now.first][now.second] > 0)get_way(now, maze, vis, way, ch[i]);
                vis[now.first][now.second] = false;
            }
            now.first -= mov[i].first;
            now.second -= mov[i].second;
        }
        switch (road[j]) {
        case 'R':
            now.second++;
            break;
        case 'L':
            now.second--;
            break;
        case 'D':
            now.first++;
            break;
        case 'U':
            now.first--;
            break;
        }
        way += road[j];
    }
    return way;
}
