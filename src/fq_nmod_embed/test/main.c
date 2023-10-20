/*
    Copyright (C) 2023 Albin Ahlbäck

    This file is part of FLINT.

    FLINT is free software: you can redistribute it and/or modify it under
    the terms of the GNU Lesser General Public License (LGPL) as published
    by the Free Software Foundation; either version 2.1 of the License, or
    (at your option) any later version.  See <https://www.gnu.org/licenses/>.
*/

#include <string.h>

/* Include functions *********************************************************/

#include "t-composition_matrix.c"
#include "t-embed.c"
#include "t-embed_matrices.c"
#include "t-mono_dual_matrix.c"
#include "t-mul_matrix.c"

/* Array of test functions ***************************************************/

test_struct tests[] =
{
    TEST_FUNCTION(fq_nmod_embed_composition_matrix),
    TEST_FUNCTION(fq_nmod_embed),
    TEST_FUNCTION(fq_nmod_embed_matrices),
    TEST_FUNCTION(fq_nmod_embed_mono_dual_matrix),
    TEST_FUNCTION(fq_nmod_embed_mul_matrix)
};

/* main function *************************************************************/

TEST_MAIN(tests)
