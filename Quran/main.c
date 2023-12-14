//
//  main.c
//  Quran
//
//  Created by Kareem Rajeh on 12/14/23.
//

#include <stdlib.h>
#include <stdio.h>


typedef struct surah
{
    int surah_number;
    char* name;
    double num_pages;
    int num_ayahs;
} Surah;


typedef struct quran
{
    int num_juzz;
    int num_of_surahs;
    Surah* surahs;
    char* color;
    double juzz_memorized;
} Quran;

int str_len(char* str) {
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    
    return len;
}

void str_cpy(char* dest, char* src) {
    int src_index = 0;
    int dest_index = 0;
    
    while (src_index < str_len(src)) {
        dest[dest_index] = src[src_index];
        src_index++;
        dest_index++;
    }
    
    return;
}


Surah* init_surah(char* name, double num_pages, int num_ayahs, int surah_number)
{
    Surah* surah = malloc(sizeof(Surah));
    (*surah).surah_number = surah_number;
    (*surah).name = malloc(sizeof(char) * str_len(name) + 1);
    str_cpy((*surah).name, name);
    (*surah).num_ayahs = num_ayahs;
    (*surah).num_pages = num_pages;
    
    
    return surah;
}


Quran* init_quran(int num_juzz, int num_of_surahs, char* color, double juzz_memorized)
{
    Quran* quran = malloc(sizeof(Quran));
    
    (*quran).num_juzz = num_juzz;
    (*quran).num_of_surahs = num_of_surahs;
    (*quran).surahs = calloc(sizeof(Surah), num_of_surahs);
    if ((*quran).surahs == NULL) {
        exit(1);
    }
    
    (*quran).color = malloc(sizeof(char) * str_len(color) + 1);
    str_cpy((*quran).color, color);
    
    (*quran).juzz_memorized = juzz_memorized;
    
    return quran;
}


void memorize_an_additional_juzz(Quran* quran, double num_of_juzz_memorized) {
    (*quran).juzz_memorized += num_of_juzz_memorized;
}


void insert_surah(Quran* quran, Surah* surah) {
    int index = (*surah).surah_number;
    (*quran).surahs[index] = *surah;
    
    return;
}


void print_surah(Surah* surah) {
    printf("Surah (%d) %s has %d ayahs and %.2f pages, ", (*surah).surah_number, (*surah).name, (*surah).num_ayahs, (*surah).num_pages);
    
    return;
}


void print_quran_at(Quran* quran, int index);


void print_quran(Quran* quran)
{
    int i = 0;
    printf("[");
    while (i < (*quran).num_of_surahs) {
        if (i == (*quran).num_of_surahs - 1) {
            if ((*quran).surahs[i].name == NULL) {
                printf("EMPTY");
            }
            else print_surah(&(*quran).surahs[i]);
            printf("]\n");
            break;
        }
        if ((*quran).surahs[i].name == NULL) {
            printf("EMPTY, ");
        }
        else print_surah(&((*quran).surahs[i]));
        i++;
    }
    
}


int main(int argc, char* argv[]) {
    Quran* kareems_quran = init_quran(30, 114, "black", 1.5);
    Surah* naba = init_surah("Naba", 1.75, 40, 78);
    insert_surah(kareems_quran, naba);
    
    print_quran(kareems_quran);
    return 0;
}
