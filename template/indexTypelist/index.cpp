#include<iostream>
using namespace std;

class NullType {};
#define TYPELIST_1(T1) Typelist<T1,NullType>
#define TYPELIST_2(T1,T2) Typelist<T1,TYPELIST_1(T2)>
#define TYPELIST_3(T1,T2,T3) Typelist<T1,TYPELIST_2(T2,T3)>
#define TYPELIST_4(T1,T2,T3,T4) Typelist<T1,TYPELIST_3(T2,T3,T4)>



template <class T, class U>
struct Typelist
{
        typedef T Head;
        typedef U Tail;
};
namespace TL
{
template <class TList, unsigned int index> struct TypeAt; 

 template <class Head, class Tail>
 struct TypeAt<Typelist<Head,Tail>,0>
 {
	typedef Head Result;
	
 };

 template <class Head, class Tail, unsigned i>
 struct TypeAt<Typelist<Head,Tail>,i>
 {
        typedef typename TypeAt<Tail,i-1>::Result Result;
 };
}
int main()
{
typedef TYPELIST_4(char, short int,int,long int ) SignedIntegrals;
TL::TypeAt<SignedIntegrals,0>::Result x;// <<endl;
x = '2';
cout<<x;
}

