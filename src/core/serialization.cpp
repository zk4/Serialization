#include "serialization.h"




bool serialize::LE()
{

    const static int n = 1;
    const static bool le= (* (char *)&n == 1);
    return le;
}

bool serialize::ReadEndian (istream &istream_)
{
    bool littleEndian = false;
    istream_.read ((char*)&littleEndian, sizeof (littleEndian));
    return littleEndian;
}

void serialize::WriteEndian (ostream &ostream_)
{
    bool littleEndian = LE();

    ostream_.write ((char*)&littleEndian, sizeof (littleEndian));
}

istream& serialize::read_internal (istream& istream_, char* p, size_t size)
{

    if (!LE())
    {
        //read as little endian
        for (int i = size - 1; i >= 0; --i)
        {
            istream_.read (p+i, 1);
        }
    }
    else
        istream_.read (p, size);
    return  istream_;
}

ostream& serialize::write_internal (ostream& ostream_, const char* p, size_t size)
{

    if (!LE())
    {
        //if big endian .write as little endian
        for (int i = size-1; i>=0; --i)
        {
            ostream_.write (p + i, 1);
        }
    }
    else
        ostream_.write (p, size);
    return  ostream_;
}

istream& serialize::DeSerialize (istream& istream_, ISerializable* t_)
{
    return t_->deSerialize (istream_);
}

istream& serialize::DeSerialize (istream& istream_, std::string& string_)
{
    int size = 0;
    DeSerialize (istream_, size);
    char* buffer = new char[size + 1];
    memset (buffer, 0, size + 1);
    read_internal (istream_, buffer, size);
    string_.assign (buffer);
    delete[] buffer;
    return  istream_;
}

istream& serialize::DeSerialize (istream& istream_, char* str)
{
    int size = 0;
    DeSerialize (istream_, size);
    read_internal (istream_, str, size);
    return  istream_;
}

istream& serialize::DeSerialize (istream& istream_, vector<bool>&container)
{
    if (!istream_.good() || istream_.eof())return istream_;

    int size;
    container.clear();
    DeSerialize (istream_, size);
    for (int i = 0; i < size; ++i)
    {
        bool t;
        DeSerialize (istream_, t);
        container.push_back (t);
    }
    assert (istream_.good());
    return istream_;
}

ostream& serialize::Serialize (ostream& ostream_, ISerializable* t_)
{
    return t_->serialize (ostream_);
}

ostream& serialize::Serialize (ostream& ostream_, const std::string& string_)
{
    size_t size = string_.size();
    Serialize (ostream_, size);
    write_internal (ostream_, string_.c_str(), string_.size());
    return ostream_;
}

ostream& serialize::Serialize (ostream& ostream_, std::string& string_)
{
    size_t size = string_.size();
    Serialize (ostream_, size);
    write_internal (ostream_, string_.c_str(), string_.size());
    return ostream_;
}

ostream& serialize::Serialize (ostream& ostream_, const char* str)
{
    size_t size = strlen (str);
    Serialize (ostream_, size);
    write_internal (ostream_, str, size);
    return ostream_;
}

ostream& serialize::Serialize (ostream& ostream_, vector<bool>& container)
{
    size_t size = container.size();
    Serialize (ostream_, size);

    for (auto ite : container)
    {
        bool c = ite;
        Serialize (ostream_, c);
    }

    return ostream_;
}
