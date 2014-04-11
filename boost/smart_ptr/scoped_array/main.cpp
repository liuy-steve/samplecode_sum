#include <iostream>  
#include <algorithm>  
#include <boost/scoped_array.hpp>  
using namespace std;  
using namespace boost;  
   
const int MAX = 10 ;
int main()  
{     
    scoped_array<char> ptr;  
    ptr.reset(new char[MAX]);   
    for(int i= 0;i<MAX;i++)  
    {  
        ptr[i] = 'a'+ i;      
        cout<<ptr[i]<<endl;   
    }    
      
    return 0;  
}  