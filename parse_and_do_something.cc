#include <fplus/fplus.hpp>

template <typename T>
T str_to_num(const std::string& str) {
  // Once a std::istringstream object has been created, 
  // then the string can be streamed and stored using the extraction operator(>>). 
  // The extraction operator will read until whitespace is reached or until the stream fails.
  T result;
  std::istringstream(str) >> result;
  return result;
}

void parse_and_mult(const std::string input) {
  const auto parts = 
    fplus::split(',', false, input);
  const auto nums =
    fplus::transform(str_to_num<int>, parts);
  const auto result =
    fplus::reduce(std::multiplies<int>(), 1, nums);

  std::cout << "String to parse: "
            << input
            << "\n"
            << "Product        : "
            << result 
            << std::endl;
}

// Exercise:
//
//     Modify the code,
//     so that the numbers are not multiplied but added.
//
//     Additionally change it
//     so that is works with floating point numbers too.
//     For this you should parse doubles instead of ints.

void parse_and_add(const std::string input) {
  const auto parts = 
    fplus::split(',', false, input);
  const auto nums =
    fplus::transform(str_to_num<double>, parts);
  const auto result =
    fplus::reduce(std::plus<double>(), 0, nums);

  std::cout << "String to parse: "
            << input
            << "\n"
            << "Sum            : "
            << result 
            << std::endl;
}

int main()
{
  const std::string input {"1.9,5.0,4.3,7.1,2.9,2.3,3.2"};
  parse_and_mult(input);
  parse_and_add(input);
}


