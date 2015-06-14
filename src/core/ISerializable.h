#pragma  once



#include <iostream>

class ISerializable
{
public:

	virtual std::ostream& serialize( std::ostream& ostream_) = 0;
	virtual std::istream& deSerialize(std::istream& istream_) = 0;
 
};



