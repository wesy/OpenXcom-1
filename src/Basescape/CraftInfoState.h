/*
 * Copyright 2010-2012 OpenXcom Developers.
 *
 * This file is part of OpenXcom.
 *
 * OpenXcom is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * OpenXcom is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with OpenXcom.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef OPENXCOM_CRAFTINFOSTATE_H
#define OPENXCOM_CRAFTINFOSTATE_H

#include "../Engine/State.h"

namespace OpenXcom
{

class Base;
class TextButton;
class Window;
class Text;
class Surface;

/**
 * Craft Info screen that shows all the
 * info of a specific craft.
 */
class CraftInfoState : public State
{
private:
	Base *_base;
	size_t _craft;

	TextButton *_btnOk, *_btnW1, *_btnW2, *_btnCrew, *_btnEquip, *_btnArmor;
	Window *_window;
	Text *_txtCraft, *_txtDamage, *_txtFuel;
	Text *_txtW1Name, *_txtW1Ammo, *_txtW1Max, *_txtW2Name, *_txtW2Ammo, *_txtW2Max;
	Surface *_sprite, *_weapon1, *_weapon2, *_crew, *_equip;
public:
	/// Creates the Craft Info state.
	CraftInfoState(Game *game, Base *base, size_t craft);
	/// Cleans up the Craft Info state.
	~CraftInfoState();
	/// Updates the craft info.
	void init();
	/// Handler for clicking the OK button.
	void btnOkClick(Action *action);
	/// Handler for clicking the 1 button.
	void btnW1Click(Action *action);
	/// Handler for clicking the 2 button.
	void btnW2Click(Action *action);
	/// Handler for clicking the Crew button.
	void btnCrewClick(Action *action);
	/// Handler for clicking the Equipment button.
	void btnEquipClick(Action *action);
	/// Handler for clicking the Armor button.
	void btnArmorClick(Action *action);
};

}

#endif
