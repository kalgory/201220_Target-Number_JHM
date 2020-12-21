#include <iostream>
#include <utility>
#include <vector>


using namespace std;

int number_vec_size;
int target;
vector<int> number_vec;

int calculate(int calculate_count, int result) {
  if (calculate_count == number_vec_size) {
    if (target == result) {
      return 1;
    } else {
      return 0;
    }
  }
  int count = 0;
  count += calculate(calculate_count + 1, result - number_vec[calculate_count]);
  count += calculate(calculate_count + 1, result + number_vec[calculate_count]);
  return count;
}

int solution(vector<int> _number_vec, int _target) {
  number_vec = std::move(_number_vec);
  target = _target;
  number_vec_size = number_vec.size();

  return calculate(0, 0);;
}

int main() {
  std::cout << solution({1, 1, 1, 1, 1}, 3) << std::endl;
  return 0;
}
