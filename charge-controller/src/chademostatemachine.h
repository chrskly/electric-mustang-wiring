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

enum ChademoEvent {
    E_IDLE,
    E_ERROR,
};

typedef void (*ChademoState)(ChademoEvent);

void chademo_state_A(ChademoEvent event);
void chademo_state_B1(ChademoEvent event);
void chademo_state_B2(ChademoEvent event);
void chademo_state_B3(ChademoEvent event);
void chademo_state_C(ChademoEvent event);
void chademo_state_D(ChademoEvent event);
void chademo_state_Bprime1(ChademoEvent event);
void chademo_state_Bprime2(ChademoEvent event);
void chademo_state_Bprime3(ChademoEvent event);
void chademo_event_Bprime4(ChademoEvent event);