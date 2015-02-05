#include "../include/animal.h"
#include "../include/dog.h"

int main()
{
    animal *a = new dog();
    a->speak();
    delete a;
    return 0;
}

