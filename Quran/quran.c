//
//  quran.c
//  Quran
//
//  Created by Kareem Rajeh on 12/14/23.
//

#include "quran.h"
#include <stdio.h>
#include <stdlib.h>

void play_game(Quran* quran) {
    char response[100];
    char play_again = 'n';
    
    printf("Welcome to Quran Al-Hakeem\n You can ask me the following:\n");
    printf("The number of juzz in quran, number of ayahs/pages in a surah, and ask for a description of the surah\n");
    printf("What would you like to do? ");
    do {
        fgets(response, sizeof(response), stdin);
        fflush(stdin); // equivalent to clear_keyboard_buffer();
        
        if (str_equal("number of juzz in quran", response))
        {
            printf("There are %d juzz in the Quran\n", 30);
        }
        else if (str_equal("number of ayahs in quran", response))
        {
            printf("There are %d ayahs in the Quran\n", 6236);
        }
        else if (str_equal("number of ayahs in surah", response))
        {
            // TODO: implement
        }
        else if (str_equal("number of pages in surah", response))
        {
            // TODO: implement
        }
        else if (str_equal("give me a description of surah", response))
        {
            // TODO: implement
        }
        else
        {
            printf("invalid response\n");
        }
        
        printf("Do you want to play again? (Y/N) ");
        scanf("%c", &play_again);
        fflush(stdin);
        
    } while (play_again == 'Y' || play_again == 'y');
}


Quran* init_quran(char* color, double juzz_memorized)
{
    Quran* quran = malloc(sizeof(Quran));
    if (quran == NULL)
    {
        printf("Failed at line: %d", __LINE__);
        exit(1);
    }
    
    (*quran).num_juzz = 30;
    (*quran).num_of_surahs = 114;
    
    (*quran).juzz = calloc(sizeof(Juzz), (*quran).num_juzz);
    if ((*quran).juzz == NULL)
    {
        printf("Failed at line: %d", __LINE__);
        exit(1);
    }

    for (int i = 0; i < (*quran).num_juzz; i++) {
        (*quran).juzz[i].surahs = calloc(sizeof(Surah), 37);
        if ((*quran).juzz[i].surahs == NULL) {
            printf("Failed at line: %d", __LINE__);
            exit(1);
        }
    }

    
    (*quran).juzz ->number_surahs = 0;
    
    (*quran).color = malloc(sizeof(char) * str_len(color) + 1);
    if ((*quran).color == NULL)
    {
        printf("Failed at line: %d", __LINE__);
        exit(1);
    }
    str_cpy((*quran).color, color);
    
    (*quran).juzz_memorized = juzz_memorized;
    
    return quran;
}

Quran* init_and_fill_quran(char* color, double juzz_memorized)
{
    Quran* quran = init_quran(color, juzz_memorized);
    // TODO: create each surah and insert
    Surah* naba = init_surah("Ama", 30, 78, "Naba", 1.75, 40, "\n\nSurah An-Naba focuses on the Day of Judgment and the consequences of people's actions in this world and the hereafter. \nIt emphasizes the importance of the Quran's message and urges reflection on the signs of God in the natural world as evidence of His power and wisdom. \nThe surah warns of the rejection of the Prophet's message by disbelievers and highlights the ultimate accountability before Allah.\n");
    
    insert_surah(quran, naba);
    
    return quran;
}

Surah* init_surah(char* juzz_name, int juzz_num, int surah_num, char* surah_name, double num_pages, int num_ayahs, char* description)
{
    Surah* surah = malloc(sizeof(Surah));
    if (surah == NULL)
    {
        printf("Failed at line: %d", __LINE__);
        exit(1);
    }
    
    (*surah).juzz_name = malloc(sizeof(char) * str_len(juzz_name) + 1);
    if ((*surah).juzz_name == NULL)
    {
        printf("Failed at line: %d", __LINE__);
        exit(1);
    }
    str_cpy((*surah).juzz_name, juzz_name);
    
    (*surah).juzz_number = juzz_num;
    (*surah).surah_number = surah_num;
    
    (*surah).surah_name = malloc(sizeof(char) * str_len(surah_name) + 1);
    if ((*surah).surah_name == NULL)
    {
        printf("Failed at line: %d", __LINE__);
        exit(1);
    }
    str_cpy((*surah).surah_name, surah_name);
    
    (*surah).num_ayahs = num_ayahs;
    (*surah).num_pages = num_pages;
    
    (*surah).description = malloc(sizeof(char) * str_len(description) + 1);
    if ((*surah).description == NULL)
    {
        printf("Failed at line: %d", __LINE__);
        exit(1);
    }
    str_cpy((*surah).description, description);
    
    return surah;
}


void memorize_an_additional_juzz(Quran* quran, double num_of_juzz_memorized)
{
    (*quran).juzz_memorized += num_of_juzz_memorized;
}


static void insert_surah(Quran* quran, Surah* surah)
{
    int juzz_number = (*surah).juzz_number -1;
    int surah_index = (*quran).juzz[juzz_number].number_surahs;

    Juzz* juzz = &((*quran).juzz[juzz_number]);
    (*juzz).surahs[surah_index] = *surah;

    (*quran).juzz[juzz_number].number_surahs++;

    return;
}


void print_surah(Quran* quran, char* surah_name)
{
    int juzz_number = 0;
    int surah_number = 0;
    Surah surah;
    Bool found_surah = false;
    
    while (juzz_number < 30)
    {
        Juzz current_juzz = (*quran).juzz[juzz_number];
        while (surah_number < 37)
        {
            if (current_juzz.surahs[surah_number].surah_name == NULL) {
                break;
            }
            if (str_equal(surah_name, current_juzz.surahs[surah_number].surah_name))
            {
                surah = current_juzz.surahs[surah_number];
                found_surah = true;
                break;
            }
            surah_number++;
        }
        if (found_surah) {
            break;
        }
        juzz_number++;
    }
    printf("Surah (%d) %s has %d ayahs and %.2f pages\n", surah.surah_number, surah_name, surah.num_ayahs, surah.num_pages);
    
    return;
}

void print_surah_with_description(Quran* quran, char* surah_name) {
    int juzz_number = 0;
    int surah_number = 0;
    Surah surah;
    Bool found_surah = false;
    
    while (juzz_number < 30)
    {
        Juzz current_juzz = (*quran).juzz[juzz_number];
        while (surah_number < 37)
        {
            if (current_juzz.surahs[surah_number].surah_name == NULL) {
                break;
            }
            if (str_equal(surah_name, current_juzz.surahs[surah_number].surah_name))
            {
                surah = current_juzz.surahs[surah_number];
                found_surah = true;
                break;
            }
            surah_number++;
        }
        if (found_surah) {
            break;
        }
        juzz_number++;
    }
    printf("Surah (%d) %s has %d ayahs and %.2f pages and %s\n", surah.surah_number, surah_name, surah.num_ayahs, surah.num_pages, surah.description);
    
    return;
}

void print_surah_description(Quran* quran, char* surah_name)
{
    int juzz_number = 0;
    int surah_number = 0;
    Surah surah;
    Bool found_surah = false;
    
    while (juzz_number < 30)
    {
        Juzz current_juzz = (*quran).juzz[juzz_number];
        while (surah_number < 37)
        {
            if (current_juzz.surahs[surah_number].surah_name == NULL) {
                break;
            }
            if (str_equal(surah_name, current_juzz.surahs[surah_number].surah_name))
            {
                surah = current_juzz.surahs[surah_number];
                found_surah = true;
                break;
            }
            surah_number++;
        }
        if (found_surah) {
            break;
        }
        juzz_number++;
    }
    printf("%s\n", surah.description);
    
    return;
}


static void __print_surah(Surah surah, Bool last_surah) {
    printf("Surah (%d) %s has %d ayahs and %.2f pages", surah.surah_number, surah.surah_name, surah.num_ayahs, surah.num_pages);
    
    if (last_surah) {
        printf("]\n");
    }
    else {
        printf(", ");
    }
    
    return;
}


void print_entire_juzz(Quran* quran, int juzz_number)
{
    if ((*quran).juzz[juzz_number -1].number_surahs == 0)
    {
        printf("[EMPTY]\n");
        return;
    }
    
    printf("[");
    Juzz current_juzz = (*quran).juzz[juzz_number -1];
    int i = 0;
    while (i < current_juzz.number_surahs) {
        __print_surah(current_juzz.surahs[i], i == current_juzz.number_surahs - 1);
        i++;
    }
    return;
}


void print_quran(Quran* quran)
{
    printf("[");
    int juzz_number = 0;
    while (juzz_number < 30) {
        if (juzz_number == 30 - 1) {
            print_entire_juzz(quran, juzz_number);
            printf("]\n");
        }
        else print_entire_juzz(quran, juzz_number);
    }
    
    return;
}

static double num_pages_in_surah(Surah* surah)
{
    return (*surah).num_pages;
}


static int num_ayahs_in_surah(Surah* surah)
{
    return (*surah).num_ayahs;
}


static int surah_number(Surah* surah)
{
    return (*surah).surah_number;
}


static int str_len(char* str)
{
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    
    return len;
}


static void str_cpy(char* dest, char* src)
{
    int src_index = 0;
    int dest_index = 0;
    
    while (src_index < str_len(src)) {
        dest[dest_index] = src[src_index];
        src_index++;
        dest_index++;
    }
    
    return;
}


static Bool str_equal(char* correct_string, char* response) {
    // edge case: Empty string
    if (response == NULL) {
        return false;
    }
    
    int correct_index = 0, response_index = 0;
    while (correct_string[correct_index] != '\0') {
        if (response[response_index] != correct_string[correct_index]) {
            return false;
        }
        correct_index++;
        response_index++;
    }
    
    return true;
}
