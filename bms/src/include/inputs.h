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

#ifndef BMS_SRC_INCLUDE_INPUTS_H_
#define BMS_SRC_INCLUDE_INPUTS_H_

void ignition_on_callback(uint gpio, uint32_t events);
void enable_listen_for_ignition_signal();

void charge_enable_callback(uint gpio, uint32_t events);
void enable_listen_for_charge_enable_signal();

#endif  // BMS_SRC_INCLUDE_INPUTS_H_
