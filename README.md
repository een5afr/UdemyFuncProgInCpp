# C++ Funtional Programming

## Functions/Data Represented As Signatures
- int x                     => x : (Int)
- std::pair<Int, Float> p   => p : (Int, Float)
- std::map<key, val> m      => m : (Map key val)
- int f (int x)             => f : (Int -> Int)
- user_data_type u          => user_data_type : u

- (vector<string>, string) -> string                                 => ([[a]], [a]) -> [a]  
- std::map(key, val) -> val                                          => (Map key val, key) -> val
- std::vector<bool> return_bool(std::function<F(T)>, std::vector<T>) => return_bool : ((T -> Bool), [T]) -> [Bool]

##