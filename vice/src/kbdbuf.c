/*
 * kbdbuf.c - Kernal keyboard buffer handling for VICE.
 *
 * Written by
 *  Ettore Perazzoli (ettore@comm2000.it)
 *
 * This file is part of VICE, the Versatile Commodore Emulator.
 * See README for copyright notice.
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA
 *  02111-1307  USA.
 *
 */

#include "vice.h"

#include <stdio.h>

#include "maincpu.h"
#include "kbdbuf.h"
#include "types.h"
#include "vmachine.h"
#include "charsets.h"

/* Maximum number of characters we can queue.  */
#define QUEUE_SIZE	16384

/* First location of the buffer.  */
static int buffer_location;

/* Location that stores the number of characters pending in the
   buffer.  */
static int num_pending_location;

/* Maximum number of characters that fit in the buffer.  */
static int buffer_size;

/* Characters in the queue.  */
static char queue[QUEUE_SIZE];

/* Next element in `queue' we must push into the kernal's queue.  */
static int head_idx;

/* Number of pending characters.  */
static int num_pending;

/* ------------------------------------------------------------------------- */

/* Initialization.  */
int kbd_buf_init(int location, int plocation, int size)
{
    buffer_location = location;
    num_pending_location = plocation;
    buffer_size = size;

    return 0;
}

/* Feed `s' into the queue.  `s' is in ASCII code.  */
int kbd_buf_feed(const char *s)
{
    int num = strlen(s);
    int i, p;

    if (num_pending + num > QUEUE_SIZE)
	return -1;

    num_pending += num;
    for (p = head_idx, i = 0; i < num; p = (p + 1) % QUEUE_SIZE, i++)
	queue[p] = s[i];

    return 0;
}

/* Return nonzero if the keyboard buffer is empty.  */
int kbd_buf_is_empty(void)
{
    return mem_read(num_pending_location) == 0;
}

/* Flush pending characters into the kernal's queue if possible.  Characters
   are automatically converted into PETSCII.  */
void kbd_buf_flush(void)
{
    BYTE *p;
    int i, n;

    if (num_pending == 0
        || clk < CYCLES_PER_RFSH * RFSH_PER_SEC
	|| !kbd_buf_is_empty())
	return;

    n = num_pending > buffer_size ? buffer_size : num_pending;
    for (i = 0; i < n; head_idx = (head_idx + 1) % QUEUE_SIZE, i++)
	mem_store(buffer_location + i, p_topetcii(queue[head_idx]));

    mem_store(num_pending_location, n);
    num_pending -= n;
}

