/* ScummVM - Graphic Adventure Engine
 *
 * ScummVM is the legal property of its developers, whose names
 * are too numerous to list here. Please refer to the COPYRIGHT
 * file distributed with this source distribution.
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
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 *
 */

#ifndef ULTIMA8_GUMPS_WIDGETS_GAMEWIDGET_H
#define ULTIMA8_GUMPS_WIDGETS_GAMEWIDGET_H

#include "ultima/ultima8/gumps/gump.h"
#include "ultima/ultima8/misc/p_dynamic_cast.h"

namespace Ultima {
namespace Ultima8 {

struct GameInfo;

class GameWidget : public Gump {
public:
	// p_dynamic_class stuff
	ENABLE_RUNTIME_CLASSTYPE()

	GameWidget(int x, int y, istring &game);
	~GameWidget() override;

	istring getGameName();

	void InitGump(Gump *newparent, bool take_focus = true) override;

	uint16 TraceObjId(int32 mx, int32 my) override;

	void PaintThis(RenderSurface *, int32 lerp_factor, bool scaled) override;

	Gump *OnMouseDown(int button, int32 mx, int32 my) override;
	void OnMouseOver() override;
	void OnMouseLeft() override;

	void ChildNotify(Gump *child, uint32 message) override;

	enum Message {
		GAME_PLAY     = 1,
		GAME_LOAD     = 2,
		GAME_SETTINGS = 3,
		GAME_REMOVE   = 4
	};

protected:
	GameInfo *_info;

	bool _highlight;
};

} // End of namespace Ultima8
} // End of namespace Ultima

#endif
