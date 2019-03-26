#include <iostream>
using namespace std;


template<class T, class B>
T add(T a, B b)
{
return a+b;
}



int main()
{
int x = 6 , z;
double y= 66.5;

z=add(x,y);
cout<<z<<endl;

}
