/***************************************************************************
 *   Copyright (C) 2012~2012 by CSSlayer                                   *
 *   wengxt@gmail.com                                                      *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA.              *
 ***************************************************************************/

#ifndef FCITX_XKB_H
#define FCITX_XKB_H

#include "fcitx/instance.h"
#define FCITX_XKB_NAME "fcitx-xkb"
#define FCITX_XKB_GETRULES 0
#define FCITX_XKB_GETRULES_RETURNTYPE FcitxXkbRules*
#define FCITX_XKB_GETCURRENTLAYOUT 1
#define FCITX_XKB_GETCURRENTLAYOUT_RETURNTYPE void
#define FCITX_XKB_LAYOUTEXISTS 2
#define FCITX_XKB_LAYOUTEXISTS_RETURNTYPE void
#define FCITX_XKB_GETLAYOUTOVERRIDE 3
#define FCITX_XKB_GETLAYOUTOVERRIDE_RETURNTYPE void
#define FCITX_XKB_SETLAYOUTOVERRIDE 4
#define FCITX_XKB_SETLAYOUTOVERRIDE_RETURNTYPE void
#define FCITX_XKB_SETDEFAULTLAYOUT 5
#define FCITX_XKB_SETDEFAULTLAYOUT_RETURNTYPE void

#define FCITX_XKB_PATH "/keyboard"
#define FCITX_XKB_INTERFACE "org.fcitx.Fcitx.Keyboard"
#endif
