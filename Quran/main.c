//
//  main.c
//  Quran
//
//  Created by Kareem Rajeh on 12/14/23.
//

#include "quran.h"


int main(int argc, char* argv[])
{
    Quran* kareems_quran = init_and_fill_quran("black", 1.5);
    
    print_surah_with_description(kareems_quran, "Naba");
    
    
    return 0;
}
