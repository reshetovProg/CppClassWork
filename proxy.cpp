#include <iostream>
#include "LinkedList.cpp"
#include <fstream>
#include <string>
#include "Proxy.h"
using namespace std;



int main()
{
    Proxy file1("C:\\Users\\Admin\\Desktop\\testproxy.txt");
    cout << file1.getData(123);

    
    
    
}
