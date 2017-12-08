/* epan-int.h
 *
 * Wireshark Protocol Analyzer Library
 *
 * Copyright (c) 2001 by Gerald Combs <gerald@wireshark.org>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#ifndef __EPAN_INT_H__
#define __EPAN_INT_H__

#include <epan/frame_data.h>
#include <wsutil/nstime.h>

struct epan_session {
	struct packet_provider *prov;	/* packet provider for this session */

	const nstime_t *(*get_frame_ts)(struct packet_provider *prov, guint32 frame_num);
	const char *(*get_interface_name)(struct packet_provider *prov, guint32 interface_id);
	const char *(*get_interface_description)(struct packet_provider *prov, guint32 interface_id);
	const char *(*get_user_comment)(struct packet_provider *prov, const frame_data *fd);
};

#endif
