/*
    Copyright (C) 2023 Jean Kieffer

    This file is part of Arb.

    Arb is free software: you can redistribute it and/or modify it under
    the terms of the GNU Lesser General Public License (LGPL) as published
    by the Free Software Foundation; either version 2.1 of the License, or
    (at your option) any later version.  See <http://www.gnu.org/licenses/>.
*/

#include "acb_mat.h"

int main(void)
{
    slong iter;
    flint_rand_t state;

    flint_printf("set_real_imag....");
    fflush(stdout);

    flint_randinit(state);

    for (iter = 0; iter < 10000 * 0.1 * flint_test_multiplier(); iter++)
    {
        slong m, n;
        arb_mat_t re, im, x, y;
        acb_mat_t z;

        m = n_randint(state, 10);
        n = n_randint(state, 10);

        arb_mat_init(re, m, n);
        arb_mat_init(im, m, n);
        arb_mat_init(x, m, n);
        arb_mat_init(x, m, n);
        acb_mat_init(z, m, n);

        arb_mat_randtest(re, state, 2 + n_randint(state, 100), 10);
        arb_mat_randtest(im, state, 2 + n_randint(state, 100), 10);

        acb_mat_set_real_imag(z, re, im);
        acb_mat_get_real(x, z);
        acb_mat_get_imag(y, z);

        if (!arb_mat_equal(x, re) || !arb_mat_equal(y, im))
        {
            flint_printf("FAIL\n\n");
            flint_printf("m = %wd, n = %wd\n", m, n);
            flint_abort();
        }

        arb_mat_clear(re);
        arb_mat_clear(im);
        arb_mat_clear(x);
        arb_mat_clear(y);
        acb_mat_clear(z);
    }

    flint_randclear(state);
    flint_cleanup();
    flint_printf("PASS\n");
    return 0;
}
