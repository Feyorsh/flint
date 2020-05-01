/*
    Copyright (C) 2020 Fredrik Johansson

    This file is part of Calcium.

    Calcium is free software: you can redistribute it and/or modify it under
    the terms of the GNU Lesser General Public License (LGPL) as published
    by the Free Software Foundation; either version 2.1 of the License, or
    (at your option) any later version.  See <http://www.gnu.org/licenses/>.
*/

#include "ca_qqbar.h"

void
ca_qqbar_get_arb(arb_t res, const ca_qqbar_t x, slong prec)
{
    if (ca_qqbar_sgn_im(x) == 0)
    {
        acb_t t;
        acb_init(t);
        ca_qqbar_get_acb(t, x, prec);
        arb_swap(res, acb_realref(t));
        acb_clear(t);
    }
    else
    {
        arb_indeterminate(res);
    }
}
