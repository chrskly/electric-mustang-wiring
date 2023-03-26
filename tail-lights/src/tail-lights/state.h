/*
 * This file is part of the ev mustang project.
 *
 * Copyright (C) 2023 Christian Kelly <chrskly@chrskly.com>
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


#ifndef STATE_H
#define STATE_H

enum State {
    OFF,
    RUNNING_LIGHT,
    BRAKE,
    FLASH,
};

void do_flash();
void do_brake();
void do_lights();
void do_off();

#endif