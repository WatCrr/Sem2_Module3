#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

std::vector<int> even_pallys(const std::string& str) {
  std::vector<int> result (str.length(), 0);
  int l = 0, r = -1;
  for (int i = 0; i < str.length(); ++i) {
    int sim_rad = i > r ? 1 : std::min(result[l + r - i], r - i + 1);
    while (i + sim_rad < str.length() && i - sim_rad >= 0 && str[i + sim_rad] == str[i - sim_rad]) ++sim_rad;
    result[i] = sim_rad;
    if (i + sim_rad - 1 > r)
      l = i - sim_rad + 1,  r = i + sim_rad - 1;
  }
  return result;
}

std::vector<int> odd_pallys(const std::string& str) {
  std::vector<int> result (str.length(), 0);
  int l = 0, r = -1;
  for (int i = 0; i < str.length(); ++i) {
    int sim_rad = i > r ? 0 : std::min(result[l + r - i + 1], r - i + 1);
    while (i + sim_rad < str.length() && i - sim_rad - 1 >= 0 && str[i + sim_rad] == str[i - sim_rad - 1]) ++sim_rad;
    result[i] = sim_rad;
    if (i + sim_rad - 1 > r)
      l = i - sim_rad,  r = i + sim_rad - 1;
  }
  return result;
}

int main() {
  std::string str;
  std::getline(std::cin, str);

  long long c = 0;
  std::vector<int> palindromes = even_pallys(str);
  for (int i = 0; i < palindromes.size(); i++) c += palindromes[i] - 1;
  palindromes = odd_pallys(str);
  for (int i = 0; i < palindromes.size(); i++) c += palindromes[i];
  std::cout << c;
  return 0;
}
