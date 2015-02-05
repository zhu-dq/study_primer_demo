#include <iostream>
#include "../include/dog.h"
using namespace std;
dog::dog()
{
    cout<<"i am a dog"<<endl;
}

void dog::speak()
{
    cout<<"wang ~ wang ~"<<endl;
}

dog::~dog()
{
    cout<<"this dog has dead"<<endl;
}

