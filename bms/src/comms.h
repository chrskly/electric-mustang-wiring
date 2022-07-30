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

#include "battery.h"

void request_module_data(BatteryModule *module);
bool poll_all_modules_for_data(struct repeating_timer *t);
void enable_module_polling();
bool send_status_message();
void enable_status_messages();
bool send_charge_limits_message();
void enable_charge_limits_messages();
void disable_charge_limits_messages();

bool handle_battery_CAN_messages(struct repeating_timer *t);
void enable_handle_battery_CAN_messages();