#include "main.h"

/**
 * init_para - clear and reset buffer
 * @par: parametre structure
 * @pr: the argument
 * Return: empty
*/

void init_para(para_t *par, va_list pr)
{
par->u_f = 0;
par->p_f = 0;
par->s_f = 0;
par->hax_f = 0;
par->z_f = 0;
par->m_f = 0;
par->h_modif = 0;
par->l_modif = 0;
par->wdth = 0;
par->precision = UINT_MAX;
(void)pr;
}
