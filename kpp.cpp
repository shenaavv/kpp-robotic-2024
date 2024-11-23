#include <iostream>
#include <vector>
using namespace std;


pair<int, int> getDirection(char direction) {
    if (direction == 'U') return {-1, 0}; 
    if (direction == 'D') return {1, 0};  
    if (direction == 'L') return {0, -1}; 
    if (direction == 'R') return {0, 1};  
    return {0, 0};  
}

int main() {
    int M, N;
    cin >> M >> N;  

    vector<string> grid(M);  

    pair<int, int> start, end; 

   
    for (int i = 0; i < M; i++) {
        cin >> grid[i];
        for (int j = 0; j < N; j++) {
            if (grid[i][j] == 'S') {
                start = {i, j};
            } else if (grid[i][j] == 'F') {
                end = {i, j};
            }
        }
    }

    int P;
    cin >> P;

    vector<char> movements(P); 
    for (int i = 0; i < P; i++) {
        cin >> movements[i];
    }

    int x = start.first;  
    int y = start.second; 
    int time = 0;  


    for (char move : movements) {
        time++; 
        pair<int, int> d = getDirection(move);  
        int nx = x + d.first; 
        int ny = y + d.second;

        if (nx >= 0 && nx < M && ny >= 0 && ny < N) {
            char cell = grid[nx][ny];  
            if (cell == 'x') {
                cout << "Robot nabrak, silahkan diperbaiki" << endl;
                break;
            } else if (cell == 'F') {
                cout << "Robot berhasil mencapai tujuan" << endl;
                break;
            } else {
                x = nx;
                y = ny;
            }
        } else {
            cout << "Robot nabrak, silahkan diperbaiki" << endl;
            break;
        }
    }

    if (x == end.first && y == end.second) {
        cout << "Robot berhasil mencapai tujuan" << endl;
    } else {
        cout << "Robot gagal dalam mencapai tujuan :(" << endl;
    }

    cout << "Robot telah berjalan selama " << time << " menit" << endl;

    return 0;
}
