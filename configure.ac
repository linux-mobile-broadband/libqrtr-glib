dnl Process this file with autoconf to produce a configure script.
AC_PREREQ([2.68])

dnl The QRTR version number
m4_define([qrtr_major_version], [0])
m4_define([qrtr_minor_version], [0])
m4_define([qrtr_micro_version], [1])
m4_define([qrtr_version],
          [qrtr_major_version.qrtr_minor_version.qrtr_micro_version])

dnl libtool versioning for libqrtr-glib (-version-info c:r:a)
dnl    If the interface is unchanged, but the implementation has changed or
dnl        been fixed, then increment r.
dnl    Otherwise, increment c and zero r.
dnl        If the interface has grown (that is, the new library is compatible
dnl            with old code), increment a.
dnl        If the interface has changed in an incompatible way (that is,
dnl            functions have changed or been removed), then zero a.
m4_define([qrtr_glib_lt_current],  [0])
m4_define([qrtr_glib_lt_revision], [0])
m4_define([qrtr_glib_lt_age],      [0])

AC_INIT([libqrtr], [qrtr_version], [libqmi-devel@lists.freedesktop.org])
AC_CONFIG_SRCDIR([config.h.in])
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_MACRO_DIR([m4])

AM_INIT_AUTOMAKE([1.11 no-define no-dist-gzip dist-xz tar-ustar -Wno-portability])
AM_MAINTAINER_MODE([enable])

dnl Support silent build rules. Disable
dnl by either passing --disable-silent-rules to configure or passing V=1
dnl to make
AM_SILENT_RULES([yes])

dnl Required programs
AC_PROG_CC
AM_PROG_CC_C_O
AC_PROG_INSTALL

dnl Initialize libtool
LT_PREREQ([2.2])
LT_INIT

dnl-----------------------------------------------------------------------------
dnl Compiler warnings
dnl

dnl Make sure autoconf-archive is available
m4_pattern_forbid([^AX_(COMPILER_FLAGS|COMPILER_FLAGS_(CFLAGS|GIR|LDFLAGS))\b],
  [Unexpanded AX_ macro found. Please install GNU autoconf-archive])

dnl Detect git or release builds
AX_IS_RELEASE([git-directory])

dnl Function type cast disabled: used throughout the code especially to
dnl cast GAsyncReadyCallbacks with the real object type instead of GObject
DISABLED_WARNINGS="${DISABLED_WARNINGS} -Wno-cast-function-type"

dnl All message protocol structs are packed, never complain about it
DISABLED_WARNINGS="${DISABLED_WARNINGS} -Wno-packed"

dnl Setup compiler checks
AX_COMPILER_FLAGS()
AX_COMPILER_FLAGS_CFLAGS(,,,[${DISABLED_WARNINGS}])

dnl Specify gnu89 mode
if test "$GCC" = "yes"; then
   CFLAGS="$CFLAGS -std=gnu89"
fi

dnl Version stuff
QRTR_MAJOR_VERSION=qrtr_major_version
QRTR_MINOR_VERSION=qrtr_minor_version
QRTR_MICRO_VERSION=qrtr_micro_version
QRTR_VERSION=qrtr_version
AC_SUBST(QRTR_MAJOR_VERSION)
AC_SUBST(QRTR_MINOR_VERSION)
AC_SUBST(QRTR_MICRO_VERSION)
AC_SUBST(QRTR_VERSION)

dnl libtool version stuff
QRTR_GLIB_LT_CURRENT=qrtr_glib_lt_current
QRTR_GLIB_LT_REVISION=qrtr_glib_lt_revision
QRTR_GLIB_LT_AGE=qrtr_glib_lt_age
AC_SUBST(QRTR_GLIB_LT_CURRENT)
AC_SUBST(QRTR_GLIB_LT_REVISION)
AC_SUBST(QRTR_GLIB_LT_AGE)

dnl Required dependency versions
GLIB_VERSION=2.48
GUDEV_VERSION=147

GLIB_BUILD_SYMBOLS="-DGLIB_VERSION_MIN_REQUIRED=GLIB_VERSION_2_48 -DGLIB_VERSION_MAX_ALLOWED=GLIB_VERSION_2_48 -DGLIB_DISABLE_DEPRECATION_WARNINGS"

dnl GLib, GIO...
PKG_CHECK_MODULES(GLIB,
                  glib-2.0 >= $GLIB_VERSION
                  gobject-2.0
                  gio-2.0
                  gio-unix-2.0)
GLIB_CFLAGS="$GLIB_CFLAGS $GLIB_BUILD_SYMBOLS"
AC_SUBST(GLIB_CFLAGS)
AC_SUBST(GLIB_LIBS)

dnl GObject Introspection
GOBJECT_INTROSPECTION_CHECK([0.9.6])

dnl Documentation
GTK_DOC_CHECK(1.0)
AM_CONDITIONAL([ENABLE_GTK_DOC], [test "x$enable_gtk_doc" = "xyes"])

dnl QRTR kernel support
AC_CHECK_HEADERS([linux/qrtr.h], [], [AC_MSG_ERROR([QRTR support not available in the kernel headers])])

AC_CONFIG_FILES([Makefile
                 data/Makefile
                 data/pkg-config/Makefile
                 data/pkg-config/qrtr-glib.pc
                 src/Makefile
                 src/libqrtr-glib/Makefile
                 src/libqrtr-glib/qrtr-version.h
                 docs/Makefile
                 docs/reference/Makefile
                 docs/reference/libqrtr-glib/Makefile
                 docs/reference/libqrtr-glib/version.xml])

AC_OUTPUT

echo "
    libqrtr $VERSION
    ==============================================

    Build:
      compiler:                 ${CC}
      cflags:                   ${CFLAGS}
      ldflags:                  ${LDFLAGS}
      warn cflags:              ${WARN_CFLAGS}
      warn ldflags:             ${WARN_LDFLAGS}
      Maintainer mode:          ${USE_MAINTAINER_MODE}
      Documentation:            ${enable_gtk_doc}
      gobject introspection:    ${found_introspection}

    System paths:
      prefix:                   ${prefix}
"
