#include "std_lib_facilities.h"

template<typename T> 
struct S
{
private:
	T val;

public:
	S(T initialVal = 0)
	{
		val = initialVal;
	}

	void print()
	{
		cout << val << endl;
	}

	//prototype for normal get
	T& get();

	//prototype for constant get
	const T& get() const;

	void set(T value)
	{
		val = value;
	}

	//to use assing operator for objects to set its values
	S<T>::operator=(const T& s)
	{
		val = s;
		return *this;
	}



};

//implementation of get
template<typename T>
T& S<T>::get()
{
	return val;
}

//implementation of constant get
template<typename T>
const T& S<T>::get() const
{
	return val;
}

template<typename T>
void read_val(T& v)
{
	cin >> v;

}

template<typename T>
istream& operator>>(istream& is, vector<T> vec)
{
	T val;
	while (val != "quit")
	{
		is >> val;
		vec.push_back(val);
	}
	return is;
}

template<typename T>
ostream& operator<<(ostream& os, vector<T> vec)
{
	os << "[";
	for (int i = 0; i < vec.size(); i++)
	{
		os << vec[i] << " ";
	}
	os << "]";

	return os;
}

int main()
{
 S<int> si {37};
    S<char> sc {'c'};
    S<double> sd {10.2};
    S<std::string> s {"Howdy"};
    S<std::vector<int>> svi { std::vector<int>{1, 1, 2, 3, 5, 8}};

    std::cout << "S<int> : " << si.get() << '\n'
              << "S<char> : " << sc.get() << '\n'
              << "S<double> : " << sd.get() << '\n'
              << "S<string> : " << s.get() << '\n'
              << "S<vector<int>> : " << svi.get() << '\n';

    /*
    std::cout << "S<vector<int>> : ";
    for (auto& a : svi.get())
        std::cout << a << ' ';
    std::cout << '\n';
    */

    /*
    sc.set('s');
    std::cout << "S<char> : " << sc.get() << '\n';
    */

    sd = 3.14159;
    std::cout << "S<double> : " << sd.get() << '\n';

    std::cout << "Reads:\n";

    /*
    std::cout << "Integer: ";
    int ii;
    read_val(ii);
    S<int> si2 {ii};
    std::cout << "Char: ";
    char cc;
    read_val(cc);
    S<char> sc2 {cc};
    std::cout << "Double: ";
    double dd;
    read_val(dd);
    S<double> sd2 {dd};
    std::cout << "String: ";
    std::string ss;
    read_val(ss);
    S<std::string> s2 {ss};
    std::cout << "S<int> read: " << si2.get() << '\n';
    std::cout << "S<char> read: " << sc2.get() << '\n';
    std::cout << "S<double> read: " << sd2.get() << '\n';
    std::cout << "S<string> read: " << s2.get() << '\n';
    */
    std::cout << "Vector<int>: (format: { val1, val2, val3 }) ";
    std::vector<int> vi2;
    read_val(vi2);
    S<std::vector<int>> svi2 {vi2};

    std::cout << "S<vector<int>> read: " << svi2.get() << '\n';
}
