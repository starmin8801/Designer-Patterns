#include "new.h"
#include "proxy.h"

int main(int argc, char *argv[]) {
    void *image = New(Proxy, "SomeBigPic.jpg");

    Show(image);

    Delete(image);
    
    return 0;
}
