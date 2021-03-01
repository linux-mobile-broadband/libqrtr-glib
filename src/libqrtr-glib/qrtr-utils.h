/* -*- Mode: C; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */
/*
 * libqrtr-glib -- GLib/GIO based library to control QRTR devices
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301 USA.
 *
 * Copyright (C) 2019-2020 Eric Caruso <ejcaruso@chromium.org>
 * Copyright (C) 2020 Aleksander Morgado <aleksander@aleksander.es>
 */

#ifndef _LIBQRTR_GLIB_QRTR_UTILS_H_
#define _LIBQRTR_GLIB_QRTR_UTILS_H_

#include <gio/gio.h>
#include <glib.h>

#include "qrtr-types.h"

/**
 * qrtr_get_uri_for_node:
 * @node_id: node id.
 *
 * Build a URI for the given QRTR node.
 *
 * Returns: a string with the URI, or %NULL if none given. The returned value
 *  should be freed with g_free().
 *
 * Since: 1.0
 */
gchar *qrtr_get_uri_for_node (guint32 node_id);

/**
 * qrtr_get_node_for_uri:
 * @uri: a URI.
 * @node_id: return location for the node id.
 *
 * Get the QRTR node id from the specified URI.
 *
 * Returns: %TRUE if @node_id is set, %FALSE otherwise.
 *
 * Since: 1.0
 */
gboolean qrtr_get_node_for_uri (const gchar *uri,
                                guint32     *node_id);

#endif /* _LIBQRTR_GLIB_QRTR_UTILS_H_ */
