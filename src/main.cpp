#include <iostream>
#include "observer.h"

using namespace std;

int main(void)
{
    Observer* observer = new Observer("/dir/to/observe/");
    observer->observe();
    return 1;
}
