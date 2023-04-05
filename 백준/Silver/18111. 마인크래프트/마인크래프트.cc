#include <iostream>

using namespace std;

int land[500][500];

int main() {
    int N, M, B;
    cin >> N >> M >> B;
    
    int min_height = 257;
    int max_height = -1;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int height;
            cin >> height;
            
            land[i][j] = height;
            
            if (height > max_height) max_height = height;
            if (height < min_height) min_height = height;
        }
    }
    
    int answer_time, answer_height;
    answer_time = 500 * 500 * 256 * 2;
    
    for (int height = min_height; height <= max_height; height++) {
        int seconds = 0;
        int blocks = B;
        
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (land[i][j] > height) {
                    seconds += 2 * (land[i][j] - height);
                    blocks += land[i][j] - height;
                } else {
                    seconds += height - land[i][j];
                    blocks -= height - land[i][j];
                }
            }
        }
        
        if (blocks < 0) continue;
        
        if (seconds <= answer_time) {
            answer_time = seconds;
            answer_height = height;
        }
    }
    
    cout << answer_time << " " << answer_height << endl;
    
    return 0;
}