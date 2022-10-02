#include <cassert>
#include <vector>
#include <iostream>

bool is_even(int x)
{
    return x % 2 == 0;
}

template <typename Pred, typename Cont>
Cont keep_if(Pred pred, const Cont& xs)
{
  Cont ys;
  for (const auto x : xs)
  {
      if (pred(x))
      {
          ys.push_back(x);
      }
  }
  return ys;
}

int main()
{
    std::vector<int> xs = {0,1,2,3,4};
    const auto ys = keep_if(is_even, xs);
    
    assert(ys == std::vector<int>({0,2,4}));
    std::cout << "Result: OK" << std::endl;
}

// Then run some tests with it.

// Bonus:
// See if you can make it work
// for different container types
// (e.g. std::list and std::vector).


