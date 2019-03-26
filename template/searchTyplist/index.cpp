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
template <class TList, class T> struct IndexOf; 

 template <class T>
 struct IndexOf<NullType,T>
 {
	enum {value = -1};
	
 };

 template <class T, class Tail>
 struct IndexOf<Typelist<T,Tail>,T>
 {
        enum {value = 0};
 };


template <class Head, class Tail, class T>
struct IndexOf<Typelist<Head,Tail>,T>
{
	private:
		enum {temp = IndexOf<Tail,T>::value};
	public:
		enum {value = temp == -1 ? -1 : 1+temp};
};
}
int main()
{
typedef TYPELIST_4(char, short int,int,long int ) SignedIntegrals;
int x = TL::IndexOf<SignedIntegrals,char>::value;// <<endl;
//x = '2';
cout<<x;
}

