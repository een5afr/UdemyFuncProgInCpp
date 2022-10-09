#include <cassert>
#include <vector>
#include <iostream>
#include <fplus/fplus.hpp>

using point = std::pair<float, float>;

//=============================================================================
float point_distance(const point& p1, const point& p2)
//=============================================================================
{
    const float dx = p2.first - p1.first;
    const float dy = p2.second - p1.second;
    return std::sqrt(dx * dx + dy * dy);
}

//=============================================================================
void find_longest_edge_of_polygon() 
//=============================================================================
{
    using namespace std;

    vector<point> polygon =
        { {1,2}, {7,3}, {6,5}, {4,4}, {2,9} };
    const auto edges =
        fplus::overlapping_pairs_cyclic(polygon);
    const auto result = fplus::maximum_on(
        [](const std::pair<point, point>& edge) -> float
        {
            return point_distance(edge.first, edge.second);
        }, edges);
    cout << fplus::show(result) << endl;
}

//=============================================================================
bool is_even(int x) 
//=============================================================================
{
    return x % 2 == 0;
}

//=============================================================================
template <typename Pred, typename Cont>
Cont keep_if(Pred pred, const Cont& xs) 
//=============================================================================
{
    Cont ys;
    for (const auto x : xs) {
        if (pred(x)) {
            ys.push_back(x);
        }
    }
    return ys;
}

//=============================================================================
template <typename T>
void filter(T const & xs) 
//=============================================================================
{
    //Container<T> xs = {0,1,2,3,4};
    const auto ys = keep_if(is_even, xs);    
    assert(ys == T({0,2,4}));
    std::cout << "Result: OK" << std::endl;
}

//=============================================================================
double str_to_double(const std::string& str)
//=============================================================================
{ 
    double result;
    std::istringstream(str) >> result;
    return result;
}

//=============================================================================
double str_to_int(const std::string& str)
//=============================================================================
{ 
    int result;
    std::istringstream(str) >> result;
    return result;
}

//=============================================================================
void parse_and_add()
//=============================================================================
{
    const std::string input = 
        "1,5,4,7,2,2,3.34";
    const auto parts = 
        fplus::split(',', false, input);
    const auto nums =
        fplus::transform(str_to_double, parts);
    const auto result =
        fplus::reduce(std::plus<double>(), 0, nums);
    std::cout << "input = " << input << "; result = " << result << std::endl;
}

//=============================================================================
template<typename NumType>
void parse_and_multiply()
//=============================================================================
{
    const std::string input = 
        "1,5,4,7,2,2,3";
    const auto parts = 
        fplus::split(',', false, input);
    const auto nums =
        fplus::transform(str_to_int, parts);
    const auto result =
        fplus::reduce(std::multiplies<NumType>(), 1, nums);
    std::cout << "input = " << input << "; result = " << result << std::endl;
}

//=============================================================================
int main()
//=============================================================================
{
    parse_and_multiply<int>();
    parse_and_add();
}
