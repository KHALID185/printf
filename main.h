#ifndef _PRINTF_H
#define _PRINTF_H

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <limits.h>
#include <unistd.h>

#define CONVERT_L	1
#define CONVERT_UNS	2
#define NULL_STR "(nul)"

#define BUFFER_S 1024
#define BUFFER_FLUSH -1

#define PARA_INIT {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}

/**
 * struct parametres - parametres in structure
 * @u_f: flag if unsigned value
 * @p_f: plus flag
 * @s_f: space flag
 * @hax_f: hashtag flag
 * @z_f: zero flag
 * @m_f: minus flag
 * @h_modif: if h moddified is specified
 * @l_modif: if l modified
 * @wdth: field width
 * @precision: field precision
*/

typedef struct par
{
unsigned int u_f	: 1;
unsigned int p_f	: 1;
unsigned int s_f	: 1;
unsigned int hax_f	: 1;
unsigned int z_f	: 1;
unsigned int m_f	: 1;
unsigned int h_modif	: 1;
unsigned int l_modif	: 1;
unsigned int wdth;
unsigned int precision;

} para_t;

/**
 * struct specifier - specifier structure
 * @sp: specefier
 * @f: funcion associed
*/
typedef struct specif
{
char *specif;
int (*f)(va_list pr, para_t *);
} specif_t;

int _puts(char *s);
int _putchar (int c);

int _printf(const char *format, ...);
void init_para(para_t *par, va_list pr);


int print_char(va_list pr, para_t *par);
int print_string(va_list pr, para_t *par);
int print_percent(va_list pr, para_t *par);
int print_int(va_list pr, para_t *par);
int print_uns(va_list pr, para_t *par);
int printf_ad(va_list pr, para_t *par);
int print_S(va_list pr, para_t *par);
int print_bi(va_list pr, para_t *par);
int print_oc(va_list pr, para_t *par);
int print_hex(va_list pr, para_t *par);
int print_hex_u(va_list pr, para_t *par);
int print_rev(va_list pr, para_t *par);
int print_r13(va_list pr, para_t *par);

char *conv_num(long int n, int b, int f, para_t *par);

int (*get_specif(char *str))(va_list pr, para_t *par);
int get_p_fct(char *str, va_list pr, para_t *par);
int get_f(char *str, para_t *par);
int get_modif(char *str, para_t *par);
char *get_wdth(char *str, para_t *par, va_list pr);
char *get_precision(char *str, para_t *par, va_list pr);

int printf_fto(char *start, char *stp, char *exep);

int digit(int c);
int len_s(char *st);
int print_num(char *str, para_t *par);
int print_num_r(char *str, para_t *par);
int print_num_l(char *str, para_t *par);

#endif
