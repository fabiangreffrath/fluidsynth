/* FluidSynth - A Software Synthesizer
 *
 * Copyright (C) 2003  Peter Hanappe and others.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public License
 * as published by the Free Software Foundation; either version 2.1 of
 * the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free
 * Software Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
 * 02110-1301, USA
 */

/* Author: Markus Nentwig, nentwig@users.sourceforge.net
 */

#ifndef _FLUID_LADSPA_H
#define _FLUID_LADSPA_H

#include "fluid_sys.h"
#include "fluidsynth_priv.h"

#ifdef LADSPA

typedef enum _fluid_ladspa_dir_t {
    FLUID_LADSPA_INPUT,
    FLUID_LADSPA_OUTPUT,
    FLUID_LADSPA_FIXED

} fluid_ladspa_dir_t;

typedef struct _fluid_ladspa_fx_t fluid_ladspa_fx_t;


fluid_ladspa_fx_t *new_fluid_ladspa_fx(fluid_real_t sample_rate, int audio_groups, int effects_channels, int audio_channels, int buffer_size);
void delete_fluid_ladspa_fx(fluid_ladspa_fx_t *fx);
int fluid_ladspa_set_sample_rate(fluid_ladspa_fx_t *fx, fluid_real_t sample_rate);

int fluid_ladspa_is_active(fluid_ladspa_fx_t *fx);
int fluid_ladspa_activate(fluid_ladspa_fx_t *fx);
int fluid_ladspa_deactivate(fluid_ladspa_fx_t *fx);
int fluid_ladspa_reset(fluid_ladspa_fx_t *fx);

void fluid_ladspa_run(fluid_ladspa_fx_t *fx, fluid_real_t *left_buf[], fluid_real_t *right_buf[],
                      fluid_real_t *fx_left_buf[], fluid_real_t *fx_right_buf[], int block_count, int block_size);

int fluid_ladspa_add_plugin(fluid_ladspa_fx_t *fx, const char *lib_name, const char *plugin_name);
int fluid_ladspa_port_exists(fluid_ladspa_fx_t *fx, int plugin_id, const char *name);

int fluid_ladspa_add_audio_node(fluid_ladspa_fx_t *fx, const char *name);
int fluid_ladspa_add_control_node(fluid_ladspa_fx_t *fx, const char *name, fluid_real_t val);
int fluid_ladspa_set_control_node(fluid_ladspa_fx_t *fx, const char *name, fluid_real_t val);
int fluid_ladspa_node_exists(fluid_ladspa_fx_t *fx, const char *name);

int fluid_ladspa_connect(fluid_ladspa_fx_t *fx, int plugin_id, fluid_ladspa_dir_t dir,
                         const char *port_name, const char *node_name);
int fluid_ladspa_check(fluid_ladspa_fx_t *fx, char *err, int err_size);
int fluid_ladspa_control_defaults(fluid_ladspa_fx_t *fx);

#endif /* LADSPA */
#endif /* _FLUID_LADSPA_H */
