//
//  quran.h
//  Quran
//
//  Created by Kareem Rajeh on 12/14/23.
//

#ifndef quran_h
#define quran_h

typedef enum boolean {false, true} Bool;

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
    int number_surahs;
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


Quran* init_quran(char* color, double juzz_memorized);
Quran* init_and_fill_quran(char* color, double juzz_memorized);
static Surah* init_surah(char* juzz_name, int juzz_num, int surah_num, char* surah_name, double num_pages, int num_ayahs, char* description);
static void insert_surah(Quran* quran, Surah* surah);
void print_surah(Quran* quran, char* surah_name);
void print_surah_with_description(Quran* quran, char* surah_name);
void print_surah_description(Quran* quran, char* surah_name);
void print_entire_juzz(Quran* quran, int juzz_number);
static void __print_surah(Surah surah, Bool last_surah);
void print_quran(Quran* quran);
static int num_ayahs_in_surah(Surah* surah);
static double num_pages_in_surah(Surah* surah);
static int surah_number(Surah* surah);
void memorize_an_additional_juzz(Quran* quran, double num_of_juzz_memorized);
static int str_len(char* str);
static void str_cpy(char* dest, char* src);
static Bool str_equal(char* correct_string, char* response);
void play_game(Quran* quran);

#endif /* quran_h */
