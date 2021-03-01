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
 * Copyright (C) 2021 Andrew Lassalle <andrewlassalle@chromium.org>
 */

#ifndef _LIBQRTR_GLIB_QRTR_TYPES_H_
#define _LIBQRTR_GLIB_QRTR_TYPES_H_

#if !defined (__LIBQRTR_GLIB_H_INSIDE__) && !defined (LIBQRTR_GLIB_COMPILATION)
#error "Only <libqrtr-glib.h> can be included directly."
#endif

G_BEGIN_DECLS

typedef struct _QrtrBus         QrtrBus;
typedef struct _QrtrClient      QrtrClient;
typedef struct _QrtrNode        QrtrNode;

G_END_DECLS

#endif /* _LIBQRTR_GLIB_QRTR_TYPES_H_ */
