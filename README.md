#ONLY HEADER required.

#A lite serialization solution
there are several lib out there support serialization,like protobuffer, boost:serialization , too heavy for me.  so I wrote this lite version.

#support 
* vector
* map
* set
* string
* primitives(int,double,long,...)

*endian support

*nesting container support
``cpp
vector<map<int, Obj*> >  
vector<vector<string> >  
vector<list<string> >  
```


use char instead bool in STL
[why](http://stackoverflow.com/questions/15809157/why-is-the-size-of-stdvectorbool-16-byte)


#build
you can build this project by CMake. or  just import **serialization.h** into your project.

camke build process:

```sh
	mkdir prj
	cd prj
	cmake ..
```
#usage
#define CHECK_ENDIAN=1  if you wanna check endian

#demo
check testSerialization.cpp 
 
#comming soom 
endian conversion.

