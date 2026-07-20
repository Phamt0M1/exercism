#include <array>
#include <string>
#include <vector>

std::vector<int> round_down_scores(std::vector<double> student_scores) {
    std::vector<int> result{};
    for (double x : student_scores) {
        result.push_back(static_cast<int>(x));
    }
    return result;
}

int count_failed_students(std::vector<int> student_scores) {
    int not_passing{0};
    for (int x : student_scores) {
        if (x <= 40) {
            not_passing++;
        }
    }
    return not_passing;
}

std::array<int, 4> letter_grades(int highest_score) {
    int step = (highest_score - 40) / 4;
    std::array<int, 4> grades{};
    for (int i = 0; i < 4; ++i) {
        grades[i] = 41 + i * step;
    }
    return grades;
}

std::vector<std::string> student_ranking(std::vector<int> student_scores, std::vector<std::string> student_names) {
    std::vector<std::string> ranking{};
    for (std::size_t i = 0; i < student_scores.size(); ++i) {
        ranking.emplace_back(std::to_string(i + 1) + ". " + student_names[i] + ": " + std::to_string(student_scores[i])
        );
    }
    return ranking;
}

std::string perfect_score(std::vector<int> student_scores, std::vector<std::string> student_names) {
    int count = 0;
    for (int x : student_scores) {
        if (x == 100) {
            return student_names[count];
        }
        count++;
    }
    return "";
}
