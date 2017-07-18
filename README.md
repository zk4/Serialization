
# A lite serialization solution
there are several lib out there support serialization,like protobuffer,flatbuffers,capnproto.
Need schema file for generating source files, which is cool between peers. 
but that is too heavy for me. so I wrote this lite version.only support c++. 
If your just want to serialize & deserialize data on the same machine. I think it is a  good choice. simple as it is , hack whatever u want.

# Only Head file needed
```cpp
src/core/serialization.h 
```
that`s it!You are set to go!	

#support 
* vector
* list
* map
* set
* string
* primitives(int,double,long,...)
* nesting container support
```cpp
Obj : implements serialize:I interface
vector<map<int, Obj*> >  
vector<vector<string> >  
vector<list<string> >  
vector<customer_struct>
vector<Obj> 
vector<string>  
```
* endian auto conversion  
  no need to worry about endian problem.all data is writed in little endian.


use char instead bool in STL
[why](http://stackoverflow.com/questions/15809157/why-is-the-size-of-stdvectorbool-16-byte)


#  build
you can build this project by CMake. or  just import **serialization.h** into your project.

cmake build process:

```sh
	mkdir prj
	cd prj
	cmake ..
```
if it doesn`t work. set compile flags to c++11


# demo
check testSerialization.cpp 
 
 

