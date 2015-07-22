// testSerialization.cpp : Defines the entry point for the console application.
//
 
#include "core/serialization.h"
#include <fstream>
#include <sstream>
 
using namespace std;
static const  char * buffer_txt = "buffer.txt";

struct ss{
	int a;
	int b;
};
ostream& operator<< (ostream& o, ss& s)
{
 o << s.a << " " << s.b << "\n";
return o;
};
 
#include "core/serialization.h"
#include "core/ISerializable.h"
class Obj :public  ISerializable
{

public:
	vector<int>			objs;
	vector<Obj*>		objs2;
	map<int, string>		maps;
	int a;
	Obj(){}
	Obj(int aa) :a(aa)   {
		objs.push_back(1);
		objs.push_back(2);
		objs.push_back(3);
		objs2.push_back(new Obj());
		objs2[0]->a = 9999;

		maps[1] = "hello,nesting";
		maps[2] = "hello,nesting2";
	}
	ostream& serialize(ostream& s)
	{
		serialize::Serialize(s, maps);
		serialize::Serialize(s, a);
		serialize::Serialize(s, objs);
		serialize::Serialize(s, objs2);

		return s;
	}
	istream& deSerialize(istream& s)
	{
		serialize::DeSerialize(s, maps);
		serialize::DeSerialize(s, a);
		serialize::DeSerialize(s, objs);
		serialize::DeSerialize(s, objs2);

		return s;
	}
    
    //not complete ==,just for a demo :)
    bool operator==(const  Obj& s)
    {

        for (int i =0;i <objs.size();++i)
            if (objs[i]!=objs[i])return false;
        
        return  true;
        
    }
	friend ostream& operator<< (ostream& o, Obj& s)
	{

		o << s.a;
		return o;
	};

};






template<typename T>
void testVectorPrimtives(vector<T> v)
{
 	cout << "-------------------------------\n";
	 
	ofstream file(buffer_txt, std::ios::out | std::ios::binary | std::ios::trunc);
	serialize::Serialize(file, v);
	file.flush();
	file.close();

	vector<T>  a2;
	ifstream  file2(buffer_txt, std::ios::in | std::ios::binary);
	serialize::DeSerialize(file2, a2);
	 for (int i=0;i <a2.size(); ++i)
	 {
         
	 }
}
 

 
void testString(string s)
{
	 cout << "string-------------------------------\n";

	ofstream file(buffer_txt, std::ios::out | std::ios::binary | std::ios::trunc);
	serialize::Serialize(file, s);
	file.flush();
	file.close();

	string  s2;
	ifstream  file2(buffer_txt, std::ios::in | std::ios::binary);
	serialize::DeSerialize(file2, s2);
	 
	 	cout <<s2<< "\n";
 
}

void testMapPoinritPrimtives(map<int, Obj*> v)
{
 	cout << "-------------------------------\n";

	ofstream file(buffer_txt, std::ios::out | std::ios::binary | std::ios::trunc);
	serialize::Serialize(file, v);
	file.flush();
	file.close();

	map<int, Obj*>   a2;
	ifstream  file2(buffer_txt, std::ios::in | std::ios::binary);
	serialize::DeSerialize(file2, a2);
	 for (auto a :a2)
	{
		cout << a.first << " " << ((a.second)?a.second->a:0 )<< "\n";
	} 
}

template<typename K, typename  V>
void testMapPrimtives(map<K, V> v)
{
	 cout << "-------------------------------\n";

	ofstream file(buffer_txt, std::ios::out | std::ios::binary | std::ios::trunc);
	serialize::Serialize(file, v);
	file.flush();
	file.close();

	map<K, V>   a2;
	ifstream  file2(buffer_txt, std::ios::in | std::ios::binary);
	serialize::DeSerialize(file2, a2);
	 for (auto a : a2)
	 {
	 	cout << a.first << " " <<  (a.second)  << "\n";
	 }
}

template<typename K>
void testSetPrimtives(set<K> v)
{
	 cout << "-------------------------------\n";

	ofstream file(buffer_txt, std::ios::out | std::ios::binary | std::ios::trunc);
	serialize::Serialize(file, v);
	file.flush();
	file.close();

	set<K>  a2;
	ifstream  file2(buffer_txt, std::ios::in | std::ios::binary);
	serialize::DeSerialize(file2, a2);
	 for (auto a : a2)
	 {
	 	cout << a << "\n";
	 }
}


void testVectorPointPrimtives(vector<Obj*> v)
{
 	cout << "-------------------------------\n";

	ofstream file(buffer_txt, std::ios::out | std::ios::binary | std::ios::trunc);
	serialize::Serialize(file, v);
	file.flush();
	file.close();

	vector<Obj*>  a2;
	ifstream  file2(buffer_txt, std::ios::in | std::ios::binary);
	serialize::DeSerialize(file2, a2);
	 for (int i = 0; i < a2.size(); ++i)
	{
	 
	} 
}


template<typename T>
void testListPrimtives(list<T> v)
{
  	cout << "-------------------------------\n";

	ofstream file(buffer_txt, std::ios::out | std::ios::binary | std::ios::trunc);
	serialize::Serialize(file, v);
	file.flush();
	file.close();

	list<T>  a2;
	ifstream  file2(buffer_txt, std::ios::in | std::ios::binary);
	serialize::DeSerialize(file2, a2);
	 for (auto a : a2)
	{

		cout << a   ;
	} 
}

template<typename T>
void testPointerListPrimtives(list<T*> v)
{
 	cout << "-------------------------------\n";

	ofstream file(buffer_txt, std::ios::out | std::ios::binary | std::ios::trunc);
	serialize::Serialize(file, v);
	file.flush();
	file.close();

	list<T*>  a2;
	ifstream  file2(buffer_txt, std::ios::in | std::ios::binary);
	serialize::DeSerialize(file2, a2);
	 for (auto a : a2)
	 {
	 	if (a)
	 	cout << *a << "\n";
	 	else 
	 	cout << "NULL\n";
	 }
}

template <typename T1, typename T2>
auto add(T1 t1, T2 t2) -> decltype(t1 + t2)
{
	static_assert(std::is_integral<T1>::value, "Type T1 must be integral");
	static_assert(std::is_integral<T2>::value, "Type T2 must be integral");
	 
	return t1 + t2;
}


int main( )
{
	add(1 ,1);
 	testVectorPrimtives<bool>({ false, true,false });
	testVectorPrimtives<int>({ 1,2, 3, 4 });
	testVectorPrimtives<double>({ 1.3, 2.3, 3.3, 4.3 });
	testVectorPrimtives<float>({ 1.3f, 2.3f, 3.3f, 4.3f });
	testVectorPrimtives<char>({  'b', 'd' });
	testVectorPrimtives<long long >({1111111111,222222222});
	testVectorPrimtives<long>({ 1111111111, 222222222 });


	testString("hello,world");
	testString("你好，世界");
	 
	{
		vector<Obj*>   objs;
		objs.push_back(new Obj(4));
		objs.push_back(new Obj(5));
		objs.push_back(NULL);
		objs.push_back(new Obj(7));
		testVectorPointPrimtives(objs);
	}
	map<int, Obj*> ms;
	ms[2] = new Obj(22);
	ms[4] = NULL;
	ms[3] = new Obj(33);
	ms[5] = NULL;
	ms[6] = new Obj(66);
	testMapPoinritPrimtives(ms);

	{
		map<int, string>  m2 = { { 1, "hello" }, { 2, "world" } };
		testMapPrimtives(m2);
	}
	{
		map<string, string>  m2 = { { "ho", "hello" }, {"wd", "world" } };
		testMapPrimtives(m2);
	}
	{
		map<int, int>  m2 = { { 1, 1 }, { 2, 2 } };
		testMapPrimtives(m2);
	}

	{
		map<int, double>  m2 = { { 1, 1111.11 }, { 2, 1111.11 } };
		testMapPrimtives(m2);
	}

	{
		map<int, float>  m2 = { { 1, 1111.11f }, { 2, 1111.11f } };
		testMapPrimtives(m2);
	}

	{
		
		map<int, ss>  m2 = { { 1, {1,2} }, { 2, {3,4}} };
		testMapPrimtives(m2);
	}

	{
		set<int> sets = { 1, 2, 3, 4   };
		testSetPrimtives(sets);
	}
	{
		set<double> sets = { 1.111, 2, 3,   };
		testSetPrimtives(sets);
	}
	{
		set<string> sets = { "hello","world"};
		testSetPrimtives(sets);
	}

	{
		list <int>  lists = { 1, 2, 31, 1, 1, 0, 0, 0, 0, 1 };
		testListPrimtives(lists);
	}
	{
		list <double>  lists = { 1, 2, 31, 1, 1, 0, 0.12321, 0, 0, 1 };
		testListPrimtives(lists);
	}
	{
		list <string>  lists = {"hello","list" };
		testListPrimtives(lists);
	}
	list <Obj*>  objs;
	objs.push_back(new Obj(11));
	objs.push_back(NULL);
	objs.push_back(new Obj(22));
	objs.push_back(NULL);
	testPointerListPrimtives(objs);



	{
	vector<map<int, Obj*> >  intss = { { { 1, new Obj(3) }, { 4, new Obj(4) } }, { { 2, new Obj(3) }, { 4, new Obj(6) } } };
	testVectorPrimtives(intss);

	}
    struct A{
        int a,b;
    };
    
    {
        vector<A>  as;
        as={{1,2},{3,4}};
        testVectorPrimtives(as);
        
    }
    
   
	 
	return 0;
}

