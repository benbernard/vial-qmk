/* Copyright 2021 Katrina (@PepperKats)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
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

#include "quantum.h"

//Display
#ifdef OLED_ENABLE
bool oled_task_kb(void) {
    if (!oled_task_user()) { return false; }
    // render_logo();
    oled_write_ln_P(PSTR(""), false);
    oled_write_P(PSTR("  Layer: "), false);

    // write layer state, converting int to string
    char layer_str[4]; // Assuming a maximum of 3 digits for layer number + null terminator
    snprintf(layer_str, sizeof(layer_str), "%u", get_highest_layer(layer_state));
    oled_write_ln(layer_str, false);
    return true;
}
#endif
