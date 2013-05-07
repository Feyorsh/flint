/*=============================================================================

    This file is part of FLINT.

    FLINT is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    FLINT is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with FLINT; if not, write to the Free Software
    Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301 USA

=============================================================================*/
/******************************************************************************

    Copyright (C) 2007 David Howden
    Copyright (C) 2007, 2008, 2009, 2010 William Hart
    Copyright (C) 2008 Richard Howell-Peak
    Copyright (C) 2011 Fredrik Johansson
    Copyright (C) 2012 Lina Kulakova

******************************************************************************/

#include <gmp.h>
#include "flint.h"
#include "fmpz_mod_poly.h"
#include "fmpz_mod_poly_factor.h"

void
fmpz_mod_poly_factor_clear(fmpz_mod_poly_factor_t fac)
{
    long i;

    for (i = 0; i < fac->alloc; i++)
        fmpz_mod_poly_clear(fac->poly + i);

    flint_free(fac->poly);
    flint_free(fac->exp);
}
