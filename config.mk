# Customize below to fit your system (run ./configure for automatic presets)

# paths (unset $PCPREFIX to not install a pkg-config-file)
DESTDIR   =
PREFIX    = /usr/local
INCPREFIX = $(PREFIX)/include
LIBPREFIX = $(PREFIX)/lib
MANPREFIX = $(PREFIX)/share/man
PCPREFIX  = $(LIBPREFIX)/pkgconfig

# names
ANAME     = libtakum.a
SONAME    = libtakum.so.$(VERSION_MAJOR).$(VERSION_MINOR).$(VERSION_PATCH)
BINSUFFIX = 

# flags
CPPFLAGS = -D_ISOC99_SOURCE
CFLAGS   = -std=c99 -Os -Wall -Wextra -Wpedantic
LDFLAGS  = -s
LDLIBS = -lm

BUILD_CPPFLAGS = $(CPPFLAGS)
BUILD_CFLAGS   = $(CFLAGS)
BUILD_LDFLAGS  = $(LDFLAGS)
BUILD_LDLIBS  = $(LDLIBS)

SHFLAGS   = -fPIC #-ffreestanding; SOFLAGS: -nostdlib after shared
SOFLAGS   = -shared -Wl,--soname=libtakum.so.$(VERSION_MAJOR).$(VERSION_MINOR)
SOSYMLINK = true

# tools (unset $LDCONFIG to not call ldconfig(1) after install/uninstall)
CC       = cc
BUILD_CC = $(CC)
AR       = ar
RANLIB   = ranlib
LDCONFIG = ldconfig
SH       = sh
