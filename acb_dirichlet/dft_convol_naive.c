/*
    Copyright (C) 2016 Pascal Molin

    This file is part of Arb.

    Arb is free software: you can redistribute it and/or modify it under
    the terms of the GNU Lesser General Public License (LGPL) as published
    by the Free Software Foundation; either version 2.1 of the License, or
    (at your option) any later version.  See <http://www.gnu.org/licenses/>.
*/

#include "acb_dirichlet.h"

void
acb_dirichlet_dft_convol_naive(acb_ptr w, acb_srcptr f, acb_srcptr g, slong len, slong prec)
{
    slong x, y;
    for (x = 0; x < len; x ++)
    {
        acb_ptr wx;
        acb_srcptr fx, gy;
        wx = w + x;
        fx = f + x;
        gy = g;
        acb_zero(wx);
        for (y = 0; y <= x; y++)
            acb_addmul(wx, fx--, gy++, prec);
        for (; y < len; y++)
            acb_addmul(wx, f + x - y, g + y, prec);
    }
}
