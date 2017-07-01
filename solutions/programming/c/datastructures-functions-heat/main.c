#include <stdio.h>
#include "field.h"
#include "pngwriter.h"
#include "functions_v2.h"

#define DX 0.01
#define DY 0.02

// Main program: initialise, compute laplacian + print

int main(void)
{
    field f;
    
    init_field(&f,NX,NY);
    laplacian(&f);
    print_field(&f);
    
    return 0;

}
