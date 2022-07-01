#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

template<typename T, typename R>
class S_2
{
public:
    S_2(const T& _a, const R& m) :a(_a), b(m) {};
    T a;
    R b;
    template<typename P>
    auto operator*(const P& m)
    {
        return a * m * (b * m);
    }
};


template<typename T>
class S_1
{
public:
    S_1(const T& m):a(m) {};
    T a;
    template<typename R>
    S_2<T, R> operator*(const R& m)
    {
        return S_2<T,R>(a,m);
    }
};



class S
{
public:
    template<typename T>
    S_1<T> operator*(const T& m)
    {
        return S_1<T>(m);
    }
};

template<typename T>
class K_1
{
public:
    K_1<T>(const T& m) :a(m) {};
    T a;
    template<typename R>
    auto operator*(const R& m)
    {
        return a;
    }
};

class K
{
public:
    template<typename T>
    K_1<T> operator*(const T& m)
    {
        return K_1<T>(m);
    }
};

class I
{
public:
    template<typename T>
    T operator*(const T& m)
    {
        return m;
    }
};

template<typename T>
class MyString
{
public:
    MyString(const string& _s, const T& _m)
    {
        s = _s;
        m = _m;
    }
    string s;
    T m;
    template<typename R>
    auto operator*(const R& _m)
    {
        return MyString<R>(s, _m);
    }
};

std::string operator*(const std::string& a, const std::string& b)
{
    return a + b;
}

template<typename T>
std::string operator*(const std::string& a, const T& b)
{
    return  MyString<T>(a, b);
}



int main(int argc, char** argv)
{
    S s;
    K k;
    I i;
    cout << (s * (k * string("a")) * (s * i * i)) * string("b") << endl;
}
