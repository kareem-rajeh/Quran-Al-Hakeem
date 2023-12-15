//
//  main.c
//  Quran
//
//  Created by Kareem Rajeh on 12/14/23.
//

#include "quran.h"

int main(void) {

    Quran* emir_quran = init_and_fill_quran("white", 10);
    
    print_surah_with_description(emir_quran, "Naba");
    
    return 0;
}
