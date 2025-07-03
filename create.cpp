#include<iostream>
#include<vector>
#include<string>
#include<random>
#include<queue>
#include<utility>
#include<iomanip>
#include<ctime>
using namespace std;

const pair<int, int>mov[4] = { {0,1},{0,-1},{1,0},{-1,0} };
const char ch[5] = { "RLDU" };

vector<vector<int>>validPasswords;

extern string solve(vector<string> maze, string road);
extern vector<vector<int>> lock(string& input, int& userPassword);
extern vector<int> BOSS_PK(string& b, string& s);

string judge(vector<string>& maze) {
    //for (int i = 0; i < maze.size(); i++)cout << maze[i] << "\n";
    int r = maze.size(), c = maze[0].size(), num = 0;
    pair<int, int>now, e, b;
    queue<pair<int, int>>q;
    string** vis;
    vis = new string * [r];
    for (int i = 0; i < r; i++) {
        vis[i] = new string[c];
        for (int j = 0; j < c; j++) {
            if (maze[i][j] == 'S') {
                b.first = i;
                b.second = j;
            }
            if (maze[i][j] == 'E') {
                e.first = i;
                e.second = j;
            }
            if (maze[i][j] != '#')num++;
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
            if (now.first >= 0 && now.first < r && now.second >= 0 && now.second < c && maze[now.first][now.second] != '#' && (vis[now.first][now.second].empty() && now != b)) {
                vis[now.first][now.second] = vis[now.first - mov[i].first][now.second - mov[i].second] + ch[i];
                q.push(now);
                num--;
            }
            now.first -= mov[i].first;
            now.second -= mov[i].second;
        }
    }
    if (!num)return vis[b.first][b.second];
    else return solve(maze, vis[e.first][e.second]);
}

void opendoor(int x1, int y1, int x2, int y2, vector<string>& maze) {
    int pos;
    if (x1 == x2) {
        pos = y1 + rand() % ((y2 - y1) / 2 + 1) * 2;
        maze[x1][pos] = ' ';
    }
    else {
        pos = x1 + rand() % ((x2 - x1) / 2 + 1) * 2;
        maze[pos][y1] = ' ';
    }
}

void devide(int x, int y, int h, int w, vector<string>& maze) {
    if (h < 3 || w < 3)return;
    int xpos, ypos, type;
    xpos = x + rand() % (h / 2) * 2 + 1;
    cout << xpos << " ";
    for (int i = y; i < y + w; i++)maze[xpos][i] = '#';
    ypos = y + rand() % (w / 2) * 2 + 1;
    cout << ypos << "\n";
    for (int i = x; i < x + h; i++)maze[i][ypos] = '#';
    type = rand() % 4;

    switch (type)
    {
    case 0:
        opendoor(xpos + 1, ypos, x + h - 1, ypos, maze);
        opendoor(xpos, ypos + 1, xpos, y + w - 1, maze);
        opendoor(x, ypos, xpos - 1, ypos, maze);
        break;
    case 1:
        opendoor(xpos, ypos + 1, xpos, y + w - 1, maze);
        opendoor(x, ypos, xpos - 1, ypos, maze);
        opendoor(xpos, y, xpos, ypos - 1, maze);
        break;
    case 2:
        opendoor(x, ypos, xpos - 1, ypos, maze);
        opendoor(xpos, y, xpos, ypos - 1, maze);
        opendoor(xpos + 1, ypos, x + h - 1, ypos, maze);
        break;
    case 3:
        opendoor(xpos, y, xpos, ypos - 1, maze);
        opendoor(xpos + 1, ypos, x + h - 1, ypos, maze);
        opendoor(xpos, ypos + 1, xpos, y + w - 1, maze);
        break;
    }
    devide(x, y, xpos - x, ypos - y, maze);
    devide(x, ypos + 1, xpos - x, w - ypos + y - 1, maze);
    devide(xpos + 1, y, h - xpos + x - 1, ypos - y, maze);
    devide(xpos + 1, ypos + 1, h - xpos + x - 1, w - ypos + y - 1, maze);
}

vector<string> init_map(int seed) {
    int r,//  ͼ д С
        c;//  ͼ д С
    srand(seed);
    r = rand() % 9 + 7;
    if (r % 2 == 0)r++;
    c = r;//  ʱ   շ
    vector<string>maze(r);
    for (int i = 0; i < r; i++) {
        maze[i].resize(c);
        for (int j = 0; j < c; j++)maze[i][j] = ' ';
    }

    for (int i = 0; i < r; i++)maze[i][0] = '#', maze[i][c - 1] = '#';
    for (int i = 0; i < c; i++)maze[0][i] = '#', maze[r - 1][i] = '#';

    devide(1, 1, r - 2, c - 2, maze);

    for (int i = 0; i < 4 + r; i++) {
        int x = rand() % r;
        int y = rand() % c;
        while (maze[x][y] != ' ') {
            x = rand() % r;
            y = rand() % c;
        }
        if (i == 0)maze[x][y] = 'S';
        else if (i == 1)maze[x][y] = 'L';
        else if (i == 2)maze[x][y] = 'B';
        else if (i <= 3 + r / 2)maze[x][y] = 'G';
        else if (i <= 3 + r)maze[x][y] = 'T';
    }
    while (1) {
        int x = rand() % r;
        int y = rand() % c;
        if (maze[1][y] != '#') {
            maze[0][y] = 'E';
            break;
        }
        else if (maze[r - 2][y] != '#') {
            maze[r - 1][y] = '#';
            break;
        }
        else if (maze[x][1] != '#') {
            maze[x][0] = 'E';
            break;
        }
        else if (maze[x][c - 2] != '#') {
            maze[x][c - 1] = 'E';
            break;
        }
    }
    char odd[6] = "13579", even[5] = "2468";
    int num_clue = rand() % 3 + 1, password = 0;
    string input = "[";
    for (int i = 1; i <= num_clue; i++) {
        int num = rand() % 2;
        input += '[';
        if (i == 1)input += "1,";
        else if (i == 2)input += "2,";
        else if (i == 3)input += "3,";
        if (num & 1) {
            input += '1';
            password *= 10;
            password += odd[rand() % 5] - '0';
        }
        else {
            input += '0';
            password *= 10;
            password += even[rand() % 4] - '0';
        }
        input += ']';
        if (i + 1 <= num_clue)input += ',';
    }
    for (int i = num_clue + 1; i <= 3; i++) {
        password *= 10;
        password += rand() % 10;
    }
    input += "]";
    cout << input << " " << password << "\n";
    validPasswords = lock(input, password);

    int boss_num = rand() % 4 + 2;
    string boss;
    boss += '[';
    for (int i = 0; i < boss_num; i++) {
        int num = rand() % 50 + 10;
        boss += to_string(num);
        if (i + 1 < boss_num)boss += ',';
    }
    boss += ']';

    int skill_num = rand() % 5 + 1, a, b;
    string skills;
    skills += '[';
    a = rand() % 20 + 1;
    skills += "[";
    skills += to_string(a);
    skills += ",0],";
    for (int i = 0; i < skill_num - 1; i++) {
        skills += "[";
        a = rand() % 20 + 1;
        b = rand() % 5 + 1;
        skills += (to_string(a) + "," + to_string(b));
        skills += ']';
        if (i + 1 < skill_num)skills += ',';
    }
    skills += ']';
    cout << boss << "\n" << skills << '\n';
    BOSS_PK(boss, skills);


    return maze;
}

