///////////////////////////////////////////////////////////////////////////////
//		  IRCSP - Internet Realy Chat Services Package
//                  Copyright (C) 2000 Lostworld Development
//          Written By: Justin Ovens [evilicey] [ice95@lostworld.net]
//
//   This program, documentation, and everything included in this
//   package are Copyright (C) 2000 Lostworld Development. You may
//   Download this package from the lostworld site, or via CVS
//   from source forge.
//
//   This program is free software; you can redistribute it and/or modify
//   it under the terms of the GNU General Public License as published by
//   the Free Software Foundation; either version 1, or (at your option)
//   any later version.
//
//   This program is distributed in the hope that it will be useful,
//   but WITHOUT ANY WARRANTY; without even the implied warranty of
//   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//   GNU General Public License for more details.
//
//   You should have received a copy of the GNU General Public License
//   along with this program; if not, write to the Free Software
//   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
//
//   The authors of this program are in no way liable for any
//   consequences or damages, suffered by you or anyone else,
//   arising out of the use or inablility to use this program.
//
//   Author Contact information: ice95@lostworld.net
///////////////////////////////////////////////////////////////////////////////

#include "services.h"

int	save_bans		();

///////////////////////////////////////////////////////////////////////////////
//

int
save_bans ()
{
	Bans	*b;
	FILE	*bandb;

	b = bans;

	if (!(bandb = fopen("bans.db", "w")))
	{
		return 0;
	}
	fprintf(bandb, "; Last Saved %lu\n", time(NULL));
	while (b)
	{
		fprintf(bandb, "%s:%s:%s\n",
			b->chan, b->host, 
			b->setby);
		b = b->next;
	}
	fclose(bandb);
	return 1;
}

///////////////////////////////////////////////////////////////////////////////
//


