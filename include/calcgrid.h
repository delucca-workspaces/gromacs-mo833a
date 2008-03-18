/*
 * $Id$
 * 
 *                This source code is part of
 * 
 *                 G   R   O   M   A   C   S
 * 
 *          GROningen MAchine for Chemical Simulations
 * 
 *                        VERSION 3.2.0
 * Written by David van der Spoel, Erik Lindahl, Berk Hess, and others.
 * Copyright (c) 1991-2000, University of Groningen, The Netherlands.
 * Copyright (c) 2001-2004, The GROMACS development team,
 * check out http://www.gromacs.org for more information.

 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 * 
 * If you want to redistribute modifications, please consider that
 * scientific software is very special. Version control is crucial -
 * bugs must be traceable. We will be happy to consider code for
 * inclusion in the official distribution, but derived work must not
 * be called official GROMACS. Details are found in the README & COPYING
 * files - if they are missing, get the official version at www.gromacs.org.
 * 
 * To help us fund GROMACS development, we humbly ask that you cite
 * the papers on the package - you can find them in the top README file.
 * 
 * For more info, check our website at http://www.gromacs.org
 * 
 * And Hey:
 * Gromacs Runs On Most of All Computer Systems
 */
#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

extern real calc_grid(FILE *fp,
		      matrix box,real gr_sp,
		      int *nx,int *ny,int *nz,int nnodes);
/* Sets the number of grid points for each zero n* to the first reasonable
 * number which gives a spacing equal to or smaller than gr_sp.
 * nx and ny should be divisible by nnodes, an error is generated when this
 * can not be achieved by calc_grid.
 * Returns the maximum grid spacing.
 */

extern bool compatible_pme_nx_ny(const t_inputrec *ir,int npme,
				 int *nx,int *ny);
/* Returns whether it could make a compatible grid.
 * Returns *nx >= ir->nkx and *ny >= ir->nky that are divisible by npme
 * and that do not contain inconvenient factors.
 */

extern void change_pme_grid(FILE *fplog,bool bStdErr,int npme,
			    t_inputrec *ir,int nkx,int nky);
/* Sets nkx and nky in ir.
 * Prints messages to fplog (if not NULL) and to stderr (if bStdErr).
 */

extern real pme_grid_enlarge_limit();
/* Returns how much nkx*nky*nkz is allowed to be increased by mdrun. */

extern void make_compatible_pme_grid(FILE *fplog,bool bStdErr,int npme,
				     t_inputrec *ir);
/* Checks if the ir->nkx and ir->nky are divisible by npme.
 * If this is not the case, they are made compatible
 * when nkx*nky does not increase by more pme_grid_enlarge_limit.
 */
