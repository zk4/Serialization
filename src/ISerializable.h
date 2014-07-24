#pragma  once



#include <iostream>
using namespace  std;

class ISerializable
{
public:

	virtual ostream& serialize( ostream& ostream_) = 0;
	virtual istream& deSerialize(istream& istream_) = 0;
 
};



