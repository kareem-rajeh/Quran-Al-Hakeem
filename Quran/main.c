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
    char* juzz_name;
    int juzz_number;
    int surah_number;
    char* surah_name;
    double num_pages;
    int num_ayahs;
    char* description; // ex. it is about the day of judgement
} Surah;


typedef struct juzz {
    Surah* surahs; // size 114
} Juzz;

typedef struct quran
{
    int num_juzz;
    int num_of_surahs;
    Juzz* juzz; // size 30
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

/*
 char* juzz_name;
 int juzz_number;
 int surah_number;
 char* surah_name;
 double num_pages;
 int num_ayahs;
 char* description; // ex. it is about the day of judgement
 */

Surah* init_surah(char* juzz_name, int juzz_num, int surah_num, char* surah_name, double num_pages, int num_ayahs, char* description)
{
    Surah* surah = malloc(sizeof(Surah));
    if (surah == NULL) {
        printf("Failed at line: %d", __LINE__);
        exit(1);
    }
    
    (*surah).juzz_name = malloc(sizeof(char) * str_len(juzz_name) + 1);
    if ((*surah).juzz_name == NULL) {
        printf("Failed at line: %d", __LINE__);
        exit(1);
    }
    str_cpy((*surah).juzz_name, juzz_name);
    
    (*surah).juzz_number = juzz_num;
    (*surah).surah_number = surah_num;
    
    (*surah).surah_name = malloc(sizeof(char) * str_len(surah_name) + 1);
    if ((*surah).surah_name == NULL) {
        printf("Failed at line: %d", __LINE__);
        exit(1);
    }
    str_cpy((*surah).surah_name, surah_name);
    
    (*surah).num_ayahs = num_ayahs;
    (*surah).num_pages = num_pages;
    
    (*surah).description = malloc(sizeof(char) * str_len(description) + 1);
    if ((*surah).description == NULL) {
        printf("Failed at line: %d", __LINE__);
        exit(1);
    }
    str_cpy((*surah).description, description);
    
    return surah;
}


Quran* init_quran(char* color, double juzz_memorized)
{
    Quran* quran = malloc(sizeof(Quran));
    if (quran == NULL) {
        printf("Failed at line: %d", __LINE__);
        exit(1);
    }
    
    (*quran).num_juzz = 30;
    (*quran).num_of_surahs = 114;
    (*quran).juzz = calloc(sizeof(Surah), (*quran).num_juzz);
    if ((*quran).juzz == NULL) {
        printf("Failed at line: %d", __LINE__);
        exit(1);
    }
    
    (*quran).color = malloc(sizeof(char) * str_len(color) + 1);
    if ((*quran).color == NULL) {
        printf("Failed at line: %d", __LINE__);
        exit(1);
    }
    str_cpy((*quran).color, color);
    
    (*quran).juzz_memorized = juzz_memorized;
    
    return quran;
}


void memorize_an_additional_juzz(Quran* quran, double num_of_juzz_memorized)
{
    (*quran).juzz_memorized += num_of_juzz_memorized;
}


void insert_surah(Quran* quran, Surah* surah)
{
    int index = (*surah).juzz_number;
    (*quran).juzz->surahs[index] = *surah;
    
    return;
}


void print_surah(Surah* surah) {
    printf("Surah (%d) %s has %d ayahs and %.2f pages, ", (*surah).surah_number, (*surah).surah_name, (*surah).num_ayahs, (*surah).num_pages);
    
    return;
}


void print_quran_at(Quran* quran, int index);

int num_ayahs_in_surah(Surah* surah) {
    return (*surah).num_ayahs;
}


double num_pages_in_surah(Surah* surah);


int surah_number(Surah* surah)
{
    return (*surah).surah_number;
}



//void print_quran(Quran* quran)
//{
//    int i = 0;
//    printf("[");
//    while (i < (*quran).num_of_surahs) {
//        if (i == (*quran).num_of_surahs - 1) {
//            if ((*quran).juzz[i].surahs == NULL) {
//                printf("EMPTY");
//            }
//            else print_surah(&(*quran).surahs[i]);
//            printf("]\n");
//            break;
//        }
//        if ((*quran).surahs[i].name == NULL) {
//            printf("EMPTY, ");
//        }
//        else print_surah(&((*quran).surahs[i]));
//        i++;
//    }
//
//}


int main(int argc, char* argv[]) {
    Quran* kareems_quran = init_quran("black", 1.5);
    // Surah* naba = init_surah("Naba", 1.75, 40, 78);
    // insert_surah(kareems_quran, naba);
    
    // print_quran(kareems_quran);
    
    // printf("number of ayahs in surah Naba is %d\n", num_ayahs_in_surah(naba));
    
    return 0;
}
