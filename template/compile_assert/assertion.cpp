#include<iostream>
#include<cassert>
#include<string>
using namespace std;


template <class To, class From>
To reInterpret_cast(From from)
{
 return (To)from;
}

template <class To, class From>
To safe_reInterpret_cast(From from)
{
assert(sizeof(from) <= sizeof(To));
return reInterpret_cast<To>(from);

}
int main()
{
int i =7;
double p = safe_reInterpret_cast<double>(i);
cout<<p<<endl;
}
