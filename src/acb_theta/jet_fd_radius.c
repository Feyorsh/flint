/*
    Copyright (C) 2023 Jean Kieffer

    This file is part of Arb.

    Arb is free software: you can redistribute it and/or modify it under
    the terms of the GNU Lesser General Public License (LGPL) as published
    by the Free Software Foundation; either version 2.1 of the License, or
    (at your option) any later version.  See <http://www.gnu.org/licenses/>.
*/

#include "acb_theta.h"

void
acb_theta_jet_fd_radius(arf_t eps, arf_t err, const arb_t c, const arb_t rho,
    slong ord, slong g, slong hprec, slong prec)
{
    slong b = ord + 1;
    arb_t t, x;

    arb_init(t);
    arb_init(x);

    /* Set x to minimum of (1/2g)^(1/b)*rho, (2^(-hprec-1)/cg)^(1/b)*rho */
    arb_mul_2exp_si(x, c, -hprec);
    arb_div(x, x, c, prec);
    arb_set_si(t, 1);
    arb_min(x, x, t, prec);
    arb_div_si(x, x, 2 * g, prec);
    arb_root_ui(x, x, b, prec);
    arb_mul(x, x, rho, prec);

    arb_get_lbound_arf(eps, x, prec);
    arf_one(err);
    arf_mul_2exp_si(err, err, -hprec);

    arb_clear(t);
    arb_clear(x);
}
