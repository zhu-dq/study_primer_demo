#include "../include/animal.h"
#include <iostream>
using namespace std;
animal::animal()

{
    cout<<"i am a animal ~"<<endl;
}

void animal::speak()
{
    cout<<"i don't know how to speak ~"<<endl;
}

animal::~animal()
{
    cout<<"animal id dead ~"<<endl;
}

