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
#ifndef OPENXCOM_DOGFIGHTSTATE_H
#define OPENXCOM_DOGFIGHTSTATE_H

#include "../Engine/State.h"
#include <vector>
#include <string>

namespace OpenXcom
{

class ImageButton;
class Text;
class Surface;
class InteractiveSurface;
class Timer;
class Globe;
class Craft;
class Ufo;
class CraftWeaponProjectile;

/**
 * Shows a dogfight (interception) between a
 * player craft and an UFO.
 */
class DogfightState : public State
{
private:
	Timer *_animTimer, *_moveTimer, *_w1Timer, *_w2Timer, *_ufoWtimer, *_ufoEscapeTimer, *_ufoHitBlingTimer;
	Surface *_window, *_battle, *_weapon1, *_range1, *_weapon2, *_range2, *_damage;
	InteractiveSurface *_btnMinimize, *_preview;
	ImageButton *_btnStandoff, *_btnCautious, *_btnStandard, *_btnAggressive, *_btnDisengage, *_btnUfo;
	ImageButton *_mode;
	Text *_txtAmmo1, *_txtAmmo2, *_txtDistance, *_txtStatus;
	Globe *_globe;
	Craft *_craft;
	Ufo *_ufo;
	int _timeout, _currentDist, _targetDist, _currentRadius, _targetRadius, _ufoFireInterval;
	bool _end, _destroyUfo, _destroyCraft, _ufoBreakingOff;
	std::vector<CraftWeaponProjectile*> _projectiles;
	static const int _ufoBlobs[8][13][13];
	static const int _projectileBlobs[4][6][3];
	int _paletteOffset, _ufoSize, _ufoHitFrame;

public:
	/// Creates the Dogfight state.
	DogfightState(Game *game, Globe *globe, Craft *craft, Ufo *ufo);
	/// Cleans up the Dogfight state.
	~DogfightState();
	/// Runs the timers.
	void think();
	/// Animates the window.
	void animate();
	/// Moves the craft.
	void move();
	// Fires the first weapon.
	void fireWeapon1();
	// Fires the second weapon.
	void fireWeapon2();
	// Fires UFO weapon.
	void ufoFireWeapon();
	// Sets the craft to minimum distance.
	void minimumDistance();
	// Sets the craft to maximum distance.
	void maximumDistance();
	/// Changes the status text.
	void setStatus(const std::string &status);
	/// Handler for clicking the Minimize button.
	void btnMinimizeClick(Action *action);
	/// Handler for clicking the Standoff button.
	void btnStandoffClick(Action *action);
	/// Handler for clicking the Cautious Attack button.
	void btnCautiousClick(Action *action);
	/// Handler for clicking the Standard Attack button.
	void btnStandardClick(Action *action);
	/// Handler for clicking the Aggressive Attack button.
	void btnAggressiveClick(Action *action);
	/// Handler for clicking the Disengage button.
	void btnDisengageClick(Action *action);
	/// Handler for clicking the Ufo button.
	void btnUfoClick(Action *action);
	/// Handler for clicking the Preview graphic.
	void previewClick(Action *action);
	/// Makes the UFO break off the interception... or at least tries to.
	void ufoBreakOff();
	/// Draws UFO.
	void drawUfo();
	/// Draws projectiles.
	void drawProjectile(const CraftWeaponProjectile* p);
};

}

#endif
