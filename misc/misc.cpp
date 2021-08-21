#include <iostream>
#include <tuple>
#include <vector>

constexpr auto expr = 1 + 1 * 4 - 5 - 1 + 4;

int main() {
  std::vector<int> vec = {1, 9, 2, 6, 0};
  std::tuple<int, int, std::string, std::vector<int> > tup =
      std::make_tuple(817, 114, "514", vec);
  std::cout << std::tuple_size<decltype(tup)>::value << std::endl;

  for (auto i : std::get<expr>(tup)) std::cout << i << " ";
  // std::get<> 中尖括号里面的必须是整型常量表达式
  // expr 常量的值是 3，注意 std::tuple 的首元素编号为 0，
  // 故我们 std::get 到了一个 std::vector<int>
  return 0;
}
