/* NetworkManager-libreswan -- Network Manager Libreswan plugin
 *
 * Dan Williams <dcbw@redhat.com>
 * Avesh Agarwal <avagarwa@redhat.com>
 * Lubomir Rintel <lkundrak@v3.sk>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 *
 * Copyright (C) 2010 - 2015 Red Hat, Inc.
 */

#ifndef __UTILS_H__
#define __UTILS_H__

typedef void (*NMDebugWriteFcn) (const char *setting);

__attribute__((__format__ (__printf__, 5, 6)))
gboolean write_config_option_newline (int fd,
                                      gboolean new_line,
                                      NMDebugWriteFcn debug_write_fcn,
                                      GError **error,
                                      const char *format, ...);

#define write_config_option(fd, debug_write_fcn, error, ...) write_config_option_newline((fd), TRUE, debug_write_fcn, error, __VA_ARGS__)

gboolean
nm_libreswan_config_write (gint fd,
                           NMConnection *connection,
                           const char *con_name,
                           const char *leftupdown_script,
                           gboolean openswan,
                           gboolean trailing_newline,
                           NMDebugWriteFcn debug_write_fcn,
                           GError **error);

#endif /* __UTILS_H__ */
