#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

std::vector<int> count_z_function (const std::string& str) {
  std::vector<int> result (str.length(), 0);

  int l = 0, r = 0;
  result[0] = str.length();
  int i = 1;
  while (i < str.length()) {
    result[i] = std::max(0, std::min(r - i, result[i - l]));
    while (result[i] + i < str.length() && str[result[i]] == str[result[i] + i]) ++result[i];
    if (result[i] + i > r) {
      l = i;
      r = i + result[i];
    }
    ++i;
  }
  return result;
}

int main() {

  std::string str, templ;
  std::getline(std::cin, templ);
  std::getline(std::cin, str);
  std::vector<int> z_func = count_z_function(templ + '\n' + str);
  for (int i = 0; i < z_func.size(); i++) {
    if (z_func[i] == templ.length()) std::cout << i - templ.length() - 1 << ' ';
  }
  return 0;
}
