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
 template <class Tlist, class T,class U> struct Replace;

 template <class T, class U>
 struct Replace<NullType,T,U>
 {
 	typedef NullType Result;
 };

 template <class T,class Tail,class U>
 struct Replace<Typelist<T,Tail>,T,U>
 {
	typedef Typelist<U,Tail> Result;
 };

template <class Head, class Tail, class T,class U>
struct Replace<Typelist<Head,Tail>,T,U>
{
	typedef Typelist<Head,typename Replace<Tail,T,U>::Result> Result;
};
}
int main()
{

typedef TYPELIST_4(signed char, short int,int,long int ) SignedIntegrals;
typedef TL::Replace<SignedIntegrals,int,double>::Result signedTypes;// <<endl; 
}
