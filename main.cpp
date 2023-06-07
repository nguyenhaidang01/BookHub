#include "BookHub.h"

int main()
{
    BookHub *bookhub = new BookHub();
    bookhub->Menu();

    delete bookhub;
    bookhub = nullptr;
    
    return 0;
}