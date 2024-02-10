#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<vector<int>> students;
    
    vector<int> one{1, 2, 3, 4, 5};
    vector<int> two{2, 1, 2, 3, 2, 4, 2, 5};
    vector<int> three{3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    
    students.push_back(one);
    students.push_back(two);
    students.push_back(three);
    
    int max_score = 0;
    vector<int> scores;
    
    for (vector<int> student: students) {
        int score = 0;
        
        for (int i = 0; i < answers.size(); i++) {
            if (answers[i] == student[i % student.size()]) {
                score++;
            }
        }
        
        if (score > max_score) {
            max_score = score;
        }
        
        scores.push_back(score);
    }
    
    vector<int> answer;
    
    for (int i = 1; i <= 3; i++) {
        if (scores[i - 1] == max_score) {
            answer.push_back(i);
        }
    }
    
    return answer;
}