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
 template <class Tlist, class T> struct Erase;
 template <class T>
 struct Erase<NullType,T>
 {
        typedef NullType Result;
 };

 template <class T,class Tail>
 struct Erase<Typelist<T,Tail>,T>
 {
        typedef Tail Result;
 };

template <class Head, class Tail, class T>
struct Erase<Typelist<Head,Tail>,T>
{
        typedef Typelist<Head,typename Erase<Tail,T>::Result> Result;
};

 template <class Tlist> struct NoDuplicates;
 template <>
 struct NoDuplicates<NullType>
 {
 	typedef NullType Result;
 };
template<class Head,class Tail>
struct NoDuplicates<Typelist<Head,Tail>>
{
private:
	typedef typename NoDuplicates<Tail>::Result L1;
	typedef typename Erase<L1,Head>::Result L2;

public:
	typedef Typelist<Head,L2> Result;
};

}
int main()
{

typedef TYPELIST_4(signed char, short int,int,long int ) SignedIntegrals;
typedef TL::NoDuplicates<SignedIntegrals>::Result signedTypes;// <<endl; 
}
