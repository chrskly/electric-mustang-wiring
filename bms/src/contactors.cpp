/*
 * This file is part of the ev mustang bms project.
 *
 * Copyright (C) 2022 Christian Kelly <chrskly@chrskly.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */


bool closeContactors(Battery battery) {

	// Check that the voltage difference between the packs in the battery is
	// a small, safe value.
	if ( voltageDeltaBetweenPacks() < SAFE_VOLTAGE_DELTA_BETWEEN_PACKS ) {
		// OK to close the contactors
	}

	// The pack voltages differ too much. We can only use one pack. Figure out
	// which pack is fuller (has higher voltage) and close the contactors for
	// just that pack.
	else {

		BatteryPack preferredPack = getPackWithHighestVoltage(Battery battery);
		closeContactors(preferredPack);
	}
}

bool openContactors() {
	// wait?
}