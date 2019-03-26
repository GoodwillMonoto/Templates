#include<iostream>
using namespace std;
*
template<class T>
class isnotInt<string>
{


public:
isnotInt(T t)
{
cout<<"not a char"<<endl;
}

};


template<T>
class isnotInt<char>
{

public:
isnotInt(char t)
{
cout<<"is char"<<endl;
}
};
*/

int main()
{
//isnotInt<int> obj1(5);
//isnotInt<char> obj2('5');
isnotInt<string> obj3("asdfd");
}
