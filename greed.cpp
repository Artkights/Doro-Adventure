#include<iostream>
#include<string>
#include<queue>
#include<vector>
#include<utility>
using namespace std;
extern const pair<int,int> mov[4];
extern const char ch[5];
extern vector<int>order;
extern int validCount;
string find_way(vector<string>& maze,const pair<int,int>&b,const pair<int,int>&e,bool**been) {
    //for (int i = 0; i < maze.size(); i++)cout << maze[i] << "\n";
    int r = maze.size(), c = maze[0].size();
    pair<int, int>now;
    queue<pair<int, int>>q;
    string** vis;
    vis = new string * [r];
    for (int i = 0; i < r; i++) {
        vis[i] = new string[c];
        for (int j = 0; j < c; j++) {
            vis[i][j].clear();
        }
    }

    now = b;
    q.push(now);
    while (!q.empty()) {
        now = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            now.first += mov[i].first;
            now.second += mov[i].second;
            if (now.first >= 0 && now.first < r && now.second >= 0 && now.second < c && maze[now.first][now.second] != '#' && (vis[now.first][now.second].empty() && now != b)&&been[now.first][now.second]) {
                vis[now.first][now.second] = vis[now.first - mov[i].first][now.second - mov[i].second] + ch[i];
                if (now == e)return vis[e.first][e.second];
                q.push(now);
            }
            now.first -= mov[i].first;
            now.second -= mov[i].second;
        }
    }
    return vis[e.first][e.second];
}
string greed(vector<string>& maze) {
    struct node {
        int first;
        int second;
        int value;
        int dis;
        bool operator<(const node& a)const {
            if (this->value != a.value)return this->value < a.value;
            return this->dis < a.dis;
        }
        bool operator!=(const node& a)const {
            if (this->first != a.first || this->second != a.second)return true;
            else return false;
        }
    }now, pass;
    priority_queue<node, vector<node>, less<node>>p;
    bool** vis;
    string road;
    cout << "1\n";
    int r = maze.size(), c = maze[0].size(), temp = order.size();
    vis = new bool* [maze.size()];
    for (int i = 0; i < maze.size(); i++) {
        vis[i] = new bool[maze[0].size()];
        for (int j = 0; j < maze[0].size(); j++) {
            vis[i][j] = false;
            if (maze[i][j] == 'S')now.first = i, now.second = j;
        }
    }
    now.dis = 0;
    p.push(now);
    pass = now;
    while (maze[now.first][now.second] != 'E') {
        cout << "3" << endl;
        now = p.top();
        p.pop();
        now.dis++;
        if (!vis[now.first][now.second])vis[now.first][now.second] = true;
        else continue;
        if (pass != now) {
            pair<int, int>b, e;
            b.first = pass.first;
            b.second = pass.second;
            e.first = now.first;
            e.second = now.second;
            road += find_way(maze, b, e, vis);
        }
        for (int i = 0; i < 4; i++) {
            now.first += mov[i].first;
            now.second += mov[i].second;
            if (now.first >= 0 && now.first < r && now.second >= 0 && now.second < c && maze[now.first][now.second] != '#' && !vis[now.first][now.second]) {
                switch (maze[now.first][now.second]) {
                case ' ':
                    now.value = 0;
                    break;
                case 'E':
                    now.value = -1;
                    break;
                case 'L':
                    now.value = -validCount;
                    break;
                case 'B':
                    now.value = -temp;
                    break;
                case 'G':
                    now.value = 5;
                    break;
                case 'T':
                    now.value = -3;
                    break;
                }
                p.push(now);
            }
            now.first -= mov[i].first;
            now.second -= mov[i].second;
        }
        pass = now;
    }
    return road;
}
